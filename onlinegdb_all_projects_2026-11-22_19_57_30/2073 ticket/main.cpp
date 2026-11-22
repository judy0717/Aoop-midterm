#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        for (int i = 0; i < (int)tickets.size(); i++) {
            if (i <= k) {//在第k人前面的,最多買k輪該人就走了,或著是他們買完自己需要的就走了
                time += min(tickets[i], tickets[k]);
            } else {//在第k人後面的,最多買k-1輪該人就走了,或著是他們買完自己需要的就走了
                time += min(tickets[i], tickets[k] - 1);
            }
        }
        return time;
    }
};

int main() {
    Solution sol;

    vector<int> t1 = {2, 3, 2};
    cout << sol.timeRequiredToBuy(t1, 2) << endl;  // 預期輸出 6

    vector<int> t2 = {5, 1, 1, 1};
    cout << sol.timeRequiredToBuy(t2, 0) << endl;  // 預期輸出 8

    return 0;
}