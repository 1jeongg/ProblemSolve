#include <iostream>

using namespace std;

typedef struct points{
    int x, y;
} Point;

Point points[101];
int   point_size, time1, c1_index, c2_index;
int   total_line = 0, half_line = 0;

int calculate_point(Point a, Point b){
    if (b.x == a.x) return b.y - a.y;
    return b.x - a.x;
}

void get_points(){
    cin >> point_size;
    c1_index = 0;
    if (point_size%2) c2_index = point_size/2;
    else              c2_index = point_size/2 - 1;

    int x, y;
    for (int i=0; i<point_size; i++){
        cin >> x >> y;
        points[i].x = x;
        points[i].y = y;
        int a = abs(calculate_point(points[i], points[i-1]));

        if (i > 0){
            total_line += a;
            if (i <= c2_index)
                half_line += a;
        }
    }

    total_line += abs(calculate_point(points[point_size-1], points[0]));
    cin >> time1;
}

Point print_points(Point a, Point b, int time1, int line){
    Point p = a;
    if (line > 0){
        if (a.x == b.x) p.y = p.y + time1;
        else p.x = p.x + time1;
    }
    else {
        if (a.x == b.x) p.y = p.y - time1;
        else p.x = p.x - time1;
    }
    return p;
}

void make_points(){
    int t, line, a, b, real_time=time1%total_line;
    Point p1, p2, tp;

    t = real_time;
    for (int i = point_size-1; i>=0; i--){
        int k = i-c2_index-1;
        if (k > 0)  a = k, b = a-1;
        if (k < 0)  a = i+c2_index+1, b = a-1;
        if (k == 0) a = 0, b = point_size-1;

        line = calculate_point(points[a], points[b]);
        if (t > abs(line))
            t -= abs(line);
        else {
            p2 = print_points(points[a], points[b], t, line);
            t -= abs(line);
            break;
        }
    }

    t = real_time;
    for (int i = 0; i<point_size-1; i++){
        line = calculate_point(points[i], points[i+1]);
        if (t > abs(line))
            t -= abs(line);
        else {
            p1 = print_points(points[i], points[i+1], t, line);
            t -= abs(line);
            break;
        }
    }
    if (t > 0){
        line = calculate_point(points[point_size-1], points[0]);
        p1   = print_points(points[point_size-1], points[0], t, line);
    }

    if (real_time > half_line/2 && real_time < (double)(total_line + half_line)*0.5){
        tp = p1;
        p1 = p2;
        p2 = tp;
    }
    cout << p1.x << " " << p1.y << endl;
    cout << p2.x << " " << p2.y << endl;
}

int main(){
    get_points();
    make_points();
    return 0;
}
