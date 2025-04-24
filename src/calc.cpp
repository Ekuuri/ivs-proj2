/******************************************************************
 * Project name: IVS 2 project
 * Date: 26.3.2025
 * Last change: 23.4.2025
 * Team: audentes Fortuna iuvat
 * Author: Dan Šrajer
 * Brief: Implementation of UI interactions
 *****************************************************************/
/**
* @file calc.cpp
*
* @brief Implementation of UI interactions
* @author Dan Šrajer
* @todo look into the regular expression (QRegularExpression) in onClearClicked likely remake from scratch
* @todo highlight cursor location
* @bug theres no cursor when display is disabled
* @bug calculator window extends more than needed
*/

#include "calc.h"
#include "parser.h"
#include <iostream>

// Constructor
Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Calculator) {
    // Setup the user interface from the .ui file.
    ui->setupUi(this);
    this->setWindowTitle("Calculator");

    this->setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);

    // Connect number buttons to corresponding slots.
    connect(ui->Button0, &QPushButton::clicked, this, &Calculator::onNumberClicked);
    connect(ui->Button1, &QPushButton::clicked, this, &Calculator::onNumberClicked);
    connect(ui->Button2, &QPushButton::clicked, this, &Calculator::onNumberClicked);
    connect(ui->Button3, &QPushButton::clicked, this, &Calculator::onNumberClicked);
    connect(ui->Button4, &QPushButton::clicked, this, &Calculator::onNumberClicked);
    connect(ui->Button5, &QPushButton::clicked, this, &Calculator::onNumberClicked);
    connect(ui->Button6, &QPushButton::clicked, this, &Calculator::onNumberClicked);
    connect(ui->Button7, &QPushButton::clicked, this, &Calculator::onNumberClicked);
    connect(ui->Button8, &QPushButton::clicked, this, &Calculator::onNumberClicked);
    connect(ui->Button9, &QPushButton::clicked, this, &Calculator::onNumberClicked);

    // Connect operation buttons to corresponding slots.
    connect(ui->ButtonAdd, &QPushButton::clicked, this, &Calculator::onAddClicked);
    connect(ui->ButtonSubtract, &QPushButton::clicked, this, &Calculator::onSubtractClicked);
    connect(ui->ButtonMultiply, &QPushButton::clicked, this, &Calculator::onMultiplyClicked);
    connect(ui->ButtonDivide, &QPushButton::clicked, this, &Calculator::onDivideClicked);
    connect(ui->ButtonPower, &QPushButton::clicked, this, &Calculator::onPowerClicked);
    connect(ui->ButtonSqrt, &QPushButton::clicked, this, &Calculator::onSqrtClicked);
    connect(ui->ButtonFactorial, &QPushButton::clicked, this, &Calculator::onFactorialClicked);
    connect(ui->ButtonModulo, &QPushButton::clicked, this, &Calculator::onModuloClicked);
    connect(ui->ButtonAbsoluteVal, &QPushButton::clicked, this, &Calculator::onAbsoluteValClicked);
        
    // Connect additional buttons to corresponding slots.
    connect(ui->ButtonDecPoint, &QPushButton::clicked, this, &Calculator::onDecimalPointClicked);
    connect(ui->ButtonOpBracket, &QPushButton::clicked, this, &Calculator::onOpBracketClicked);
    connect(ui->ButtonClBracket, &QPushButton::clicked, this, &Calculator::onClBracketClicked);
    connect(ui->ButtonEquals, &QPushButton::clicked, this, &Calculator::onEqualsClicked);
    connect(ui->ButtonPlaceHolder, &QPushButton::clicked, this, &Calculator::onPlaceHolderClicked);
    connect(ui->ButtonDelete, &QPushButton::clicked, this, &Calculator::onDeleteClicked);
    connect(ui->ButtonClear, &QPushButton::clicked, this, &Calculator::onClearClicked);
    connect(ui->ButtonLeftArr, &QPushButton::clicked, this, &Calculator::onLeftArrClicked);
    connect(ui->ButtonRightArr, &QPushButton::clicked, this, &Calculator::onRightArrClicked);

    //Connect input change event to update clear button.
    connect(ui->Display, &QLineEdit::textChanged, this, &Calculator::onInputChanged);

    updateVisualCursor();
}

// Destructor
Calculator::~Calculator() {
    delete ui;
}

// Slots
void Calculator::onNumberClicked() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
        cursor_id++;
        QString currentText = ui->Display->text().insert(cursor_id, button->text());
        ui->Display->setText(currentText);
    }
}

void Calculator::onAddClicked() {
    cursor_id++;
    QString currentText = ui->Display->text().insert(cursor_id, "+");
    ui->Display->setText(currentText);
}

void Calculator::onSubtractClicked() {
    cursor_id++;
    QString currentText = ui->Display->text().insert(cursor_id, "-");
    ui->Display->setText(currentText);
}

void Calculator::onMultiplyClicked() {
    cursor_id++;
    QString currentText = ui->Display->text().insert(cursor_id, "*");
    ui->Display->setText(currentText);
}

void Calculator::onDivideClicked() {
    cursor_id++;
    QString currentText = ui->Display->text().insert(cursor_id, "/");
    ui->Display->setText(currentText);
}

void Calculator::onPowerClicked() {
    cursor_id++;
    QString currentText = ui->Display->text().insert(cursor_id, "^");
    ui->Display->setText(currentText);
}

void Calculator::onSqrtClicked() {
    cursor_id++;
    QString currentText = ui->Display->text().insert(cursor_id, QChar(0x221A));
    ui->Display->setText(currentText);
}

void Calculator::onFactorialClicked() {
    cursor_id++;
    QString currentText = ui->Display->text().insert(cursor_id, "!");
    ui->Display->setText(currentText);
}

void Calculator::onModuloClicked() {
    cursor_id++;
    QString currentText = ui->Display->text().insert(cursor_id, "%");
    ui->Display->setText(currentText);
}

void Calculator::onAbsoluteValClicked() {
    cursor_id++;
    QString currentText = ui->Display->text().insert(cursor_id, "|");
    ui->Display->setText(currentText);
}

void Calculator::onDecimalPointClicked() {
    cursor_id++;
    QString currentText = ui->Display->text().insert(cursor_id, ".");
    ui->Display->setText(currentText);
}

void Calculator::onOpBracketClicked() {
    cursor_id++;
    QString currentText = ui->Display->text().insert(cursor_id, "(");
    ui->Display->setText(currentText);
}

void Calculator::onClBracketClicked() {
    cursor_id++;
    QString currentText = ui->Display->text().insert(cursor_id, ")");
    ui->Display->setText(currentText);
}

void Calculator::onLeftArrClicked() {
    if (cursor_id > 0) {
       cursor_id--;
    }
    updateVisualCursor();
}

void Calculator::onRightArrClicked() {
    if (cursor_id < ui->Display->text().length()) {
        cursor_id++;
    }
    updateVisualCursor();
}

void Calculator::onEqualsClicked() {
    QString expression = ui->Display->text();
    expression.replace("|", ""); // Remove any existing cursor symbol
    ui->Display->setText(parse(expression));
    cursor_id = ui->Display->text().length(); // Move cursor to the end after evaluation
}

void Calculator::onPlaceHolderClicked() {
    // Placeholder button does nothing.
}

void Calculator::onDeleteClicked() {
    QString currentText = ui->Display->text();
    currentText.remove(cursor_id - 1, 1);
    onLeftArrClicked(); // Move cursor left after deletion
    ui->Display->setText(currentText);
}

void Calculator::onInputChanged() {
    if (ui->Display->text().isEmpty()) {
        ui->ButtonClear->setText("C");
    } 
    else {
        ui->ButtonClear->setText("CE");
    }
    updateVisualCursor();
}

void Calculator::onClearClicked() {
    if (ui->ButtonClear->text() == "CE") {
        QString text = ui->Display->text();
        int lastOp = text.lastIndexOf(QRegularExpression("[+-*/]"));

        if (lastOp != -1) {
            ui->Display->setText(text.left(lastOp + 1));
        }
        else {
            ui->Display->clear();
        }
    }
    else {
        ui->Display->clear();
    }
    ui->ButtonClear->setText("C");
}

void Calculator::updateVisualCursor() {
    QString currentText = ui->Display->text();

    // Remove any existing cursor symbol
    currentText.replace("|", "");

    if (cursor_id < 0) {
        cursor_id = 0;
    } 
    else if (cursor_id > currentText.length()) {
        cursor_id = currentText.length();
    }

    std::cout << "Cursor ID: " << cursor_id << std::endl;

    // Insert the cursor symbol at the correct position
    currentText.insert(cursor_id, "|");

    // Update the display
    ui->Display->setText(currentText);
}

/**
 * @brief Main entry point of the application.
 * 
 * Initializes the QApplication and the Calculator window, then enters the main event loop.
 * @param argc The number of arguments passed to the application.
 * @param argv The array of argument strings.
 * @return An integer exit status.
 */
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Calculator calculator;  ///< Create the calculator window
    calculator.show();      ///< Show the calculator window

    return app.exec();      ///< Start the event loop
}

/*** End of file calc.cpp ***/
