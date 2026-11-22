#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int cnt[2] = {0, 0};//隊伍中想吃該三明治的人數,第一個為0第二個為1
        for (int s : students) cnt[s]++;

        int n = sandwiches.size();
        for (int i = 0; i < n; i++) {
            if (cnt[sandwiches[i]] == 0) {//沒人想吃最上面的
                return n - i;
            }
            cnt[sandwiches[i]]--;//拿走三明治
        }
        return 0;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> students(n), sandwiches(n);
    for (int i = 0; i < n; i++) cin >> students[i];
    for (int i = 0; i < n; i++) cin >> sandwiches[i];

    Solution sol;
    cout << sol.countStudents(students, sandwiches) << endl;
    return 0;
}