#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (auto command: commands) {
        vector<int> array_copy = array;
        int i = command[0], j = command[1], k = command[2];
        sort(array_copy.begin()+i-1, array_copy.begin()+j);
        answer.push_back(array_copy[i+k-2]);
    }
    return answer;
}
