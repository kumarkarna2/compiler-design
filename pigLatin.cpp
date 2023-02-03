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
    // string res;
    string tempCon;
    // int count = 0;
    string subStr;
    for (int i = 0; i < s.length(); i++)
    {

        // treat u as a consonant
        if ((s[i] == 'u' || s[i] == 'U') && (s[i - 1] == 'Q' || s[i - 1] == 'q'))
        {
            tempCon += s[i];
        }
        else if (s[i] == 'y' || s[i] == 'Y')
        {
            if (chkVowel(s[i + 1]))
            {
                tempCon += s[i];
            }
            else // if (!chkVowel(s[i - 1]))
            {
                subStr = s.substr(i);
                break;
            }
        }
        // after encounterring a vowel copy the left string to a new string and stop traversing
        else if (chkVowel(s[i]))
        {
            subStr = s.substr(i);
            break;
        }

        // copy consonant untill vowel is encountered
        else
        {
            tempCon += s[i];
        }
    }
    subStr += tempCon;
    subStr += "ay";

    print(subStr);
}

void translate(string s)
{
    // single length string
    if (s.length() == 1)
    {
        print(s);
    }

    // string started with vowel
    else if (chkVowel(s[0]))
    {
        s += "yay";
        print(s);
    }

    // for consonant
    else
    {
        moveCons(s);
    }
}

void print(string s)
{
    cout << s;
    // exit;
}

int main()
{
    string input = "ahello";
    translate(input);

    return 0;
}