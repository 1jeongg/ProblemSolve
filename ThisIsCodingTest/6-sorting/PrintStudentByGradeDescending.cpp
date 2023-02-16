#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Student {
    string name;
    int grade;
};
bool cmp(Student &a, Student &b){
    return a.grade > b.grade;
}
vector<Student> sequence;
void getInput() {
    int student_num, inp;
    string inp_str;
    cin >> student_num;
    for (int i=0; i<student_num; i++) {
        cin >> inp_str >> inp;
        Student s = {inp_str, inp};
        sequence.push_back(s);
    }
}

void sortByDescending() {
    sort(sequence.begin(), sequence.end(), cmp);
    reverse(sequence.begin(), sequence.end());
    for (auto w: sequence){
        cout << w.name << " ";
    }
}
int main() {
    getInput();
    sortByDescending();
    return 0;
}

