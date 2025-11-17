/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        // Your Code Here
        int count1 = 0, count2 = 0;
        Node *temp1 = head1;
        Node *temp2 = head2;
        while(temp1) {
            count1++;
            temp1 = temp1->next;
        }
        while(temp2) {
            count2++;
            temp2 = temp2->next;
        }
        
        temp1 = head1;
        temp2 = head2;
        if(count1 > count2) {
            int extraNode = count1 - count2;
            while(extraNode != 0) {
                temp1 = temp1->next;
                extraNode--;
            }
        }
        
        if(count2 > count1) {
            int extraNode = count2 - count1;
            while(extraNode != 0) {
                temp2 = temp2->next;
                extraNode--;
            }
        }
        
        
        while((temp1 != temp2) && temp1 && temp2) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        if(temp1 && temp2) {
            return temp1;
        }
        
        return nullptr;
    }
};
