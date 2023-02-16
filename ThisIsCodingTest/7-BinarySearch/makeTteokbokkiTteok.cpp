#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> tteok;
long long tteok_size, request_height, max_height;

void getInput() {
    long long inp;
    cin >> tteok_size >> request_height;
    for (int i=0; i<tteok_size; i++) {
        cin >> inp;
        tteok.push_back(inp);
    }
}
long long makeTotalLength(long long height) {
    long long total = 0;
    for (auto t: tteok) {
        if (height < t) total += t-height;
    }
    return total;
}
void makeTteok() {
    long long result = 0;
    long long startIndex = 0, endIndex = *max_element(tteok.begin(), tteok.end());
    while (startIndex <= endIndex){
        long long midIndex = (startIndex + endIndex)/2;
        if (makeTotalLength(midIndex) < request_height)
            endIndex = midIndex - 1;
        else {
            result = midIndex;
            startIndex = midIndex + 1;
        }
    }
    cout << result;
}
int main() {
    getInput();
    makeTteok();
    return 0;
}
/*

4 6
19 15 10 17
*/
