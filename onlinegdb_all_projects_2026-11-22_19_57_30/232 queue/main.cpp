#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> in;   // 接收新元素
    stack<int> out;  // 以先進先出的順序存放元素

    void transfer() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());//top是in的末端元素
                in.pop();
            }
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        in.push(x);
    }

    int pop() {
        transfer();
        int front = out.top();
        out.pop();
        return front;
    }

    int peek() {//看in首元素=out末元素
        transfer();
        return out.top();
    }

    bool empty() {
        return in.empty() && out.empty();
    }
};

int main() {
    MyQueue myQueue;

    myQueue.push(1);  // queue: [1]
    myQueue.push(2);  // queue: [1, 2]
    //out=[2,1]
    cout << "peek:  " << myQueue.peek() << endl;                  // 1
    cout << "pop:   " << myQueue.pop() << endl;                   // 1
    cout << "empty: " << (myQueue.empty() ? "true" : "false") << endl;  // false

    return 0;
}