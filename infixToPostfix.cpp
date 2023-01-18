#include <bits/stdc++.h>
using namespace std;

int precidence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int main()
{
    string input;
    cout << "Enter Input Expression"
         << "\n";
    cin >> input;

    vector<char> res;
    stack<char> stack;

    // string scaning
    for (int i = 0; i < input.length(); i++)
    {
        // for operands
        if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 0 && input[i] <= 9))
        {
            res.push_back(input[i]);
        }

        else if (input[i] == '(')
        {
            stack.push('(');
        }

        else if (input[i] == ')')
        {
            while (stack.top() != '(')
            {
                res.push_back(stack.top());
                stack.pop();
            }
            stack.pop();
        }
        // for operators
        else
        {
            if (!stack.empty())
            {
                while ((precidence(stack.top()) >= precidence(input[i])) && !stack.empty())
                {
                    res.push_back(stack.top());
                    stack.pop();
                }
            }
            stack.push(input[i]);
        }

        // cout << res[i];
    }

    // while (!stack.empty())
    // {
    //     res.push_back(stack.top());
    //     stack.pop();
    // }

    // result printing
    for (auto i : res)
    {
        cout << i;
    }

    return 0;
}