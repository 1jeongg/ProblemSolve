#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int seat_num, record_num;
vector <int> seat_vec;
vector <pair <int, int>> id_vec;

void put_seat(int id){
    for (auto i: seat_vec) cout << i << " ";
    cout << endl;
    int max_index, max_num = 0, cdist;
    for (int i=0; i<seat_vec.size()-1; i++){
        cdist = seat_vec[i+1] - seat_vec[i];
        if (cdist > max_num){
            max_num = cdist;
            max_index = i;
        }
    }
    cdist = seat_vec[0] - seat_vec[seat_vec.size()-1] + seat_num;
    if (cdist > max_num){
        max_num = cdist;
        max_index = seat_vec.size()-1;
    }
    cdist = seat_vec[max_index] + max_num/2;
    if (cdist > seat_num) {
        max_index = -1;
        cdist = cdist-seat_num;
    }
    if (cdist == seat_num && max_index != seat_num-2){
        max_index = -1;
        cdist = 1;
    }
    seat_vec.insert(seat_vec.begin()+max_index+1, cdist);
    id_vec.push_back(make_pair(id, cdist));

    cout << id << " " << cdist << endl;
}
bool find_id(int id){
    for (int i=0; i<id_vec.size(); i++){
        if (id_vec[i].first == id) {
            auto it = find(seat_vec.begin(), seat_vec.end(), id_vec[i].second);
            seat_vec.erase(seat_vec.begin() + (it-seat_vec.begin()));
            id_vec.erase(id_vec.begin() + i);
            return true;
        }
    }
    return false;
}

void cafeX(){
    int inp = 1, flag = 0;
    cin >> seat_num >> record_num;
    seat_vec = {1};

    for (int i=0; i<record_num; i++){
        cin >> inp;
        if (i == 0) {
            id_vec.push_back(make_pair(inp,1));
            cout << inp << " " << 1 << endl;
        }
        else if (!find_id(inp)){
          if (id_vec.size() < seat_num) put_seat(inp);
        }
    }
}

int main(){
    cafeX();
    return 0;
}
