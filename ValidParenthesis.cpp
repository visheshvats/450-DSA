#include <bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string expression)
{
    stack<char> st;

    for (int i = 0; i < expression.size(); i++)
    {
        char aa = expression[i];

        if (aa == '{' || aa == '(' || aa == '[')
        {
            st.push(aa);
        }
        else
        {
            if (!st.empty())
            {
                if ((st.top() == '{' && aa == '}') ||
                    (st.top() == '[' && aa == ']') ||
                    (st.top() == '(' && aa == ')'))
                {
                    st.pop();
                }
                else

                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    if(!st.empty())
    {
        return false;
    }

    return true;
}