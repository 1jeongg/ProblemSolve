#include <iostream>
#include <vector>
#include <algorithm>
#define PRINT_BLANK(x) cout << 0        << " " << x << endl  // empty column number
#define PRINT_POINT(x) cout << x.second << " "               // point's column number
#define PRINT_NUM(x)   cout << x        << endl;

using namespace std;

int jungle_size;
vector<pair<int, int>> jungle; // row, column

void get_row_order(){ // make points
    int inp, row_index = 0;
    cin >> jungle_size;
    jungle.push_back(make_pair(0,0));
    while(cin >> inp){
        if(inp){ // if inp > 0
            row_index += 1;
            while(1){
                jungle.push_back(make_pair(inp, row_index)); // point's row number
                cin >> inp;
                if (inp == 0) break;
            }
        } else { // if inp == 0
            cin >> inp; // empty row number
            row_index += inp;
        }
    }
}

int find_difference(int i){
    return jungle[i].first - jungle[i-1].first;
}

void get_column_order(){
    int column_index = 1, difference, last_blank;
    sort(jungle.begin(), jungle.end()); // make points sorted by row

    PRINT_NUM(jungle_size);

    while(column_index < jungle.size()){
        difference = find_difference(column_index);
        if (difference > 1) PRINT_BLANK(difference-1); // empty column's number

        PRINT_POINT(jungle[column_index]); // print index's column point

        while(find_difference(column_index+1) == 0){
            PRINT_POINT(jungle[column_index+1]); // print sequence index's column point
            column_index += 1;
        }

        PRINT_NUM(0); // end of non empty points
        column_index += 1;
    }

    last_blank = jungle_size-jungle[jungle.size()-1].first; // last blank column num
    if (last_blank) PRINT_BLANK(last_blank);
}

int main(){
    get_row_order();
    get_column_order();
    return 0;
}
