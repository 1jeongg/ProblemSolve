#include <iostream>
#include <vector>

using namespace std;
vector < vector<int>> lugguage;

void put_lugguage(int weight, int index){
    vector <int> container;
    for (int i=0; i<lugguage.size(); i++){
        if (weight + lugguage[i][0] <= 100) {
            lugguage[i][0] += weight;
            lugguage[i].push_back(index);
            return;
        }
    }
    container = {weight, index};
    lugguage.push_back(container);
}

void get_input(){
    int lugguage_num, weight;
    cin >> lugguage_num;
    for (int i=0; i<lugguage_num; i++){
        cin >> weight;
        put_lugguage(weight, i+1);
    }
}
void print_lugguage(){
    for (int i=0; i<lugguage.size(); i++){
        for (int j=1; j<lugguage[i].size(); j++){
            cout << lugguage[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    get_input();
    print_lugguage();
    return 0;
}
