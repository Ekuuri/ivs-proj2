/******************************************************************
 * Project name: IVS 2 project
 * Date: 26.3.2025
 * Last change: 27.3.2025
 * Team: audentes Fortuna iuvat
 * Author: Dan Šrajer
 * Brief:
 *****************************************************************/

#include "calc.h"
#include "calc-ui.h"  // Generated file from calc.ui

// Constructor
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

// Destructor
~Calculator() {
    delete ui;
}

private slots:

    void onNumberClicked() {
        QPushButton* button = qobject_cast<QPushButton*>(sender());
        if (button) {
            ui->Display->insert(button->text());
        }
    }

    void onAddClicked() {
        ui->Display->insert("+");
    }

    void onSubtractClicked() {
        ui->Display->insert("-");
    }

    void onMultiplyClicked() {
        ui->Display->insert("*");
    }

    void onDivideClicked() {
        ui->Display->insert("/");
    }

    void onPowerClicked() {
        ui->Display->insert("^");
    }

    void onSqrtClicked() {
        ui->Display->insert("sqrt(");
    }

    void onFactorialClicked() {
        ui->Display->insert("!");
    }

    void onModuloClicked() {
        ui->Display->insert("%");
    }

    void onDecimalPointClicked() {
        ui->Display->insert(".");
    }

    void onOpBracketClicked() {
        ui->Display->insert("(");
    }

    void onClBracketClicked() {
        ui->Display->insert(")");
    }

    void onEqualsClicked() {
        QString expression = ui->Display->text();
        ui->Display->setText("Result");
    }

    void onPlaceHolderClicked() {
        // Placeholder button does nothing.
    }

    void onDeleteClicked() {
        QString currentText = ui->Display->text();
        currentText.chop(1);  // Remove the last character
        ui->Display->setText(currentText);
    }

    void onInputChanged() {
        if (ui->Display->text().isEmpty()) {
            ui->ButtonClear->setText("C");
        } 
        else {
            ui->ButtonClear->setText("CE");
        }
    }

    void onClearClicked() {
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
