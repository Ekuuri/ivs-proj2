/********************************************************************************
** Form generated from reading UI file 'calc.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CALC_2D_UI_H
#define CALC_2D_UI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calculator
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *Button1;
    QPushButton *Button0;
    QPushButton *ButtonFactorial;
    QPushButton *Button7;
    QPushButton *ButtonMultiply;
    QPushButton *ButtonDecPoint;
    QPushButton *ButtonDivide;
    QPushButton *ButtonOpBracket;
    QPushButton *ButtonAdd;
    QPushButton *Button8;
    QPushButton *Button5;
    QPushButton *ButtonPower;
    QPushButton *ButtonClBracket;
    QPushButton *ButtonClear;
    QPushButton *Button9;
    QLineEdit *Display;
    QPushButton *ButtonModulo;
    QPushButton *ButtonPlaceHolder;
    QPushButton *ButtonDelete;
    QPushButton *ButtonSqrt;
    QPushButton *Button4;
    QPushButton *Button6;
    QPushButton *Button3;
    QPushButton *ButtonEquals;
    QPushButton *Button2;
    QPushButton *ButtonSubtract;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Calculator)
    {
        if (Calculator->objectName().isEmpty())
            Calculator->setObjectName(QString::fromUtf8("Calculator"));
        Calculator->resize(1734, 1291);
        Calculator->setAutoFillBackground(false);
        Calculator->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #ECEFF4;\n"
"}\n"
"\n"
"/*Display*/\n"
"QLineEdit {\n"
"    background-color: #ECEFF4;\n"
"    color: #2E3440;\n"
"    border: 2px solid #4C566A;\n"
"    border-radius: 5px;\n"
"    font-size: 44pt;\n"
"}\n"
"\n"
"/*Numbers color*/\n"
"QPushButton#Button0, QPushButton#Button1, QPushButton#Button2, QPushButton#Button3,\n"
"QPushButton#Button4, QPushButton#Button5, QPushButton#Button6, QPushButton#Button7,\n"
"QPushButton#Button8, QPushButton#Button9 {\n"
"    background-color: #4F4F4F;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"/*Functions color*/\n"
"QPushButton#ButtonPower, QPushButton#ButtonSqrt, QPushButton#ButtonFactorial, \n"
"QPushButton#ButtonModulo, QPushButton#ButtonPlaceHolder {\n"
"    background-color: #3B3B3B;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"/*Operations color*/\n"
"QPushButton#ButtonAdd, QPushButton#ButtonSubtract, QPushButton#ButtonDivide,\n"
"QPushButton#ButtonMultiply, QPushButton#ButtonOpBracket, QPushB"
                        "utton#ButtonClBracket,\n"
"QPushButton#ButtonDecPoint {\n"
"    background-color: #808080;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"/*Equals color*/\n"
"QPushButton#ButtonEquals {\n"
"    background-color: #00BFFF;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"/*Dlete, Clear color*/\n"
"QPushButton#ButtonDelete, QPushButton#ButtonClear {\n"
"    background-color: #FF4500;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"/*All Buttons*/\n"
"QPushButton {\n"
"    font-size: 28px;\n"
"    padding: 10px;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #5E81AC;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #88C0D0;\n"
"}\n"
"\n"
"/*Numbers hover, press*/\n"
"QPushButton#Button0:hover, QPushButton#Button1:hover, QPushButton#Button2:hover,\n"
"QPushButton#Button3:hover, QPushButton#Button4:hover, QPushButton#Button5:hover,\n"
"QPushButton#Button6:hover, QPushButton#Button7:hover, QPushButton#Button8:hover,\n"
""
                        "QPushButton#Button9:hover {\n"
"    background-color: #6D6D6D;\n"
"}\n"
"\n"
"QPushButton#Button0:pressed, QPushButton#Button1:pressed, QPushButton#Button2:pressed,\n"
"QPushButton#Button3:pressed, QPushButton#Button4:pressed, QPushButton#Button5:pressed,\n"
"QPushButton#Button6:pressed, QPushButton#Button7:pressed, QPushButton#Button8:pressed,\n"
"QPushButton#Button9:pressed {\n"
"    background-color: #888888;\n"
"}\n"
"\n"
"/*Funcions hover, press*/\n"
"QPushButton#ButtonPower:hover, QPushButton#ButtonSqrt:hover, QPushButton#ButtonFactorial:hover,\n"
"QPushButton#ButtonModulo:hover, QPushButton#ButtonPlaceHolder:hover {\n"
"    background-color: #555555; \n"
"}\n"
"\n"
"QPushButton#ButtonPower:pressed, QPushButton#ButtonSqrt:pressed, QPushButton#ButtonFactorial:pressed,\n"
"QPushButton#ButtonModulo:pressed, QPushButton#ButtonPlaceHolder:pressed {\n"
"    background-color: #777777;\n"
"}\n"
"\n"
"/*Operations hover, press*/\n"
"QPushButton#ButtonAdd:hover, QPushButton#ButtonSubtract:hover, QPushButton#Button"
                        "Divide:hover,\n"
"QPushButton#ButtonMultiply:hover, QPushButton#ButtonOpBracket:hover, QPushButton#ButtonClBracket:hover,\n"
"QPushButton#ButtonDecPoint:hover {\n"
"    background-color: #9E9E9E;\n"
"}\n"
"\n"
"QPushButton#ButtonAdd:pressed, QPushButton#ButtonSubtract:pressed, QPushButton#ButtonDivide:pressed,\n"
"QPushButton#ButtonMultiply:pressed, QPushButton#ButtonOpBracket:pressed, QPushButton#ButtonClBracket:pressed,\n"
"QPushButton#ButtonDecPoint:pressed {\n"
"    background-color: #B0B0B0;\n"
"}\n"
"\n"
"/*Equals hover, press*/\n"
"QPushButton#ButtonEquals:hover {\n"
"    background-color: #33A1D9;\n"
"}\n"
"\n"
"QPushButton#ButtonEquals:pressed {\n"
"    background-color: #00BFFF;\n"
"}\n"
"\n"
"/*Delete, Clear hover, press*/\n"
"QPushButton#ButtonDelete:hover, QPushButton#ButtonClear:hover {\n"
"    background-color: #FF6347;\n"
"}\n"
"\n"
"QPushButton#ButtonDelete:pressed, QPushButton#ButtonClear:pressed {\n"
"    background-color: #FF4500;\n"
"}"));
        Calculator->setTabShape(QTabWidget::Rounded);
        centralwidget = new QWidget(Calculator);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 240, 551, 641));
        layoutWidget->setAutoFillBackground(false);
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Button1 = new QPushButton(layoutWidget);
        Button1->setObjectName(QString::fromUtf8("Button1"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Button1->sizePolicy().hasHeightForWidth());
        Button1->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Sans Serif"));
        Button1->setFont(font);
        Button1->setAutoFillBackground(false);

        gridLayout->addWidget(Button1, 4, 0, 1, 1);

        Button0 = new QPushButton(layoutWidget);
        Button0->setObjectName(QString::fromUtf8("Button0"));
        sizePolicy.setHeightForWidth(Button0->sizePolicy().hasHeightForWidth());
        Button0->setSizePolicy(sizePolicy);
        Button0->setFont(font);
        Button0->setAutoFillBackground(false);

        gridLayout->addWidget(Button0, 5, 0, 1, 1);

        ButtonFactorial = new QPushButton(layoutWidget);
        ButtonFactorial->setObjectName(QString::fromUtf8("ButtonFactorial"));
        sizePolicy.setHeightForWidth(ButtonFactorial->sizePolicy().hasHeightForWidth());
        ButtonFactorial->setSizePolicy(sizePolicy);
        ButtonFactorial->setFont(font);
        ButtonFactorial->setAutoFillBackground(false);

        gridLayout->addWidget(ButtonFactorial, 1, 2, 1, 1);

        Button7 = new QPushButton(layoutWidget);
        Button7->setObjectName(QString::fromUtf8("Button7"));
        sizePolicy.setHeightForWidth(Button7->sizePolicy().hasHeightForWidth());
        Button7->setSizePolicy(sizePolicy);
        Button7->setFont(font);
        Button7->setAutoFillBackground(false);

        gridLayout->addWidget(Button7, 2, 0, 1, 1);

        ButtonMultiply = new QPushButton(layoutWidget);
        ButtonMultiply->setObjectName(QString::fromUtf8("ButtonMultiply"));
        sizePolicy.setHeightForWidth(ButtonMultiply->sizePolicy().hasHeightForWidth());
        ButtonMultiply->setSizePolicy(sizePolicy);
        ButtonMultiply->setFont(font);
        ButtonMultiply->setAutoFillBackground(false);

        gridLayout->addWidget(ButtonMultiply, 3, 3, 1, 1);

        ButtonDecPoint = new QPushButton(layoutWidget);
        ButtonDecPoint->setObjectName(QString::fromUtf8("ButtonDecPoint"));
        sizePolicy.setHeightForWidth(ButtonDecPoint->sizePolicy().hasHeightForWidth());
        ButtonDecPoint->setSizePolicy(sizePolicy);
        ButtonDecPoint->setFont(font);
        ButtonDecPoint->setAutoFillBackground(false);

        gridLayout->addWidget(ButtonDecPoint, 5, 1, 1, 1);

        ButtonDivide = new QPushButton(layoutWidget);
        ButtonDivide->setObjectName(QString::fromUtf8("ButtonDivide"));
        sizePolicy.setHeightForWidth(ButtonDivide->sizePolicy().hasHeightForWidth());
        ButtonDivide->setSizePolicy(sizePolicy);
        ButtonDivide->setFont(font);
        ButtonDivide->setAutoFillBackground(false);

        gridLayout->addWidget(ButtonDivide, 3, 4, 1, 1);

        ButtonOpBracket = new QPushButton(layoutWidget);
        ButtonOpBracket->setObjectName(QString::fromUtf8("ButtonOpBracket"));
        sizePolicy.setHeightForWidth(ButtonOpBracket->sizePolicy().hasHeightForWidth());
        ButtonOpBracket->setSizePolicy(sizePolicy);
        ButtonOpBracket->setFont(font);
        ButtonOpBracket->setAutoFillBackground(false);

        gridLayout->addWidget(ButtonOpBracket, 5, 2, 1, 1);

        ButtonAdd = new QPushButton(layoutWidget);
        ButtonAdd->setObjectName(QString::fromUtf8("ButtonAdd"));
        sizePolicy.setHeightForWidth(ButtonAdd->sizePolicy().hasHeightForWidth());
        ButtonAdd->setSizePolicy(sizePolicy);
        ButtonAdd->setFont(font);
        ButtonAdd->setAutoFillBackground(false);

        gridLayout->addWidget(ButtonAdd, 4, 3, 1, 1);

        Button8 = new QPushButton(layoutWidget);
        Button8->setObjectName(QString::fromUtf8("Button8"));
        sizePolicy.setHeightForWidth(Button8->sizePolicy().hasHeightForWidth());
        Button8->setSizePolicy(sizePolicy);
        Button8->setFont(font);
        Button8->setAutoFillBackground(false);

        gridLayout->addWidget(Button8, 2, 1, 1, 1);

        Button5 = new QPushButton(layoutWidget);
        Button5->setObjectName(QString::fromUtf8("Button5"));
        sizePolicy.setHeightForWidth(Button5->sizePolicy().hasHeightForWidth());
        Button5->setSizePolicy(sizePolicy);
        Button5->setFont(font);
        Button5->setAutoFillBackground(false);

        gridLayout->addWidget(Button5, 3, 1, 1, 1);

        ButtonPower = new QPushButton(layoutWidget);
        ButtonPower->setObjectName(QString::fromUtf8("ButtonPower"));
        sizePolicy.setHeightForWidth(ButtonPower->sizePolicy().hasHeightForWidth());
        ButtonPower->setSizePolicy(sizePolicy);
        ButtonPower->setFont(font);
        ButtonPower->setAutoFillBackground(false);

        gridLayout->addWidget(ButtonPower, 1, 0, 1, 1);

        ButtonClBracket = new QPushButton(layoutWidget);
        ButtonClBracket->setObjectName(QString::fromUtf8("ButtonClBracket"));
        sizePolicy.setHeightForWidth(ButtonClBracket->sizePolicy().hasHeightForWidth());
        ButtonClBracket->setSizePolicy(sizePolicy);
        ButtonClBracket->setFont(font);
        ButtonClBracket->setAutoFillBackground(false);

        gridLayout->addWidget(ButtonClBracket, 5, 3, 1, 1);

        ButtonClear = new QPushButton(layoutWidget);
        ButtonClear->setObjectName(QString::fromUtf8("ButtonClear"));
        sizePolicy.setHeightForWidth(ButtonClear->sizePolicy().hasHeightForWidth());
        ButtonClear->setSizePolicy(sizePolicy);
        ButtonClear->setFont(font);
        ButtonClear->setAutoFillBackground(false);

        gridLayout->addWidget(ButtonClear, 2, 4, 1, 1);

        Button9 = new QPushButton(layoutWidget);
        Button9->setObjectName(QString::fromUtf8("Button9"));
        sizePolicy.setHeightForWidth(Button9->sizePolicy().hasHeightForWidth());
        Button9->setSizePolicy(sizePolicy);
        Button9->setFont(font);
        Button9->setAutoFillBackground(false);

        gridLayout->addWidget(Button9, 2, 2, 1, 1);

        Display = new QLineEdit(layoutWidget);
        Display->setObjectName(QString::fromUtf8("Display"));
        sizePolicy.setHeightForWidth(Display->sizePolicy().hasHeightForWidth());
        Display->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Sans Serif"));
        font1.setPointSize(44);
        font1.setItalic(false);
        Display->setFont(font1);
        Display->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Display->setReadOnly(false);

        gridLayout->addWidget(Display, 0, 0, 1, 5);

        ButtonModulo = new QPushButton(layoutWidget);
        ButtonModulo->setObjectName(QString::fromUtf8("ButtonModulo"));
        sizePolicy.setHeightForWidth(ButtonModulo->sizePolicy().hasHeightForWidth());
        ButtonModulo->setSizePolicy(sizePolicy);
        ButtonModulo->setFont(font);
        ButtonModulo->setAutoFillBackground(false);

        gridLayout->addWidget(ButtonModulo, 1, 3, 1, 1);

        ButtonPlaceHolder = new QPushButton(layoutWidget);
        ButtonPlaceHolder->setObjectName(QString::fromUtf8("ButtonPlaceHolder"));
        ButtonPlaceHolder->setEnabled(false);
        sizePolicy.setHeightForWidth(ButtonPlaceHolder->sizePolicy().hasHeightForWidth());
        ButtonPlaceHolder->setSizePolicy(sizePolicy);
        ButtonPlaceHolder->setAutoFillBackground(false);
        ButtonPlaceHolder->setStyleSheet(QString::fromUtf8("#buttonPlaceholder {\n"
"    background-color: #3B4252; \n"
"    border: none;\n"
"}"));

        gridLayout->addWidget(ButtonPlaceHolder, 1, 4, 1, 1);

        ButtonDelete = new QPushButton(layoutWidget);
        ButtonDelete->setObjectName(QString::fromUtf8("ButtonDelete"));
        sizePolicy.setHeightForWidth(ButtonDelete->sizePolicy().hasHeightForWidth());
        ButtonDelete->setSizePolicy(sizePolicy);
        ButtonDelete->setFont(font);
        ButtonDelete->setAutoFillBackground(false);

        gridLayout->addWidget(ButtonDelete, 2, 3, 1, 1);

        ButtonSqrt = new QPushButton(layoutWidget);
        ButtonSqrt->setObjectName(QString::fromUtf8("ButtonSqrt"));
        sizePolicy.setHeightForWidth(ButtonSqrt->sizePolicy().hasHeightForWidth());
        ButtonSqrt->setSizePolicy(sizePolicy);
        ButtonSqrt->setFont(font);
        ButtonSqrt->setAutoFillBackground(false);

        gridLayout->addWidget(ButtonSqrt, 1, 1, 1, 1);

        Button4 = new QPushButton(layoutWidget);
        Button4->setObjectName(QString::fromUtf8("Button4"));
        sizePolicy.setHeightForWidth(Button4->sizePolicy().hasHeightForWidth());
        Button4->setSizePolicy(sizePolicy);
        Button4->setFont(font);
        Button4->setAutoFillBackground(false);

        gridLayout->addWidget(Button4, 3, 0, 1, 1);

        Button6 = new QPushButton(layoutWidget);
        Button6->setObjectName(QString::fromUtf8("Button6"));
        sizePolicy.setHeightForWidth(Button6->sizePolicy().hasHeightForWidth());
        Button6->setSizePolicy(sizePolicy);
        Button6->setFont(font);
        Button6->setAutoFillBackground(false);

        gridLayout->addWidget(Button6, 3, 2, 1, 1);

        Button3 = new QPushButton(layoutWidget);
        Button3->setObjectName(QString::fromUtf8("Button3"));
        sizePolicy.setHeightForWidth(Button3->sizePolicy().hasHeightForWidth());
        Button3->setSizePolicy(sizePolicy);
        Button3->setFont(font);
        Button3->setAutoFillBackground(false);

        gridLayout->addWidget(Button3, 4, 2, 1, 1);

        ButtonEquals = new QPushButton(layoutWidget);
        ButtonEquals->setObjectName(QString::fromUtf8("ButtonEquals"));
        sizePolicy.setHeightForWidth(ButtonEquals->sizePolicy().hasHeightForWidth());
        ButtonEquals->setSizePolicy(sizePolicy);
        ButtonEquals->setFont(font);
        ButtonEquals->setAutoFillBackground(false);

        gridLayout->addWidget(ButtonEquals, 5, 4, 1, 1);

        Button2 = new QPushButton(layoutWidget);
        Button2->setObjectName(QString::fromUtf8("Button2"));
        sizePolicy.setHeightForWidth(Button2->sizePolicy().hasHeightForWidth());
        Button2->setSizePolicy(sizePolicy);
        Button2->setFont(font);
        Button2->setAutoFillBackground(false);

        gridLayout->addWidget(Button2, 4, 1, 1, 1);

        ButtonSubtract = new QPushButton(layoutWidget);
        ButtonSubtract->setObjectName(QString::fromUtf8("ButtonSubtract"));
        sizePolicy.setHeightForWidth(ButtonSubtract->sizePolicy().hasHeightForWidth());
        ButtonSubtract->setSizePolicy(sizePolicy);
        ButtonSubtract->setFont(font);
        ButtonSubtract->setAutoFillBackground(false);

        gridLayout->addWidget(ButtonSubtract, 4, 4, 1, 1);

        gridLayout->setRowStretch(0, 2);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setRowStretch(3, 1);
        gridLayout->setRowStretch(4, 1);
        gridLayout->setRowStretch(5, 1);
        Calculator->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Calculator);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1734, 20));
        Calculator->setMenuBar(menubar);
        statusbar = new QStatusBar(Calculator);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Calculator->setStatusBar(statusbar);

        retranslateUi(Calculator);

        QMetaObject::connectSlotsByName(Calculator);
    } // setupUi

    void retranslateUi(QMainWindow *Calculator)
    {
        Calculator->setWindowTitle(QCoreApplication::translate("Calculator", "MainWindow", nullptr));
        Button1->setText(QCoreApplication::translate("Calculator", "1", nullptr));
#if QT_CONFIG(shortcut)
        Button1->setShortcut(QCoreApplication::translate("Calculator", "1", nullptr));
#endif // QT_CONFIG(shortcut)
        Button0->setText(QCoreApplication::translate("Calculator", "0", nullptr));
        ButtonFactorial->setText(QCoreApplication::translate("Calculator", "n!", nullptr));
#if QT_CONFIG(shortcut)
        ButtonFactorial->setShortcut(QCoreApplication::translate("Calculator", "!", nullptr));
#endif // QT_CONFIG(shortcut)
        Button7->setText(QCoreApplication::translate("Calculator", "7", nullptr));
#if QT_CONFIG(shortcut)
        Button7->setShortcut(QCoreApplication::translate("Calculator", "7", nullptr));
#endif // QT_CONFIG(shortcut)
        ButtonMultiply->setText(QCoreApplication::translate("Calculator", "\303\227", nullptr));
#if QT_CONFIG(shortcut)
        ButtonMultiply->setShortcut(QCoreApplication::translate("Calculator", "*", nullptr));
#endif // QT_CONFIG(shortcut)
        ButtonDecPoint->setText(QCoreApplication::translate("Calculator", ",", nullptr));
#if QT_CONFIG(shortcut)
        ButtonDecPoint->setShortcut(QCoreApplication::translate("Calculator", ".", nullptr));
#endif // QT_CONFIG(shortcut)
        ButtonDivide->setText(QCoreApplication::translate("Calculator", "\303\267", nullptr));
#if QT_CONFIG(shortcut)
        ButtonDivide->setShortcut(QCoreApplication::translate("Calculator", "/", nullptr));
#endif // QT_CONFIG(shortcut)
        ButtonOpBracket->setText(QCoreApplication::translate("Calculator", "(", nullptr));
#if QT_CONFIG(shortcut)
        ButtonOpBracket->setShortcut(QCoreApplication::translate("Calculator", "(", nullptr));
#endif // QT_CONFIG(shortcut)
        ButtonAdd->setText(QCoreApplication::translate("Calculator", "+", nullptr));
#if QT_CONFIG(shortcut)
        ButtonAdd->setShortcut(QCoreApplication::translate("Calculator", "+", nullptr));
#endif // QT_CONFIG(shortcut)
        Button8->setText(QCoreApplication::translate("Calculator", "8", nullptr));
#if QT_CONFIG(shortcut)
        Button8->setShortcut(QCoreApplication::translate("Calculator", "8", nullptr));
#endif // QT_CONFIG(shortcut)
        Button5->setText(QCoreApplication::translate("Calculator", "5", nullptr));
#if QT_CONFIG(shortcut)
        Button5->setShortcut(QCoreApplication::translate("Calculator", "5", nullptr));
#endif // QT_CONFIG(shortcut)
        ButtonPower->setText(QCoreApplication::translate("Calculator", "x\302\262", nullptr));
#if QT_CONFIG(shortcut)
        ButtonPower->setShortcut(QCoreApplication::translate("Calculator", "^", nullptr));
#endif // QT_CONFIG(shortcut)
        ButtonClBracket->setText(QCoreApplication::translate("Calculator", ")", nullptr));
#if QT_CONFIG(shortcut)
        ButtonClBracket->setShortcut(QCoreApplication::translate("Calculator", ")", nullptr));
#endif // QT_CONFIG(shortcut)
        ButtonClear->setText(QCoreApplication::translate("Calculator", "C", nullptr));
#if QT_CONFIG(shortcut)
        ButtonClear->setShortcut(QCoreApplication::translate("Calculator", "Esc, Del", nullptr));
#endif // QT_CONFIG(shortcut)
        Button9->setText(QCoreApplication::translate("Calculator", "9", nullptr));
#if QT_CONFIG(shortcut)
        Button9->setShortcut(QCoreApplication::translate("Calculator", "9", nullptr));
#endif // QT_CONFIG(shortcut)
        Display->setText(QString());
        ButtonModulo->setText(QCoreApplication::translate("Calculator", "%", nullptr));
#if QT_CONFIG(shortcut)
        ButtonModulo->setShortcut(QCoreApplication::translate("Calculator", "%", nullptr));
#endif // QT_CONFIG(shortcut)
        ButtonPlaceHolder->setText(QString());
        ButtonDelete->setText(QCoreApplication::translate("Calculator", "\342\214\253", nullptr));
#if QT_CONFIG(shortcut)
        ButtonDelete->setShortcut(QCoreApplication::translate("Calculator", "Backspace", nullptr));
#endif // QT_CONFIG(shortcut)
        ButtonSqrt->setText(QCoreApplication::translate("Calculator", "\342\210\232", nullptr));
        Button4->setText(QCoreApplication::translate("Calculator", "4", nullptr));
#if QT_CONFIG(shortcut)
        Button4->setShortcut(QCoreApplication::translate("Calculator", "4", nullptr));
#endif // QT_CONFIG(shortcut)
        Button6->setText(QCoreApplication::translate("Calculator", "6", nullptr));
#if QT_CONFIG(shortcut)
        Button6->setShortcut(QCoreApplication::translate("Calculator", "6", nullptr));
#endif // QT_CONFIG(shortcut)
        Button3->setText(QCoreApplication::translate("Calculator", "3", nullptr));
#if QT_CONFIG(shortcut)
        Button3->setShortcut(QCoreApplication::translate("Calculator", "3", nullptr));
#endif // QT_CONFIG(shortcut)
        ButtonEquals->setText(QCoreApplication::translate("Calculator", "=", nullptr));
#if QT_CONFIG(shortcut)
        ButtonEquals->setShortcut(QCoreApplication::translate("Calculator", "Enter", nullptr));
#endif // QT_CONFIG(shortcut)
        Button2->setText(QCoreApplication::translate("Calculator", "2", nullptr));
#if QT_CONFIG(shortcut)
        Button2->setShortcut(QCoreApplication::translate("Calculator", "2", nullptr));
#endif // QT_CONFIG(shortcut)
        ButtonSubtract->setText(QCoreApplication::translate("Calculator", "-", nullptr));
#if QT_CONFIG(shortcut)
        ButtonSubtract->setShortcut(QCoreApplication::translate("Calculator", "-", nullptr));
#endif // QT_CONFIG(shortcut)
    } // retranslateUi

};

namespace Ui {
    class Calculator: public Ui_Calculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CALC_2D_UI_H
