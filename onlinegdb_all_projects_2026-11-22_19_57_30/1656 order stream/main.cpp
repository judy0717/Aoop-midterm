#include <iostream>
#include <string>
#include <vector>
using namespace std;

class OrderedStream {
private:
    vector<string> data;
    int ptr; // 指向下一個要輸出的位置（0-indexed）

public:
    OrderedStream(int n) : data(n), ptr(0) {}

     vector<string> insert(int idKey, string value) {
        data[idKey - 1] = value;

        vector<string> result;
        while (ptr < (int)data.size() && !data[ptr].empty()) {
            result.push_back(data[ptr]);
            ptr++;
        }
        return result;
    }
};

// 輔助函式：印出一個 chunk，例如 ["bbbbb", "ccccc"]
void printChunk(const vector<string>& chunk) {
    cout << "[";
    for (size_t i = 0; i < chunk.size(); i++) {
        cout << "\"" << chunk[i] << "\"";
        if (i + 1 < chunk.size()) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    // 題目範例
    OrderedStream os(5);

    cout << "insert(3, \"ccccc\") -> ";
    printChunk(os.insert(3, "ccccc")); // []

    cout << "insert(1, \"aaaaa\") -> ";
    printChunk(os.insert(1, "aaaaa")); // ["aaaaa"]

    cout << "insert(2, \"bbbbb\") -> ";
    printChunk(os.insert(2, "bbbbb")); // ["bbbbb", "ccccc"]

    cout << "insert(5, \"eeeee\") -> ";
    printChunk(os.insert(5, "eeeee")); // []

    cout << "insert(4, \"ddddd\") -> ";
    printChunk(os.insert(4, "ddddd")); // ["ddddd", "eeeee"]

    return 0;
}