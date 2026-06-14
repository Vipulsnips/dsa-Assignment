/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        int n=0;
        ListNode * t=head;
        while(t!=NULL){
            n++;
            t=t->next;
        }
        vector<int> ans(n/2,0);
        t=head;
        for(int i=0;i<(n/2);i++){
            ans[i]+=t->val;
            t=t->next;
        }
        for(int i=(n/2);i<n;i++){
            ans[(n-i)-1]+=t->val;
            t=t->next;
        }
        return *max_element(ans.begin(),ans.end());
    }
};