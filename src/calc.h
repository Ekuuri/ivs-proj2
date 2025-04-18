/****************************************************************** 
* Project name: IVS 2 project
* Date: 18.4.2025
* Last change: 18.4.2025
* Team: audentes Fortuna iuvat 
* Author: Tobias Leščenko
* Brief: Header file for the interactions of the UI
*****************************************************************/
#pragma once

#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QRegularExpression>
#include "calc-ui.h"

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
    explicit Calculator(QWidget *parent = nullptr);

    /**
     * @brief Destructor for the Calculator class.
     *
     * Deletes the user interface object.
     */
    virtual ~Calculator();

private slots:
    /**
     * @brief Slot to handle number button clicks.
     * 
     * Appends the clicked number to the display.
     * @param button The button that was clicked.
     */
    void onNumberClicked();

    /**
     * @brief Slot to handle addition operation.
     * 
     * Appends a plus sign to the display.
     */
    void onAddClicked();

    /**
     * @brief Slot to handle subtraction operation.
     * 
     * Appends a minus sign to the display.
     */
    void onSubtractClicked();

    /**
     * @brief Slot to handle multiplication operation.
     * 
     * Appends a multiplication sign to the display.
     */
    void onMultiplyClicked();

    /**
     * @brief Slot to handle division operation.
     * 
     * Appends a division sign to the display.
     */
    void onDivideClicked();

    /**
     * @brief Slot to handle power operation.
     * 
     * Appends a power symbol to the display.
     */
    void onPowerClicked();

    /**
     * @brief Slot to handle square root operation.
     * 
     * Appends a square root symbol to the display.
     */
    void onSqrtClicked();

    /**
     * @brief Slot to handle factorial operation.
     * 
     * Appends a factorial symbol to the display.
     */
    void onFactorialClicked();

    /**
     * @brief Slot to handle modulo operation.
     * 
     * Appends a modulo symbol to the display.
     */
    void onModuloClicked();

    /**
     * @brief Slot to handle decimal point.
     * 
     * Adds a decimal point to the display.
     */
    void onDecimalPointClicked();

    /**
     * @brief Slot to handle opening bracket.
     * 
     * Appends an opening bracket to the display.
     */
    void onOpBracketClicked();

    /**
     * @brief Slot to handle closing bracket.
     * 
     * Appends a closing bracket to the display.
     */
    void onClBracketClicked();

    /**
     * @brief Slot to handle equals operation.
     * 
     * Evaluates the expression in the display and shows the result.
     */
    void onEqualsClicked();

    /**
     * @brief Slot to handle placeholder button click.
     * 
     * Does nothing (used to fill space in the UI).
     */
    void onPlaceHolderClicked();

    /**
     * @brief Slot to handle delete/backspace operation.
     * 
     * Removes the last character from the display.
     */
    void onDeleteClicked();

    /**
     * @brief Slot to handle clear button text changes.
     * 
     * Sets clear button text to CE, whenever display is not empty.
     */
    void onInputChanged();

    /**
     * @brief Slot to handle clear operation.
     * 
     * CE clears last input.
     * C clears the whole display.
     */
    void onClearClicked();

private:
    Ui::Calculator *ui;
};

