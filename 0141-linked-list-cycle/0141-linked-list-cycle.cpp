/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* r = head;
        ListNode* t = head;
        while(r && t && t->next){
            r = r->next;
            t = t->next->next;
            if (r==t)
            return true;
        }
        return false;
    }
};