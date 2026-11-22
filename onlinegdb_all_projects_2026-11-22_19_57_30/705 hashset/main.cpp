#include <iostream>
#include <vector>
using namespace std;

class MyHashSet {
private:
    vector<int> data;

public:
    MyHashSet() {}

    void add(int key) {
        for (int x : data)
            if (x == key) return;   // 已存在就不重複加入
        data.push_back(key);
    }

    void remove(int key) {
        for (size_t i = 0; i < data.size(); ++i) {
            if (data[i] == key) {
                data[i] = data.back();  // 用最後一個元素覆蓋，再 pop
                data.pop_back();
                return;
            }
        }
    }

    bool contains(int key) {
        for (int x : data)
            if (x == key) return true;
        return false;
    }
};

int main() {
    MyHashSet myHashSet;

    myHashSet.add(1);                                        // set = [1]
    myHashSet.add(2);                                        // set = [1, 2]
    cout << boolalpha;                                       // 讓 bool 印成 true/false
    cout << myHashSet.contains(1) << endl;                   // true
    cout << myHashSet.contains(3) << endl;                   // false
    myHashSet.add(2);                                        // set = [1, 2]
    cout << myHashSet.contains(2) << endl;                   // true
    myHashSet.remove(2);                                     // set = [1]
    cout << myHashSet.contains(2) << endl;                   // false

    return 0;
}