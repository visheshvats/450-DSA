#include<bits/stdc++.h>
using namespace std;

int getPrecedence(char a)
{
    if(a=='^')
        return 3;
    if(a=='+'||a=='-')
        return 1;
    if(a=='*'||a=='/')
        return 2;
    
    return -1;
}

string infixToPostfix(string exp){
    int n=exp.size();
    stack<char> op;
    string ans;

    for(int i=0;i<n;i++)
    {
        char temp = exp[i];
        if(temp=='(')
            op.push(temp);
        else if(temp>='a'&&temp<='z')
            ans.push_back(temp);
        else if(temp==')')
        {
            while(op.top()=='(')
            {
                char t= op.top();
                op.pop();
                ans.push_back(t);
            }
        }
        else
        {
            int p =getPrecedence(temp);
            if(getPrecedence(op.top())<=p)
            {
                op.push(temp);
            }
            else
            {
                while(getPrecedence(op.top())>p)
                {
                    char t = op.top();
                    op.pop();
                    ans.push_back(t);
                }

                op.push(temp);
            }
        }

    }

    while(!op.empty())
    {
        char t =op.top();
        op.pop();
        ans.push_back(t);
    }

    return ans;
	
}