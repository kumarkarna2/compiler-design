#include <bits/stdc++.h>
using namespace std;

int precidence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void toPostfix(string input)
{
    stack<char> stack;
    string output;
    for (int i = 0; i < input.length(); i++)
    {
        if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || input[i] >= 0 && input[i] <= 9)
        {
            output += input[i];
        }
        else if (input[i] == '(')
        {
            stack.push(input[i]);
        }
        else if (input[i] == ')')
        {
            while (stack.top() != '(')
            {
                output += stack.top();
                stack.pop();
            }
            // if (!stack.empty())
            stack.pop();
        }
        else
        {
            if (!stack.empty())
            {
                while (precidence(input[i]) <= precidence(stack.top()))
                {
                    output += stack.top();
                    stack.pop();
                }
                stack.push(input[i]);
            }
        }
    }
    cout << output;
}

int main()
{
    string input = "((a+b)*(c/d)^e)+f";
    toPostfix(input);

    return 0;
}