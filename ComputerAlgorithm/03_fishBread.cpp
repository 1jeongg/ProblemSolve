#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string flipComplex(vector<int> fish_point) {
    int a = fish_point[0], b = fish_point[1], c = fish_point[2];
    if (a > 0){
        if (a == max({a, abs(b), abs(c)})
            && abs(b) == min({a, abs(b), abs(c)})) return "two";
    }
    if (b > 0) {
        if (abs(a) <= b && b <= abs(c)) return "two";
        if (abs(c) <= b && b <= abs(a)) return "two";
    }
    if (c > 0) {
        if (abs(b) == max({abs(a), abs(b), abs(c)})
            && abs(c) == min({abs(a), abs(b), abs(c)})) return "two";
    }
    return "over";
}
string getFishFlipCount(vector<int> fish_point){
    int positive_count=0, negative_count=0;
    for (auto point: fish_point) {
        if (point > 0) positive_count++;
        else negative_count++;
    }
    if (negative_count == 1) {
        if (positive_count == 0) return "one";
        if (positive_count == 1) return "two";
    }
    if (negative_count == 2){
        if (positive_count == 0) return "two";
        if (positive_count == 1) return flipComplex(fish_point);
    }
    return "over";
}

void makeEachFish(int fish_size) {
    int inp, previous_fish = 0;
    vector<int> fish_point;
    for (int i=0; i<fish_size; i++){
        cin >> inp;
        if (previous_fish+1 == inp) {
            previous_fish++;
            continue;
        }
        if (i+1 != inp)
            fish_point.push_back(inp);
        previous_fish = inp;
    }
    cout << getFishFlipCount(fish_point) << endl;
}
void main_fish() {
    int fish_size;
    cin >> fish_size;
    for (int i=0; i<5; i++){
        makeEachFish(fish_size);
    }
}

int main() {
    main_fish();
    return 0;
}
