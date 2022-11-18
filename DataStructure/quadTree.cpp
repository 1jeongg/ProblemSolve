#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
int imageSize;
int quadTree[128][128];


char decompressed[128][128];

void decompress(string::iterator& it, int y, int x, int s){

    char head = *(it++);

    if(head == '0' || head == '1'){
        for(int dy = 0; dy < s; ++dy)
            for(int dx = 0; dx < s; ++dx){
                decompressed[y+dy][x+dx] = head;
            }
    }
    else{
        int half = s/2;
        if (half == 0) return;
        decompress(it, y, x+half, half);
        decompress(it, y, x, half);
        decompress(it, y+half, x, half);
        decompress(it, y+half, x+half, half);
    }
}
void printQts(){
    for (int i=0; i<pow(2, imageSize); i++){
        for (int j=0; j<pow(2, imageSize); j++)
            cout << decompressed[i][j];
        cout << endl;
    }
}

void QTS() {
    string inp;
    string out="";
    cin >> inp;
    int depth = 0, i = 0;
    while (i < inp.size()){
        if (inp[i] == '(') depth ++;
        else if (inp[i] == ')') depth --;
        else {
            int a = pow(2, (imageSize-depth)*2);
            out += string(a, inp[i]);
        }
        i++;
    }

    inp.erase(remove(inp.begin(), inp.end(), ')'), inp.end());
    auto it = inp.begin();
    decompress(it, 0, 0, pow(2, imageSize));
    printQts();

}
void IMG_REC(int n, int y, int x) {
    if (n == 1) {
        cout << quadTree[y][x];
        return;
    }
    bool zero = true;
    bool one = true;
    for (int i=y; i<y+n; i++) {
        for (int j=x; j<x+n; j++) {
            if (quadTree[i][j]) zero = false;
            else one = false;
        }
    }
    if (zero) cout << 0;
    else if (one) cout << 1;
    else {
        cout << "(";
        IMG_REC(n/2, y, x+n/2);
        IMG_REC(n/2, y, x);
        IMG_REC(n/2, y+n/2, x);
        IMG_REC(n/2, y+n/2, x+n/2);
        cout << ")";
    }
}
void IMG() {
    string inp;
    imageSize = pow(2, imageSize);
    for (int i=0; i<imageSize; i++) {
        cin >> inp;
        for (int j=0; j<imageSize; j++)
            quadTree[i][j] = inp[j] - '0';
    }
    IMG_REC(imageSize, 0, 0);
}
void getInput() {
    string fileType;
    cin >> imageSize >> fileType;

    if (fileType == "QTS") QTS();
    else IMG();
}
int main() {
    getInput();
    return 0;
}
