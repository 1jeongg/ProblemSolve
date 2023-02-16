#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> sequence;

void getInput() {
    int sequence_size, inp;
    cin >> sequence_size;
    for (int i=0; i<sequence_size; i++) {
        cin >> inp;
        sequence.push_back(inp);
    }
}

void sortByDescending() {
    sort(sequence.begin(), sequence.end());
    reverse(sequence.begin(), sequence.end());
    for (auto s: sequence) cout << s << " ";
}
int main() {
    getInput();
    sortByDescending();
    return 0;
}

 
