#include <bits/stdc++.h>
using namespace std;

void print(string res)
{
    for (int i = 0; i < res.size(); i++)
    {
        switch (res[i])
        {
            {
            case '-':
                cout << "Minus "
                     << "\n";
                break;

            case '0':
                cout << "Zer0 "
                     << "\n";
                break;
            case '1':
                cout << "One "
                     << "\n";
                break;
            case '2':
                cout << "Two "
                     << "\n";
                break;
            case '3':
                cout << "Three "
                     << "\n";
                break;

            case '4':
                cout << "Four "
                     << "\n";
                break;
            case '5':
                cout << "Five "
                     << "\n";
                break;
            case '6':
                cout << "Six "
                     << "\n";
                break;
            case '7':
                cout << "Seven "
                     << "\n";
                break;
            case '8':
                cout << "Eight "
                     << "\n";
                break;
            case '9':
                cout << "Nine "
                     << "\n";
            default:
                break;
            }
        }
    }
}

int main()
{
    string num;
    cout << "Enter any less than or equal to three digit number : "
         << "\n";
    cin >> num;
    int res = stoi(num);
    if (res > -1000 && res < 1000)
    {
        print(num);
    }
    else
    {
        cout << "Invalid input"
             << "\n";
    }
    return 0;
}