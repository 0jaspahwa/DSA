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
    void reorderList(ListNode* head) {
        stack<ListNode*> s;

        ListNode* curr = head;
        while(curr){
            s.push(curr);
            curr= curr->next;
        }

        int k = s.size()/2;
        curr = head;

        while(k--){
            ListNode* topNode = s.top();
            s.pop();
            ListNode* temp = curr->next;
            curr->next = topNode;
            topNode->next = temp;
            curr=temp;
        }
        curr->next = NULL;
    }
};