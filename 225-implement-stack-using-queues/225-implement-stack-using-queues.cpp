class MyStack {
public:
    queue<int>a;
        queue<int>b;
        int peek;
    MyStack() {
        
    }
    
    void push(int x) {
        a.push(x);
        peek=x;
    }
    
    int pop() {
        int temp=a.back();
        while(a.size()>1)
        {
            peek=a.front();
            a.pop();
            b.push(peek);
        }
        a.pop();
        a=b;
        while(!b.empty())
        {
            b.pop();
        }
        return temp;
    }
    
    int top() {
        while(a.size()>1)
        {
             peek=a.front();
            a.pop();
            b.push(peek);
        }
        int temp=a.front();
        b.push(a.front());
        a=b;
        while(!b.empty())
        {
            b.pop();
        }
        return temp;
    }
    
    bool empty() {
        return a.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */