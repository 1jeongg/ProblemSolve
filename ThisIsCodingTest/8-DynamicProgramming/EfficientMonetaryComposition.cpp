#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> money;
int money_array[100];
int money_size, valueTotal;

void getInput() {
    int inp;
    cin >> money_size >> valueTotal;
    for (int i=0; i<money_size; i++){
        cin >> inp;
        money.push_back(inp);
    }
}
void monetaryComposition() {
    fill(money_array, money_array+100, 10001);
    money_array[0] = 0;
    for (int i=0; i<money_size; i++) {
        for (int j=money[i]; j<=valueTotal; j++) {
            money_array[j] = min(money_array[j], money_array[j - money[i]]+1);
        }
    }
    cout << money_array[valueTotal];
}
int main() {
    getInput();
    monetaryComposition();
    return 0;
}
/*
3 4
3 5 7
*/
