#include <bits/stdc++.h>
using std::cout, std::cin, std::endl;
using std::string, std::vector, std::set;

class production
{
public:
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

class Grammer
{
public:
    set<production> newProductions;
    set<production> productions;

    void split_string(string input)
    {
        string str = "";
        for (int i = 3; i <= input.size(); i++)
        {
            if (input[i] == ' ')
            {
                continue;
            }
            else if (input[i] == '|' || i == input.size())
            {
                production prod;
                prod.lhs = input[0];
                prod.rhs = str;
                if (str != "")
                {
                    productions.insert(prod);
                    str = "";
                }
            }
            else
            {
                str += input[i];
            }
        }
    }

    void productionRules()
    {
        string input = "E->E + T|T|E-T|";
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

    void display(set<production> productions)
    {
        for (auto production : productions)
        {
            cout << production.lhs << " -> ";
            for (auto symbol : production.rhs)
            {
                cout << symbol;
            }
            cout << endl;
        }
    }

    bool isLeftRecursive()
    {
        for (auto production : productions)
        {
            if (production.lhs[0] == production.rhs[0])
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Grammer grammer;

    grammer.productionRules();
    cout << "Original Productions: \n";
    grammer.display(grammer.productions);

    bool isLeftRecursive = grammer.isLeftRecursive();

    if (isLeftRecursive)
    {
        grammer.removeLeftRecursion();
        cout << "\nNew Productions: \n";
        grammer.display(grammer.newProductions);
    }
    else
    {
        cout << "Grammer is not left recursive\n";
        grammer.display(grammer.productions);
    }

    return 0;
}