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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = NULL;
        ListNode* more = NULL;
        ListNode* lessPointer = NULL;
        ListNode* morePointer = NULL;
        while(head!=NULL){
            if(head->val>=x){
                if(more==NULL){
                    more = head;
                    morePointer = more;
                }
                else{
                    more->next = head;
                    more = more->next;
                }
            }
            else{
                if(less==NULL){
                    less = head;
                    lessPointer = less;
                }
                else{
                    less->next = head;
                    less = less->next;
                }
            }
            head = head->next;
        }
        if(lessPointer == NULL)
        return morePointer;
        less->next = morePointer;
        if(more!=NULL)
        more->next = NULL;
        return lessPointer;
    }
};