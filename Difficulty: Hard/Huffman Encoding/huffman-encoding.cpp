class Solution {
  public:
    class Node {
        public:
            int freq;
            Node *left, *right;
            
            Node(int count) {
                freq = count;
                left = right = NULL;
            }
    };
    
    class compare {
        public: 
            bool operator()(Node *a, Node *b) {
                return a->freq > b->freq;       // minHeap
                
                // return a->freq < b->freq;       // maxHeap
            }
    };
    
    void preOrder(Node *root, string s, vector<string> &huff) {
        if(!root) {
            return;
        }
        
        if(!root->left && !root->right) {
            huff.push_back(s);
            return;
        }
        
        preOrder(root->left, s + "0", huff);
        preOrder(root->right, s + "1", huff);
    }
    
    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        
        // create minHeap
        priority_queue<Node*, vector<Node*>, compare> q;
        
        for(int i = 0; i < N; i++) {
            Node *ans = new Node(f[i]);
            q.push(ans);
        }
        
        Node *root;
        Node *min1, *min2;
        while(q.size() > 1) {
            min1 = q.top();
            q.pop();
            min2 = q.top();
            q.pop();
            
            root = new Node(min1->freq + min2->freq);
            root->left = min1;
            root->right = min2;
            
            q.push(root);
        }
        
        root = q.top();
        vector<string> huff;
        
        preOrder(root, "", huff);
        
        
        return huff;
    }
};