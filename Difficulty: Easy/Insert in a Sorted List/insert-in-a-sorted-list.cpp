/*
structure of the node of the list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    // Should return head of the modified linked list
    Node* sortedInsert(Node* head, int key) {
        
        if(key < head->data) {      // insertion at begining
            Node *temp = new Node(key);
            temp->next = head;
            head = temp;
            return head;
        }
        
        Node *first = head;
        
        while((first->next) && (first->next->data < key)) {     // first->next: exist && its data < key
            first = first->next;
        }
        
        Node *temp = new Node(key);
        temp->next = first->next;
        first->next = temp;
        
        return head;
    }
};