#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n, m;
vector<vector<int>> map_system;

void getInput() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        vector<int> inp_vec;
        for (int j=0; j<m; j++) {
            char inp;
            cin >> inp;
            inp_vec.push_back(inp-'0');
        }
        map_system.push_back(inp_vec);
    }
}

bool isInBound(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
void mazeEscape() {
    int answer = 0;
    queue<pair<int, int>> maze;
    maze.push(make_pair(0, 0));
    while (!maze.empty()) {
        int x = maze.front().first, y = maze.front().second;
        maze.pop();
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        for (int i=0; i<4; i++){
            int temp_x = x + dx[i], temp_y = y + dy[i];
            if (!isInBound(temp_x, temp_y)) continue;
            if (map_system[temp_x][temp_y] == 0) continue;
            if (map_system[temp_x][temp_y] == 1) {
                map_system[temp_x][temp_y] = map_system[x][y] + 1;
                maze.push(make_pair(temp_x, temp_y));
            }
        }
    }

    cout << map_system[n-1][m-1];
}

int main() {
    getInput();
    mazeEscape();
    return 0;
}
/*
5 6
101010
111111
000001
111111
111111
*/
