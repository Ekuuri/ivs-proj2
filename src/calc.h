/****************************************************************** 
* Project name: IVS 2 project
* Date: 18.4.2025
* Last change: 18.4.2025
* Team: audentes Fortuna iuvat 
* Author: Tobias Leščenko
* Brief: Header file of UI interactions
*****************************************************************/
/**
* @file calc.h
*
* @brief Header file of UI interactions
* @author Tobias Leščenko
*/

#pragma once

#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QRegularExpression>
#include "../build/src/ui_calc.h"  // Generated file from calc.ui

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
    int cursor_id = 0; ///< Cursor position in the display 

    /**
     * @brief Constructor for the Calculator class.
     *
     * Sets up the user interface and connects signals to corresponding slots.
     * 
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
     * @brief Slot to handle help button.
     * 
     * Shows help message.
     */
    void onHelpClicked();

    /**
     * @brief Slot to handle number button clicks.
     * 
     * Appends the clicked number to the display.
     * 
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
     * @brief Slot to handle absolute value.
     * 
     * Appends a straight bracket to the display.
     */
    void onAbsoluteValClicked();

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
     * @brief Slot to handle left arrow.
     * 
     * Moves display cursor to the left.
     */
    void onLeftArrClicked();

    /**
     * @brief Slot to handle right arrow.
     * 
     * Moves display cursor to the right.
     */
    void onRightArrClicked();

    /**
     * @brief Slot to handle equals operation.
     * 
     * Evaluates the expression in the display and shows the result.
     */
    void onEqualsClicked();

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

    /**
     * @brief Clears the display up to the last operator.
     *
     * This function removes all characters from the display after the last operator,
     * allowing the user to quickly clear the most recent input or operand while preserving
     * the previous part of the expression.
     */
    void clearToLastOperator();

    /**
     * @brief Clears the entire display.
     *
     * This function removes all content from the display, resetting it to an empty state.
     * It is typically used when the user wants to start a new calculation from scratch.
     */
    void clearDisplay();

    /**
     * @brief Resets the clear button text.
     *
     * This function updates the clear button's label (e.g., from "CE" to "C" or vice versa)
     * based on the current state of the display, providing appropriate feedback to the user.
     */
    void resetClearButtonText();

    /**
     * @brief Updates the visual representation of the cursor on the screen.
     * 
     * This function is responsible for synchronizing the visual cursor's position
     * with the logical cursor's state, ensuring that the user interface reflects
     * the current cursor location accurately.
     */
    void updateVisualCursor();

    /**
     * @brief Clears any existing error state if one is present.
     *
     * This function checks for the presence of an error state and clears it
     * if necessary. It ensures that the system is in a clean state for further
     * operations.
     */
    void clearErrorIfNeeded();

    /**
     * @brief Inserts a symbol at the current cursor position in the display.
     *
     * This function inserts the specified symbol into the display at the current
     * cursor position, updates the cursor position accordingly, and refreshes the
     * visual cursor. It is used for inserting operators, brackets, or other special
     * symbols as part of the user's input.
     *
     * @param symbol The symbol to insert at the cursor position.
     */
    void insertSymbolAtCursor(const QString& symbol);

private:
    Ui::Calculator *ui; ///< Pointer to the user interface (generated by uic).
};

