#include <bits/stdc++.h>

using namespace std;
vector<vector<char>> full_figure;
int full_size, part_size;
string part_figure;
void getInput(){
    ifstream readFile("map.txt");
    char c;
    readFile >> full_size;
    readFile.get(c);
    cin >> part_size;
    string secret[full_size+1];
    bool flag = true;
    for (int i=0; i<full_size; i++){
        vector<char> inp_vec, inp_vec2;
        string s = "";
        for (int j=0; j<full_size+1; j++){
           if (i<part_size && j<part_size){
             cin >> c;
             part_figure += c;
           }
           readFile.get(c);
           if (c == '\n' || j == full_size) continue;
           if (s.length() < part_size){
                s += c;
           } else {
                s.erase(s.begin());
                s += c;
           }
           if (j < part_size-1) continue;
           if (i == 0) secret[j] = s;
           else if (i < part_size){
               secret[j] += s;
           }
           else {
               secret[j] = secret[j].substr(part_size) + s;
           }
           if (i >= part_size-1) {
                if (secret[j] == part_figure){
                    cout << j+2-part_size << " " << i+2-part_size << endl;
                    flag = false;
                }
           }
           inp_vec2.push_back(c);
       }
       full_figure.push_back(inp_vec2);
    }
    if (flag) cout << "0 0";
    readFile.close();
}

int main() {
    getInput();
    return 0;
}
