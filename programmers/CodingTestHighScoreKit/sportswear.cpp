#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    vector<int> lost_reserve;
    for (auto x: lost) {
        for (auto y: reserve) {
            if (x == y) lost_reserve.push_back(x);
        }
    }
    answer = n - lost.size() + lost_reserve.size();
    for (auto w: lost_reserve) {
        auto p = remove(lost.begin(), lost.end(), w);
        auto p2 = remove(reserve.begin(), reserve.end(), w);
        lost.resize(p-lost.begin());
        reserve.resize(p2-reserve.begin());
    }
    for (int i=0; i<lost.size(); i++){
        bool flag = false;
        for (int j=0; j<reserve.size(); j++){
            if (abs(lost[i] - reserve[j]) == 1) {
                flag = true;
                reserve.erase(reserve.begin() + j);
            }
        }
        if (flag) answer++;
    }
    return answer;
}
