#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int fun_num;
vector<pair<int, int>> poly, answer;
#define ERASE_POLY(x) poly.erase(poly.begin()+x);

void get_input(){
    int coef, degree, poly_num;
    cin >> fun_num;
    for (int i=0; i<fun_num; i++){
        cin >> poly_num;
        for (int j=0; j<poly_num; j++){
            cin >> coef >> degree;
            poly.push_back(make_pair(coef, degree));
        }
    }
}

bool comp(pair<int, int>a, pair<int, int> b){
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

void poly_add(){
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

    if (poly.size()){
        cout << poly.size() << endl;
        for (auto& k: poly) cout << k.first << " " << k.second << endl;
    } else{
        cout << "0 0"<< endl;
    }
}


int main() {
    get_input();
    poly_add();
    return 0;
}
