#include <iostream>

using namespace std;

int isMovable(char x, char y) {
    bool is_x_movable = x >= 'a' && x <= 'h';
    bool is_y_movable = y >= '1' && y <= '8';
    if (is_x_movable && is_y_movable) return 1;
    return 0;
}

void Knight() {
    char x, y;
    cin >> x >> y;
    int answer = 0;
    pair<int, int> moving[8] =
    answer += isMovable(x+2, y+1);
    answer += isMovable(x+2, y-1);
    answer += isMovable(x-2, y+1);
    answer += isMovable(x-2, y-1);

    answer += isMovable(x+1, y+2);
    answer += isMovable(x-1, y+2);
    answer += isMovable(x+1, y-2);
    answer += isMovable(x-1, y-2);
    cout << answer;
}

int main() {
    Knight();
    return 0;
}
// 5
