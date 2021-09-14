#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode * res = new ListNode();
        ListNode * temp = res;
        int carry =0;

        while(l1!=0||l2!=0||carry==1)
        {
            int sum =0;
            if(l1!=0)
            {
                sum = sum + (l1->val);
                l1=l1->next;


            }

            if(l2!=0)
            {
                sum = sum + (l2->val);
                l2=l2->next;
                

            }

            if(carry==1)
            {
                sum=sum +1;

            }


            carry = sum/10;
            ListNode * nn = new ListNode(sum%10);
            temp->next=nn;
            temp=temp->next;
            

        }

        return res->next;
    }
};