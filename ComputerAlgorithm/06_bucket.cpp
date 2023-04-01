// 6110 - in PNU computer Engineering Hall
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <set>
#define TUPLE tuple<int,int,int>

using namespace std;

vector<int> capacity,water;

void getInput() {
    int inp;
    for (int i=0; i<3; i++){
        cin >> inp;
        capacity.push_back(inp);
    }
    for (int i=0; i<3; i++){
        cin >> inp;
        water.push_back(inp);
    }
}
vector<TUPLE> moveWater(TUPLE bucket, int mover, int movee){
    vector<TUPLE> next_bucket;
    int temp[3] = {get<0>(bucket), get<1>(bucket), get<2>(bucket)};
    int diff = min(capacity[movee] - temp[movee] , temp[mover]);
    temp[mover] -= diff;
    temp[movee] += diff;
    next_bucket.push_back({temp[0], temp[1], temp[2]});
    return next_bucket;
}
void main_bucket(){
    int answer = 0;
    TUPLE t = {water[0], water[1], water[2]};
    // bfs
    set<TUPLE> visited;
    queue<TUPLE> q;
    q.push(t);
    visited.insert(t);
    while(!q.empty()){
        TUPLE cur = q.front();
        q.pop();
        answer ++;
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                if (i != j){
                    vector<TUPLE> next_bucket = moveWater(cur, i, j);
                    for (auto n: next_bucket){
                        if (visited.find(n) == visited.end()){
                            q.push(n);
                            visited.insert(n);
                        }
                    }
                }
            }
        }
    }
    cout << answer;
}
int main(){
    getInput();
    main_bucket();
    return 0;
}
