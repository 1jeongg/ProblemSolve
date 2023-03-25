#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>

#define TUPLE tuple<double, double, double>
#define EPS 0.00000001
using namespace std;

double a,b,c,d,e,f,x,y,z;
double diff[2] = {0.5-0.0001, 0.5+0.0001};

double calculateDistance(TUPLE A, TUPLE B){
    tie(a,b,c) = A;
    tie(d,e,f) = B;
    return sqrt((a-d)*(a-d) + (b-e)*(b-e) + (c-f)*(c-f));
}
TUPLE getPoint(TUPLE A, TUPLE B, double k){
    tie(a,b,c) = A;
    tie(d,e,f) = B;
    return {a+k*(d-a), b+k*(e-b), c+k*(f-c)};
}
bool isEqual(double a, double b){
    return fabs(a - b) < 0.00000001;
}
double getDistance(TUPLE A, TUPLE B, TUPLE C){
    TUPLE left = getPoint(B, C, diff[0]), right = getPoint(B,C, diff[1]);
    double left_len = calculateDistance(left, A);
    double right_len = calculateDistance(right, A);
    if (isEqual(left_len, right_len))
        return left_len;
    if (left_len < right_len)
        return getDistance(A,B,right);
    return getDistance(A,left,C);
}
double main_space(TUPLE A, TUPLE B, TUPLE C, TUPLE D){
    TUPLE side[4];
    double len[4];
    for (int i=0; i<2; i++){
        side[i] = getPoint(A,B,diff[i]);
        side[i+2] = getPoint(C,D,diff[i]);
        len[i] = getDistance(side[i], C, D);
        len[i+2] = getDistance(side[i+2], A, B);
    }
    if (isEqual(len[0], len[1])){
        if (len[2] < len[3]) return main_space(A, B, C, side[3]);
        if (isEqual(len[2], len[3])) return len[2];
        return main_space(A, B, side[2], D);
    }
    if (len[0] < len[1]) return main_space(A, side[1], C, D);
    return main_space(side[0], B, C, D);
}
void getInput() {
    TUPLE points[4];
    for (int i=0; i<4; i++) {
        cin >> x >> y >> z;
        points[i] = {x,y,z};
    }
    double answer = main_space(points[0], points[1], points[2], points[3]);
    if(abs(answer - floor(answer)) > 0.001) answer++;
    cout << (int)answer;
}
int main() {
    getInput();
    return 0;
}
