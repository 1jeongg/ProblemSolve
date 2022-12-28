#include <bits/stdc++.h>

using namespace std;
int min_cost_array[100], err_array[100];
int vertex_size;
vector<pair<int, int> > cities[100];
#define INF 100000
vector<int> answer;

void putCity(int start_inp, int weight, int end_inp) {
    int _start = start_inp - 'A';
    int _end = end_inp - 'A';
    cities[_start].push_back(make_pair(weight, _end));
}
void getInput() {
    int weight_inp;
    char start_inp, end_inp;
    cin >> vertex_size;
    for (int i=0; i<vertex_size; i++) {
        cin >> start_inp;
        while (cin >> end_inp) {
            if (end_inp == '$') break;
            cin >> weight_inp;
            putCity(start_inp, weight_inp, end_inp);
        }
    }
}
void shortestPath(int start_node) {
    min_cost_array[start_node] = 0;
    priority_queue<pair<int, int> > priority_cities; // weight, end
    priority_cities.push(make_pair(0, start_node));

    while (!priority_cities.empty()) {
        int current = priority_cities.top().second;
        int current_distance = -priority_cities.top().first;
        priority_cities.pop();
        if (min_cost_array[current] < current_distance) continue;
        for (int i=0; i<cities[current].size(); ++i) {
            int next_end = cities[current][i].second;
            int next_distance = current_distance + cities[current][i].first*2;
            next_distance += cities[next_end].size();
            //cout << next_end << " " << cities[next_end].size() << "  " << next_distance << endl;
            if (min_cost_array[next_end] > next_distance) {
                min_cost_array[next_end] = next_distance;
                err_array[next_end] = cities[next_end].size();
           //     cout << next_end << " " << next_distance << " " <<cities[next_end].size() << endl;
                answer.push_back(next_distance - cities[next_end].size());
                priority_cities.push(make_pair(-next_distance, next_end));
            }
        }
     //   cout <<endl;
    }
}

int main() {
    getInput();
    int max_num = 0;
    for (int i=0; i<100; ++i){
        min_cost_array[i] = INF;
    }
    for (int i=0; i<100; i++){
        if (cities[i].empty()) continue;
        shortestPath(i);
        for (int j=0; j<100; ++j){
            if (min_cost_array[j] == INF) continue;
            if (max_num < min_cost_array[j] - err_array[j])
                max_num = min_cost_array[j] - err_array[j];
            min_cost_array[j] = INF;
        }
    }
    cout << max_num;
    /*
    for (int i=0; i<100; i++) {
        if (!cities[i].empty()) shortestPath(i);
        cout << *min_element( min_cost_array, min_cost_array+100 ) << endl;
    }
  +*/
    return 0;
}
