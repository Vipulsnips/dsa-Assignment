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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int ind=1;vector<int> crit;
        int prev=head->val;
        head=head->next;
        while(head->next){
            if(head->val > (head->next->val) && head->val > prev){
                crit.push_back(ind);
            }
            if(head->val < (head->next->val) && head->val < prev){
                crit.push_back(ind);
            }
            ind++;
            prev=head->val;
            head=head->next;
        }
        if(crit.size()<2) return {-1,-1};
        int minm=INT_MAX;
        for(int i=1;i<crit.size();i++) minm=min(minm,crit[i]-crit[i-1]);
        return {minm,crit[crit.size()-1]-crit[0]};
    }
};