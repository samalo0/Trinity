/********************************************************************************
** Form generated from reading UI file 'trinity.ui'
**
** Created: Fri Apr 24 09:29:03 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRINITY_H
#define UI_TRINITY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Trinity
{
public:
    QTabWidget *tabWidget;
    QWidget *tabPerformance;
    QLineEdit *lineEditTimeline;
    QLineEdit *lineEditBigsky;
    QLabel *labelSongName;
    QLineEdit *lineEditMobius;
    QFrame *frameBigsky;
    QFrame *frameTimeline;
    QFrame *frameMobius;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonA;
    QPushButton *pushButtonB;
    QPushButton *pushButtonC;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButtonPrevSong;
    QPushButton *pushButtonDetect;
    QPushButton *pushButtonNextSong;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButtonLoopSw1;
    QPushButton *pushButtonLoopSw2;
    QWidget *tabLooper;
    QLabel *labelLooperStatus;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonLoopRec;
    QPushButton *pushButtonLoopUndo;
    QPushButton *pushButtonLoopStop;
    QFrame *frameTimelinePic;
    QWidget *tabEdit;
    QCheckBox *checkBoxP1Sw1;
    QCheckBox *checkBoxP1Sw2;
    QLineEdit *lineEditP1Bs;
    QLabel *labelSw1;
    QLabel *labelSw2;
    QLabel *labelBs;
    QLabel *labelMo;
    QLineEdit *lineEditP1Mo;
    QLabel *labelTl;
    QLineEdit *lineEditP1Tl;
    QLineEdit *lineEditP2Tl;
    QCheckBox *checkBoxP2Sw2;
    QLineEdit *lineEditP2Mo;
    QCheckBox *checkBoxP2Sw1;
    QLineEdit *lineEditP2Bs;
    QLineEdit *lineEditP3Tl;
    QCheckBox *checkBoxP3Sw2;
    QLineEdit *lineEditP3Mo;
    QCheckBox *checkBoxP3Sw1;
    QLineEdit *lineEditP3Bs;
    QLabel *labelA;
    QLabel *labelB;
    QLabel *labelC;
    QPushButton *pushButtonMoveUp;
    QPushButton *pushButtonMoveDown;
    QPushButton *pushButtonCopy;
    QPushButton *pushButtonPaste;
    QLabel *labelPatchName;
    QLineEdit *lineEditP1Name;
    QLineEdit *lineEditP2Name;
    QLineEdit *lineEditP3Name;
    QLineEdit *lineEditSongName;
    QLabel *label;
    QListWidget *listWidgetSongNames;
    QWidget *tabSetup;
    QLabel *labelMidiInput;
    QComboBox *comboBoxMidiInput;
    QLabel *labelMidiOutput;
    QComboBox *comboBoxMidiOutput;
    QLabel *labelSetupMessage;
    QLabel *labelBigskyMidi;
    QComboBox *comboBoxBigskyMidi;
    QLabel *labelMobiusMidi;
    QComboBox *comboBoxMobiusMidi;
    QComboBox *comboBoxTimelineMidi;
    QLabel *labelTimelineMidi;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonLoad;
    QPushButton *pushButtonPower;

    void setupUi(QWidget *Trinity)
    {
        if (Trinity->objectName().isEmpty())
            Trinity->setObjectName(QString::fromUtf8("Trinity"));
        Trinity->resize(480, 320);
        Trinity->setStyleSheet(QString::fromUtf8("#frameTimelinePic {\n"
"	border-image: url(:/images/timeline.svg);\n"
"}\n"
"\n"
"#Trinity {\n"
"	background-color: black;\n"
"}\n"
"\n"
"#tabPerformance, #tabLooper, #tabEdit, #tabSetup {\n"
"	background-color: black;\n"
"}\n"
"\n"
"#tabEdit QLabel, QCheckbox {\n"
"	color: white;\n"
"}\n"
"\n"
"#tabSetup QLabel {\n"
"	color: white;\n"
"}\n"
"\n"
"#tabLooper QLabel {\n"
"	color:white;\n"
"}\n"
"\n"
"#tabPerformance QLabel {\n"
"	color: red;\n"
"	font: 42pt \"MS Shell Dlg 2\";\n"
"	font-weight: bold;\n"
"}\n"
"\n"
"#frameBigsky, #frameBigSky2 {\n"
"	border-image: url(:/images/bigsky.svg);\n"
"}\n"
"\n"
"#frameTimeline {\n"
"	border-image: url(:/images/timeline.svg);\n"
"}\n"
"\n"
"#frameMobius {\n"
"	border-image: url(:/images/mobius.svg);\n"
"}\n"
"\n"
"QPushButton {\n"
"	border: 0px;\n"
"	color: rgb(150, 150, 150);\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(150, 150, 150, 155), stop:1 rgba(50, 50, 50, 155));\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: "
                        "qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(150, 150, 150, 255), stop:1 rgba(50, 50, 50, 255));\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"	color: rgb(50, 50, 50);\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(150, 150, 150, 100), stop:1 rgba(50, 50, 50, 100));\n"
"}\n"
"\n"
"QPushButton:checked{\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(255, 0, 0, 255), stop:1 rgba(75, 75, 75, 255));\n"
"}\n"
"\n"
"QTabWidget {\n"
"	border: 0px;\n"
"}\n"
"\n"
"QTabBar, QTabBar::tab {\n"
"	background-color: black;\n"
"	color: rgb(100, 100, 100);\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"	color: white;\n"
"	background-color:rgb(50, 50, 50);\n"
"}\n"
""));
        tabWidget = new QTabWidget(Trinity);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 789, 330));
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        tabWidget->setFont(font);
        tabWidget->setUsesScrollButtons(false);
        tabWidget->setMovable(false);
        tabPerformance = new QWidget();
        tabPerformance->setObjectName(QString::fromUtf8("tabPerformance"));
        lineEditTimeline = new QLineEdit(tabPerformance);
        lineEditTimeline->setObjectName(QString::fromUtf8("lineEditTimeline"));
        lineEditTimeline->setEnabled(false);
        lineEditTimeline->setGeometry(QRect(420, 70, 51, 31));
        QFont font1;
        font1.setPointSize(18);
        lineEditTimeline->setFont(font1);
        lineEditBigsky = new QLineEdit(tabPerformance);
        lineEditBigsky->setObjectName(QString::fromUtf8("lineEditBigsky"));
        lineEditBigsky->setEnabled(false);
        lineEditBigsky->setGeometry(QRect(100, 70, 51, 31));
        lineEditBigsky->setFont(font1);
        labelSongName = new QLabel(tabPerformance);
        labelSongName->setObjectName(QString::fromUtf8("labelSongName"));
        labelSongName->setGeometry(QRect(10, 0, 461, 61));
        labelSongName->setAlignment(Qt::AlignCenter);
        lineEditMobius = new QLineEdit(tabPerformance);
        lineEditMobius->setObjectName(QString::fromUtf8("lineEditMobius"));
        lineEditMobius->setEnabled(false);
        lineEditMobius->setGeometry(QRect(260, 70, 51, 31));
        lineEditMobius->setFont(font1);
        lineEditMobius->setReadOnly(false);
        frameBigsky = new QFrame(tabPerformance);
        frameBigsky->setObjectName(QString::fromUtf8("frameBigsky"));
        frameBigsky->setGeometry(QRect(10, 70, 81, 31));
        frameBigsky->setFrameShape(QFrame::StyledPanel);
        frameBigsky->setFrameShadow(QFrame::Raised);
        frameTimeline = new QFrame(tabPerformance);
        frameTimeline->setObjectName(QString::fromUtf8("frameTimeline"));
        frameTimeline->setGeometry(QRect(320, 70, 91, 21));
        frameTimeline->setFrameShape(QFrame::StyledPanel);
        frameTimeline->setFrameShadow(QFrame::Raised);
        frameMobius = new QFrame(tabPerformance);
        frameMobius->setObjectName(QString::fromUtf8("frameMobius"));
        frameMobius->setGeometry(QRect(160, 70, 91, 25));
        frameMobius->setFrameShape(QFrame::StyledPanel);
        frameMobius->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(tabPerformance);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 210, 461, 61));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButtonA = new QPushButton(layoutWidget);
        pushButtonA->setObjectName(QString::fromUtf8("pushButtonA"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonA->sizePolicy().hasHeightForWidth());
        pushButtonA->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font2.setPointSize(20);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        pushButtonA->setFont(font2);
        pushButtonA->setCheckable(true);

        horizontalLayout_3->addWidget(pushButtonA);

        pushButtonB = new QPushButton(layoutWidget);
        pushButtonB->setObjectName(QString::fromUtf8("pushButtonB"));
        sizePolicy.setHeightForWidth(pushButtonB->sizePolicy().hasHeightForWidth());
        pushButtonB->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setPointSize(20);
        pushButtonB->setFont(font3);
        pushButtonB->setCheckable(true);

        horizontalLayout_3->addWidget(pushButtonB);

        pushButtonC = new QPushButton(layoutWidget);
        pushButtonC->setObjectName(QString::fromUtf8("pushButtonC"));
        sizePolicy.setHeightForWidth(pushButtonC->sizePolicy().hasHeightForWidth());
        pushButtonC->setSizePolicy(sizePolicy);
        pushButtonC->setFont(font3);
        pushButtonC->setCheckable(true);

        horizontalLayout_3->addWidget(pushButtonC);

        layoutWidget1 = new QWidget(tabPerformance);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 154, 461, 51));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButtonPrevSong = new QPushButton(layoutWidget1);
        pushButtonPrevSong->setObjectName(QString::fromUtf8("pushButtonPrevSong"));
        sizePolicy.setHeightForWidth(pushButtonPrevSong->sizePolicy().hasHeightForWidth());
        pushButtonPrevSong->setSizePolicy(sizePolicy);
        pushButtonPrevSong->setFont(font3);

        horizontalLayout_4->addWidget(pushButtonPrevSong);

        pushButtonDetect = new QPushButton(layoutWidget1);
        pushButtonDetect->setObjectName(QString::fromUtf8("pushButtonDetect"));
        sizePolicy.setHeightForWidth(pushButtonDetect->sizePolicy().hasHeightForWidth());
        pushButtonDetect->setSizePolicy(sizePolicy);
        pushButtonDetect->setFont(font3);
        pushButtonDetect->setCheckable(true);

        horizontalLayout_4->addWidget(pushButtonDetect);

        pushButtonNextSong = new QPushButton(layoutWidget1);
        pushButtonNextSong->setObjectName(QString::fromUtf8("pushButtonNextSong"));
        sizePolicy.setHeightForWidth(pushButtonNextSong->sizePolicy().hasHeightForWidth());
        pushButtonNextSong->setSizePolicy(sizePolicy);
        pushButtonNextSong->setFont(font3);

        horizontalLayout_4->addWidget(pushButtonNextSong);

        layoutWidget2 = new QWidget(tabPerformance);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(11, 111, 461, 41));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        pushButtonLoopSw1 = new QPushButton(layoutWidget2);
        pushButtonLoopSw1->setObjectName(QString::fromUtf8("pushButtonLoopSw1"));
        sizePolicy.setHeightForWidth(pushButtonLoopSw1->sizePolicy().hasHeightForWidth());
        pushButtonLoopSw1->setSizePolicy(sizePolicy);
        pushButtonLoopSw1->setFont(font2);
        pushButtonLoopSw1->setCheckable(true);

        horizontalLayout_5->addWidget(pushButtonLoopSw1);

        pushButtonLoopSw2 = new QPushButton(layoutWidget2);
        pushButtonLoopSw2->setObjectName(QString::fromUtf8("pushButtonLoopSw2"));
        sizePolicy.setHeightForWidth(pushButtonLoopSw2->sizePolicy().hasHeightForWidth());
        pushButtonLoopSw2->setSizePolicy(sizePolicy);
        pushButtonLoopSw2->setFont(font3);
        pushButtonLoopSw2->setCheckable(true);

        horizontalLayout_5->addWidget(pushButtonLoopSw2);

        tabWidget->addTab(tabPerformance, QString());
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        lineEditTimeline->raise();
        lineEditBigsky->raise();
        labelSongName->raise();
        lineEditMobius->raise();
        frameBigsky->raise();
        frameTimeline->raise();
        frameMobius->raise();
        tabLooper = new QWidget();
        tabLooper->setObjectName(QString::fromUtf8("tabLooper"));
        labelLooperStatus = new QLabel(tabLooper);
        labelLooperStatus->setObjectName(QString::fromUtf8("labelLooperStatus"));
        labelLooperStatus->setGeometry(QRect(10, 150, 461, 41));
        labelLooperStatus->setFont(font1);
        layoutWidget3 = new QWidget(tabLooper);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 198, 461, 71));
        horizontalLayout = new QHBoxLayout(layoutWidget3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonLoopRec = new QPushButton(layoutWidget3);
        pushButtonLoopRec->setObjectName(QString::fromUtf8("pushButtonLoopRec"));
        sizePolicy.setHeightForWidth(pushButtonLoopRec->sizePolicy().hasHeightForWidth());
        pushButtonLoopRec->setSizePolicy(sizePolicy);
        QFont font4;
        font4.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font4.setPointSize(18);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(50);
        pushButtonLoopRec->setFont(font4);
        pushButtonLoopRec->setCheckable(false);

        horizontalLayout->addWidget(pushButtonLoopRec);

        pushButtonLoopUndo = new QPushButton(layoutWidget3);
        pushButtonLoopUndo->setObjectName(QString::fromUtf8("pushButtonLoopUndo"));
        sizePolicy.setHeightForWidth(pushButtonLoopUndo->sizePolicy().hasHeightForWidth());
        pushButtonLoopUndo->setSizePolicy(sizePolicy);
        pushButtonLoopUndo->setFont(font1);
        pushButtonLoopUndo->setCheckable(false);

        horizontalLayout->addWidget(pushButtonLoopUndo);

        pushButtonLoopStop = new QPushButton(layoutWidget3);
        pushButtonLoopStop->setObjectName(QString::fromUtf8("pushButtonLoopStop"));
        sizePolicy.setHeightForWidth(pushButtonLoopStop->sizePolicy().hasHeightForWidth());
        pushButtonLoopStop->setSizePolicy(sizePolicy);
        pushButtonLoopStop->setFont(font1);
        pushButtonLoopStop->setCheckable(false);

        horizontalLayout->addWidget(pushButtonLoopStop);

        frameTimelinePic = new QFrame(tabLooper);
        frameTimelinePic->setObjectName(QString::fromUtf8("frameTimelinePic"));
        frameTimelinePic->setGeometry(QRect(10, 40, 461, 81));
        frameTimelinePic->setFrameShape(QFrame::StyledPanel);
        frameTimelinePic->setFrameShadow(QFrame::Raised);
        tabWidget->addTab(tabLooper, QString());
        tabEdit = new QWidget();
        tabEdit->setObjectName(QString::fromUtf8("tabEdit"));
        checkBoxP1Sw1 = new QCheckBox(tabEdit);
        checkBoxP1Sw1->setObjectName(QString::fromUtf8("checkBoxP1Sw1"));
        checkBoxP1Sw1->setGeometry(QRect(180, 20, 16, 17));
        checkBoxP1Sw2 = new QCheckBox(tabEdit);
        checkBoxP1Sw2->setObjectName(QString::fromUtf8("checkBoxP1Sw2"));
        checkBoxP1Sw2->setGeometry(QRect(230, 20, 21, 17));
        lineEditP1Bs = new QLineEdit(tabEdit);
        lineEditP1Bs->setObjectName(QString::fromUtf8("lineEditP1Bs"));
        lineEditP1Bs->setGeometry(QRect(280, 20, 31, 20));
        QFont font5;
        font5.setPointSize(10);
        lineEditP1Bs->setFont(font5);
        labelSw1 = new QLabel(tabEdit);
        labelSw1->setObjectName(QString::fromUtf8("labelSw1"));
        labelSw1->setGeometry(QRect(180, 0, 31, 16));
        labelSw1->setFont(font5);
        labelSw2 = new QLabel(tabEdit);
        labelSw2->setObjectName(QString::fromUtf8("labelSw2"));
        labelSw2->setGeometry(QRect(230, 0, 41, 16));
        labelSw2->setFont(font5);
        labelBs = new QLabel(tabEdit);
        labelBs->setObjectName(QString::fromUtf8("labelBs"));
        labelBs->setGeometry(QRect(280, 0, 51, 16));
        labelBs->setFont(font5);
        labelMo = new QLabel(tabEdit);
        labelMo->setObjectName(QString::fromUtf8("labelMo"));
        labelMo->setGeometry(QRect(350, 0, 51, 16));
        labelMo->setFont(font5);
        lineEditP1Mo = new QLineEdit(tabEdit);
        lineEditP1Mo->setObjectName(QString::fromUtf8("lineEditP1Mo"));
        lineEditP1Mo->setGeometry(QRect(350, 20, 31, 20));
        lineEditP1Mo->setFont(font5);
        labelTl = new QLabel(tabEdit);
        labelTl->setObjectName(QString::fromUtf8("labelTl"));
        labelTl->setGeometry(QRect(410, 0, 61, 16));
        labelTl->setFont(font5);
        lineEditP1Tl = new QLineEdit(tabEdit);
        lineEditP1Tl->setObjectName(QString::fromUtf8("lineEditP1Tl"));
        lineEditP1Tl->setGeometry(QRect(410, 20, 31, 20));
        lineEditP1Tl->setFont(font5);
        lineEditP2Tl = new QLineEdit(tabEdit);
        lineEditP2Tl->setObjectName(QString::fromUtf8("lineEditP2Tl"));
        lineEditP2Tl->setGeometry(QRect(410, 50, 31, 20));
        lineEditP2Tl->setFont(font5);
        checkBoxP2Sw2 = new QCheckBox(tabEdit);
        checkBoxP2Sw2->setObjectName(QString::fromUtf8("checkBoxP2Sw2"));
        checkBoxP2Sw2->setGeometry(QRect(230, 50, 21, 17));
        lineEditP2Mo = new QLineEdit(tabEdit);
        lineEditP2Mo->setObjectName(QString::fromUtf8("lineEditP2Mo"));
        lineEditP2Mo->setGeometry(QRect(350, 50, 31, 20));
        lineEditP2Mo->setFont(font5);
        checkBoxP2Sw1 = new QCheckBox(tabEdit);
        checkBoxP2Sw1->setObjectName(QString::fromUtf8("checkBoxP2Sw1"));
        checkBoxP2Sw1->setGeometry(QRect(180, 50, 16, 17));
        lineEditP2Bs = new QLineEdit(tabEdit);
        lineEditP2Bs->setObjectName(QString::fromUtf8("lineEditP2Bs"));
        lineEditP2Bs->setGeometry(QRect(280, 50, 31, 20));
        lineEditP2Bs->setFont(font5);
        lineEditP3Tl = new QLineEdit(tabEdit);
        lineEditP3Tl->setObjectName(QString::fromUtf8("lineEditP3Tl"));
        lineEditP3Tl->setGeometry(QRect(410, 80, 31, 20));
        lineEditP3Tl->setFont(font5);
        checkBoxP3Sw2 = new QCheckBox(tabEdit);
        checkBoxP3Sw2->setObjectName(QString::fromUtf8("checkBoxP3Sw2"));
        checkBoxP3Sw2->setGeometry(QRect(230, 80, 21, 17));
        lineEditP3Mo = new QLineEdit(tabEdit);
        lineEditP3Mo->setObjectName(QString::fromUtf8("lineEditP3Mo"));
        lineEditP3Mo->setGeometry(QRect(350, 80, 31, 20));
        lineEditP3Mo->setFont(font5);
        checkBoxP3Sw1 = new QCheckBox(tabEdit);
        checkBoxP3Sw1->setObjectName(QString::fromUtf8("checkBoxP3Sw1"));
        checkBoxP3Sw1->setGeometry(QRect(180, 80, 16, 17));
        lineEditP3Bs = new QLineEdit(tabEdit);
        lineEditP3Bs->setObjectName(QString::fromUtf8("lineEditP3Bs"));
        lineEditP3Bs->setGeometry(QRect(280, 80, 31, 20));
        lineEditP3Bs->setFont(font5);
        labelA = new QLabel(tabEdit);
        labelA->setObjectName(QString::fromUtf8("labelA"));
        labelA->setGeometry(QRect(10, 20, 16, 20));
        labelA->setFont(font5);
        labelB = new QLabel(tabEdit);
        labelB->setObjectName(QString::fromUtf8("labelB"));
        labelB->setGeometry(QRect(10, 50, 16, 16));
        labelB->setFont(font5);
        labelC = new QLabel(tabEdit);
        labelC->setObjectName(QString::fromUtf8("labelC"));
        labelC->setGeometry(QRect(10, 80, 20, 20));
        labelC->setFont(font5);
        pushButtonMoveUp = new QPushButton(tabEdit);
        pushButtonMoveUp->setObjectName(QString::fromUtf8("pushButtonMoveUp"));
        pushButtonMoveUp->setGeometry(QRect(260, 140, 101, 61));
        QFont font6;
        font6.setPointSize(14);
        pushButtonMoveUp->setFont(font6);
        pushButtonMoveDown = new QPushButton(tabEdit);
        pushButtonMoveDown->setObjectName(QString::fromUtf8("pushButtonMoveDown"));
        pushButtonMoveDown->setGeometry(QRect(260, 210, 101, 61));
        pushButtonMoveDown->setFont(font6);
        pushButtonCopy = new QPushButton(tabEdit);
        pushButtonCopy->setObjectName(QString::fromUtf8("pushButtonCopy"));
        pushButtonCopy->setEnabled(true);
        pushButtonCopy->setGeometry(QRect(370, 140, 101, 61));
        pushButtonCopy->setFont(font6);
        pushButtonPaste = new QPushButton(tabEdit);
        pushButtonPaste->setObjectName(QString::fromUtf8("pushButtonPaste"));
        pushButtonPaste->setEnabled(false);
        pushButtonPaste->setGeometry(QRect(370, 210, 101, 61));
        pushButtonPaste->setFont(font6);
        labelPatchName = new QLabel(tabEdit);
        labelPatchName->setObjectName(QString::fromUtf8("labelPatchName"));
        labelPatchName->setGeometry(QRect(30, 0, 91, 16));
        labelPatchName->setFont(font5);
        lineEditP1Name = new QLineEdit(tabEdit);
        lineEditP1Name->setObjectName(QString::fromUtf8("lineEditP1Name"));
        lineEditP1Name->setGeometry(QRect(30, 20, 131, 20));
        lineEditP1Name->setFont(font5);
        lineEditP2Name = new QLineEdit(tabEdit);
        lineEditP2Name->setObjectName(QString::fromUtf8("lineEditP2Name"));
        lineEditP2Name->setGeometry(QRect(30, 50, 131, 20));
        lineEditP2Name->setFont(font5);
        lineEditP3Name = new QLineEdit(tabEdit);
        lineEditP3Name->setObjectName(QString::fromUtf8("lineEditP3Name"));
        lineEditP3Name->setGeometry(QRect(30, 80, 131, 20));
        lineEditP3Name->setFont(font5);
        lineEditSongName = new QLineEdit(tabEdit);
        lineEditSongName->setObjectName(QString::fromUtf8("lineEditSongName"));
        lineEditSongName->setGeometry(QRect(110, 110, 141, 20));
        lineEditSongName->setFont(font5);
        label = new QLabel(tabEdit);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 110, 91, 16));
        label->setFont(font5);
        listWidgetSongNames = new QListWidget(tabEdit);
        listWidgetSongNames->setObjectName(QString::fromUtf8("listWidgetSongNames"));
        listWidgetSongNames->setGeometry(QRect(10, 140, 241, 131));
        QFont font7;
        font7.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font7.setPointSize(10);
        listWidgetSongNames->setFont(font7);
        tabWidget->addTab(tabEdit, QString());
        tabSetup = new QWidget();
        tabSetup->setObjectName(QString::fromUtf8("tabSetup"));
        labelMidiInput = new QLabel(tabSetup);
        labelMidiInput->setObjectName(QString::fromUtf8("labelMidiInput"));
        labelMidiInput->setGeometry(QRect(10, 10, 51, 51));
        labelMidiInput->setFont(font1);
        comboBoxMidiInput = new QComboBox(tabSetup);
        comboBoxMidiInput->setObjectName(QString::fromUtf8("comboBoxMidiInput"));
        comboBoxMidiInput->setGeometry(QRect(70, 10, 401, 51));
        comboBoxMidiInput->setFont(font1);
        labelMidiOutput = new QLabel(tabSetup);
        labelMidiOutput->setObjectName(QString::fromUtf8("labelMidiOutput"));
        labelMidiOutput->setGeometry(QRect(10, 70, 51, 51));
        labelMidiOutput->setFont(font1);
        comboBoxMidiOutput = new QComboBox(tabSetup);
        comboBoxMidiOutput->setObjectName(QString::fromUtf8("comboBoxMidiOutput"));
        comboBoxMidiOutput->setGeometry(QRect(70, 70, 401, 51));
        comboBoxMidiOutput->setFont(font1);
        labelSetupMessage = new QLabel(tabSetup);
        labelSetupMessage->setObjectName(QString::fromUtf8("labelSetupMessage"));
        labelSetupMessage->setGeometry(QRect(10, 170, 461, 31));
        labelSetupMessage->setFont(font1);
        labelBigskyMidi = new QLabel(tabSetup);
        labelBigskyMidi->setObjectName(QString::fromUtf8("labelBigskyMidi"));
        labelBigskyMidi->setGeometry(QRect(10, 130, 71, 31));
        QFont font8;
        font8.setPointSize(16);
        labelBigskyMidi->setFont(font8);
        comboBoxBigskyMidi = new QComboBox(tabSetup);
        comboBoxBigskyMidi->setObjectName(QString::fromUtf8("comboBoxBigskyMidi"));
        comboBoxBigskyMidi->setGeometry(QRect(90, 130, 51, 31));
        comboBoxBigskyMidi->setFont(font1);
        labelMobiusMidi = new QLabel(tabSetup);
        labelMobiusMidi->setObjectName(QString::fromUtf8("labelMobiusMidi"));
        labelMobiusMidi->setGeometry(QRect(150, 130, 91, 31));
        labelMobiusMidi->setFont(font8);
        comboBoxMobiusMidi = new QComboBox(tabSetup);
        comboBoxMobiusMidi->setObjectName(QString::fromUtf8("comboBoxMobiusMidi"));
        comboBoxMobiusMidi->setGeometry(QRect(250, 130, 51, 31));
        comboBoxMobiusMidi->setFont(font1);
        comboBoxTimelineMidi = new QComboBox(tabSetup);
        comboBoxTimelineMidi->setObjectName(QString::fromUtf8("comboBoxTimelineMidi"));
        comboBoxTimelineMidi->setGeometry(QRect(420, 130, 51, 31));
        comboBoxTimelineMidi->setFont(font1);
        labelTimelineMidi = new QLabel(tabSetup);
        labelTimelineMidi->setObjectName(QString::fromUtf8("labelTimelineMidi"));
        labelTimelineMidi->setGeometry(QRect(310, 130, 101, 31));
        labelTimelineMidi->setFont(font8);
        layoutWidget4 = new QWidget(tabSetup);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(11, 210, 461, 61));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButtonSave = new QPushButton(layoutWidget4);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));
        sizePolicy.setHeightForWidth(pushButtonSave->sizePolicy().hasHeightForWidth());
        pushButtonSave->setSizePolicy(sizePolicy);
        pushButtonSave->setFont(font4);
        pushButtonSave->setCheckable(false);

        horizontalLayout_2->addWidget(pushButtonSave);

        pushButtonLoad = new QPushButton(layoutWidget4);
        pushButtonLoad->setObjectName(QString::fromUtf8("pushButtonLoad"));
        sizePolicy.setHeightForWidth(pushButtonLoad->sizePolicy().hasHeightForWidth());
        pushButtonLoad->setSizePolicy(sizePolicy);
        pushButtonLoad->setFont(font1);
        pushButtonLoad->setCheckable(false);

        horizontalLayout_2->addWidget(pushButtonLoad);

        pushButtonPower = new QPushButton(layoutWidget4);
        pushButtonPower->setObjectName(QString::fromUtf8("pushButtonPower"));
        sizePolicy.setHeightForWidth(pushButtonPower->sizePolicy().hasHeightForWidth());
        pushButtonPower->setSizePolicy(sizePolicy);
        pushButtonPower->setFont(font1);
        pushButtonPower->setCheckable(false);

        horizontalLayout_2->addWidget(pushButtonPower);

        tabWidget->addTab(tabSetup, QString());
#ifndef QT_NO_SHORTCUT
        labelPatchName->setBuddy(lineEditP1Name);
        label->setBuddy(lineEditSongName);
        labelMidiInput->setBuddy(comboBoxMidiInput);
        labelMidiOutput->setBuddy(comboBoxMidiOutput);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(tabWidget, pushButtonPrevSong);
        QWidget::setTabOrder(pushButtonPrevSong, pushButtonDetect);
        QWidget::setTabOrder(pushButtonDetect, pushButtonNextSong);
        QWidget::setTabOrder(pushButtonNextSong, pushButtonA);
        QWidget::setTabOrder(pushButtonA, pushButtonB);
        QWidget::setTabOrder(pushButtonB, pushButtonC);
        QWidget::setTabOrder(pushButtonC, lineEditMobius);
        QWidget::setTabOrder(lineEditMobius, lineEditTimeline);
        QWidget::setTabOrder(lineEditTimeline, lineEditBigsky);
        QWidget::setTabOrder(lineEditBigsky, lineEditP1Name);
        QWidget::setTabOrder(lineEditP1Name, checkBoxP1Sw1);
        QWidget::setTabOrder(checkBoxP1Sw1, checkBoxP1Sw2);
        QWidget::setTabOrder(checkBoxP1Sw2, lineEditP1Bs);
        QWidget::setTabOrder(lineEditP1Bs, lineEditP1Mo);
        QWidget::setTabOrder(lineEditP1Mo, lineEditP1Tl);
        QWidget::setTabOrder(lineEditP1Tl, lineEditP2Name);
        QWidget::setTabOrder(lineEditP2Name, checkBoxP2Sw1);
        QWidget::setTabOrder(checkBoxP2Sw1, checkBoxP2Sw2);
        QWidget::setTabOrder(checkBoxP2Sw2, lineEditP2Bs);
        QWidget::setTabOrder(lineEditP2Bs, lineEditP2Mo);
        QWidget::setTabOrder(lineEditP2Mo, lineEditP2Tl);
        QWidget::setTabOrder(lineEditP2Tl, lineEditP3Name);
        QWidget::setTabOrder(lineEditP3Name, checkBoxP3Sw1);
        QWidget::setTabOrder(checkBoxP3Sw1, checkBoxP3Sw2);
        QWidget::setTabOrder(checkBoxP3Sw2, lineEditP3Bs);
        QWidget::setTabOrder(lineEditP3Bs, lineEditP3Mo);
        QWidget::setTabOrder(lineEditP3Mo, lineEditP3Tl);
        QWidget::setTabOrder(lineEditP3Tl, listWidgetSongNames);
        QWidget::setTabOrder(listWidgetSongNames, lineEditSongName);
        QWidget::setTabOrder(lineEditSongName, pushButtonMoveUp);
        QWidget::setTabOrder(pushButtonMoveUp, pushButtonCopy);
        QWidget::setTabOrder(pushButtonCopy, pushButtonMoveDown);
        QWidget::setTabOrder(pushButtonMoveDown, pushButtonPaste);
        QWidget::setTabOrder(pushButtonPaste, comboBoxMidiInput);
        QWidget::setTabOrder(comboBoxMidiInput, comboBoxMidiOutput);
        QWidget::setTabOrder(comboBoxMidiOutput, comboBoxBigskyMidi);
        QWidget::setTabOrder(comboBoxBigskyMidi, comboBoxMobiusMidi);
        QWidget::setTabOrder(comboBoxMobiusMidi, comboBoxTimelineMidi);
        QWidget::setTabOrder(comboBoxTimelineMidi, pushButtonSave);
        QWidget::setTabOrder(pushButtonSave, pushButtonLoad);
        QWidget::setTabOrder(pushButtonLoad, pushButtonLoopRec);
        QWidget::setTabOrder(pushButtonLoopRec, pushButtonLoopUndo);
        QWidget::setTabOrder(pushButtonLoopUndo, pushButtonLoopStop);

        retranslateUi(Trinity);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Trinity);
    } // setupUi

    void retranslateUi(QWidget *Trinity)
    {
        Trinity->setWindowTitle(QApplication::translate("Trinity", "Trinity", 0, QApplication::UnicodeUTF8));
        lineEditTimeline->setText(QApplication::translate("Trinity", "99A", 0, QApplication::UnicodeUTF8));
        lineEditBigsky->setText(QApplication::translate("Trinity", "99A", 0, QApplication::UnicodeUTF8));
        labelSongName->setText(QApplication::translate("Trinity", "1. SONG NAME", 0, QApplication::UnicodeUTF8));
        lineEditMobius->setText(QApplication::translate("Trinity", "99A", 0, QApplication::UnicodeUTF8));
        pushButtonA->setText(QApplication::translate("Trinity", "A\n"
" CLEAN", 0, QApplication::UnicodeUTF8));
        pushButtonB->setText(QApplication::translate("Trinity", "B\n"
" DIST", 0, QApplication::UnicodeUTF8));
        pushButtonC->setText(QApplication::translate("Trinity", "C\n"
" SOLO", 0, QApplication::UnicodeUTF8));
        pushButtonPrevSong->setText(QApplication::translate("Trinity", "<", 0, QApplication::UnicodeUTF8));
        pushButtonDetect->setText(QApplication::translate("Trinity", "DETECT", 0, QApplication::UnicodeUTF8));
        pushButtonNextSong->setText(QApplication::translate("Trinity", ">", 0, QApplication::UnicodeUTF8));
        pushButtonLoopSw1->setText(QApplication::translate("Trinity", "SW1", 0, QApplication::UnicodeUTF8));
        pushButtonLoopSw2->setText(QApplication::translate("Trinity", "SW2", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabPerformance), QApplication::translate("Trinity", "SONG", 0, QApplication::UnicodeUTF8));
        labelLooperStatus->setText(QApplication::translate("Trinity", "Stopped.", 0, QApplication::UnicodeUTF8));
        pushButtonLoopRec->setText(QApplication::translate("Trinity", "A\n"
"REC", 0, QApplication::UnicodeUTF8));
        pushButtonLoopUndo->setText(QApplication::translate("Trinity", "B\n"
"UNDO", 0, QApplication::UnicodeUTF8));
        pushButtonLoopStop->setText(QApplication::translate("Trinity", "C\n"
"STOP", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabLooper), QApplication::translate("Trinity", "LOOP", 0, QApplication::UnicodeUTF8));
        checkBoxP1Sw1->setText(QString());
        checkBoxP1Sw2->setText(QString());
        lineEditP1Bs->setText(QApplication::translate("Trinity", "99A", 0, QApplication::UnicodeUTF8));
        labelSw1->setText(QApplication::translate("Trinity", "SW1", 0, QApplication::UnicodeUTF8));
        labelSw2->setText(QApplication::translate("Trinity", "SW2", 0, QApplication::UnicodeUTF8));
        labelBs->setText(QApplication::translate("Trinity", "BIGSKY", 0, QApplication::UnicodeUTF8));
        labelMo->setText(QApplication::translate("Trinity", "MOBIUS", 0, QApplication::UnicodeUTF8));
        lineEditP1Mo->setText(QApplication::translate("Trinity", "99A", 0, QApplication::UnicodeUTF8));
        labelTl->setText(QApplication::translate("Trinity", "TIMELINE", 0, QApplication::UnicodeUTF8));
        lineEditP1Tl->setText(QApplication::translate("Trinity", "99A", 0, QApplication::UnicodeUTF8));
        lineEditP2Tl->setText(QApplication::translate("Trinity", "99A", 0, QApplication::UnicodeUTF8));
        checkBoxP2Sw2->setText(QString());
        lineEditP2Mo->setText(QApplication::translate("Trinity", "99A", 0, QApplication::UnicodeUTF8));
        checkBoxP2Sw1->setText(QString());
        lineEditP2Bs->setText(QApplication::translate("Trinity", "99A", 0, QApplication::UnicodeUTF8));
        lineEditP3Tl->setText(QApplication::translate("Trinity", "99A", 0, QApplication::UnicodeUTF8));
        checkBoxP3Sw2->setText(QString());
        lineEditP3Mo->setText(QApplication::translate("Trinity", "99A", 0, QApplication::UnicodeUTF8));
        checkBoxP3Sw1->setText(QString());
        lineEditP3Bs->setText(QApplication::translate("Trinity", "99A", 0, QApplication::UnicodeUTF8));
        labelA->setText(QApplication::translate("Trinity", "A", 0, QApplication::UnicodeUTF8));
        labelB->setText(QApplication::translate("Trinity", "B", 0, QApplication::UnicodeUTF8));
        labelC->setText(QApplication::translate("Trinity", "C", 0, QApplication::UnicodeUTF8));
        pushButtonMoveUp->setText(QApplication::translate("Trinity", "MOVE\n"
"UP", 0, QApplication::UnicodeUTF8));
        pushButtonMoveDown->setText(QApplication::translate("Trinity", "MOVE\n"
"DOWN", 0, QApplication::UnicodeUTF8));
        pushButtonCopy->setText(QApplication::translate("Trinity", "COPY", 0, QApplication::UnicodeUTF8));
        pushButtonPaste->setText(QApplication::translate("Trinity", "PASTE", 0, QApplication::UnicodeUTF8));
        labelPatchName->setText(QApplication::translate("Trinity", "PATCH NAME", 0, QApplication::UnicodeUTF8));
        lineEditP1Name->setText(QApplication::translate("Trinity", "123456789", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Trinity", "Song Name", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabEdit), QApplication::translate("Trinity", "EDIT", 0, QApplication::UnicodeUTF8));
        labelMidiInput->setText(QApplication::translate("Trinity", "IN", 0, QApplication::UnicodeUTF8));
        labelMidiOutput->setText(QApplication::translate("Trinity", "OUT", 0, QApplication::UnicodeUTF8));
        labelSetupMessage->setText(QApplication::translate("Trinity", "Message", 0, QApplication::UnicodeUTF8));
        labelBigskyMidi->setText(QApplication::translate("Trinity", "Bigsky", 0, QApplication::UnicodeUTF8));
        labelMobiusMidi->setText(QApplication::translate("Trinity", "Mobius", 0, QApplication::UnicodeUTF8));
        labelTimelineMidi->setText(QApplication::translate("Trinity", "Timeline", 0, QApplication::UnicodeUTF8));
        pushButtonSave->setText(QApplication::translate("Trinity", "A\n"
"SAVE", 0, QApplication::UnicodeUTF8));
        pushButtonLoad->setText(QApplication::translate("Trinity", "B\n"
"LOAD", 0, QApplication::UnicodeUTF8));
        pushButtonPower->setText(QApplication::translate("Trinity", "C\n"
"POWER", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabSetup), QApplication::translate("Trinity", "SETUP", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Trinity: public Ui_Trinity {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRINITY_H
