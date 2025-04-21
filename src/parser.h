/****************************************************************** 
* Project name: IVS 2 project
* Date: 21.4.2025
* Last change: 21.4.2025
* Team: audentes Fortuna iuvat 
* Author: Tobias Leščenko
* Brief: Header file of mathematical formula parsing
*****************************************************************/
/**
* @file parser.h
*
* @brief Header file of mathematical formula parsing
* @author Tobias Leščenko
*/

#pragma once

#include "calc.h"
#include "mathlib-code.h"

/**
 * @class TreeNode
 * @brief Superclass for all nodes in the mathematical expression tree.
 */
class TreeNode {
protected:
    TreeNode *left; ///< Pointer to the left child node.
    TreeNode *right; ///< Pointer to the right child node.
    TreeNode *arg; ///< Pointer to the unary operator child node.
public:
    /**
     * @brief Constructor for TreeNode.
     */
    TreeNode() : left(nullptr), right(nullptr), arg(nullptr) {};

    /**
     * @brief Binary constructor for TreeNode.
     * @param left Pointer to the left child node.
     * @param right Pointer to the right child node.
     */
    TreeNode(TreeNode *left, TreeNode *right) : left(left), right(right), arg(nullptr) {};

    /**
     * @brief Unary constructor for TreeNode.
     * @param arg Pointer to the unary operator child node.
     */
    TreeNode(TreeNode *arg) : left(nullptr), right(nullptr), arg(arg) {};

    /**
     * @brief Destructor for TreeNode.
     */
    virtual ~TreeNode() {
        delete left;
        delete right;
        delete arg;
    };

    /**
     * @brief Evaluates the expression represented by the tree node.
     * @result The result of the evaluation.
     */
    virtual double eval() = 0;
};

/**
 * @class Add
 * @brief Represents addition operation in the expression tree.
 */
class Add : public TreeNode {
public:
    using TreeNode::TreeNode; ///< Inherit TreeNode constructors.

    /**
     * @brief Evaluates the addition operation.
     * @return The sum of the left and right child nodes.
     */
    double eval() override {
        return addition(left->eval(), right->eval());
    }
};

/**
 * @class Subtract
 * @brief Represents subtraction operation in the expression tree.
 */
class Subtract : public TreeNode {
public:
    using TreeNode::TreeNode; ///< Inherit TreeNode constructors.

    /**
     * @brief Evaluates the subtraction operation.
     * @return The difference between the left and right child nodes.
     */
    double eval() override {
        return subtraction(left->eval(), right->eval());
    }
};

/**
 * @class Mult
 * @brief Represents multiplication operation in the expression tree.
 */
class Mult : public TreeNode {
public:
    using TreeNode::TreeNode; ///< Inherit TreeNode constructors.

    /**
     * @brief Evaluates the multiplication operation.
     * @return The product of the left and right child nodes.
     */
    double eval() override {
        return multiplication(left->eval(), right->eval());
    }
};

/**
 * @class Div
 * @brief Represents division operation in the expression tree.
 */
class Div : public TreeNode {
public:
    using TreeNode::TreeNode; ///< Inherit TreeNode constructors.

    /**
     * @brief Evaluates the division operation.
     * @return The quotient of the left and right child nodes.
     */
    double eval() override {
        return division(left->eval(), right->eval());
    }
};

/**
 * @class Factorial
 * @brief Represents factorial operation in the expression tree.
 */
class Factorial : public TreeNode {
public:
    using TreeNode::TreeNode; ///< Inherit TreeNode constructors.

    /**
     * @brief Evaluates the factorial operation.
     * @return The factorial of the unary child node.
     */
    double eval() override {
        return factorial(arg->eval());
    }
};

/**
 * @class Exp
 * @brief Represents exponentiation operation in the expression tree.
 */
class Exp : public TreeNode {
public:
    using TreeNode::TreeNode; ///< Inherit TreeNode constructors.

    /**
     * @brief Evaluates the exponentiation operation.
     * @return The result of raising the left child node to the power of the right child node.
     */
    double eval() override {
        return exponentiation(left->eval(), right->eval());
    }
};

/**
 * @class Root
 * @brief Represents root operation in the expression tree.
 */
class Root : public TreeNode {
public:
    using TreeNode::TreeNode; ///< Inherit TreeNode constructors.

    /**
     * @brief Evaluates the root operation.
     * @return The nth root of the right child node with respect to the left child node.
     */
    double eval() override {
        return nthRoot(right->eval(), left->eval());
    }
};

/**
 * @class Mod
 * @brief Represents modulus operation in the expression tree.
 */
class Mod : public TreeNode {
public:
    using TreeNode::TreeNode; ///< Inherit TreeNode constructors.

    /**
     * @brief Evaluates the modulus operation.
     * @return The remainder of the division of the left child node by the right child node.
     */
    double eval() override {
        return modulo(left->eval(), right->eval());
    }
};

/**
 * @class Abs
 * @brief Represents absolute value operation in the expression tree.
 */
class Abs : public TreeNode {
public:
    using TreeNode::TreeNode; ///< Inherit TreeNode constructors.

    /**
     * @brief Evaluates the absolute value operation.
     * @return The absolute value of the unary child node.
     */
    double eval() override {
        return absoluteValue(arg->eval());
    }
};

/**
 * @class Neg
 * @brief Represents negation operation in the expression tree.
 */
class Neg : public TreeNode {
    public:
    using TreeNode::TreeNode; ///< Inherit TreeNode constructors.
    
    /**
     * @brief Evaluates the negation operation.
     * @return The negated value of the unary child node.
     */
    double eval() override {
        return -(arg->eval());
    }
};

/**
 * @class Integer
 * @brief Represents an integer value in the expression tree.
 */
class Integer : public TreeNode {
public:
    double value; ///< The integer value.

    using TreeNode::TreeNode; ///< Inherit TreeNode constructors.

    /**
     * @brief Evaluates the integer node.
     * @return The value of the integer node.
     */
    double eval() override {
        return value;
    }
};

/**
 * @brief Parses an expression and returns the root of the expression tree.
 * @return A pointer to the root node of the parsed expression tree.
 */
TreeNode* parseExp();

/**
 * @brief Parses a term and returns the corresponding tree node.
 * @return A pointer to the tree node representing the parsed term.
 */
TreeNode* parseTerm();

/**
 * @brief Parses a factor and returns the corresponding tree node.
 * @return A pointer to the tree node representing the parsed factor.
 */
TreeNode* parseFactor();

/**
 * @brief Scans the next token in the input expression.
 */
void scanToken();

/**
 * @brief Parses a mathematical expression and evaluates it.
 * @param expression The input mathematical expression as a QString.
 * @return The result of evaluating the expression as a QString.
 */
QString parse(QString expression);

/*** End of file parser.h ***/