/*
class Node {
   public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
} */

class Solution {
  public:
    bool detectLoop(Node* head) {
        unordered_map<Node*, int> mp;
        Node *temp = head;
        while(temp) {
            if(mp.count(temp)) {
                return true;
            }
            mp[temp] = 1;
            temp = temp->next;
        }
        
        return false;
        
    }
};