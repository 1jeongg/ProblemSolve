#include <iostream>

using namespace std;


void Clock() {
    int hour, num = 0;
    cin >> hour;
    int three_size = (hour + 7) / 10;
    int answer = (hour+1)*3600 - (hour-three_size+1)*45*45;
    cout << answer;
}

int main() {
    Clock();
    return 0;
}
// 예시: 5
