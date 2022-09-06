#include <iostream>

using namespace std;

int points[100][2] = {0,};
int i=1;

void make_points(){
    points[0][0] = 0, points[0][1] = 0;
    int inp;
    while(1){
        cin >> inp;
        if (inp == 0) break;
        if (i%2) {
            points[i][0] += points[i-1][0] + inp;
            points[i][1] = points[i-1][1];
        } else {
            points[i][1] += points[i-1][1] + inp;
            points[i][0] = points[i-1][0];
        }
        i++;
    }
}
int compare_point(int k){
    return points[i-1][1] - points[k][1];
}

int is_in(int a, int b){
    for (int k=0; k<i; k++){
        if (a < points[k][0]){
            if (b < compare_point(k)) return 0; // in
            else if (b > compare_point(k)) return 1; // out
            else return 2; // on
        }
        if (a == points[k][0]){
            if (b < compare_point(k+1)) return 0; // in
            else if (b > compare_point(k)) return 1; // out
            else return 2; // on
        }
    }
    return 1;
}

void print_point(){
    int a,b, answer;
    while(cin >> a >> b){
        answer = is_in(a,b);
        if (answer == 0) cout << "in" << endl;
        if (answer == 1) cout << "out" << endl;
        if (answer == 2) cout << "on" << endl;
    }
}

int main()
{
    make_points();
    print_point();
    return 0;
}
