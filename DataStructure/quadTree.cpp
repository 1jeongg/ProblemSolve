#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int imageSize;
int quadTree[128][128];

void PRINT_QTS() {
    for (int i=0; i<imageSize; i++){
        for (int j=0; j<imageSize; j++)
            cout << quadTree[i][j];
        cout << endl;
    }
}

void QTS_REC(string::iterator& it, int y, int x, int s) {
    char first = *(it++);
    if(first == '0' || first == '1') {
        for(int dy = 0; dy < s; ++dy)
            for(int dx = 0; dx < s; ++dx)
                quadTree[y+dy][x+dx] = first - '0';
    } else {
        int half = s/2;
        if (half == 0) return;
        QTS_REC(it, y, x+half, half);
        QTS_REC(it, y, x, half);
        QTS_REC(it, y+half, x, half);
        QTS_REC(it, y+half, x+half, half);
    }
}

void QTS() {
    string inp;
    cin >> inp;
    inp.erase(remove(inp.begin(), inp.end(), ')'), inp.end());

    auto it = inp.begin();
    QTS_REC(it, 0, 0, imageSize);
    PRINT_QTS();

}
void IMG_REC(int n, int y, int x) {
    if (n == 1) {
        cout << quadTree[y][x];
        return;
    }
    bool zero = true, one = true;
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
    for (int i=0; i<imageSize; i++) {
        cin >> inp;
        for (int j=0; j<imageSize; j++)
            quadTree[i][j] = inp[j] - '0';
    }
    IMG_REC(imageSize, 0, 0);
}
void startQuadTree() {
    string fileType;
    cin >> imageSize >> fileType;
    imageSize = pow(2, imageSize);

    if (fileType == "QTS") QTS();
    else IMG();
}
int main() {
    startQuadTree();
    return 0;
}
