#include <bits/stdc++.h>
using namespace std;

class NStack
{
private:

int *arr;
int *top;
int *next;
int freepointer;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        // Write your code here.

        arr = new int(S);
        top = new int(N);
        next = new int(S);
        for(int i=0;i<N;i++)
        {
            top[i]=-1;
        }

        for(int i=0;i<S;i++)
        {
            next[i]=i+1;
        }

        next[S-1]=-1;

        freepointer = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.
        if(freepointer==-1)
            return false;
        
        int index = freepointer;
        freepointer = next[freepointer];
        arr[index] = x;
        next[index]= top[m-1];
        top[m-1]=index;
        return true;
        
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.
        if(top[m-1]==-1)
            return -1;
        
        int index = top[m-1];
        int res = arr[index];
        top[m-1] = next[index];
        next[index]=freepointer;
        freepointer = index;

        return res;
        
    }
};