class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;

        // create the newNode and places it between
        while(temp) {
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;

            temp = temp->next->next;
        }

        // connect the random poineters
        temp = head;
        while(temp) {
            if(temp->random == NULL) temp->next->random = NULL;
            else temp->next->random = temp->random->next;
            temp = temp->next->next;
        }

        // connecting the next pointers
        Node* dummy = new Node(0);
        Node* newHead = dummy;
        temp = head; 
        while(temp) {
            dummy->next = temp->next;
            dummy = dummy->next;
            temp->next = dummy->next;
            temp = temp->next;
        }

        return newHead->next;
    }
};