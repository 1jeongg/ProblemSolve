#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int height, width;
int ball_park[1111][1111] = {0, };

void getInput(){
    string inp;
    cin >> height >> width;
    for (int i=1; i<=height; i++){
        cin >> inp;
        for (int j=1; j<=width; j++){
            ball_park[i][j] = (inp[j-1] == '0') ? 1 : 0;
        }
    }
}
int getSpaceInfo(int i, int j) {
    int up = ball_park[i-1][j];
    int left = ball_park[i][j-1];
    int up_left = ball_park[i-1][j-1];

    if (up == 0 || left == 0 || up_left == 0) return 1;
    if (left == up && up == up_left) return up_left+1;
    if (up < left) return up + 1;
    if (up > left) return left + 1;
    return up;

}
void mainBallPark() {
    vector<pair<int, int>> answer;
    int max_value = 0;
    for (int i=1; i<=height; i++){
        for (int j=1; j<=width; j++){
            if (ball_park[i][j] != 0)
                ball_park[i][j] = getSpaceInfo(i,j);
            else continue;

            if (max_value < ball_park[i][j]) {
                answer.clear();
                max_value = ball_park[i][j];
                answer.push_back({j-max_value+1, height-i+1});
            }
            else if (max_value == ball_park[i][j])
                answer.push_back({j-max_value+1, height-i+1});
        }
    }
    sort(answer.begin(), answer.end());
    cout << max_value << " " << answer.size() <<endl;
    for (auto a: answer){
        cout << a.first << " " << a.second <<endl;
    }
}
int main() {
    getInput();
    mainBallPark();
    return 0;
}
