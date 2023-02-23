#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int x_num = 0, y_num = 0, z_num = 0;
    int x[] = {1,2,3,4,5};
    int y[] = {2,1,2,3,2,4,2,5};
    int z[] = {3,3,1,1,2,2,4,4,5,5};
    for (int i=0; i<answers.size(); i++) {
        if (answers[i] == x[i%5]) x_num ++;
        if (answers[i] == y[i%8]) y_num ++;
        if (answers[i] == z[i%10]) z_num ++;
    }
    int max_num = max(max(x_num, y_num),z_num);
    if (max_num == x_num) answer.push_back(1);
    if (max_num == y_num) answer.push_back(2);
    if (max_num == z_num) answer.push_back(3);

    return answer;
}
