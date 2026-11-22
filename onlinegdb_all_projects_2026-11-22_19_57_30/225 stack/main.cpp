#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q1; // 主佇列，front 即為堆疊頂端
    queue<int> q2; // 輔助佇列

public:
    MyStack() {}
    //queue只能取首元素先進先出,所以將順序互換才會變成後進先出的stack
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }

    int top() {//後進的放在q1的首元素
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    // 對應題目的 Example 1
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    cout << "top: " << myStack.top() << endl;                  // 2
    cout << "pop: " << myStack.pop() << endl;                  // 2
    cout << "empty: " << (myStack.empty() ? "true" : "false")  // false
         << endl;

    // // 額外測試：清空堆疊並依序彈出
    // myStack.push(3);
    // myStack.push(4);
    // cout << "\n依序彈出: ";
    // while (!myStack.empty()) {
    //     cout << myStack.pop() << " ";                          // 4 3 1
    // }
    // cout << endl;
    // cout << "empty: " << (myStack.empty() ? "true" : "false")  // true
    //      << endl;

    return 0;
}