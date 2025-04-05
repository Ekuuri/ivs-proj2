/******************************************************************
 * Project name: IVS 2 project
 * Date: 26.3.2025
 * Last change: 27.3.2025
 * Team: audentes Fortuna iuvat
 * Author: Dan Šrajer
 * Brief:
 *****************************************************************/

#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include "calc-ui.h"  // Generated file from calc.ui

/**
 * @class Calculator
 * @brief A simple calculator application.
 *
 * This class provides the basic functionality of a calculator with operations such as
 * addition, subtraction, multiplication, division, power, square root, factorial, modulo,
 * and clear. It also includes backspace functionality to remove the last entered character.
 */
class Calculator : public QMainWindow {
    Q_OBJECT

public:
    /**
     * @brief Constructor for the Calculator class.
     * 
     * Sets up the user interface and connects signals to corresponding slots.
     * @param parent The parent widget, default is nullptr.
     */
    Calculator(QWidget *parent = nullptr)
        : QMainWindow(parent), ui(new Ui::Calculator) {
        // Setup the user interface from the .ui file.
        ui->setupUi(this);

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
        
        // Connect additional buttons to corresponding slots.
        connect(ui->ButtonDecPoint, &QPushButton::clicked, this, &Calculator::onDecimalPointClicked);
        connect(ui->ButtonOpBracket, &QPushButton::clicked, this, &Calculator::onOpBracketClicked);
        connect(ui->ButtonClBracket, &QPushButton::clicked, this, &Calculator::onClBracketClicked);
        connect(ui->ButtonEquals, &QPushButton::clicked, this, &Calculator::onEqualsClicked);
        connect(ui->ButtonPlaceHolder, &QPushButton::clicked, this, &Calculator::onPlaceHolderClicked);
        connect(ui->ButtonDelete, &QPushButton::clicked, this, &Calculator::onDeleteClicked);
        connect(ui->ButtonClear, &QPushButton::clicked, this, &Calculator::onClearClicked);

        //Connect input change event to update clear button.
        connect(ui->Display, &QLineEdit::textChanged, this, &Calculator::onInputChanged);
    }

    /**
     * @brief Destructor for the Calculator class.
     * 
     * Deletes the user interface object.
     */
    ~Calculator() {
        delete ui;
    }

private slots:
    /**
     * @brief Slot to handle number button clicks.
     * 
     * Appends the clicked number to the display.
     * @param button The button that was clicked.
     */
    void onNumberClicked() {
        QPushButton* button = qobject_cast<QPushButton*>(sender());
        if (button) {
            ui->Display->insert(button->text());
        }
    }

    /**
     * @brief Slot to handle addition operation.
     * 
     * Appends a plus sign to the display.
     */
    void onAddClicked() {
        ui->Display->insert("+");
    }

    /**
     * @brief Slot to handle subtraction operation.
     * 
     * Appends a minus sign to the display.
     */
    void onSubtractClicked() {
        ui->Display->insert("-");
    }

    /**
     * @brief Slot to handle multiplication operation.
     * 
     * Appends a multiplication sign to the display.
     */
    void onMultiplyClicked() {
        ui->Display->insert("*");
    }

    /**
     * @brief Slot to handle division operation.
     * 
     * Appends a division sign to the display.
     */
    void onDivideClicked() {
        ui->Display->insert("/");
    }

    /**
     * @brief Slot to handle power operation.
     * 
     * Appends a power symbol to the display.
     */
    void onPowerClicked() {
        ui->Display->insert("^");
    }

    /**
     * @brief Slot to handle square root operation.
     * 
     * Appends a square root symbol to the display.
     */
    void onSqrtClicked() {
        ui->Display->insert("sqrt(");
    }

    /**
     * @brief Slot to handle factorial operation.
     * 
     * Appends a factorial symbol to the display.
     */
    void onFactorialClicked() {
        ui->Display->insert("!");
    }

    /**
     * @brief Slot to handle modulo operation.
     * 
     * Appends a modulo symbol to the display.
     */
    void onModuloClicked() {
        ui->Display->insert("%");
    }

    /**
     * @brief Slot to handle decimal point.
     * 
     * Adds a decimal point to the display.
     */
    void onDecimalPointClicked() {
        ui->Display->insert(".");
    }

    /**
     * @brief Slot to handle opening bracket.
     * 
     * Appends an opening bracket to the display.
     */
    void onOpBracketClicked() {
        ui->Display->insert("(");
    }

    /**
     * @brief Slot to handle closing bracket.
     * 
     * Appends a closing bracket to the display.
     */
    void onClBracketClicked() {
        ui->Display->insert(")");
    }

    /**
     * @brief Slot to handle equals operation.
     * 
     * Evaluates the expression in the display and shows the result.
     */
    void onEqualsClicked() {
        QString expression = ui->Display->text();
        ui->Display->setText("Result");
    }

    /**
     * @brief Slot to handle placeholder button click.
     * 
     * Does nothing (used to fill space in the UI).
     */
    void onPlaceHolderClicked() {
        // Placeholder button does nothing.
    }

    /**
     * @brief Slot to handle delete/backspace operation.
     * 
     * Removes the last character from the display.
     */
    void onDeleteClicked() {
        QString currentText = ui->Display->text();
        currentText.chop(1);  // Remove the last character
        ui->Display->setText(currentText);
    }

    /**
     * @brief Slot to handle clear button text changes.
     * 
     * Sets clear button text to CE, whenever display is not empty.
     */
    void onInputChanged() {
        if (ui->Display->text(.isEmpty())) {
            ui->ButtonClear->setText("C");
        } 
        else {
            ui->ButtonClear->setText("CE");
        }
    }

    /**
     * @brief Slot to handle clear operation.
     * 
     * CE clears last input.
     * C clears the whole display.
     */
    void onClearclicked() {
        if (ui->ButtonClear->text() == "CE") {
            QString text = ui->Display->text();
            int lastOp = text.lastIndexOf(QRegExp("[+-*/]"));

            if (lstOp != -1) {
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


private:
    Ui::Calculator *ui;  ///< Pointer to the user interface (generated by uic).
};

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
