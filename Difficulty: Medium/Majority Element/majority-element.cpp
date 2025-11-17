class Solution {
  public:
    int majorityElement(vector<int>& arr) {
      
        unordered_map<int, int> m;
        
        for(int i = 0; i < arr.size(); i++){
            m[arr[i]]++;
        }
        
        int k = arr.size() / 2;
        
        for(auto i = m.begin(); i != m.end(); i++) {
            if(i->second > k){
                return i->first;
            }
        }
        return -1;
    }
};



