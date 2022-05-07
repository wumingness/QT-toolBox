#include "SevenZHelper.hpp"

SevenZHelper::SevenZHelper()
	: m_pProgressFunc(nullptr)
	, m_pFileFunc(nullptr)
	, m_SourcePath(TEXT(""))
	, m_DestDir(TEXT(""))
	, m_FileSize(0)
	, DefaultSuffix(TEXT("default"))
    , m_Level((bit7z::BitCompressionLevel)5)
    , m_Method((bit7z::BitCompressionMethod)5)
    , m_Dictionsize(2)
    , m_OpType(SevenZType::OpType_None)
{}

SevenZHelper::~SevenZHelper()
{
}

double SevenZHelper::getProgress(){
    return progress;
}




void SevenZHelper::CompressDecompression(SevenZType type, const wstring& Src, const wstring& Dest, const wstring& Password,
	const bit7z::BitCompressionLevel Level, const bit7z::BitCompressionMethod Method,
	const uint64_t Dicsize, const bool ifSolid, const bool ifUpdate)
{
	this->m_OpType = type;
	if ((int)Level > -1)
		this->m_Level = Level;
	if ((int)Method > -1)
		this->m_Method = Method;
	if (Dicsize > 0)
		this->m_Dictionsize = Dicsize;
	if (!ifSolid)
		this->m_Solidmode = ifSolid;
	if (!ifUpdate)
		this->m_Updatemode = ifUpdate;
	if (type == SevenZType::OpType_Compress)
	{
        Compress(type, Src, Dest, Password);
	}
	else if (type == SevenZType::OpType_Decompression)
	{
		Extract(type, Src, Dest, Password);
	}
}

wstring RelativeToAbsolute(wstring convertPath)//参数为相对于工作目录的路径
{
	wchar_t toolSpace[1000];//申请一个临时空间
	_wgetcwd(toolSpace, 1000);//获取当前工作目录(/7-zip)
	wstring workDir = toolSpace;
	uint64_t dotPosition;//记录'.'所在位置
	uint64_t returnCount = 0;//记录'../'出现次数
	while (true) {
		dotPosition = (int)convertPath.find_first_of('.');
		if (dotPosition == 0)//当且仅当首字符为'.'时进行裁剪操作
		{

			if (convertPath[dotPosition + 1] == '.')
				returnCount++;
			else if (convertPath[dotPosition + 1] != '/')
				break;								//若为'./'则无需继续进行裁剪
			convertPath = convertPath.erase(0, convertPath.find_first_of('/')+1);//裁剪'../'部分
			continue;
		}
		break;
	}
	while (returnCount--) {
		//根据'../'出现次数对工作目录地址进行尾部裁剪
		workDir.erase(workDir.find_last_of('\\'));
	}
	workDir.append((wchar_t)'/'+convertPath);//拼接出绝对路径
	return workDir;
}

void SevenZHelper::GetFileSuffix(const wstring& Path)
{
	if (Path.find('.') == Path.npos) {
		//默认后缀格式
		this->m_FileSuffix.push_back(DefaultSuffix);
	}
	else {
		//获取文件后缀
		wstring m_Path = Path;
		while (m_Path.find_first_of(',') != m_Path.npos) {
			int len = m_Path.find_first_of(',') - m_Path.find_first_of('.');
			wstring suffix_str = m_Path.substr(m_Path.find_first_of('.') + 1, len - 1);
			m_Path = m_Path.erase(0, m_Path.find_first_of(',') + 1);
			m_FileSuffix.push_back(suffix_str);
			}
	}
}

void SevenZHelper::TotalSizeCB(uint64_t total_size)
{
	TotalSize = total_size;
}

void SevenZHelper::ProgressCB(uint64_t size)
{
	double progress = ((1.0 * size) / TotalSize) * 100;

//    bar->progressbar->setValue(progress);
//    t->


}//输出压缩解压缩进度

void SevenZHelper::FileNameCB(wstring filename)
{
	wstring temp = filename;
	cout << temp.c_str() << std::endl;
	if (m_pFileFunc) {
		m_pFileFunc(temp);
	}
}


//压缩
void SevenZHelper::Compress(SevenZType type, const wstring& Src, const wstring& Dest, const wstring& Password)
{
	if (Src.empty()) 
		return;

	//源文件路径Vector 
	std::vector<wstring>m_Src;

    wstring m_s = Src;//临时存储单个路径
    int fileNum = 0;
    if (Src.find_last_of(',')){
        m_s += (wchar_t)',';
        fileNum++;
    }
    if(fileNum > 1)
        while (m_s.find_first_of(',') != m_s.npos) {
            double pos = m_s.find_first_of(',');
            m_SourcePath = m_s.substr(0, pos);
            m_s.erase(0, pos + 1);
            m_SourcePath = RelativeToAbsolute(m_SourcePath);
            m_Src.push_back(m_SourcePath);
        }
    else{
        m_Src.push_back(Src);
    }

	GetFileSuffix(Dest);

	//判断当前传入的文件路径是否和解析的后缀一样
    if (Dest.empty())
	{
		m_DestDir = Dest;
		if (m_DestDir.substr(m_DestDir.find_last_of('.') + 1).compare(m_FileSuffix[0]))
		{
			m_DestDir = m_DestDir.substr(0, m_DestDir.find_last_of('.'));
			m_DestDir.append(TEXT("."));
			m_DestDir.append(m_FileSuffix[0]);
		}
	}
	else
	{
		//如果目标路径不设置的话, 会根据当前的压缩文件名称或者压缩文件路径名称创建一个.default(.7z)的压缩文件出来
        if(m_SourcePath!=L"")
            m_DestDir = m_SourcePath;
        else
            m_DestDir=m_s;
		m_DestDir = m_DestDir.substr(0, m_DestDir.find_last_of('.'));
		m_DestDir.append(TEXT("."));
        m_DestDir.append(Dest);
	}

	try {
        bit7z::Bit7zLibrary lib(L"7z.dll");
		std::shared_ptr<BitCompressor> compressor = nullptr;
		if (m_FileSuffix[0].compare(TEXT("default")) == 0 || m_FileSuffix[0].compare(TEXT("7z")) == 0)
		{
			//后缀L".7z"
			compressor = std::make_shared<BitCompressor>(lib, BitFormat::SevenZip);
		}
		else if (m_FileSuffix[0].compare(TEXT("zip")) == 0)
		{
			//后缀L".zip"
			compressor = std::make_shared<BitCompressor>(lib, BitFormat::Zip);
		}
		else if (m_FileSuffix[0].compare(TEXT("rar")) == 0)
		{
			//后缀L".rar"

		}
		bit7z::TotalCallback TotalCB = std::bind(&SevenZHelper::TotalSizeCB, this, std::placeholders::_1);
		bit7z::ProgressCallback ProCB = std::bind(&SevenZHelper::ProgressCB, this, std::placeholders::_1);
		bit7z::FileCallback FC = std::bind(&SevenZHelper::FileNameCB, this, std::placeholders::_1);//定义相关回调函数
		compressor->setTotalCallback(TotalCB);
        compressor->setProgressCallback(ProCB);
		compressor->setFileCallback(FC);
		if ((int)m_Level > -1)
			compressor->setCompressionLevel(m_Level);
		if ((int)m_Method > -1)
			compressor->setCompressionMethod(m_Method);
		if (m_Dictionsize > 0)
			compressor->setDictionarySize(m_Dictionsize);
		compressor->setSolidMode(m_Solidmode);
		compressor->setUpdateMode(m_Updatemode);
		const wstring& m_Pass = Password;
		compressor->setPassword(m_Pass);
        const wstring& m_Dest = this->m_DestDir;
        compressor->compress(m_Src, m_Dest);
	}
	catch (const BitException& ex) {
		//do something with ex.what()...
		cout << ex.what() << endl;
		if (m_pExpFunc)
		{
			m_pExpFunc(ex);
		}
	}
}

//解压
void SevenZHelper::Extract(SevenZType type, const wstring& Src, const wstring& Dest, const wstring& Password)
{
	//Src不能为空
	if (Src.empty()) return;

	//源文件(压缩文件格式) 
	std::vector<wstring>m_Src;
    wstring m_s = Src;
    int fileNum = 0;
    if (Src.find_last_of(',')){
        m_s += (wchar_t)',';
        fileNum++;
    }
    if(fileNum > 1)
        while (m_s.find_first_of(',') != m_s.npos) {
            double pos = m_s.find_first_of(',');
            m_SourcePath = m_s.substr(0, pos);
            m_s.erase(0, pos + 1);
            m_Src.push_back(m_SourcePath);
        }
    else{
        m_Src.push_back(Src);
    }
	//获取文件后缀
    GetFileSuffix(m_s);
	//设置目标路径
	if (!Dest.empty())
    {
		m_DestDir = Dest;
	}
	else
	{
		//如果目标路径不设置的话, 则会在同级目录创建一个同级文件夹出来
        if(m_SourcePath!=L"")
            m_DestDir = m_SourcePath;
        else
            m_DestDir = Src;
		if (!m_FileSuffix.empty())
		{
			//创建一个同级文件夹路径
			m_DestDir = m_DestDir.substr(0, m_DestDir.find_last_of('.'));
        }

	}

	try {
		bit7z::Bit7zLibrary lib(L"7z.dll");
		std::shared_ptr<bit7z::BitExtractor> extractor = nullptr;
		int i = 0;
		while (i < m_FileSuffix.size()) {
			if (m_FileSuffix[i].compare(TEXT("default")) == 0 || m_FileSuffix[i].compare(TEXT("7z")) == 0)
			{
                //后缀L".7z"
				extractor = std::make_shared<bit7z::BitExtractor>(lib, bit7z::BitFormat::SevenZip);
			}
			else if (m_FileSuffix[i].compare(TEXT("zip")) == 0)
			{
                //后缀L".zip"
				extractor = std::make_shared<bit7z::BitExtractor>(lib, bit7z::BitFormat::Zip);
			}
			else if (m_FileSuffix[i].compare(TEXT("rar")) == 0)
			{
				//后缀L".rar"
				extractor = std::make_shared<bit7z::BitExtractor>(lib, bit7z::BitFormat::Rar5);
			}

			bit7z::TotalCallback TotalCB = std::bind(&SevenZHelper::TotalSizeCB, this, std::placeholders::_1);
			bit7z::ProgressCallback ProCB = std::bind(&SevenZHelper::ProgressCB, this, std::placeholders::_1);
			bit7z::FileCallback FC = std::bind(&SevenZHelper::FileNameCB, this, std::placeholders::_1);	//定义相关回调函数
			extractor->setTotalCallback(TotalCB);
            extractor->setProgressCallback(ProCB);
			extractor->setFileCallback(FC);
			const wstring& m_Pass = Password;
			extractor->setPassword(m_Pass);
            const wstring& m_Dest = this->m_DestDir;
            extractor->extract(m_Src[i++], m_Dest);
		}
	}
	catch (const BitException& ex) {
		cout << ex.what() << endl;
		if (m_pExpFunc)
		{
			m_pExpFunc(ex);
		}
	}
}

void SevenZHelper::SetProgressCB(ProgressCallback upcFunc)
{
	this->m_pProgressFunc = upcFunc;
}

void SevenZHelper::SetBitExceptionCallback(BitExceptionCallback ExceptionFunc)
{
	this->m_pExpFunc = ExceptionFunc;
}

void SevenZHelper::SetFileNameCurOperatorCallback(MyFileCallback ufcFunc)
{
	this->m_pFileFunc = ufcFunc;
}
