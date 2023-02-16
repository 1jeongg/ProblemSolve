#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> storage;
int num;

void getInput() {
    int inp;
    cin >> num;
    for (int i=0; i<num; i++){
        cin >> inp;
        storage.push_back(inp);
    }
}
void antWarrior() {
    for (int i=2; i<num; i++){
        storage[i] = max(storage[i-1], storage[i-2]+storage[i]);
    }
    cout << storage[num-1];

}
int main() {
    getInput();
    antWarrior();
    return 0;
}
/*
4
1 3 1 5
*/
