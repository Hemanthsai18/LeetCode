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
    int getSize(ListNode* head){
        int size = 0;
        while(head!=NULL){
            size++;
            head = head->next;
        }
        return size;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int n= getSize(head);
        if(k==0 || head == NULL || k%n == 0) return head;
        int req = n - (k%n);

        cout<<req<<" "<<n;
        ListNode* temp = head;
        ListNode* firstHead = head;
        for(int i=0;i<req-1;i++){
            temp = temp->next;
        }
        head = temp->next;
        temp->next = NULL;
        temp = head;
        while(temp!=NULL && temp->next!=NULL){
            temp =temp->next;
        }
        temp->next = firstHead;
        return head;
    }
};