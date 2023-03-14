#include <iostream>
#include <vector>
#include "container.h"

using namespace std;
vector<vector<int>> boxes;

void makeTournamentTree(vector<int> box, int box_size){
    vector<int> new_box;
    if (box_size == 1) return;
    for (int i=0; i<box_size/2; i++){
        bool isLarger = box_comp(box[2*i], box[2*i+1]) == 1;
        if (isLarger)
            new_box.push_back(box[2*i]);
        else
            new_box.push_back(box[2*i+1]);
    }
    if (box_size%2 == 1) new_box.push_back(box[box_size-1]);
    boxes.push_back(new_box);
    makeTournamentTree(new_box, new_box.size());
}
void makeLoserTree() {
    vector<int> box;
    int largest = boxes.back().back();
    for (int i=0; i<boxes.size(); i++){
        for (int j=0; j<boxes[i].size(); j++){
            if (boxes[i][j] == largest){
                if (j%2 == 1)
                    box.push_back(boxes[i][j-1]);
                else if (j<boxes[i].size()-1)
                    box.push_back(boxes[i][j+1]);
            }
        }
    }
    boxes.push_back(box);
    makeTournamentTree(box, box.size());
}
int getSecondLargest(int box_size) {
    vector<int> box;
    for(int i=1; i<=box_size; i++){
        box.push_back(i);
    }
    boxes.push_back(box);
    makeTournamentTree(box, box_size);
    makeLoserTree();
    return boxes.back().back();
}
void main_container() {
    box_ready();
    int n = box_size();
    int result = getSecondLargest(n);
    box_report(result);
}
int main() {
    main_container();
    return 0;
}
