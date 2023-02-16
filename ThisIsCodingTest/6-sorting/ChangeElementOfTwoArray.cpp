#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> A, B;
int sequence_size, maxChange;

void getInput() {
    int inp;
    cin >> sequence_size >> maxChange;
    for (int i=0; i<sequence_size; i++) {
        cin >> inp;
        A.push_back(inp);
    }
    for (int i=0; i<sequence_size; i++) {
        cin >> inp;
        B.push_back(inp);
    }
}
bool isChangeAble(int index) {
    if (index >= maxChange) return false;
    if (A[index] > B[sequence_size-index-1]) return false;
    return true;
}
void chageElement() {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int answer = 0;
    for (int i=0; i<sequence_size; i++) {
        if (isChangeAble(i)) answer += B[sequence_size-i-1];
        else answer += A[i];
    }
    cout << answer;
}
int main() {
    getInput();
    chageElement();
    return 0;
}
/*
5 3
1 2 5 4 3
5 5 6 6 5
*/
