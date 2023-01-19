#include <bits/stdc++.h>
using namespace std;
void print(string s);
int chkVowel(char s)
{
    if (s == 'a' || s == 'A' || s == 'e' || s == 'E' || s == 'i' || s == 'I' || s == 'o' || s == 'O' || s == 'u' || s == 'U')
    {
        return 1;
    }
    return 0;
}

void moveCons(string s)
{
    string tempStr;
    char temp = s[0];
    for (int i = 1; i < s.length(); i++)
    {
        tempStr += s[i];
    }
    tempStr += temp;
    tempStr += "ay";

    print(tempStr);
}

void translate(string s)
{
    if (s.length() == 1)
    {
        print(s);
    }
    else if (chkVowel(s[0]))
    {
        if ((s[0] == 'u' || s[0] == 'U') && s[1] == 'Q' || s[1] == 'q')
        {
            moveCons(s);
        }
        else
        {
            s += "yay";
            print(s);
        }
    }
    else if ((s[0] == 'y' || s[0] == 'Y') && chkVowel(s[1]))
    {
        s += "yay";
        print(s);
    }
    else
    {
        moveCons(s);
    }
}

void print(string s)
{
    cout << s;
    exit;
}

int main()
{
    string input = "owl";
    translate(input);

    return 0;
}