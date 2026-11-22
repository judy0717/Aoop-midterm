#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class RecentCounter {
private:
    queue<int> q;

public:
    RecentCounter() {}

    int ping(int t) {
        q.push(t);
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }
        return static_cast<int>(q.size());
    }
};

int main() {
    // 對應題目範例:ping(1), ping(100), ping(3001), ping(3002)
    RecentCounter recentCounter;
    vector<int> inputs = {1, 100, 3001, 3002};

    cout << "null";  // RecentCounter() 建構函式沒有回傳值
    for (int t : inputs) {
        cout << ", " << recentCounter.ping(t);
    }
    cout << endl;  // 預期輸出: null, 1, 2, 3, 3

    return 0;
}