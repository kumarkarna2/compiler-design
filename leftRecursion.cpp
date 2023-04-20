#include <bits/stdc++.h>
using std::cout, std::cin, std::endl;
using std::string, std::vector, std::set;

struct production
{
    string lhs;
    string rhs;

    bool operator<(const production &other) const
    {
        if (lhs != other.lhs)
        {
            return lhs < other.lhs;
        }
        else
        {
            return rhs < other.rhs;
        }
    }
};
set<production> newProductions;
vector<production> productions;
// vector<production> newProductions;

class Grammer
{
public:
    void split_string(string input)
    {
        string str = "";
        for (int i = 3; i <= input.size(); i++)
        {
            if (input[i] == '|' || i == input.size())
            {
                production prod;
                prod.lhs = input[0];
                prod.rhs = str;
                productions.push_back(prod);
                str = "";
            }
            else
            {
                str += input[i];
            }
        }
    }

    void productionRules()
    {
        string input = "E->E+T|T|E-T";
        split_string(input);
    }

    void removeLeftRecursion()
    {
        string str = "";
        string temp = "";

        for (auto production : productions)
        {

            if (production.lhs[0] == production.rhs[0])
            {
                for (int i = 1; i < production.rhs.size(); i++)
                {
                    str += production.rhs[i];
                }
                str += production.lhs;
                str += "'";
                production.lhs += "'";
                newProductions.insert({production.lhs, str});
                newProductions.insert({production.lhs, "e"});
            }
            else
            {
                for (int i = 0; i < production.rhs.size(); i++)
                {
                    temp += production.rhs[i];
                }
                temp += production.lhs;
                temp += "'";
                newProductions.insert({production.lhs, temp});
            }

            str = "";
            temp = "";
        }
    }
};

int main()
{
    Grammer grammer;
    grammer.productionRules();
    cout << "Original Productions: \n";
    for (auto production : productions)
    {
        cout << production.lhs << " -> ";
        for (auto symbol : production.rhs)
        {
            cout << symbol;
        }
        cout << endl;
    }

    // LeftRecursion lr;
    grammer.removeLeftRecursion();
    cout << "\n\nNew Productions: \n";
    for (auto production : newProductions)
    {
        cout << production.lhs << " -> ";
        for (auto symbol : production.rhs)
        {
            cout << symbol;
        }
        cout << endl;
    }
    return 0;
}