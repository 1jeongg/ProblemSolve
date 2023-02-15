#include <iostream>

using namespace std;

bool isInRange(int num, int x, int y) {
    return x>=1 && y>=1 && x<=num && y<=num;
}
void LRUD() {
    int num, x=1, y=1;
    char moving;
    cin >> num;
    while (cin >> moving) {
        int temp_x = x, temp_y = y;
        switch(moving) {
        case 'R': temp_y += 1; break;
        case 'L': temp_y -= 1; break;
        case 'U': temp_x -= 1; break;
        case 'D': temp_x += 1; break;
        default: cout <<"Nothing";
        }
        if (isInRange(num, temp_x, temp_y)){
            x = temp_x;
            y = temp_y;
        }
    }
    cout << x<< " " << y <<endl;
}

int main() {
    LRUD();
    return 0;
}
// example input: 5 R R R U D D
