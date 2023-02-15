#include <iostream>

using namespace std;
int n, m, temp_x, temp_y;
int x_point, y_point, direction;
int map_system[50][50];

void getInput() {
    cin >> n >> m;
    cin >> x_point >> y_point >> direction;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> map_system[i][j];
}
int getDirection(int x) {
    if (x == 0) return 3;
    return x - 1;
}
bool isInRange(int x, int y) {
    return x>=0 && x<n && y>=0 && y<m;
}
void makePoint() {
    switch (direction) {
    case 0: temp_x = x_point;   temp_y = y_point-1; break;
    case 1: temp_x = x_point+1; temp_y = y_point;   break;
    case 2: temp_x = x_point;   temp_y = y_point+1; break;
    case 3: temp_x = x_point-1; temp_y = y_point;   break;
    }
}
void gameSystem() {

    int answer = 1;
    map_system[x_point][y_point]= 2;
    while (true) {
        bool flag = true;
        for (int i=direction; i<direction+4; i++){
            direction = getDirection(i%4);
            makePoint();
            if (isInRange(temp_x, temp_y)
                 && map_system[temp_x][temp_y] == 0){
                x_point = temp_x;
                y_point = temp_y;
                answer += 1;
                map_system[x_point][y_point] = 2;
                flag = false;
            }
        }
        if (flag) {
            makePoint();
            if (isInRange(x_point, y_point)
                 && map_system[x_point][y_point] != 1)
                    break;
        }

    }
    cout << answer;
}

int main() {
    getInput();
    gameSystem();
    return 0;
}
// 4 4 1 1 0 1 1 1 1 1 0 0 1 1 1 0 1 1 1 1 1
