#include <iostream>

using namespace std;
int single, day, triple, week, ticket_size;
int ticket_sum[366] = {0, };
int tickets[366] = {0, };

void getInput(){
    cin >> single >> day >> triple >> week;
    cin >> ticket_size;
    for (int i=0; i<ticket_size; i++){
        int d, r;
        cin >> d >> r;
        tickets[d] = min(day, single*r);
        ticket_sum[d] = tickets[d];
    }
}

void main_tram() {
    ticket_sum[2] += tickets[1];
    for (int i=3; i<=365; i++){
        ticket_sum[i] = min(ticket_sum[i-1] + tickets[i], ticket_sum[i-3] + triple);
        if (i%7 == 0)
            ticket_sum[i] = min(ticket_sum[i], ticket_sum[i-7] + week);
    }
    cout << ticket_sum[365];
}
int main() {
    getInput();
    main_tram();
    return 0;
}
