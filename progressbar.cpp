#include "progressbar.h"
#include <QFont>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QProgressBar>
#include <QPushButton>
#include <QGridLayout>
#include <QProgressDialog>

progressBar::progressBar(QWidget *parent)
    : QWidget(parent)
{
    QFont font("KaiTi_GB2312", 12);
    setFont(font);
    setWindowTitle(tr("Progress"));

    FileNum = new QLabel;
    FileNum->setText(tr("File Number: "));
    FileNumLineEdit = new QLineEdit;
    FileNumLineEdit->setText(tr("100000"));

    ProgressType = new QLabel;
    ProgressType->setText(tr("Dispaly Type: "));
    comboBox = new QComboBox;
    comboBox->addItem(tr("progressBar"));
    comboBox->addItem(tr("progressDialog"));

    progressbar = new QProgressBar;

    starBtn = new QPushButton;
    starBtn->setText(tr("Start"));

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(ProgressType, 0, 0);
    mainLayout->addWidget(comboBox, 0, 1);
    mainLayout->addWidget(progressbar, 1, 0, 1, 2);
    mainLayout->addWidget(starBtn, 2, 1);
    mainLayout->setMargin(25);
    mainLayout->setSpacing(20);

    this->setAcceptDrops(true);

    connect(starBtn,&QPushButton::clicked,this,&progressBar::setStart);
    connect(starBtn,&QPushButton::clicked,this,&progressBar::startProgress);
}

progressBar::~progressBar()
{
    if(FileNum) delete FileNum;
    if(FileNumLineEdit) delete FileNumLineEdit;
    if(ProgressType) delete ProgressType;
    if(comboBox) delete comboBox;
    if(progressbar) delete progressbar;
    if(starBtn) delete starBtn;
    if(mainLayout) delete mainLayout;
    if(t) delete t;
}

void progressBar::setStart(){
    isStarted = true;
}

void progressBar::startProgress()
{
    if(isStarted){
    starBtn->setDisabled(true);
    isStarted = true;
    bool ok = false;
    int num = FileNumLineEdit->text().toInt(&ok);

    if (!ok)
        return ;

    if (comboBox->currentIndex() == 0)
    {
        progressbar->setRange(0, 100);
        for (int i = 0; i < num + 1; i+=50)
        {
            progressbar->setValue(i);
        }
    }
    else if (comboBox->currentIndex() == 1)
    {
        QProgressDialog *progressDialog = new QProgressDialog(this);
        QFont font("KaiTi_GB2312", 15);
        progressDialog->setFont(font);
        progressDialog->setWindowModality(Qt::WindowModal);
        progressDialog->setMinimumDuration(5);
        progressDialog->setWindowTitle(tr("Please Wait"));
        progressDialog->setLabelText(tr("Progressing..."));
        progressDialog->setCancelButtonText(tr("Cancel"));
        progressDialog->setRange(0, num);
        for (int i = 0; i < num + 1; ++i)
        {
            progressDialog->setValue(i);
            if (progressDialog->wasCanceled())
            {
                delete progressDialog;
                return ;
            }
        }

        delete progressDialog;
    }
    starBtn->setEnabled(true);
    }
}

void progressBar::setProgress(){
    progressbar->setValue(0);
}

void progressBar::setThread(QThread* t){
    this->t=t;
}
