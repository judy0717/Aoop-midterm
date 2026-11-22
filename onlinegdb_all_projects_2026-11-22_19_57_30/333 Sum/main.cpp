#include <iostream>
#include <vector>
using namespace std;

class NumArray {
private:
    vector<int> prefix;

public:
    NumArray(vector<int>& nums) {
        prefix.assign(nums.size() + 1, 0);//prefix存到目前的和,[0]=0避免往前一格是-1的情況
        for (size_t i = 0; i < nums.size(); ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);

    cout << numArray.sumRange(0, 2) << endl;  // 1
    cout << numArray.sumRange(2, 5) << endl;  // -1
    cout << numArray.sumRange(0, 5) << endl;  // -3

    return 0;
}