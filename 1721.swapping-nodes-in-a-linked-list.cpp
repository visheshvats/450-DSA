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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* slow=head;
        ListNode* fast=head;
        int step=k;
        while(--step)
        {
            fast=fast->next;
        }
        ListNode * first = fast;
        while(fast->next)
        {
            slow=slow->next;
            fast=fast->next;

        }
        ListNode* last=slow;


        swap(first->val, last->val);

        return head;

        
    }
};
// @lc code=end

