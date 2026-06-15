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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* t= head;int n=0;
        while(t!=NULL){
            n++;
            t=t->next;
        }
        t=head;
        for(int i=0;i<((n/2)-1);i++){
            t=t->next;
        }
        if(t->next == NULL) return NULL;
        t->next= t->next->next;
        return head;
    }
};