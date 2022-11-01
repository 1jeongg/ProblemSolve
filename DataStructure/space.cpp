#include <iostream>
#include <vector>
using namespace std;
int start_num, end_num, start_id, end_id;
int moved, space_size, dist;
vector<pair<int, bool>> space;

void space_func(){
    cin >> start_num >> end_num;
    for (int i=start_num; i<=end_num; i++)
        space.push_back(make_pair(i, false));

    space_size = end_num - start_num;
    for (int i=0; i<space_size; i++){
        space[start_id].second = true;
        moved = 1;
        dist = space[start_id].first%3 + 2;
        while (moved <= dist){
            end_id += 1;
            if (end_id > space_size){
                dist -= moved;
                start_id = end_id = moved = 0;
            }
            if(!space[start_id+moved].second) moved += 1;
            else start_id += 1;
        }
        start_id = end_id;
    }
    cout << space[end_id].first;
}
int main(){
    space_func();
    return 0;
}
