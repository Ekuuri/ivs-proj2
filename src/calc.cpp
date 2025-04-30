/******************************************************************
 * Project name: IVS 2 project
 * Date: 26.3.2025
 * Last change: 23.4.2025
 * Team: audentes Fortuna iuvat
 * Author: Dan Šrajer, Tobias Leščenko, Marek Furiš
 * Brief: Implementation of UI interactions
 *****************************************************************/
/**
* @file calc.cpp
*
* @brief Implementation of UI interactions
* @author Dan Šrajer
* @author Tobias Leščenko
* @author Marek Furiš
*
*/

#include "calc.h"
#include "parser.h"
#include <QMessageBox>

// Constructor
Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Calculator) {
    // Setup the user interface from the .ui file.
    ui->setupUi(this);
    this->setWindowTitle("EpicCalculator");

    this->setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);

    // Connect help button to coresponding slot.
    connect(ui->ButtonHelp, &QPushButton::clicked, this, &Calculator::onHelpClicked);

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
    // Removed ButtonPlaceHolder connection as it has no functionality.
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
void Calculator::onHelpClicked() {
    QString helpText =
    "Calculator Usage Help\n"
        "   Welcome to our Calculator!\n"
        "   Here's a quick guide to using the calculator and understanding the functions of each button:\n\n"

    "Basic Controls\n"
        "   • Digits (0-9): Tap to input numbers.\n"
        "   • Operators (+, -, ×, ÷): Perform standard arithmetic operations.\n"
        "   • Equals (=): Evaluates the full expression and shows the result.\n"
        "   • Decimal point (.): Use for floating-point numbers.\n"
        "   • Delete (DEL): Deletes the last entered character.\n"
        "   • Clear (C/CE):\n"   
            "       o Press once for CE to clear only the last part of the expression.\n"
            "       o Press again for C to clear the entire input.\n"
    "Advanced Functions\n"
        "   • Power (x ^ n): Raises the number to a power. Example: 2^3 = 8.\n"
        "   • Square root (n√): Calculates square root. Example: √9 = 3.\n"
        "   • Factorial (n!): Factorial function. Example: 5! = 120.\n"
        "   • Modulo (%): Computes remainder after division.\n"
        "   • Absolute value (|n|): Returns absolute value. Needs to be in pair. Example: |-4| = 4.\n"
    "Navigation\n"
        "   • ← / →: Move the input cursor left or right in the expression for editing.\n"
    "Brackets:\n"
        "   • Use ( and ) to group expressions or control operation precedence.\n"
    "Note:\n"
        "   • Invalid expressions will not be evaluated.\n"
        "   • Cursor navigation and editing are supported with the arrow buttons.\n";
    
    QMessageBox msgBox;
    msgBox.setWindowTitle("Help");
    msgBox.setText(helpText);
    msgBox.setStyleSheet("QLabel{font-size: 14pt; min-width: 900px; min-height: 600px;}");
        
    msgBox.exec();
}

void Calculator::onNumberClicked() {
    clearErrorIfNeeded();
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QString currentText = ui->Display->text().insert(cursor_id, button->text());
        cursor_id++;
        ui->Display->setText(currentText);
    }
}

void Calculator::onAddClicked() {
    insertSymbolAtCursor("+");
}

void Calculator::onSubtractClicked() {
    insertSymbolAtCursor("-");
}

void Calculator::onMultiplyClicked() {
    insertSymbolAtCursor("*");
}

void Calculator::onDivideClicked() {
    insertSymbolAtCursor("/");
}

void Calculator::onPowerClicked() {
    insertSymbolAtCursor("^");
}

void Calculator::onSqrtClicked() {
    insertSymbolAtCursor("√");
}

void Calculator::onFactorialClicked() {
    insertSymbolAtCursor("!");
}

void Calculator::onModuloClicked() {
    insertSymbolAtCursor("%");
}

void Calculator::onAbsoluteValClicked() {
    insertSymbolAtCursor("|");
}

void Calculator::onDecimalPointClicked() {
    insertSymbolAtCursor(".");
}

void Calculator::onOpBracketClicked() {
    insertSymbolAtCursor("(");
}

void Calculator::onClBracketClicked() {
    insertSymbolAtCursor(")");
}

void Calculator::onLeftArrClicked() {
    if (cursor_id > 0) {
       cursor_id--;
       updateVisualCursor();
    }
}

void Calculator::onRightArrClicked() {
    if (cursor_id < ui->Display->text().length()) {
        cursor_id++;
        updateVisualCursor();
    }
}

void Calculator::onEqualsClicked() {
    QString expression = ui->Display->text();
    expression.remove("▏"); // Remove any existing cursor symbol
    QString result = parse(expression);
    bool valid;
    double number = result.toDouble(&valid);
    if (valid) {
        if (floor(number) == number) {
            result = QString::number(number, 'f', 0);
        }
        else {
            result = QString::number(number, 'f', 4);
            result = result.replace(QRegularExpression("([\\.][0-9]*?)0+$"), "\\1");
        }
    }
    ui->Display->setText(result);
    cursor_id = ui->Display->text().length(); // Move cursor to the end after evaluation
    updateVisualCursor();
}

// Removed onPlaceHolderClicked as ButtonPlaceHolder is no longer used.

void Calculator::onDeleteClicked() {
    if (cursor_id > 0) {
        QString currentText = ui->Display->text();
        currentText.remove(cursor_id - 1, 1);
        onLeftArrClicked(); // Move cursor left after deletion
        ui->Display->setText(currentText);
    }  
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
        clearToLastOperator();
    } else {
        clearDisplay();
    }
    resetClearButtonText();
}

void Calculator::clearToLastOperator() {
    QString text = ui->Display->text();
    int lastOp = text.lastIndexOf(QRegularExpression("[+\\-*/%^|]"));

    if (lastOp != -1) {
        ui->Display->setText(text.left(lastOp + 1));
    } else {
        ui->Display->clear();
    }
}

void Calculator::clearDisplay() {
    ui->Display->clear();
}

void Calculator::resetClearButtonText() {
    ui->ButtonClear->setText("C");
}

void Calculator::updateVisualCursor() {
    QString currentText = ui->Display->text();

    // Check if the cursor position has changed
    if (!currentText.contains("▏") || currentText.indexOf("▏") != cursor_id) {
        // Remove any existing cursor symbol
        currentText.replace("▏", "");

        if (cursor_id < 0) {
            cursor_id = 0;
        } 
        else if (cursor_id > currentText.length()) {
            cursor_id = currentText.length();
        }

        // Insert the cursor symbol at the correct position
        currentText.insert(cursor_id, "▏");

        // Update the display
        ui->Display->setText(currentText);
    }
}

void Calculator::clearErrorIfNeeded() {
    if (ui->Display->text().startsWith("Error")) {
        ui->Display->clear();
        cursor_id = 0;
    }
}

void Calculator::insertSymbolAtCursor(const QString& symbol) {
    clearErrorIfNeeded();
    QString currentText = ui->Display->text().insert(cursor_id, symbol);
    cursor_id++;
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
