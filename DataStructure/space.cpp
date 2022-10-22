#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

void space(){
    int start_num, end_num, index;
    vector<tuple<int, int, bool>> space;

    cin >> start_num >> end_num;
    index = start_num % 3;
    for (int i=start_num; i<=end_num; i++){
        space.push_back(make_tuple(i, index, false));
        index++;
        if (index == 3) index = 0;
    }

    index = 0;

    for (int i=0; i<end_num-start_num; i++){
        get<2>(space[index]) = true;
        int cnt = 1, my_max = get<1>(space[index]) + 2, myindex = index;
        while (cnt <= my_max){
            myindex++;
            if (myindex > end_num-start_num){
                index = myindex = 0;
                my_max -= cnt;
                cnt = 0;
            }

            if(!get<2>(space[index+cnt])) cnt++;
            else index++;
        }
        index = myindex;
    }
    cout << get<0>(space[index]) << endl;
}
int main(){
    space();
    return 0;
}
