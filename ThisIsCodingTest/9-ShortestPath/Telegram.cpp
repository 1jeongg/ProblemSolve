#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9

using namespace std;

vector<pair<int, int> > graph[30001]; // graph[i] = (j, w) -> i에서 j까지 가는데 가중치 w가 필요함
int dist[30001]; // dist[i] = i까지 가는데 필요한 최단 경로
int n, m, start;

void dijkstra(int start) {
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start)); // (dist, vertex)
    dist[start] = 0;
    while(!pq.empty()) {
        int cost = -pq.top().first; // 가중치
        int current = pq.top().second; // 현재 노드
        pq.pop();
        for(int i = 0; i < graph[current].size(); i++) {
            int next = graph[current][i].first; // 다음 노드
            int nextDist = cost + graph[current][i].second; // 다음 노드까지 가는데 필요한 비용
            if(nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push(make_pair(-nextDist, next));
            }
        }
    }
}

int main() {
    cin >> n >> m >> start;
    for(int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        graph[x].push_back(make_pair(y, z));
    }

    fill(dist, dist + 30001, INF);

    dijkstra(start);

    int cnt = 0;
    int maxTime = 0;
    for(int i = 1; i <= n; i++) {
        if(dist[i] != INF && i != start) { // 도달할 수 있는 도시인 경우
            cnt++;
            maxTime = max(maxTime, dist[i]);
        }
    }

    cout << cnt << " " << maxTime << endl;

    return 0;
}
