class SpecialStack {
  public:
    stack<pair<int, int>> st;
    SpecialStack() {
        // Define Stack
    }

    void push(int x) {
        // Push an element into the stack
        if(st.empty()) {
            st.push({x, x});
        } else {
            int max = x > st.top().second ? x : st.top().second;
            st.push({x, max});
        }
    }

    void pop() {
        // Remove the top element from the Stack
        if(!st.empty()) {
            st.pop();
        }
    }

    int peek() {
        // Returns the top element
        if(st.empty()) {
            return -1;
        }
        return st.top().first;
    }

    bool isEmpty() {
        // Check if stack is empty
        return st.empty();
    }

    int getMax() {
        // Return maximum element of Stack
        if(st.empty()) {
            return -1;
        }
        return st.top().second;
    }
};