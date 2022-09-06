#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
vector<int> signal;    // range: signal      <= 100000
long long signal_size; // range: signal_size <= 2**31
int SIGNAL;            // range: SIGNAL      <= 100000
void print_signal(bool is_T);

void read_txt(){
    string s;
    ifstream myfile ("zsignal.txt");

    long long i = 0 ;  // range: i <= 2**31
    if (myfile.is_open()) {
        while (myfile >> s) {
            signal.push_back(stoi(s));
            if (i >= 1){
                if (signal[i] == 0);
                else if (signal[i-1] == 0) signal_size += signal[i];
                else signal_size++; // entire signal's size
            }
            i++;
        }
        SIGNAL = signal[0]; // The first signal
        myfile.close();
    }
}
void get_question(){
    char QUESTION;
    while(cin >> QUESTION){
        if (QUESTION == 'T') print_signal(true);
        if (QUESTION == 'M') print_signal(false);
    }
}
void print_signal(bool is_T){
    long long u,v,i=1, cnt=1;      // range: u,v,i,cnt        <= 2**31
    int min_sig=100000, max_sig=0; // range: min_sig, max_sig <= 100000
    int out_signal=SIGNAL;         // range: out_signal       <= 100000

    if (is_T){
        cin >> v;
        u = 0;
    } else cin >> u >> v;

    if (u > signal_size || v > signal_size) {
        cout << -1 << endl;
        return;
    }

    while (cnt<=v){
        if (signal[i] == 0){
            cnt += signal[i+1];
            i++;   // index of signal
        } else {
            out_signal += signal[i];
            cnt++; // total signal size of this point
        }
        i++;

        if (cnt>=u){
            if (out_signal < min_sig) min_sig = out_signal;
            if (out_signal > max_sig) max_sig = out_signal;
        }
    }

    if (is_T) cout << out_signal << endl;
    else      cout << min_sig << " " << max_sig << endl;
}

int main(){
    read_txt();
    get_question();
    return 0;
}

