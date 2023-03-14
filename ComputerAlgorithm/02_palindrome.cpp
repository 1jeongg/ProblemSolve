#include <iostream>
#include <string>
#define PALINDROME 1
#define SIMILAR_PALINDROME 2
#define OTHER 3

using namespace std;

bool isPalinValid(string str, int i, int j){
    while (i < j) {
        if (str[i++] != str[j--])
            return false;
    }
    return true;
}

int isSimiliarPalin(string &str, int &i, int &j){
    if (isPalinValid(str, i+1, j) || isPalinValid(str, i, j-1))
        return SIMILAR_PALINDROME;
    return OTHER;
}

int isPalindrome(string str) {
    int start_index = 0;
    int end_index = str.length()-1;
    while (start_index <= end_index){
        if (str[start_index] == str[end_index]) {
            start_index++;
            end_index--;
            continue;
        }
        return isSimiliarPalin(str, start_index, end_index);
    }
    return PALINDROME;
}

void main_palin() {
    int string_size;
    string inp;
    cin >> string_size;
    for (int i=0; i<string_size; i++){
        cin >> inp;
        cout << isPalindrome(inp) << endl;
    }
}

int main() {
    main_palin();
    return 0;
}
