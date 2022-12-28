#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Guest {
    int arrive_time, id, consult_time;
    Guest(int _arrive, int _id, int _consult)
        : arrive_time(_arrive), id(_id), consult_time(_consult) {};

    bool operator<(const Guest guest) const {
        if (this->consult_time == guest.consult_time)
            return this->id > guest.id;
        return this->consult_time < guest.consult_time;
    }
};

int currentTime = 30;
vector<Guest> waitingRoom;
Guest getTopGuest() {
    priority_queue<Guest> v;
    for (auto w: waitingRoom) {
        if (w.arrive_time <= currentTime) v.push(w);
    }
    while (v.empty()){
        currentTime ++;
        for (auto w: waitingRoom) {
            if (w.arrive_time <= currentTime) v.push(w);
        }
    }
    return v.top();
}

void getInput() {
    int arrive_inp, id_inp,consult_inp;
    int i=0, inp;
    cin >> inp;
    while (i++ < inp){
        cin >> arrive_inp >> id_inp >> consult_inp;
        waitingRoom.push_back(Guest(arrive_inp, id_inp, consult_inp));
    }
}

void consulting() {
    while (!waitingRoom.empty()) {
        Guest topGuest = getTopGuest();
        waitingRoom.erase(remove_if(
            waitingRoom.begin(), waitingRoom.end(),
            [&](Guest const & Guest) { return Guest.arrive_time == topGuest.arrive_time; }));
        if (topGuest.consult_time <= 10){
            currentTime += topGuest.consult_time;
            cout << topGuest.id << endl;
        } else {
            currentTime += topGuest.consult_time / 2;
            topGuest.consult_time -= topGuest.consult_time / 2;
            waitingRoom.push_back(topGuest);
        }
    }
}

int main() {
    getInput();
    consulting();
    return 0;
}
