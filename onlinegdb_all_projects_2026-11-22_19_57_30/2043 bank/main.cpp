#include <iostream>
#include <vector>
using namespace std;

class Bank {
    vector<long long> bal;//餘額
    int n;//帳號數
public:
    Bank(vector<long long>& balance) : bal(balance), n(balance.size()) {}

    bool transfer(int account1, int account2, long long money) {//從1轉錢到2
        if (account1 < 1 || account1 > n || account2 < 1 || account2 > n) return false;
        if (bal[account1 - 1] < money) return false;
        //帳號從1 開始,但陣列index從0開始
        bal[account1 - 1] -= money;
        bal[account2 - 1] += money;
        return true;
    }

    bool deposit(int account, long long money) {
        if (account < 1 || account > n) return false;
        bal[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (account < 1 || account > n || bal[account - 1] < money) return false;
        bal[account - 1] -= money;
        return true;
    }
};

int main() {
    vector<long long> init = {10, 100, 20, 50, 30};
    Bank bank(init);

    cout << boolalpha;
    cout << bank.withdraw(3, 10) << endl;     // true
    cout << bank.transfer(5, 1, 20) << endl;  // true
    cout << bank.deposit(5, 20) << endl;
}