/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        Node *temp = new Node(0);
        Node *current = temp;   // storing the pointer of temp node
        
        while(head1 && head2) {
            if(head1->data == head2->data) {
                current->next = new Node(head1->data);
                head1 = head1->next;
                head2 = head2->next;
                current = current->next;
            } else if(head1->data < head2->data) {
                head1 = head1->next;
            } else {
                head2 = head2->next;
            }
        }
        
        return temp->next;      // since first node is 0 so returning next node
        
    }
};