#include<bits/stdc++.h>
using namespace std;


  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head==NULL)
            return NULL;
        int t=0;
        ListNode* tmp = head;

        while(tmp!=NULL)
        {
            t++;
            tmp=tmp->next;
        }
        if(t<k)
        {
            return head;
        }

        int count =0;
        ListNode * cur=head;
        ListNode* prev=NULL;
        ListNode* next=head;
        
        while(cur!=NULL&&count<k)
        {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
            count++;

        }

        if(next!=NULL)
        {
            head->next = reverseKGroup(next, k);
        }

        return prev;
    }
};