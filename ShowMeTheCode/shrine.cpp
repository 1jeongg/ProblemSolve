#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int num, input;
vector<int> rock_left, rock_right;

void getInput() {
    int left = 0, right = 0;
    cin >> num;
    for (int i=0; i<num; i++) {
        cin >> input;
        if (input == 1) left ++;
        else right ++;
        rock_left.push_back(left);
        rock_right.push_back(right);
    }
}
void getAnswer() {
    int max_num = 0, min_num = 0;

    for (int i=0; i<num; i++){
        int r = rock_left[i] - rock_right[i];
        if (r < 0){
            if (min_num > r) min_num = r;
        } else if (max_num < r) max_num = r;
    }
    cout << max_num - min_num;
}
int main() {
    getInput();
    getAnswer();
    return 0;
}
