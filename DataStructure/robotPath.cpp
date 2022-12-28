#include <bits/stdc++.h>

using namespace std;

int  grid_size, wait_time, inp;

vector<int> r {0,0,+1,-1};
vector<int> c {+1,-1,0,0};
vector<vector<int>> grid;
bool visited[100][100];
bool inBounds(int i, int j){
    if (i > -1 && i < grid_size && j > -1 && j < grid_size)
        return !visited[i][j];
    return false;

}

int minCost() {

    vector<vector<int>> dist(grid_size, vector<int>(grid_size, INT_MAX));
    dist[grid_size-1][0] = 0;

    priority_queue<vector<int>> minheap;

    minheap.push({0, -1, grid_size-1,0}); // {dist, direciton, i, j}

    while(!minheap.empty()){
        auto curr = minheap.top();
        minheap.pop();

        int currDist = -curr[0], direction = curr[1], i = curr[2],  j = curr[3]; // dist i j
        if (dist[i][j] + wait_time <= currDist) continue;
        for(int d=0; d<4; d++){
            int newI = i + r[d];
            int newJ = j + c[d];
            int weight = ((d == direction || direction == -1) ? 1 : 1+wait_time);


            if(inBounds(newI, newJ) &&
                dist[newI][newJ] >= currDist + weight){
                dist[newI][newJ] = currDist + weight;
                minheap.push({-dist[newI][newJ], d, newI, newJ});
            }

        }
    }
    if (dist[0][grid_size-1] == INT_MAX) return -1;
    return dist[0][grid_size-1];

}

void getInput() {

    cin >> grid_size >> wait_time;
    for (int i=0; i<grid_size; i++){
        vector<int> grid_inp;
        for (int j=0; j<grid_size; j++){
            cin >> inp;
            grid_inp.push_back(inp);
            visited[i][j] = (inp == 1);
        }
        grid.push_back(grid_inp);
    }
}

int main() {
    getInput();
    cout << minCost() << endl;

}
