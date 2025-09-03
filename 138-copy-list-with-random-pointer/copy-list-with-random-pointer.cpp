/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;

        //inserting new nodes in between the org linked lsit
        Node* curr = head;
        while(curr){
            Node* CurrNext = curr->next; // B
            curr->next = new Node(curr->val); // A -> X
            curr->next->next = CurrNext; // A-> X -> B
            curr = CurrNext; // curr = B
        }

        // deep copy

        curr = head;
        while(curr && curr->next){
            if(curr->random == NULL){
                curr->next->random = NULL;
            }
            else{
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;

        }

        // seperate
        Node* newHead = head->next;
        Node* Newcurr = newHead;
        curr = head;

        while(curr && Newcurr){
            curr->next = curr->next == NULL ? NULL : curr->next->next;
            Newcurr->next = Newcurr->next == NULL ? NULL : Newcurr->next->next;

            curr = curr->next;
            Newcurr = Newcurr->next;
        }
        return newHead;
    }
};