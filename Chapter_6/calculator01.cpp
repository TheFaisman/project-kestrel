/*
    First iteration of the calculator program in Chapter 6.
    
    Calculator 1.0
    
    This is a calculator, and it should follow the standard order of operations.
    Furthermore, it should accept expressions with more than one operator.
    Defined operations are +, -, *, /
    For example:
        4+5*2 should return 14
        7/2+3*2 should return 9.5

    

    Regarding implementation, the concepts of tokens, token streams, and a grammar
    should be utilized. 
*/

#include "../std_lib_facilities.h"


// Define a Token
class Token {
public:
    char kind;
    double value;
};
// Define a Token_stream
class Token_stream {
private:
    bool is_full {false};
    Token buffer;
public:
    Token get();
    void putback(Token t);
};

// Define Token_stream functions
Token Token_stream::get() {
    Token token;
    if (is_full) {
        is_full = false;
        return buffer;
    }
    // Do stuff to get the next token from the console input stream
    char ch;
    cin >> ch;
    switch (ch) {
    case ';':
    case 'q':
    case '(': case ')': case '+': case '-': case '*': case '/':
        return Token{ch};
        break;
    case '0': case '1': case '2': case '3': case '4': 
    case '5': case '6': case '7': case '8': case '9':
        cin.putback(ch);
        double val;
        cin >> val;
        return Token{'8', val};
        break;
    default:
        error("Bad token.");
    }
}

void Token_stream::putback(Token t) {
    if (is_full) {
        error("Token stream is full. Cannot putback token.");
    }
    buffer = t;
    is_full = true;
}

// Token stream initialization
Token_stream tstream;
// Grammar function declaration
double expression();

// Grammer function definitions
double primary() {
    Token token = tstream.get();
    double primary;
    
    switch (token.kind) {
    case '(':
    {
        primary = expression();
        token = tstream.get();
        if (token.kind != ')') {
            error("')' expected. Primary invalid.");
        }
        break;
    }
    case '8':
        primary = token.value;
        break;
    default:
        error("Invalid token. Primary expected.");
    }
    return primary;
}

double term() {
    double term = primary();
    Token token = tstream.get();
    while (true) {
        switch (token.kind) {
        case '*':
            term *= primary();
            token = tstream.get();
            break;
        case '/': 
        {
            double d = primary();
            if (d == 0) {
                error("Cannot divide by 0.");
            }
            term /= d;
            token = tstream.get();
            break;
        }
        default:
            tstream.putback(token);
            return term;
        }
    }
}

double expression() {
    double expression = term();
    Token token = tstream.get();
    while (true) {
        switch (token.kind) {
        case '+':
            expression += term();
            token = tstream.get();
            break;
        case '-':
            expression -= term();
            token = tstream.get();
            break;
        default:
            tstream.putback(token);
            return expression;
        }
    }
    return expression;
}

int main() {

    cout << "Calculator 1.0 - Use ; to calculate your expression.\n";
    double val {0};
    while (cin) {
        val = expression();
        Token token = tstream.get();
        if (token.kind == 'q') break;
        if (token.kind == ';') {
            cout << "=" << val << endl;
        } else {
            tstream.putback(token);
        }
    }
    
    return 0;
}