#include "calculator.h"

bool Calculator::isDigit(const char &c) {
    return c >= '0' && c <= '9';
}

bool Calculator::isOperation(const char &c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool Calculator::isValidExpr(string s) {
    Stack<char> brackets;
    istringstream ss(s);
    ostringstream expr;
    Stack<char> opr;
    Token prev = Token::NONE;
    while (ss) {
        if (ss.peek() == -1)
            break;
        if (ss.peek() == '(') {
            // check ------------------
            if (!brackets.isEmpty() && brackets.Top() == ')')
                return false;
            if (prev == Token::NUMBER)
                return false;
            brackets.Push('(');
            prev = Token::OPEN_BRACKET;
            ss.ignore(1);
            // make expr --------------
            opr.Push('(');
        }
        else if (ss.peek() == ')') {
            // check ------------------
            if (brackets.isEmpty())
                return false;
            if (prev == Token::OPERATION)
                return false;
            brackets.Pop();
            prev = Token::CLOSE_BRACKET;
            ss.ignore(1);
            // make expr --------------
            while (opr.Top() != '(')
                expr << opr.Pop() << " ";
            opr.Pop();
        }
        else if (isDigit(ss.peek())) {
            // check ------------------
            if (prev == Token::CLOSE_BRACKET || prev == Token::NUMBER)
                return false;
            int a;
            ss >> a;
            prev = Token::NUMBER;
            // make expr --------------
            expr << a << " ";
        }
        else if (isOperation(ss.peek())) {
            // check ------------------
            if (prev == Token::OPERATION)
                return false;
            if (ss.peek() == '/' || ss.peek() == '*')
                if (prev == Token::NONE)
                    return false;
            prev = Token::OPERATION;
            char operation = ss.peek();
            ss.ignore(1);
            // make expr --------------
            if (operation == '^')
                while (!opr.isEmpty() && priority[operation] < priority[opr.Top()])
                    expr << opr.Pop() << " ";
            else
                while (!opr.isEmpty() && priority[operation] <= priority[opr.Top()])
                    expr << opr.Pop() << " ";
            opr.Push(operation);
        }
        else if (ss.peek() == ' ') {
            ss.ignore(1);
        }
        else {
            return false;
        }
    }
    if (!brackets.isEmpty())
        return false;
    if (prev == Token::OPERATION)
        return false;

    while (!opr.isEmpty())
        expr << opr.Pop() << " ";
    polish_notation = expr.str();

    return true;
}

double Calculator::polishNotationCalc() {
    istringstream ss(polish_notation);
    Stack <double> numb;
    while (ss.peek() != -1) {
        if (ss.peek() == ' ')
            ss.ignore(1);
        else if (isDigit(ss.peek())) {
            int a;
            ss >> a;
            numb.Push(a);
        }
        else {
            char c;
            ss >> c;
            switch (c) {
                case '+':
                    numb.Push(numb.Pop() + numb.Pop());
                    break;
                case '-': {
                    int a = numb.Pop();
                    int b = numb.Pop();
                    numb.Push(b - a);
                }
                    break;
                case '*':
                    numb.Push(numb.Pop() * numb.Pop());
                    break;
                case '/': {
                    int a = numb.Pop();
                    int b = numb.Pop();
                    numb.Push((double)b / a);
                }
                    break;
                case '^':
                    numb.Push(pow(numb.Pop(), numb.Pop()));
                    break;
            }
        }
    }
    return numb.Top();
}

double Calculator::calculate(const string &expr) {
    if (!isValidExpr(expr))
        throw runtime_error("invalid expression");
    return polishNotationCalc();
}