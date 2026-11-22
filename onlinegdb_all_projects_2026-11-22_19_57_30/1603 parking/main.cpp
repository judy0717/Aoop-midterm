#include <iostream>
#include <vector>
using namespace std;

class ParkingSystem {
private:
    vector<int> slots;

public:
    ParkingSystem(int big, int medium, int small) : slots{0, big, medium, small} {}

    bool addCar(int carType) {
        if (slots[carType] > 0) {
            slots[carType]--;
            return true;
        }
        return false;
    }
};

int main() {
    ParkingSystem parkingSystem(1, 1, 0);

    cout << boolalpha;  // 讓 bool 印成 true / false,而不是 1 / 0
    cout << parkingSystem.addCar(1) << endl;  // true
    cout << parkingSystem.addCar(2) << endl;  // true
    cout << parkingSystem.addCar(3) << endl;  // false
    cout << parkingSystem.addCar(1) << endl;  // false

    return 0;
}