#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class KthLargest {
    int k;
    //greater代表最大的元素優先權最大,priorityqueue會自動依照規則排列
    priority_queue<int, vector<int>, greater<int>> minHeap; // 最多維持 k 個元素

public:
    //nums是原始數列
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int n : nums) {
            add(n);
        }
    }
    //input的每個元素呼叫add
    int add(int val) {
        if ((int)minHeap.size() < k) {//還沒滿都加進去\
            minHeap.push(val);
        } else if (val > minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        }
        return minHeap.top();
    }
};

int main() {
    // 範例 1
    {
        vector<int> nums = {4, 5, 8, 2};
        KthLargest kth(3, nums);
        vector<int> inputs = {3, 5, 10, 9, 4};

        cout << "範例 1: ";
        for (int v : inputs) {
            cout << kth.add(v) << " ";
        }
        cout << endl; // 預期: 4 5 5 8 8
    }

    // 範例 2
    {
        vector<int> nums = {7, 7, 7, 7, 8, 3};
        KthLargest kth(4, nums);
        vector<int> inputs = {2, 10, 9, 9};

        cout << "範例 2: ";
        for (int v : inputs) {
            cout << kth.add(v) << " ";
        }
        cout << endl; // 預期: 7 7 7 8
    }

    return 0;
}