#include <iostream>
#include <algorithm>

using namespace std;

typedef struct MyPoint{
    int x, y;
} Point;

int   point_size, total_line;
int   time_points[5];
Point points[51];

int calculate_line(Point a, Point b){
    if (b.x == a.x) return b.y - a.y;
    return b.x - a.x;
} // end of calculate_line

void print_points(Point a, Point b, int time, int line){
    int is_plus = (line > 0) - (line < 0);
    if (a.x == b.x)
        cout << a.x << " " << a.y + time*is_plus << endl; // up,   right (plus)
    else
        cout << a.x + time*is_plus << " " << a.y << endl; // down, left  (minus)
} // end of print_points

void get_input(){
    int x, y, time;
    cin >> point_size;

    for (int i=0; i<point_size; i++){
        cin >> x >> y;
        points[i].x = x;
        points[i].y = y;
        if (i > 0) // sum of lines
            total_line += abs(calculate_line(points[i], points[i-1]));
    }
    total_line += abs(calculate_line(points[point_size-1], points[0]));

    for (int i=0; i<5; i++){
        cin >> time;
        time_points[i] = time;
    }
} // end of get_input

void make_points(){
    int time_count = 0, line;

    for (auto time: time_points){
        time_count = time%total_line;

        for (int i = 0; i<point_size-1; i++){
            line = calculate_line(points[i], points[i+1]);

            if (time_count > abs(line))
                time_count -= abs(line);
            else {
                print_points(points[i], points[i+1], time_count, line);
                time_count -= abs(line);
                break;
            }
        }

        if (time_count > 0){ // the case you don't get a break
            line = calculate_line(points[point_size-1], points[0]);
            print_points(points[point_size-1], points[0], time_count, line);
        }
    }
} // end of make_points

int main(){
    get_input();
    make_points();
    return 0;
}
