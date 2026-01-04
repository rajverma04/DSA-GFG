/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    Node* delPos(Node* head, int x) {
        // code here
        if(head == NULL || x <= 0) {
            return head;
        }
        
        Node *temp = head;
        for (int i = 1; i < x && temp != NULL; i++) {
            temp = temp->next;
        }
        
        if(!temp) {
            return head;
        }
        
        // delete head
        if(!temp->prev) {
            head = temp->next;
            if(head) {
                head->prev = NULL;
            }
            delete temp;
            return head;
        }
        
        if(temp->next) {
            temp->next->prev = temp->prev;
        }
        temp->prev->next = temp->next;
        delete temp;
        
        
        return head;
    }
};