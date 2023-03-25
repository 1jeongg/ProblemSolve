#include <bits/stdc++.h>
#define TUPLE tuple<double, double, double>

using namespace std;

vector<TUPLE> points;
double a,b,c,d,e,f;

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
void getInput() {
    double x,y,z;
    for (int i=0; i<4; i++) {
        cin >> x >> y >> z;
        points.push_back({x,y,z});
    }
}

void main_space(){
    double i_gap=0, j_gap=0, gap = 0.0001;
    double dot_distance, min_distance=1e9;
    TUPLE i_temp, j_temp;
    while(i_gap <= 1){
        j_gap = 0;
        i_temp = getPoint(points[0], points[1], i_gap);
        while (j_gap <= 1){
            j_temp = getPoint(points[2], points[3], j_gap);
            j_gap += gap;
            dot_distance = calculateDistance(i_temp, j_temp);
            if (abs(dot_distance-min_distance) < FLT_EPSILON
                || min_distance > dot_distance)
                min_distance = dot_distance;
        }
        i_gap += gap;
    }
    if(min_distance < FLT_EPSILON)
        min_distance = 0;
	cout << ceil(min_distance);
}
int main() {
    getInput();
    main_space();
    return 0;
}
