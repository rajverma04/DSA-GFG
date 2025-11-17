/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};
*/

class Solution {
  public:
    bool isPalindrome(Node *head) {
        //  code here
        vector<int> arr;
        
        Node *temp = head;
        while(temp) {
            arr.push_back(temp->data);
            temp = temp->next;
        }
        
        int size = arr.size() - 1;
        
        int left = 0, right = size;
        while(left < right) {
            if(arr[left] != arr[right]) {
                return false;
            }
            left++, right--;
        }
        
        return true;
    }
};