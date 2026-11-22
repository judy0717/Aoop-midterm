#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;//main深度=0
        for (const string& op : logs) {
            if (op == "../") {
                if (depth > 0) depth--;
            } else if (op != "./") {
                depth++;
            }
        }
        return depth;
    }
};

int main() {
    Solution sol;

    vector<string> logs1 = {"d1/", "d2/", "../", "d21/", "./"};
    vector<string> logs2 = {"d1/", "d2/", "./", "d3/", "../", "d31/"};
    vector<string> logs3 = {"d1/", "../", "../", "../"};

    cout << sol.minOperations(logs1) << endl;  // 2
    cout << sol.minOperations(logs2) << endl;  // 3
    cout << sol.minOperations(logs3) << endl;  // 0

    return 0;
}