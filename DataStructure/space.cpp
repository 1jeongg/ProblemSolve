#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int start_num, end_num, start_id, end_id;
vector<tuple<int, int, bool>> space;

void space_func(){
    cin >> start_num >> end_num;
    for (int i=start_num; i<=end_num; i++)
        space.push_back(make_tuple(i, i%3, false));

    for (int i=0; i<end_num-start_num; i++){
        get<2>(space[start_id]) = true;
        int moved = 1, distance = get<1>(space[start_id]) + 2;
        while (moved <= distance){
            end_id += 1;
            if (end_id > end_num-start_num){
                distance -= moved;
                start_id = end_id = moved = 0;
            }
            if(!get<2>(space[start_id+moved])) moved += 1;
            else start_id += 1;
        }
        start_id = end_id;
    }
    cout << get<0>(space[end_id]);
}
int main(){
    space_func();
    return 0;
}
