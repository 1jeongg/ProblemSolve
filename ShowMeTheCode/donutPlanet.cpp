#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
int region[1000][1000];

void getInput() {
    cin >> n >> m;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> region[i][j];
        }
    }

}
void changeValue(int i, int j) {
    if (region[i][j] == 1 || region[i][j] == 2) return;
    region[i][j] = 2;
    if (i>0) changeValue(i-1, j);
    else changeValue(n-1, j);

    if (i<n-1) changeValue(i+1, j);
    else changeValue(0, j);

    if (j>0) changeValue(i, j-1);
    else changeValue(i, m-1);

    if (j<m-1) changeValue(i, j+1);
    else changeValue(i, 0);

}
void getAnswer() {
    int answer = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (region[i][j] == 0){
                changeValue(i,j);
                answer ++;
            }
        }
    }
    cout <<answer;
}
int main() {
    getInput();
    getAnswer();
    return 0;
}
