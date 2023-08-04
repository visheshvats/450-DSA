#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<long long int> a;
    long long int getmin=INT_MAX;
    MinStack() {
        
        
    }
    
    void push(long long int val) {
        if(a.empty())
        {
            a.push(val);
            getmin=val;
            return ;
        }
        long long int t=getmin;
        if(t<=val)
        {
            a.push(val);
        }
        else{
            getmin=val;
            a.push(2*val-t);
        }

        
    }
    
    void pop() {
        if(a.top()<getmin)
        {
            long long int t=a.top();
            long long int minn=getmin;
            getmin=2*minn-t;
            a.pop();
        }
        else
        a.pop();
        
    }
    
    int top() {
        if(a.top()>=getmin)
        {
            return a.top();
        }
        else
        return getmin;
        
    }
    
    int getMin() {
        return getmin;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * long long int param_3 = obj->top();
 * long long int param_4 = obj->getMin();
 */