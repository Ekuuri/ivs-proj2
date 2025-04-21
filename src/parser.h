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

class TreeNode {
private:
    TreeNode *left;
    TreeNode *right;
public:
    TreeNode(TreeNode *left, TreeNode *right);
    ~TreeNode();
};

class Add : TreeNode {
private:
    /* data */
public:
    using TreeNode::TreeNode;
};

class Subtract : TreeNode {
private:
    /* data */
public:
    using TreeNode::TreeNode;
};

class Mult : TreeNode {
private:
    /* data */
public:
    using TreeNode::TreeNode;
};

class Div : TreeNode {
private:
    /* data */
public:
    using TreeNode::TreeNode;
};

class Factorial : TreeNode {
private:
    /* data */
public:
    Factorial();
    ~Factorial();
};

class Exp : TreeNode {
private:
    /* data */
public:
    Exp();
    ~Exp();
};

class Root : TreeNode {
private:
    /* data */
public:
    using TreeNode::TreeNode;
};

class Mod : TreeNode {
private:
    /* data */
public:
    using TreeNode::TreeNode;
};

class Abs : TreeNode {
private:
    /* data */
public:
    Abs();
    ~Abs();
};

class Neg : TreeNode {
private:
    /* data */
public:
    Neg();
    ~Neg();
};

class Integer : TreeNode {
private:
    /* data */
public:
    Integer();
    ~Integer();
};

/*** End of file parser.h ***/