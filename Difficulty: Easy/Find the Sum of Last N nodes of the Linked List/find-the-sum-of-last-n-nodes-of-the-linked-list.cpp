class Solution {
  public:
    /*Structure of the node of the linled list is as

    struct Node {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }
    };
    */
    // your task is to complete this function
    // function should return sum of last n nodes
    int sumOfLastN_Nodes(struct Node* head, int n) {
        // Code here
        Node *temp = head;
        int countNodes = 0;
        while(temp) {
            temp = temp->next;
            countNodes++;
        }
        
        
        int sum = 0;
        temp = head;
        int skipNode = countNodes - n;
        
        while(temp) {
            if(skipNode != 0) {
                temp = temp->next;
                skipNode--;
                continue;
            }
            sum += temp->data;
            temp = temp->next;
        }
        
        return sum;
    }
};