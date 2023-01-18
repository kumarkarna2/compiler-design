#include <bits/stdc++.h>
using namespace std;

int main()
{
    string input = "aa";
    if (input.length() == 1)
    {
        if (input[0] == 'a' || input[0] == 'b')
        {
            cout << "Accepted"
                 << "\n";
        }
        else
        {
            cout << "Rejected"
                 << "\n";
        }
    }

    else
    {
        if (input[0] != 'a')
        {
            cout << "Rejected"
                 << "\n";
        }
        else
        {
            int i = 0;
            while (input[i] = 'a')
            {
                i++;
            }
            cout << i << "\n";
            // if (i % 2 == 0)
            // {
            //     int temp = input.length() - 1;
            //     cout << temp << "\n";
            //     if (input[temp] = 'b')
            //     {
            //         return 1;
            //     }
            //     else
            //     {
            //         cout << "Rejected"
            //              << "\n";
            //     }
            // }
            // else
            // {
            //     cout << "Rejected"
            //          << "\n";
            // }
        }
    }

    return 0;
}