#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
string S, T;

vector<string> dp[101][101];

void makeDP(int i, int a, int j, int b){
    if (i-a >= 0 && j-b >= 0 && S[i-a] == T[j-b]){
        for (auto p: dp[i-a][j-b])
            dp[i][j].push_back(p+S[i-a]);
    }
}
void main_quasi() {
    int max_value = 0;
    vector<string> answer;
    for (int i=0; i<=S.size(); i++){
        for (int j=0; j<=T.size(); j++){
            if (i == 0 || j == 0) {
                dp[i][j].push_back("");
                continue;
            }
            makeDP(i,1,j,1);
            makeDP(i,1,j,2);
            makeDP(i,2,j,1);
            makeDP(i,2,j,2);

            if (dp[i][j].size() == 0)
                dp[i][j].push_back("");

            for (auto p: dp[i][j]) {
                if (max_value < (int)p.size()){
                    answer.clear();
                    answer.push_back(p);
                }
                if (max_value == (int)p.size())
                    answer.push_back(p);
                max_value = max((int)p.size(), max_value);
            }
        }
    }
    sort(answer.begin(), answer.end());
    cout <<answer[0];
}
int main() {
    cin >> S >> T;
    main_quasi();
    return 0;
}
