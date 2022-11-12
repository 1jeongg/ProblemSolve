#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>

using namespace std;

list<char> chromosome;
string     command;
int        command_size, start_index, end_index;

void get_file_input(){

    ifstream inpFile;
    string firstLine;
    char c;

    inpFile.open("sapiens.txt");

    if (inpFile.is_open()){
        getline(inpFile, firstLine);
        while(inpFile.get(c)){
            if (c != '\n') chromosome.push_back(c);
        }
    }
    inpFile.close();
} // end of get_file_input()

int is_okay(){

    int chromosome_size = chromosome.size();
    if (start_index > end_index)       return -1;
    if (start_index > chromosome_size) return -1;
    if (end_index   > chromosome_size) return 0;
    return 1; // no error
} // end of is_okay

void chromosome_function(){

    auto it_start = chromosome.begin();
    auto it_end   = chromosome.begin();

    int okay = is_okay(); // check exception
    if (okay < 0){
        if (command == "report") cout << "NONE" << endl;
        return;
    }
    if (okay == 0) end_index = chromosome.size();

    advance(it_start, start_index-1); // set starting point of subList
    advance(it_end, end_index); // set ending point of subList

    if (command == "front") // splice substring to front
        chromosome.splice(chromosome.begin(), chromosome, it_start, it_end);

    if (command == "back") // splice substring to back
        chromosome.splice(chromosome.end(), chromosome, it_start, it_end);

    if (command == "cut") // erase substring
        chromosome.erase(it_start, it_end);

    if (command == "double") // insert substring
        chromosome.insert(it_end, it_start, it_end);

    if (command == "flip") // reverse substring
        reverse(it_start, it_end);

    if (command == "report"){ // print substring
        for (auto it = it_start; it != it_end; it++)
            cout << *it;
        cout << endl;
    }
}// end of chromosome_function

void get_command_input(){

    cin >> command_size;
    for (int i=0; i<command_size; i++){
        cin >> command >> start_index >> end_index;
        chromosome_function();
    }
} // end of get_command_input

int main(){
    get_file_input();
    get_command_input();
    return 0;
} // end of main
