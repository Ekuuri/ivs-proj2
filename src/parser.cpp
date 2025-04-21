/****************************************************************** 
* Project name: IVS 2 project
* Date: 21.4.2025
* Last change: 21.4.2025
* Team: audentes Fortuna iuvat 
* Author: Tobias Leščenko
* Brief: Implementation of mathematical formula parsing
*****************************************************************/
/**
* @file parser.cpp
*
* @brief Implementation of mathematical formula parsing
* @author Tobias Leščenko
*/

#include "parser.h"

// TreeNode::TreeNode(TreeNode *left, TreeNode *right) {
// }

// TreeNode::~TreeNode() {
// }

// Add::Add() {
// }

// Add::~Add() {
// }

// Subtract::Subtract() {
// }

// Subtract::~Subtract() {
// }

// Mult::Mult() {
// }

// Mult::~Mult() {
// }

// Div::Div() {
// }

// Div::~Div() {
// }

// Factorial::Factorial() {
// }

// Factorial::~Factorial() {
// }

// Exp::Exp() {
// }

// Exp::~Exp() {
// }

// Root::Root() {
// }

// Root::~Root() {
// }

// Mod::Mod() {
// }

// Mod::~Mod() {
// }

// Abs::Abs() {
// }

// Abs::~Abs() {
// }

// Neg::Neg() {
// }

// Neg::~Neg() {
// }

// Integer::Integer() {
// }

// Integer::~Integer() {
// }

QChar nextToken;
TreeNode* resultTree;
size_t id = 1;
QString globExp;

void scanToken() {
    if (nextToken == QChar(0)) {
        return;
    }

    nextToken = globExp[id];
    id++;
}


TreeNode* parseExp() {
    auto result = parseTerm();
    while (true) {
        if (nextToken == '+') {
            scanToken();
            result = new Add(result, parseTerm());
        }
        else if (nextToken == '-') {
            scanToken();
            result = new Subtract(result, parseTerm());
        }
        else {
            return result;
        }
    }
}

TreeNode* parseFactor() {
    if (nextToken.isDigit()) {
        QString number;
        while (nextToken.isDigit() || nextToken == '.') {
            number += nextToken;
            scanToken();
        }
        // Create an Integer node for the parsed number
        auto result = new Integer();
        result->value = number.toDouble();
        return result;
    }
    else if (nextToken == '(') {
        scanToken();
        auto result = parseExp();
        if (nextToken != ')') {
            nextToken = QChar(0);
            exit(1);
        }
        scanToken();
        return result;
    }
    else if (nextToken == '-') {
        scanToken();
        auto result = parseFactor();
        return new Neg(result);
    }
    else {
        exit(1);
    }
}

TreeNode* parseTerm() {
    auto result = parseFactor();
    if (nextToken == '*') {
        scanToken();
        result = new Mult(result, parseFactor());
    }
    else if (nextToken == '/') {
        scanToken();
        result = new Div(result, parseFactor());
    }
    else if (nextToken == '%') {
        scanToken();
        result = new Mod(result, parseFactor());
    }
    else if (nextToken == '^') {
        scanToken();
        result = new Exp(result, parseTerm());
    }
    else if (nextToken == QChar(0x221A)) {
        scanToken();
        result = new Root(result, parseTerm());
    }
    return result;
}

QString parse(QString expression) {
    globExp = expression;
    nextToken = expression[0];
    resultTree = parseExp();

    // if (nextToken != QChar(0)) {
    //     return "Error: Invalid expression";
    // }

    resultTree->print();


    return expression[0];
}


/*** End of file parser.cpp ***/