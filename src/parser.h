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

#include "mathlib-code.h"
#include "mathlib-code.cpp"

/**
 * @class TreeNode
 * @brief Base class for all nodes in the mathematical expression tree.
 */
class TreeNode {
protected:
    TreeNode *left; ///< Pointer to the left child node.
    TreeNode *right; ///< Pointer to the right child node.
    TreeNode *arg; ///< Pointer to the unary operator child node.
public:
    /**
     * @brief Binary constructor for TreeNode.
     * @param left Pointer to the left child node.
     * @param right Pointer to the right child node.
     */
    TreeNode(TreeNode *left, TreeNode *right);

    /**
     * @brief Unary constructor for TreeNode.
     * @param arg Pointer to the unary operator child node.
     */
    TreeNode(TreeNode *arg);

    /**
     * @brief Destructor for TreeNode.
     */
    ~TreeNode();

    virtual void print();

    virtual double eval();
};

/**
 * @class Add
 * @brief Represents addition operation in the expression tree.
 */
class Add : TreeNode {
public:
    using TreeNode::TreeNode; ///< Inherit TreeNode constructors.

    double eval() override {
        return addition(left->eval(), right->eval());
    }
};

/**
 * @class Subtract
 * @brief Represents subtraction operation in the expression tree.
 */
class Subtract : TreeNode {
public:
    using TreeNode::TreeNode; ///< Inherit TreeNode constructors.

    double eval() override {
        return subtraction(left->eval(), right->eval());
    }
};

/**
 * @class Mult
 * @brief Represents multiplication operation in the expression tree.
 */
class Mult : TreeNode {
public:
    using TreeNode::TreeNode; ///< Inherit TreeNode constructors.

    double eval() override {
        return multiplication(left->eval(), right->eval());
    }
};

/**
 * @class Div
 * @brief Represents division operation in the expression tree.
 */
class Div : TreeNode {
public:
    using TreeNode::TreeNode; ///< Inherit TreeNode constructors.

    double eval() override {
        return division(left->eval(), right->eval());
    }
};

/**
 * @class Factorial
 * @brief Represents factorial operation in the expression tree.
 */
class Factorial : TreeNode {
public:
    using TreeNode::TreeNode; ///< Inherit TreeNode constructors.

    double eval() override {
        return factorial(arg->eval());
    }
};

/**
 * @class Exp
 * @brief Represents exponentiation operation in the expression tree.
 */
class Exp : TreeNode {
public:
    using TreeNode::TreeNode; ///< Inherit TreeNode constructors.

    double eval() override {
        return exponentiation(left->eval(), right->eval());
    }
};

/**
 * @class Root
 * @brief Represents root operation in the expression tree.
 */
class Root : TreeNode {
public:
    using TreeNode::TreeNode; ///< Inherit TreeNode constructors.

    double eval() override {
        return nthRoot(left->eval(), right->eval());
    }
};

/**
 * @class Mod
 * @brief Represents modulus operation in the expression tree.
 */
class Mod : TreeNode {
public:
    using TreeNode::TreeNode; ///< Inherit TreeNode constructors.

    double eval() override {
        return modulo(left->eval(), right->eval());
    }
};

/**
 * @class Abs
 * @brief Represents absolute value operation in the expression tree.
 */
class Abs : TreeNode {
public:
    using TreeNode::TreeNode; ///< Inherit TreeNode constructors.

    double eval() override {
        return absoluteValue(arg->eval());
    }
};

/**
 * @class Neg
 * @brief Represents negation operation in the expression tree.
 */
class Neg : TreeNode {
public:
    using TreeNode::TreeNode; ///< Inherit TreeNode constructors.

    double eval() override {
        return -(arg->eval());
    }
};

/**
 * @class Integer
 * @brief Represents an integer value in the expression tree.
 */
class Integer : TreeNode {
private:
    double value; ///< The integer value.
public:
    using TreeNode::TreeNode; ///< Inherit TreeNode constructors.

    double eval() override {
        return value;
    }
};

/*** End of file parser.h ***/