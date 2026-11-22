#include <iostream>
#include <vector>
using namespace std;

class MyHashMap {
private:
    vector<int> data;

public:
    MyHashMap() : data(1000001, -1) {}   // -1 代表這個 key 不存在

    void put(int key, int value) {
        data[key] = value;
    }

    int get(int key) {
        return data[key];
    }

    void remove(int key) {
        data[key] = -1;
    }
};

int main() {
    MyHashMap myHashMap;

    myHashMap.put(1, 1);
    myHashMap.put(2, 2);
    cout << myHashMap.get(1) << endl;   // 1
    cout << myHashMap.get(3) << endl;   // -1
    myHashMap.put(2, 1);
    cout << myHashMap.get(2) << endl;   // 1
    myHashMap.remove(2);
    cout << myHashMap.get(2) << endl;//-1
}