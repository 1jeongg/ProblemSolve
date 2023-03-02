#include <iostream>
#include <string>

using namespace std;

int x, y;

void checkDuplicated(string &str, int &num) {
    bool isDuplicated = str.find(to_string(num)) != string::npos;
    if (isDuplicated) {
        if (x == 0) x = num;
        else y = num;
    }
}

void addCard(string &str, int &num) {
    checkDuplicated(str, num);
    str += to_string(num) + " ";
}

void main_duplicated() {
    int num, inp;
    string cards = "";
    cin >> num;
    for (int i=0; i<num+2; i++){
        cin >> inp;
        addCard(cards, inp);
    }
    cout << min(x,y) << endl << max(x,y);
}

int main() {
    main_duplicated();
    return 0;
}
