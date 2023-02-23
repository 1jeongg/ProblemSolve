#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b){
    string ab = a + b;
    string ba = b + a;
    return ab > ba;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str_numbers;
    for (auto num: numbers){
        str_numbers.push_back(to_string(num));
    }
    sort(str_numbers.begin(), str_numbers.end(), cmp);
    if (str_numbers[0] == "0") return "0";
    for (auto str: str_numbers){
        answer += str;
    }
    return answer;
}
