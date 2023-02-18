#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int company[100][100];
int company_size, path_size;
int destination, waypoint;

void initialCompany(){
    for (int i=0; i<company_size; i++){
        for (int j=0; j<company_size; j++){
            if (i == j) company[i][j] = 0;
            else company[i][j] = 1e9;
        }
    }
}

void getInput() {
    int inp1, inp2;
    cin >> company_size >> path_size;
    initialCompany();
    for (int i=0; i<path_size; i++){
        cin >> inp1 >> inp2;
        company[inp1-1][inp2-1] = 1;
    }
    cin >> destination >> waypoint;
}
void futureCity() {
    for (int i=0; i<company_size; i++){
        for (int j=0; j<company_size; j++){
            for (int k=0; k<company_size; k++){
                company[j][k] = min(company[j][k], company[j][i] + company[i][k]);
            }
        }
    }
    int answer = company[0][waypoint-1] + company[waypoint-1][destination] + 1;
    if (answer > 1e9) cout << -1;
    else cout << answer;
}
int main() {
    getInput();
    futureCity();
    return 0;
}
/*
5 7
1 2
1 3
1 4
2 4
3 4
3 5
4 5
4 5
*/
