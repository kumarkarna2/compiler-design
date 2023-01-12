#include <bits/stdc++.h>
using namespace std;

void print(vector<int> res)
{
    for (int i = res.size(); i >= 0; i--)
    {
        switch (res[i])
        {
        case 1:
            cout << "One "
                 << "\n";
            break;

        case 2:
            cout << "Two "
                 << "\n";
            break;

        case 3:
            cout << "Three "
                 << "\n";
            break;

        case 4:
            cout << "Four "
                 << "\n";
            break;

        case 5:
            cout << "Five "
                 << "\n";
            break;

        case 6:
            cout << "Six "
                 << "\n";
            break;

        case 7:
            cout << "Seven "
                 << "\n";
            break;

        case 8:
            cout << "Eight "
                 << "\n";
            break;

        case 9:
            cout << "Nine "
                 << "\n";
            break;
        case 0:
            cout << "Zer0"
                 << "\n";
            break;

        default:
            break;
        }
    }
}

int main()
{

    int num;
    cout << "Enter any less than or equal to three digit number : "
         << "\n";
    cin >> num;
    vector<int> res;
    if (num / 1000 == 0)
    {
        for (int i = 0; i < 3; i++)
        {

            if (num >= 10)
            {
                res.push_back(num % 10);
                num /= 10;
            }
            else
            {
                res.push_back(num);
                num = 0;
                break;
            }
        }
        print(res);
    }
    return 0;
}