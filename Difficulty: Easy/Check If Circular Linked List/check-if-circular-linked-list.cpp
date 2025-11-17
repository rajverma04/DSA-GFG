/* Link list Node
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

/* Should return true if linked list is circular, else false */
class Solution {
  public:
    bool isCircular(Node *head) {
        // Your code here
        Node *temp = head;
        
        while(temp) {
            if(temp->next == NULL) {
                return false;
            }
            if(temp->next == head) {
                break;
            }
            temp = temp->next;
        }
        
        return true;
    }
};