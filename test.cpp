#include <bits/stdc++.h>
using namespace std;

int dfa(string s)
{
    if (s.length() == 1)
    {
        if (s[0] == 'a' || s[0] == 'b')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (s.length() > 1)
    {
        if (s[0] == 'a')
        {
            int count_a = 0, count_b = 0;
            int size = s.length();
            for (int i = 0; i < size; i++)
            {
                if (s[i] == 'a' || s[i] == 'b')
                {

                    if (s[i] == 'a')
                    {
                        count_a++;
                    }

                    else if (s[i] == 'b')
                    {
                        count_b++;
                        if (count_b > 1)
                        {
                            return 0;
                        }
                    }
                }
                else
                {
                    return 0;
                }
            }
            if (count_a % 2 == 0)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    string s = "ab";
    if (dfa(s))
    {
        cout << "Accepted"
             << "\n";
    }
    else
        cout << "Rejected"
             << "\n";
    return 0;
}