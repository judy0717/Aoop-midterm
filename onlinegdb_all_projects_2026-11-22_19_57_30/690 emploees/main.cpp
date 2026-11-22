#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
//class在leetcode已內建好
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mp;
        for (auto* e : employees) mp[e->id] = e;
        return dfs(mp, id);
    }

private:
    int dfs(unordered_map<int, Employee*>& mp, int id) {
        Employee* e = mp[id];
        int total = e->importance;
        for (int sub : e->subordinates) {
            total += dfs(mp, sub);
        }
        return total;
    }
};

// 建立員工的輔助函式
Employee* makeEmployee(int id, int importance, vector<int> subs) {
    Employee* e = new Employee();
    e->id = id;
    e->importance = importance;
    e->subordinates = subs;
    return e;
}

int main() {
    Solution sol;

    // 範例 1:預期輸出 11
    vector<Employee*> emp1 = {
        makeEmployee(1, 5, {2, 3}),
        makeEmployee(2, 3, {}),
        makeEmployee(3, 3, {})
    };
    cout << "Example 1: " << sol.getImportance(emp1, 1) << endl;

    // 範例 2:預期輸出 -3
    vector<Employee*> emp2 = {
        makeEmployee(1, 2, {5}),
        makeEmployee(5, -3, {})
    };
    cout << "Example 2: " << sol.getImportance(emp2, 5) << endl;

    // 釋放記憶體
    for (auto* e : emp1) delete e;
    for (auto* e : emp2) delete e;

    return 0;
}