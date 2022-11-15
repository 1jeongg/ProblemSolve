#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
int nodeNumber, under, root;
map<string, vector<string>> mafia;
map<string, int> mafiaRoot;
vector<pair<string, int>> mafiaPriority;

void getInput() {
    string person, boss;
    cin >> nodeNumber;
    for (int i=0; i<nodeNumber-1; i++) {
        cin >> person >> boss;
        mafia[boss].push_back(person);
        mafia[person].push_back("");
    }
}

void getPriority(string people) {
    for (auto w: mafia[people]){
        under += 1;
        mafiaRoot[w] += 1;
        getPriority(w);
    }
}

bool compareMafia(pair<string, int>& m1, pair<string, int>& m2){

    if (m1.second != m2.second) return m1.second > m2.second;
    if (mafiaRoot[m1.first] != mafiaRoot[m2.first])
        return mafiaRoot[m1.first] < mafiaRoot[m2.first];
    return m1.first < m2.first;

}

void sortMafia() {
    for (auto w: mafia){
        under = 0;
        getPriority(w.first);
        mafiaPriority.push_back(make_pair(w.first, under));
    }
    sort(mafiaPriority.begin(), mafiaPriority.end(), compareMafia);
    for (auto w: mafiaPriority){
        cout << w.first << endl;
    }
}

int main() {
    getInput();
    sortMafia();
    return 0;
}
