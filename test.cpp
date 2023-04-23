#include <bits/stdc++.h>
using std::cout, std::cin, std::endl, std::pair;
using std::vector, std::string, std::set, std::map;

class production
{

public:
    char lhs;
    vector<string> rhs;

    vector<production> productions;
    map<char, set<char>> firstSet;
    map<char, set<char>> followSet;
    vector<bool> visited = {false};

    void productionRules()
    {
        productions.push_back({'E', {"E+T", "T"}}); // E->+T|T
        productions.push_back({'T', {"F*F", "F"}}); // T->*F|F
        productions.push_back({'F', {"(E)", "i"}}); // F->(E)|i
    }

    void display()
    {
        for (auto production : productions)
        {
            cout << production.lhs << "->";
            for (auto rhs : production.rhs)
            {
                if (rhs != production.rhs.back())
                {
                    cout << rhs << "|";
                }
                else
                {
                    cout << rhs;
                }
            }
            cout << endl;
        }
    }

    bool isNonTerminal(char symbol)
    {
        if (symbol >= 'A' && symbol <= 'Z')
            return true;

        return false;
    }

    void first()
    {
        for (int i = 0; i < productions.size(); i++)
        {
            char temp;
            for (int j = 0; j < productions[i].rhs.size(); j++)
            {
                if (!isNonTerminal(productions[i].rhs[j][0]))
                {
                    firstSet[productions[i].lhs].insert(productions[i].rhs[j][0]);
                    
                }

                else if (isNonTerminal(productions[i].rhs[j][0]) && visited[i])
                {
                    // temp = productions[i].rhs[j][0];
                    firstSet[productions[i].lhs].insert(firstSet[temp].begin(), firstSet[temp].end());
                }
                else
                {
                    temp = productions[i].rhs[j][0];
                }
            }
        }
    }

    void print(map<char, set<char>> &m)
    {
        cout << "First Set" << endl;
        for (auto i : m)
        {
            cout << i.first << "-> {";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << "}" << endl;
        }
    }
};

int main()
{
    production pr;
    pr.productionRules();
    pr.display();
    pr.first();
    // pr.print(pr.firstSet);
    return 0;
}