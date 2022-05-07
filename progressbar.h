#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <QDialog>
class QLabel;
class QLineEdit;
class QComboBox;
class QProgressBar;
class QPushButton;
class QGridLayout;
#include <QLabel>
#include<QDialog>
#include <QWidget>
#include<QLineEdit>
#include<QComboBox>

#include<QObject>
#include<QPainter>
#include<qtimer.h>
#include<QThread>
#ifdef Plugin
#if (QT_VERSION < QT_VERSION_CHECK(5,7,0))
#include <QtDesigner/QDesignerExportWidget>
#else
#include <QtUiPlugin/QDesignerExportWidget>
#endif

class QDESIGNER_WIDGET_EXPORT ProgressLabel : public QLabel
#else
class progressBar : public QWidget
#endif
{
    Q_OBJECT
public:
    progressBar(QWidget *parent = 0);
    ~progressBar();
    void show();
    void setThread(QThread* t);
    bool isStarted = false;
    QThread* t;
    QProgressBar *progressbar;

    void startProgress();
    void setStart();

public slots:
    void setProgress();

private:
    QLabel *FileNum;
    QLineEdit *FileNumLineEdit;
    QLabel *ProgressType;
    QComboBox *comboBox;
    QPushButton *starBtn;
    QGridLayout *mainLayout;
 };

#endif
