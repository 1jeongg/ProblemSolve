#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int arr[30003];

int makeOne(int x) {
    for (int i=2; i<=x; i++) {
        arr[i] = arr[i-1] + 1;
        if (i%2 == 0)
            arr[i] = min(arr[i/2]+1, arr[i]);
        else if (i%3 == 0)
            arr[i] = min(arr[i/3]+1, arr[i]);
        else if (i%5 == 0)
             arr[i] = min(arr[i/5]+1, arr[i]);
    }
    return arr[x];
}
int main() {
    int num;
    cin >> num;
    cout << makeOne(num);
    return 0;
}
