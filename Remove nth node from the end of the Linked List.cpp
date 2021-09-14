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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode * s = new ListNode();
        s->next=head;
        ListNode* fast =s;
        ListNode* slow =s;
        
        for(int i=0;i<n;i++)
        {
            fast=fast->next;

        }

        while(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;

        }
        ListNode * tmp= slow->next;

        slow->next=slow->next->next;

        delete tmp;

        return s->next;
        
    }
};