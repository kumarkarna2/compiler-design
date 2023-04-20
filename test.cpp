#include <bits/stdc++.h>
using namespace std;
vector<string> keywords;
vector<string> operators;
vector<string> delimiters;
vector<string> identifiers;
vector<string> integers;
vector<string> tokens;

void print()
{
    cout << "Tokens: ";
    for (int i = 0; i < tokens.size(); i++)
    {
        cout << tokens[i] << " ";
    }
    cout << endl;

    cout << "Keywords: ";
    for (int i = 0; i < keywords.size(); i++)
    {
        cout << keywords[i] << " ";
    }
    cout << endl;
    cout << "Identifiers: ";
    for (int i = 0; i < identifiers.size(); i++)
    {
        cout << identifiers[i] << " ";
    }
    cout << endl;
    cout << "Constants: ";
    for (int i = 0; i < integers.size(); i++)
    {
        cout << integers[i] << " ";
    }
    cout << endl;
    cout << "Operators: ";
    for (int i = 0; i < operators.size(); i++)
    {
        cout << operators[i] << " ";
    }
    cout << endl;
    cout << "Delimiters: ";
    for (int i = 0; i < delimiters.size(); i++)
    {
        cout << delimiters[i] << " ";
    }
    cout << endl;
}

bool chkDelimiter(char c)
{
    vector<char> delimtr = {',', ';', '(', ')', '{', '}', '[', ']', '#', '\\', '<', '>', '~', '`', '\'', '\"'};
    for (int i = 0; i < delimtr.size(); i++)
    {
        if (c == delimtr[i])
        {
            return true;
        }
    }
    return false;
}

bool chkOperator(char c)
{
    vector<char> op = {'+', '-', '*', '/', '%', '=', '!', '<', '>', '&', '|', '^', '~'};
    for (int i = 0; i < op.size(); i++)
    {
        if (c == op[i])
        {
            return true;
        }
    }
    return false;
}

bool chkAlphabet(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        return true;
    }
    return false;
}

bool chkInt(char c)
{
    if (c >= '0' && c <= '9')
    {
        return true;
    }
    return false;
}

bool chkKeyword(string s)
{
    vector<string> key = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
    for (int i = 0; i < key.size(); i++)
    {
        if (s == key[i])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string s = "int a = 5; int b = 6; int c = a + b;     x+++y; ";

    string tempStr, tempInt, tempDel, tempOp;
    for (int i = 0; i < s.size(); i++)
    {
        if (chkInt(s[i]) && !(s[i - 1] == '_' || s[i + 1] == '_' || chkAlphabet(s[i - 1]) || chkAlphabet(s[i + 1])))
        {
            tempInt += s[i];
        }
        else if (chkAlphabet(s[i]) || s[i] == '_' || chkInt(s[i]))
        {
            if (chkInt(s[i]) && (chkAlphabet(s[i - 1]) || chkAlphabet(s[i + 1])))
            {

                int j = i;
                while (chkInt(s[j]))
                {
                    tempStr += s[j];
                    j++;
                }
                i = j - 1;
                continue;
            }
            tempStr += s[i];
            continue;
        }

        else if (chkDelimiter(s[i]))
        {
            tempDel += s[i];
        }
        else if (chkOperator(s[i]))
        {
            if (tempOp.size() < 2)
            {
                tempOp += s[i];
            }

            // else
            // {
            // tokens.push_back(tempOp);
            //     operators.push_back(tempOp);
            //     tempOp = "";
            //     tempOp += s[i];
            // }
        }
        else
        {
            if (tempStr != "")
            {
                if (chkKeyword(tempStr))
                {
                    keywords.push_back(tempStr);
                    tokens.push_back(tempStr);
                }
                else
                {
                    identifiers.push_back(tempStr);
                    tokens.push_back(tempStr);
                }
                tempStr = "";
            }
            if (tempInt != "")
            {
                integers.push_back(tempInt);
                tokens.push_back(tempInt);
                tempInt = "";
            }
            if (tempDel != "")
            {
                delimiters.push_back(tempDel);
                tokens.push_back(tempDel);
                tempDel = "";
            }
            if (tempOp != "")
            {
                operators.push_back(tempOp);
                tokens.push_back(tempOp);
                tempOp = "";
            }
        }
    }
    print();

    return 0;
}