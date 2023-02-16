#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> N, M;
int n_size, m_size;

void getInput() {
    int inp;
    cin >> n_size;
    for (int i=0; i<n_size; i++) {
        cin >> inp;
        N.push_back(inp);
    }
    cin >> m_size;
    for (int i=0; i<m_size; i++) {
        cin >> inp;a
        M.push_back(inp);
    }
}
int customBinarySearch(int target){
    int startIndex = 0, endIndex = n_size-1;
    while (startIndex <= endIndex) {
        int midIndex = (startIndex + endIndex) / 2;
        if (N[midIndex] == target) return midIndex;
        else if (N[midIndex] > target) endIndex = midIndex - 1;
        else startIndex = midIndex + 1;
    }
    return -1;
}
void findElement() {
    sort(N.begin(), N.end());
    for (auto m: M){
        /*int isExist = binary_search(N.begin(), N.end(), m);
        if (isExist) cout << "yes ";
        else cout << "no ";*/
        int isCustomExist = customBinarySearch(m);
        if (isCustomExist >= 0) cout << "yes ";
        else cout << "no ";
    }
}
int main() {
    getInput();
    findElement();
    return 0;
}
/*
5
8 3 7 9 2
3
5 7 9
*/
