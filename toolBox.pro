QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    SevenZHelper.cpp \
    codewindow.cpp \
    compressWindow.cpp \
    main.cpp \
    mainwindow.cpp \
    progressbar.cpp \
    sevenztype.cpp \
    src/BarcodeFormat.cpp \
    src/BinaryBitmap.cpp \
    src/BitArray.cpp \
    src/BitMatrix.cpp \
    src/BitMatrixIO.cpp \
    src/BitSource.cpp \
    src/CharacterSetECI.cpp \
    src/ConcentricFinder.cpp \
    src/DecodeHints.cpp \
    src/DecodeStatus.cpp \
    src/GenericGF.cpp \
    src/GenericGFPoly.cpp \
    src/GenericLuminanceSource.cpp \
    src/GlobalHistogramBinarizer.cpp \
    src/GridSampler.cpp \
    src/HybridBinarizer.cpp \
    src/LuminanceSource.cpp \
    src/MultiFormatReader.cpp \
    src/MultiFormatWriter.cpp \
    src/PerspectiveTransform.cpp \
    src/ReadBarcode.cpp \
    src/ReedSolomonDecoder.cpp \
    src/ReedSolomonEncoder.cpp \
    src/Result.cpp \
    src/ResultMetadata.cpp \
    src/ResultPoint.cpp \
    src/TextDecoder.cpp \
    src/TextEncoder.cpp \
    src/TextUtfEncoding.cpp \
    src/WhiteRectDetector.cpp \
    src/ZXBigInteger.cpp \
    src/aztec/AZDecoder.cpp \
    src/aztec/AZDetector.cpp \
    src/aztec/AZEncoder.cpp \
    src/aztec/AZHighLevelEncoder.cpp \
    src/aztec/AZReader.cpp \
    src/aztec/AZToken.cpp \
    src/aztec/AZWriter.cpp \
    src/datamatrix/DMBitMatrixParser.cpp \
    src/datamatrix/DMDataBlock.cpp \
    src/datamatrix/DMDecoder.cpp \
    src/datamatrix/DMDefaultPlacement.cpp \
    src/datamatrix/DMDetector.cpp \
    src/datamatrix/DMECEncoder.cpp \
    src/datamatrix/DMHighLevelEncoder.cpp \
    src/datamatrix/DMReader.cpp \
    src/datamatrix/DMSymbolInfo.cpp \
    src/datamatrix/DMVersion.cpp \
    src/datamatrix/DMWriter.cpp \
    src/maxicode/MCBitMatrixParser.cpp \
    src/maxicode/MCDecoder.cpp \
    src/maxicode/MCReader.cpp \
    src/oned/ODCodabarReader.cpp \
    src/oned/ODCodabarWriter.cpp \
    src/oned/ODCode128Patterns.cpp \
    src/oned/ODCode128Reader.cpp \
    src/oned/ODCode128Writer.cpp \
    src/oned/ODCode39Reader.cpp \
    src/oned/ODCode39Writer.cpp \
    src/oned/ODCode93Reader.cpp \
    src/oned/ODCode93Writer.cpp \
    src/oned/ODEAN13Reader.cpp \
    src/oned/ODEAN13Writer.cpp \
    src/oned/ODEAN8Reader.cpp \
    src/oned/ODEAN8Writer.cpp \
    src/oned/ODEANManufacturerOrgSupport.cpp \
    src/oned/ODITFReader.cpp \
    src/oned/ODITFWriter.cpp \
    src/oned/ODMultiUPCEANReader.cpp \
    src/oned/ODRSS14Reader.cpp \
    src/oned/ODRSSExpandedReader.cpp \
    src/oned/ODReader.cpp \
    src/oned/ODRowReader.cpp \
    src/oned/ODUPCAReader.cpp \
    src/oned/ODUPCAWriter.cpp \
    src/oned/ODUPCEANCommon.cpp \
    src/oned/ODUPCEANExtensionSupport.cpp \
    src/oned/ODUPCEANReader.cpp \
    src/oned/ODUPCEReader.cpp \
    src/oned/ODUPCEWriter.cpp \
    src/oned/ODWriterHelper.cpp \
    src/oned/rss/ODRSSExpandedBinaryDecoder.cpp \
    src/oned/rss/ODRSSFieldParser.cpp \
    src/oned/rss/ODRSSGenericAppIdDecoder.cpp \
    src/oned/rss/ODRSSReaderHelper.cpp \
    src/pdf417/PDFBarcodeValue.cpp \
    src/pdf417/PDFBoundingBox.cpp \
    src/pdf417/PDFCodewordDecoder.cpp \
    src/pdf417/PDFDecodedBitStreamParser.cpp \
    src/pdf417/PDFDetectionResult.cpp \
    src/pdf417/PDFDetectionResultColumn.cpp \
    src/pdf417/PDFDetector.cpp \
    src/pdf417/PDFEncoder.cpp \
    src/pdf417/PDFHighLevelEncoder.cpp \
    src/pdf417/PDFModulusGF.cpp \
    src/pdf417/PDFModulusPoly.cpp \
    src/pdf417/PDFReader.cpp \
    src/pdf417/PDFScanningDecoder.cpp \
    src/pdf417/PDFWriter.cpp \
    src/qrcode/QRBitMatrixParser.cpp \
    src/qrcode/QRCodecMode.cpp \
    src/qrcode/QRDataBlock.cpp \
    src/qrcode/QRDecoder.cpp \
    src/qrcode/QRDetector.cpp \
    src/qrcode/QREncoder.cpp \
    src/qrcode/QRErrorCorrectionLevel.cpp \
    src/qrcode/QRFormatInformation.cpp \
    src/qrcode/QRMaskUtil.cpp \
    src/qrcode/QRMatrixUtil.cpp \
    src/qrcode/QRReader.cpp \
    src/qrcode/QRVersion.cpp \
    src/qrcode/QRWriter.cpp \
    src/textcodec/Big5MapTable.cpp \
    src/textcodec/Big5TextDecoder.cpp \
    src/textcodec/Big5TextEncoder.cpp \
    src/textcodec/GBTextDecoder.cpp \
    src/textcodec/GBTextEncoder.cpp \
    src/textcodec/JPTextDecoder.cpp \
    src/textcodec/JPTextEncoder.cpp \
    src/textcodec/KRHangulMapping.cpp \
    src/textcodec/KRTextDecoder.cpp \
    src/textcodec/KRTextEncoder.cpp \
    toolthread.cpp

HEADERS += \
    SevenZHelper.hpp \
    codewindow.h \
    compressWindow.h \
    include/bit7z.hpp \
    include/bit7zlibrary.hpp \
    include/bitarchivecreator.hpp \
    include/bitarchivehandler.hpp \
    include/bitarchiveinfo.hpp \
    include/bitarchiveitem.hpp \
    include/bitarchiveopener.hpp \
    include/bitcompressionlevel.hpp \
    include/bitcompressionmethod.hpp \
    include/bitcompressor.hpp \
    include/bitexception.hpp \
    include/bitextractor.hpp \
    include/bitformat.hpp \
    include/bitguids.hpp \
    include/bitinputarchive.hpp \
    include/bitmemcompressor.hpp \
    include/bitmemextractor.hpp \
    include/bitpropvariant.hpp \
    include/bitstreamcompressor.hpp \
    include/bitstreamextractor.hpp \
    include/bittypes.hpp \
    include/bufferextractcallback.hpp \
    include/bufferupdatecallback.hpp \
    include/callback.hpp \
    include/cbufoutstream.hpp \
    include/cmultivoloutstream.hpp \
    include/cstdinstream.hpp \
    include/cstdoutstream.hpp \
    include/extractcallback.hpp \
    include/fileextractcallback.hpp \
    include/fileupdatecallback.hpp \
    include/fsindexer.hpp \
    include/fsitem.hpp \
    include/fsutil.hpp \
    include/opencallback.hpp \
    include/streamextractcallback.hpp \
    include/streamupdatecallback.hpp \
    include/updatecallback.hpp \
    mainwindow.h \
    progressbar.h \
    sevenztype.h \
    src/BarcodeFormat.h \
    src/BinaryBitmap.h \
    src/BitArray.h \
    src/BitHacks.h \
    src/BitMatrix.h \
    src/BitMatrixCursor.h \
    src/BitMatrixIO.h \
    src/BitSource.h \
    src/ByteArray.h \
    src/ByteMatrix.h \
    src/CharacterSet.h \
    src/CharacterSetECI.h \
    src/ConcentricFinder.h \
    src/CustomData.h \
    src/DecodeHints.h \
    src/DecodeStatus.h \
    src/DecoderResult.h \
    src/DetectorResult.h \
    src/Flags.h \
    src/GTIN.h \
    src/GenericGF.h \
    src/GenericGFPoly.h \
    src/GenericLuminanceSource.h \
    src/GlobalHistogramBinarizer.h \
    src/GridSampler.h \
    src/HybridBinarizer.h \
    src/LogMatrix.h \
    src/LuminanceSource.h \
    src/Matrix.h \
    src/MultiFormatReader.h \
    src/MultiFormatWriter.h \
    src/Pattern.h \
    src/PerspectiveTransform.h \
    src/Point.h \
    src/Quadrilateral.h \
    src/ReadBarcode.h \
    src/Reader.h \
    src/ReedSolomonDecoder.h \
    src/ReedSolomonEncoder.h \
    src/RegressionLine.h \
    src/Result.h \
    src/ResultMetadata.h \
    src/ResultPoint.h \
    src/Scope.h \
    src/TextDecoder.h \
    src/TextEncoder.h \
    src/TextUtfEncoding.h \
    src/TritMatrix.h \
    src/WhiteRectDetector.h \
    src/ZXBigInteger.h \
    src/ZXConfig.h \
    src/ZXContainerAlgorithms.h \
    src/ZXNullable.h \
    src/ZXStrConvWorkaround.h \
    src/ZXTestSupport.h \
    src/aztec/AZDecoder.h \
    src/aztec/AZDetector.h \
    src/aztec/AZDetectorResult.h \
    src/aztec/AZEncoder.h \
    src/aztec/AZEncodingState.h \
    src/aztec/AZHighLevelEncoder.h \
    src/aztec/AZReader.h \
    src/aztec/AZToken.h \
    src/aztec/AZWriter.h \
    src/datamatrix/DMBitMatrixParser.h \
    src/datamatrix/DMDataBlock.h \
    src/datamatrix/DMDecoder.h \
    src/datamatrix/DMDefaultPlacement.h \
    src/datamatrix/DMDetector.h \
    src/datamatrix/DMECB.h \
    src/datamatrix/DMECEncoder.h \
    src/datamatrix/DMEncoderContext.h \
    src/datamatrix/DMHighLevelEncoder.h \
    src/datamatrix/DMReader.h \
    src/datamatrix/DMSymbolInfo.h \
    src/datamatrix/DMSymbolShape.h \
    src/datamatrix/DMVersion.h \
    src/datamatrix/DMWriter.h \
    src/maxicode/MCBitMatrixParser.h \
    src/maxicode/MCDecoder.h \
    src/maxicode/MCReader.h \
    src/oned/ODCodabarReader.h \
    src/oned/ODCodabarWriter.h \
    src/oned/ODCode128Patterns.h \
    src/oned/ODCode128Reader.h \
    src/oned/ODCode128Writer.h \
    src/oned/ODCode39Reader.h \
    src/oned/ODCode39Writer.h \
    src/oned/ODCode93Reader.h \
    src/oned/ODCode93Writer.h \
    src/oned/ODEAN13Reader.h \
    src/oned/ODEAN13Writer.h \
    src/oned/ODEAN8Reader.h \
    src/oned/ODEAN8Writer.h \
    src/oned/ODEANManufacturerOrgSupport.h \
    src/oned/ODITFReader.h \
    src/oned/ODITFWriter.h \
    src/oned/ODMultiUPCEANReader.h \
    src/oned/ODRSS14Reader.h \
    src/oned/ODRSSExpandedReader.h \
    src/oned/ODReader.h \
    src/oned/ODRowReader.h \
    src/oned/ODUPCAReader.h \
    src/oned/ODUPCAWriter.h \
    src/oned/ODUPCEANCommon.h \
    src/oned/ODUPCEANExtensionSupport.h \
    src/oned/ODUPCEANReader.h \
    src/oned/ODUPCEReader.h \
    src/oned/ODUPCEWriter.h \
    src/oned/ODWriterHelper.h \
    src/oned/rss/ODRSSDataCharacter.h \
    src/oned/rss/ODRSSExpandedBinaryDecoder.h \
    src/oned/rss/ODRSSExpandedPair.h \
    src/oned/rss/ODRSSExpandedRow.h \
    src/oned/rss/ODRSSFieldParser.h \
    src/oned/rss/ODRSSFinderPattern.h \
    src/oned/rss/ODRSSGenericAppIdDecoder.h \
    src/oned/rss/ODRSSPair.h \
    src/oned/rss/ODRSSReaderHelper.h \
    src/pdf417/PDFBarcodeMetadata.h \
    src/pdf417/PDFBarcodeValue.h \
    src/pdf417/PDFBoundingBox.h \
    src/pdf417/PDFCodeword.h \
    src/pdf417/PDFCodewordDecoder.h \
    src/pdf417/PDFCompaction.h \
    src/pdf417/PDFDecodedBitStreamParser.h \
    src/pdf417/PDFDecoderResultExtra.h \
    src/pdf417/PDFDetectionResult.h \
    src/pdf417/PDFDetectionResultColumn.h \
    src/pdf417/PDFDetector.h \
    src/pdf417/PDFEncoder.h \
    src/pdf417/PDFHighLevelEncoder.h \
    src/pdf417/PDFModulusGF.h \
    src/pdf417/PDFModulusPoly.h \
    src/pdf417/PDFReader.h \
    src/pdf417/PDFScanningDecoder.h \
    src/pdf417/PDFWriter.h \
    src/qrcode/QRBitMatrixParser.h \
    src/qrcode/QRCodecMode.h \
    src/qrcode/QRDataBlock.h \
    src/qrcode/QRDataMask.h \
    src/qrcode/QRDecoder.h \
    src/qrcode/QRDecoderMetadata.h \
    src/qrcode/QRDetector.h \
    src/qrcode/QRECB.h \
    src/qrcode/QREncodeResult.h \
    src/qrcode/QREncoder.h \
    src/qrcode/QRErrorCorrectionLevel.h \
    src/qrcode/QRFormatInformation.h \
    src/qrcode/QRMaskUtil.h \
    src/qrcode/QRMatrixUtil.h \
    src/qrcode/QRReader.h \
    src/qrcode/QRVersion.h \
    src/qrcode/QRWriter.h \
    src/stb_image.h \
    src/stb_image_write.h \
    src/textcodec/Big5MapTable.h \
    src/textcodec/Big5TextDecoder.h \
    src/textcodec/Big5TextEncoder.h \
    src/textcodec/GBTextDecoder.h \
    src/textcodec/GBTextEncoder.h \
    src/textcodec/JPTextDecoder.h \
    src/textcodec/JPTextEncoder.h \
    src/textcodec/KRHangulMapping.h \
    src/textcodec/KRTextDecoder.h \
    src/textcodec/KRTextEncoder.h \
    toolthread.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/./ -lbit7z64
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/./ -lbit7z64d

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/./libbit7z64.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/./libbit7z64d.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/./bit7z64.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/./bit7z64d.lib

RESOURCES +=
