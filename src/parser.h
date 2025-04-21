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

/**
 * @class TreeNode
 * @brief Base class for all nodes in the mathematical expression tree.
 */
class TreeNode {
private:
    TreeNode *left; ///< Pointer to the left child node.
    TreeNode *right; ///< Pointer to the right child node.
public:
    /**
     * @brief Constructor for TreeNode.
     * @param left Pointer to the left child node.
     * @param right Pointer to the right child node.
     */
    TreeNode(TreeNode *left, TreeNode *right);

    /**
     * @brief Destructor for TreeNode.
     */
    ~TreeNode();
};

/**
 * @class Add
 * @brief Represents addition operation in the expression tree.
 */
class Add : TreeNode {
public:
    using TreeNode::TreeNode; ///< Inherit TreeNode constructor.
};

/**
 * @class Subtract
 * @brief Represents subtraction operation in the expression tree.
 */
class Subtract : TreeNode {
public:
    using TreeNode::TreeNode; ///< Inherit TreeNode constructor.
};

/**
 * @class Mult
 * @brief Represents multiplication operation in the expression tree.
 */
class Mult : TreeNode {
public:
    using TreeNode::TreeNode; ///< Inherit TreeNode constructor.
};

/**
 * @class Div
 * @brief Represents division operation in the expression tree.
 */
class Div : TreeNode {
public:
    using TreeNode::TreeNode; ///< Inherit TreeNode constructor.
};

/**
 * @class Factorial
 * @brief Represents factorial operation in the expression tree.
 */
class Factorial : TreeNode {
public:
    /**
     * @brief Constructor for Factorial.
     */
    Factorial();

    /**
     * @brief Destructor for Factorial.
     */
    ~Factorial();
};

/**
 * @class Exp
 * @brief Represents exponentiation operation in the expression tree.
 */
class Exp : TreeNode {
public:
    /**
     * @brief Constructor for Exp.
     */
    Exp();

    /**
     * @brief Destructor for Exp.
     */
    ~Exp();
};

/**
 * @class Root
 * @brief Represents root operation in the expression tree.
 */
class Root : TreeNode {
public:
    using TreeNode::TreeNode; ///< Inherit TreeNode constructor.
};

/**
 * @class Mod
 * @brief Represents modulus operation in the expression tree.
 */
class Mod : TreeNode {
public:
    using TreeNode::TreeNode; ///< Inherit TreeNode constructor.
};

/**
 * @class Abs
 * @brief Represents absolute value operation in the expression tree.
 */
class Abs : TreeNode {
public:
    /**
     * @brief Constructor for Abs.
     */
    Abs();

    /**
     * @brief Destructor for Abs.
     */
    ~Abs();
};

/**
 * @class Neg
 * @brief Represents negation operation in the expression tree.
 */
class Neg : TreeNode {
public:
    /**
     * @brief Constructor for Neg.
     */
    Neg();

    /**
     * @brief Destructor for Neg.
     */
    ~Neg();
};

/**
 * @class Integer
 * @brief Represents an integer value in the expression tree.
 */
class Integer : TreeNode {
public:
    /**
     * @brief Constructor for Integer.
     */
    Integer();

    /**
     * @brief Destructor for Integer.
     */
    ~Integer();
};

/*** End of file parser.h ***/