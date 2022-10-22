#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<string>                code;
vector<vector<string>>       all_function;
vector<pair<string, int>>    my_function;
vector<pair<string, string>> output;

int N, k1, k2;

void get_input(){
    cin >> N >> k1 >> k2;
    for (int i=0; i<N; i++){
        string inp = "";
        all_function.push_back(vector <string>());
        cin >> inp;
        my_function.push_back(make_pair(inp, 0));
        while (true){
            cin >> inp;
            if (inp == "$") break;
            all_function[i].push_back(inp);
        }
    }
}
int get_function_index(string s){
    for (int i=0; i<N; i++){
        if (my_function[i].first == s)
            return i;
    }
    return -1;
}
void print_myfunc(int index){
    cout << output[index-1].first << "-" << output[index-1].second << endl;
}
void print_output(){
    bool b1 = (k1 <= output.size()), b2 = (k2 <= output.size());
    if (b1 && b2){
        print_myfunc(k1); print_myfunc(k2);
    }
    if (b1 && !b2){
        print_myfunc(k1); cout << "NONE" << endl;
    }
    if (!b1 && b2){
        cout << "NONE" << endl; print_myfunc(k2);
    }
    if (!b1 && !b2){
        cout << "NONE" << endl;
    }
}

int is_deadlock(string s, stack<string> my_stack){
    while(!my_stack.empty()){
        if (s == my_stack.top()) return 1;
        my_stack.pop();
    }
    return 0;
}
void code_run(){
    int index, function_index, function_size;
    code.push("M");
    while (!code.empty()){
        index = get_function_index(code.top());
        function_index = my_function[index].second;
        function_size  = all_function[index].size();

        for (int i=function_index; i<function_size; i++){
            my_function[index].second += 1;
            int my = get_function_index(all_function[index][i]);
            if (my >= 0){
                if (is_deadlock(my_function[my].first, code) == 1) {
                    cout << "DEADLOCK" << endl;
                    return;
                }
                code.push(my_function[my].first);
                break;
            }
            else output.push_back(make_pair(code.top(), all_function[index][i]));

        }
        if (function_index == function_size){
            my_function[index].second = 0;
            code.pop();
        }
    }
    print_output();
}

int main(){
    get_input();
    code_run();
    return 0;
}
