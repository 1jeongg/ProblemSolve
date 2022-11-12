#include <iostream>
#include <vector>

using namespace std;
vector<char> code;
int opened, closed, complexity;

void get_input(){
    char inp;
    while (cin >> inp){
        if (inp == '{' || inp == '}')
            code.push_back(inp);
    }
}

void code_complexity(){
    for (auto w: code){
        if (w == '{') {
            opened ++;
            complexity += opened;
        } else opened --;
    }
    cout <<complexity << endl;
}

int main() {
    get_input();
    code_complexity();
    return 0;
}
