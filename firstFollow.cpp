#include <bits/stdc++.h>
using namespace std;

string S = "BC";
string B = "C";
string C = "D";
string D = "ac";

char chkNonTerminal(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c;

    return 0;
}

char first(string s)
{

    if (s[0] == 'B')
    {
        return first(B);
    }
    else if (s[0] == 'C')
    {
        return first(C);
    }
    else if (s[0] == 'D')
    {
        return first(D);
    }
    else
    {
        return s[0];
    }

    return 0;
}

int main()
{
    set<char> firstSetof_S;
    set<char> firstSetof_B;
    firstSetof_S.insert(first(S));
    // firstSetof_B.insert(first(B));
    cout << "First of S: ";
    for (auto i = firstSetof_S.begin(); i != firstSetof_S.end(); i++)
    {
        cout << *i << " ";
    }
    return 0;
}