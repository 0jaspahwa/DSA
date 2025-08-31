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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || head->next == NULL) return head;

        ListNode* temp=head;
        int size =0;
        while(temp != NULL){
            size++;
            temp = temp->next;
        }
        k = k%size;
        temp = head;

        for(int i=0; i<k; i++){
            ListNode* tail = temp,*pretail;
            while(tail->next != NULL){
                pretail = tail;
                tail = tail->next;
            }
            tail->next = temp;
            temp = tail;
            pretail->next =NULL;
        }
        return temp;
    }
};