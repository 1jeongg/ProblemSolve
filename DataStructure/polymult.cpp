#include <iostream>
#include <vector>
#include <algorithm>

#define ERASE_POLY(x) poly.erase(poly.begin()+x);
using namespace std;

bool comp(pair<int, int>a, pair<int, int> b){
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}
void poly_add(vector<pair<int, int>> &poly){
    int index = 0;
    sort(poly.begin(), poly.end(), comp);

    while(index < poly.size()-1){
        if (poly[index].second == poly[index+1].second){
            poly[index].first  += poly[index+1].first;
            ERASE_POLY(index+1);
        } else {
            if (poly[index].first) index ++;
            else ERASE_POLY(index);
        }
    }
    if (!poly[0].first) ERASE_POLY(0);
}
void make_output(vector<pair<int, int>> &poly){
    if (poly.size()){
        cout << poly.size() << endl;
        for (auto& k: poly) cout << k.first << " " << k.second << endl;
    } else{
        cout << "0 0"<< endl;
    }
}
void poly_multi(){
    int coef, degree, poly_num, fun_num;
    vector<pair<int, int>> previous_vec, next_vec;

    previous_vec.push_back(make_pair(1,0));
    cin >> fun_num;

    for (int i=0; i<fun_num; i++){
        cin >> poly_num;

        for (int j=0; j<poly_num; j++){
            cin >> coef >> degree;
            for (int k=0; k<previous_vec.size(); k++){
                next_vec.push_back(make_pair(previous_vec[k].first*coef, previous_vec[k].second+degree));
            }
        }
        previous_vec.clear();
        previous_vec.assign(next_vec.begin(), next_vec.end());
        next_vec.clear();
        sort(previous_vec.begin(), previous_vec.end(), comp);
        poly_add(previous_vec);
    }
    make_output(previous_vec);
}


int main() {
    poly_multi();
    return 0;
}
