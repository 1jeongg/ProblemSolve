#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> floor;
int num;

void floorWorking() {
    floor.push_back(1);
    floor.push_back(3);
    for (int i=2; i<num; i++){
        floor[i] = (floor[i-1] + floor[i-2]*2) % 796796;
    }
    cout << floor[num-1];
}
int main() {
    cin >> num;
    floorWorking();
    return 0;
}
