#include <iostream>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;
class Solution {
   public:
   int calculate(string s) {
        int res = 0, i = 0, n = s.length(), flag = 1, op = 0;
        // flag is the sign of each operand, 1 as default value
        stack<int> outer_flag;
        outer_flag.emplace(1);
        // outer_flag stores the signs of each pair of brackets, 1 as default value
        while(i < n) {
            char c = s[i++];
            if(c != ' ') {
                if(isdigit(c)) {
                    op *= 10;
                    op += c - '0';
                } else if(c == '+') {
                    res += flag == outer_flag.top() ? op : -op;
                    flag = 1;
                    op = 0;
                } else if(c == '-') {
                    res += flag == outer_flag.top() ? op : -op;
                    flag = -1;
                    op = 0;
                } else if(c == '(') {
                    outer_flag.emplace(flag == outer_flag.top() ? 1 : -1);
                    flag = 1;
                } else {
                    res += flag == outer_flag.top() ? op : -op;
                    op = 0;
                    flag = 1;
                    outer_flag.pop();
                }
            }
        }
        res += flag == outer_flag.top() ? op : -op;
        return res;
    }
};
main(){
   Solution ob;
   string t;
   cin>>t;
   remove(t.begin(), t.end(), ' ');
   cout << (ob.calculate(t));
}