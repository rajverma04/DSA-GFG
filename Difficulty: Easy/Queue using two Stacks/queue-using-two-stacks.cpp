/* The structure of the class is
class StackQueue{
private:
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */
void StackQueue::push(int B) {
    s1.push(B);
    
}

int StackQueue::pop() {
    if(s1.empty() && s2.empty()) {
        return -1;
    }
    
    if(s2.size()) {
        int data = s2.top();
        s2.pop();
        return data;
    }
    
    while(s1.size()) {
        s2.push(s1.top());
        s1.pop();
    }
    
    int data = s2.top();
    s2.pop();
    return data;
}