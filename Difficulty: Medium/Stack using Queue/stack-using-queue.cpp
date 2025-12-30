class myStack {
    queue<int> q;

  public:

    void push(int x) {
        q.push(x);
        int sz = q.size();

        // rotate queue
        for (int i = 1; i < sz; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (!q.empty())
            q.pop();
    }

    int top() {
        if (q.empty()) return -1;
        return q.front();
    }

    int size() {
        return q.size();
    }
};
