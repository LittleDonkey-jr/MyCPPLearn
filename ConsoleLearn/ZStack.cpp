#include "ZStack.h"

bool Solution::bracket_Is_Valid(std::string s) {
    std::stack<char> brack;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            brack.push(s[i]);
        }
        else {
            if (brack.empty())
            {
                return false;
            }
            else if (s[i] == ')')
            {
                if (brack.top() == '(')
                {
                    brack.pop();
                }
                else
                {
                    return false;
                }
            }
            else if (s[i] == ']')
            {
                if (brack.top() == '[')
                {
                    brack.pop();
                }
                else
                {
                    return false;
                }
            }
            else if (s[i] == '}')
            {
                if (brack.top() == '{')
                {
                    brack.pop();
                }
                else
                {
                    return false;
                }
            }
        }

    }
    if (!brack.empty())
    {
        return false;
    }
    else
    {
        return true;
    }
}


void TestSheet::Test_bracket_Is_Valid(std::string s)
{
    if (Solution::bracket_Is_Valid(s))
    {
        std::cout << "bracket is valid!\n";
    }
    else
    {
        std::cout << "bracket is not valid!\n";
    }
}