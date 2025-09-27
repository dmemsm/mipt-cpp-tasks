//
// A bitwise logical expression is much like an arithmetic expression except
// that the operators are ! (not), ~ (complement), & (and), | (or), and ^
// (exclusive or). Each operator does its operation to each bit of its
// integer operands (see §25.5). ! and ~ are prefix unary operators. A ^
// binds tighter than a | (just as * binds tighter than +) so that x|y^z
// means x|(y^z) rather than (x|y)^z. The & operator binds tighter than ^ so
// that x^y&z means x^(y&z).
//

/*
  Grammar of a bitwise logical expression.

  Expression:
    Term
    Expression "|" Term
  Term:
    Subterm
    Term "^" Subterm
  Subterm:
    Primary
    Subterm "&" Primary
  Primary:
    Number
    "(" Expression ")"
    "!" Primary
    "~" Primary
  Number:
    integer_literal

*/

#include "std_lib_facilities.h"

class Token {

public:
    char kind;
    int value;

    Token(char ch): kind{ch}, value{0} {}
    Token(int val): kind{'8'}, value{val} {}

};

class TokenStream {

public:
    TokenStream(): buffer{0} {}

    Token get() {
        if (full) {
            full = false;
            return buffer;
        }

        char ch;
        cin >> ch;
        switch (ch)
        {
            case '!':
            case '~':
            case '&':
            case '|':
            case '^':
            case ';':
            case 'q':
            case '(':
            case ')': {
                return Token(ch);
            }

            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9': {
                cin.putback(ch);
                int val;
                cin >> val;
                return Token(val);
            }

            default: {
                error("Bad token");
            }
        }
    }

    void putback(Token t) {
        if (full)
            error("putback() into a full buffer");

        buffer = t;
        full = true;
    }

private:
    bool full{false};
    Token buffer;

};

TokenStream stream;

int expression();

int primary() {
    Token t = stream.get();

    switch(t.kind) {
        case '(': {
            int d = expression();
            t = stream.get();
            if (t.kind != ')')
                error("')' expected");
            return d;
        }

        case '8': {
            return t.value;
        }

        case '!': {
            return !primary();
        }

        case '~': {
            return ~primary();
        }

        default: {
            error("primary expected");
        }
    }
}

int subterm() {
    int left = primary();
    Token t = stream.get();

    while (true) {
        switch(t.kind) {
            case '&': {
                left &= primary();
                t = stream.get();
                break;
            }

            default: {
                stream.putback(t);
                return left;
            }
        }
    }
}

int term() {
    int left = subterm();
    Token t = stream.get();

    while (true) {
        switch (t.kind) {
            case '^': {
                left ^= subterm();
                t = stream.get();
                break;
            }

            default: {
                stream.putback(t);
                return left;
            }
        }
    }
}

int expression ()
{
    int left = term();
    Token t = stream.get();

    while (true) {
        switch (t.kind) {
            case '|': {
                left |= term();
                t = stream.get();
                break;
            }

            default: {
                stream.putback(t);
                return left;
            }
        }
    }
}

int main ()
try
{
    int val{};

    while (cin)
    {
        Token t = stream.get();

        if (t.kind == 'q') { // 'q' for quit
            break;
        }
        if (t.kind == ';') { // ';' for "print now"
            cout << "=" << val << '\n';
            continue;
        }
        else {
            stream.putback(t);
        }

        val = expression();
    }
}
catch (exception& e)
{
    cerr << "error: " << e.what() << '\n';
    return 1;
}
catch (...)
{
    cerr << "Oops: unknown exception!\n";
    return 2;
}
