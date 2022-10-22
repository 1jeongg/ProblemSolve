#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void space(){
    int start_num, end_num, index;
    vector<pair<int,int>> space;
    vector<bool> mybool;

    cin >> start_num >> end_num;
    index = start_num % 3;
    for (int i=start_num; i<=end_num; i++){
        space.push_back(make_pair(i, index));
        mybool.push_back(false);
        index++;
        if (index == 3) index = 0;
    }

    index = 0;

    for (int i=0; i<end_num-start_num; i++){
        mybool[index] = true;
        int cnt = 1, my_max = space[index].second + 2, myindex = index;
        while (cnt <= my_max){
            myindex++;
            if (myindex > end_num-start_num){
                index = myindex = 0;
                my_max -= cnt;
                cnt = 0;
            }

            if(!mybool[index+cnt]) cnt++;
            else index++;
        }

        index = myindex;
    }
    cout << space[index].first << endl;

    /*
    for (int i=0; i<end_num-start_num; i++){
        auto value = space.begin() + index;
        index += (*value).second + 1;
        if (index >= space.size()-1)
            index = (*value).second + 2 - (space.end() - value);
        if (space.size() <= 3) index = index%2;
        space.erase(value);
    }
    */

}
int main(){
    space();
    return 0;
}
