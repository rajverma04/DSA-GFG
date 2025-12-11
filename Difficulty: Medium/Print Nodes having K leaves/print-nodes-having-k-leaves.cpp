/*The Node is defined as follows:
struct Node
{
    int data ;
    struct Node * left, * right ;
};
*/

class Solution {
  public:
    /*You are required to complete below method */
    int leafNode(Node *ptr, vector<int> &ans, int k) {
        if(!ptr) {
            return 0;
        }
        
        if(!ptr->left && !ptr->right) {
            return 1;
        }
        
        int left = leafNode(ptr->left, ans, k);
        int right = leafNode(ptr->right, ans, k);
        
        int totalLeaves = left + right;
        if(totalLeaves == k) {
            ans.push_back(ptr->data);
        }
        
        return totalLeaves;
    }
    
    
    vector<int> btWithKleaves(Node *ptr, int k) {
        vector<int> ans;
        
        leafNode(ptr, ans, k);
        if(ans.empty()) {
            return {-1};
        }
        
        return ans;
    }
};