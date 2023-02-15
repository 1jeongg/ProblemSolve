#include <iostream>

using namespace std;
int n, m;
char map_system[1000][1000];

void getInput() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> map_system[i][j];
        }
    }
}
bool isInBound(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}
void freeze_part(int x, int y) {
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    for (int i=0; i<4; i++){
        int temp_x = x+dx[i], temp_y = y+dy[i];
        if (isInBound(temp_x, temp_y)
             && map_system[temp_x][temp_y] == '0') {
            map_system[temp_x][temp_y] = '1';
            freeze_part(temp_x, temp_y);
        }
    }
}
void freezing() {
    int answer = 0;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++){
            if (map_system[i][j] == '0') {
                freeze_part(i, j);
                answer ++;
            }
        }
    cout <<answer;
}

int main() {
    getInput();
    freezing();
    return 0;
}
/*
15 14
00000111100000
11111101111110
11011101101110
11011101100000
11011111111111
11011111111100
11000000011111
01111111111111
00000000011111
01111111111000
00011111111000
00000001111000
11111111110011
11100011111111
11100011111111
*/
