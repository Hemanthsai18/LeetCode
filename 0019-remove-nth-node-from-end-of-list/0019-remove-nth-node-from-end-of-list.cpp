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
    int size(ListNode* head){
        int i=0;
        while(head){
            head= head->next;
            i++;
        }
        return i;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = size(head);
        n = len - n;
        ListNode* temp = head;
        for(int i=0;i<n-1;i++){
            temp = temp->next;
        }
        if(n!=0)
        temp->next = temp->next->next;
        else head = temp->next;
        return head;
    }
};