#include <iostream>
#include <vector>

using namespace std;
int file_capacity, file_size;
string file_name;
vector <pair<string, int>> file;

int get_empty_size(){
    int mysize = file_capacity;
    for (auto &w: file){
        if (w.first != "") mysize -= w.second;
    }
    return mysize;
}
void write_file(){
    cin >> file_name >> file_size;
    if (get_empty_size() < file_size) {
        cout << "diskfull" << endl;
        return;
    }

    for (int i=0; i<file.size(); i++){
        if(file[i].first == "" && file[i].second >= file_size){
            int temp = file[i].second;
            file[i] = make_pair(file_name, file_size);
            file.insert(file.begin()+i+1, make_pair("", temp - file_size));
            return;
        }
    }
    for (int i=0; i<file.size(); i++){
        if(file[i].first == "" && file[i].second != 0){
            file[i].first = file_name;
            int temp = file[i].second;

            if (temp < file_size) file_size -= temp;
            else {
                file[i].second = file_size,
                file.insert(file.begin()+i+1, make_pair("", temp-file_size));
                return;
            }
        }
    }
}
void show_file(){
    int index = 0;
    bool flag = true;
    cin >> file_name;
    for (auto &w: file){
        if (w.first == file_name){
            cout << index << " ";
            flag = false;
        }
        index += w.second;
    }
    if (flag) cout << "error";
    cout << endl;
}
void compact_empty(int index){
    int tmp = index;
    for (int i = index-1; i>=0; i--){
        if (file[i].first == ""){
            file[index].second += file[i].second;
            file[i].second = 0;
        }
        else break;
    }
    for (int i = index+1; i<file.size(); i++){
        if (file[i].first == ""){
            file[index].second += file[i].second;
            file[i].second = 0;
        }
        else break;
    }
}
void delete_file(){
    cin >> file_name;
    bool flag = true;
    int index = 0;
    while (index < file.size()){
        if (file[index].first == file_name) {
            file[index].first = "";
            compact_empty(index);
            flag = false;
        }
        index ++;
    }
    if (flag) cout << "error" << endl;
}
void compact_file(){
    int tmp = 0;
    string s = "";
    for (int i=0; i<file.size(); i++){
        if (file[i].first == "") file[i].second = 0;
        else{
            if (file[i].first == s){
                file[tmp].second += file[i].second;
                file[i].first = "", file[i].second = 0;
            }
            else{
                tmp = i;
                s = file[tmp].first;
            }
        }
    }
    file.push_back(make_pair("", get_empty_size()));
}
void disk(){
    cin >> file_capacity;
    file.push_back(make_pair("", file_capacity));

    string inp = "";
    while(cin >> inp){
        if (inp == "end")     break;
        if (inp == "write")   write_file();
        if (inp == "show")    show_file();
        if (inp == "delete")  delete_file();
        if (inp == "compact") compact_file();
    }
}

int main(){
    disk();
    return 0;
}
