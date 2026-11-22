#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

class UndergroundSystem {
    unordered_map<int, pair<string, int>> in;//乘客資料<ID,<起始站,進站時間>>
    unordered_map<string, pair<double, int>> trips;//<路線,<時間,次數>>

public:
    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t) {
        in[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        auto& [start, time] = in[id];
        auto& r = trips[start + "->" + stationName];
        //r[花的時間,次數]
        r.first += t - time;
        r.second++;
    }

    double getAverageTime(string startStation, string endStation) {
        auto& r = trips[startStation + "->" + endStation];
        return r.first / r.second;
    }
};

int main() {
    UndergroundSystem us;

    us.checkIn(45, "Leyton", 3);
    us.checkIn(32, "Paradise", 8);
    us.checkIn(27, "Leyton", 10);
    us.checkOut(45, "Waterloo", 15);
    us.checkOut(27, "Waterloo", 20);
    us.checkOut(32, "Cambridge", 22);

    cout << us.getAverageTime("Paradise", "Cambridge") << endl;  // 14
    cout << us.getAverageTime("Leyton", "Waterloo") << endl;     // 11

    us.checkIn(10, "Leyton", 24);
    cout << us.getAverageTime("Leyton", "Waterloo") << endl;     // 11

    us.checkOut(10, "Waterloo", 38);
    cout << us.getAverageTime("Leyton", "Waterloo") << endl;     // 12

    return 0;
}