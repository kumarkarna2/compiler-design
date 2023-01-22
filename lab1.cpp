#include <bits/stdc++.h>
using namespace std;

void print(string res)
{
    for (int i = 0; i < res.size(); i++)
    {
        switch (res[i])
        {
        case '-':
            cout << "Minus ";
            break;

        case '0':
            cout << "Zer0 ";
            break;
        case '1':
            cout << "One ";
            break;
        case '2':
            cout << "Two ";
            break;
        case '3':
            cout << "Three ";
            break;

        case '4':
            cout << "Four ";
            break;
        case '5':
            cout << "Five ";
            break;
        case '6':
            cout << "Six ";
            break;
        case '7':
            cout << "Seven ";
            break;
        case '8':
            cout << "Eight ";
            break;
        case '9':
            cout << "Nine ";
        default:
            break;
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