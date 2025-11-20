class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        // M1
    
    //     vector<long long> ans(n, -1);        // here -1 is initialize in each index of vector
    //     // time complexcity = O(n^2)
    //     for(int i = 0; i < n; i++) {
    //         for(int j = i + 1; j < n; j++) {
    //             if(arr[j] > arr[i]) {
    //                 ans[i] = arr[j];
    //                 break;
    //             }
    //         }
    //     }
    //         return ans;
    // }
    
    
    // M2 using stack, time complexcity = O(n) 
    // && if any problem is asking next or prev greater or smaller elem. then can use stack
    stack<int> st;
    vector<int> ans(n, -1);
    for(int i = 0; i < n; i++) {
        while(!st.empty() && arr[st.top()] < arr[i]) {  // if curr ele is greater than for the ele. who do not get their next greater
            // Current element arr[i] is the next greater element
            // for the element at index st.top()    
            ans[st.top()] = arr[i];         
            st.pop();   // Remove that index from stack since we found its answer
        }
        st.push(i);     // store index of array who do no get their greater ele.
    }
    return ans;
    }
};