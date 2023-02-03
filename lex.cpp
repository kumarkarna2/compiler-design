#include <bits/stdc++.h>
using namespace std;
vector<string> resKey;
vector<string> resOp;
vector<string> resDel;
vector<string> resInt;
vector<string> resId;

void print()
{
    cout << "Keywords: ";
    for (auto i : resKey)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Operators: ";
    for (auto i : resOp)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Delimiters: ";
    for (auto i : resDel)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Identifiers: ";
    for (auto i : resId)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Constants: ";
    for (auto i : resInt)
    {
        cout << i << " ";
    }
}

int chkInt(char c)
{
    if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
    {
        return 1;
    }
    return 0;
}

int chkAlphabet(char c)
{
    if (c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'g' || c == 'h' || c == 'i' || c == 'j' || c == 'k' || c == 'l' || c == 'm' || c == 'n' || c == 'o' || c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't' || c == 'u' || c == 'v' || c == 'w' || c == 'x' || c == 'y' || c == 'z' || c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F' || c == 'G' || c == 'H' || c == 'I' || c == 'J' || c == 'K' || c == 'L' || c == 'M' || c == 'N' || c == 'O' || c == 'P' || c == 'Q' || c == 'R' || c == 'S' || c == 'T' || c == 'U' || c == 'V' || c == 'W' || c == 'X' || c == 'Y' || c == 'Z')
    {
        return 1;
    }
    return 0;
}

int chkOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '=' || c == '!' || c == '>' || c == '<' || c == '&' || c == '|' || c == '^' || c == '~' || c == '?' || c == ':')
    {
        return 1;
    }
    return 0;
}

int chkDelimiter(char c)
{
    if (c == ' ' || c == ',' || c == ';')
    {
        return 1;
    }
    return 0;
}

void resKeyword(string s)
{
    vector<string> keyword = {"alignas", "alignof", "and", "and_eq", "asm", "atomic_cancel", "atomic_commit", "atomic_noexcept", "auto", "bitand", "bitor", "bool", "break", "case", "catch", "char", "char8_t", "char16_t", "char32_t", "class", "compl", "concept", "const", "consteval", "constexpr", "constinit", "const_cast", "continue", "co_await", "co_return", "co_yield", "decltype", "default", "delete", "do", "double", "dynamic_cast", "else", "enum", "explicit", "export", "extern", "false", "float", "for", "friend", "goto", "if", "inline", "int", "long", "mutable", "namespace", "new", "noexcept", "not", "not_eq", "nullptr", "operator", "or", "or_eq", "private", "protected", "public", "reflexpr", "register", "reinterpret_cast", "requires", "return", "short", "signed", "sizeof", "static", "static_assert", "static_cast", "struct", "switch", "synchronized", "template", "this", "thread_local", "throw", "true", "try", "typedef", "typeid", "typename", "union", "unsigned", "using", "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq"};
    for (int i = 0; i < keyword.size(); i++)
    {
        if (s == keyword[i])
        {
            resKey.push_back(s);
            return;
        }
    }

    resId.push_back(s);
}

void operators(string s)
{
    vector<string> operators = {"+", "-", "*", "/", "%", "++", "--", "=", "+=", "-=", "*=", "/=", "%=", "==", "!=", ">", "<", ">=", "<=", "&&", "||", "!", "&", "|", "^", "~", "<<", ">>", ">>=", "<<=", "&=", "|=", "^=", "?:", ",", ".", "->", ".*", "->*", "()", "[]", "new", "delete", "new[]", "delete[]"};
    for (int i = 0; i < operators.size(); i++)
    {
        if (s == operators[i])
        {
            resOp.push_back(s);
        }
    }
}

void delimiters(string s)
{
    vector<string> delimtr = {",", ";"};
    for (int i = 0; i < delimtr.size(); i++)
    {
        if (s == delimtr[i])
        {
            resDel.push_back(s);
        }
    }
}

int main()
{
    string s = "int, + xgffy b /= float == -= a = 10;";

    cout << s[10];
    string tempstr, tempint, tempop, tempdel;
    for (int i = 0; i < s.length(); i++)
    {
        if (!chkDelimiter(s[i]))
        {
            if (chkInt(s[i]))
            {
                cout << "inside constant"
                     << "\n";
                tempint += s[i];
            }
            else if (chkAlphabet(s[i]) || chkInt(s[i]))
            {
                cout << "inside alphabet"
                     << "\n";

                tempstr += s[i];
            }
            else if (chkOperator(s[i]))
            {
                cout << "inside operator"
                     << "\n";
                tempop += s[i];
            }
        }
        else
        {
            if (chkDelimiter(s[i]))
            {
                cout << "inside delimiter"
                     << "\n";
                tempdel += s[i];
            }
            resKeyword(tempstr);
            operators(tempop);
            delimiters(tempdel);
            resInt.push_back(tempint);
            tempstr = "";
            tempop = "";
            tempdel = "";
            tempint = "";
        }
    }

    print();
    return 0;
}