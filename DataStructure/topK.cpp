#include <iostream>
#include <algorithm>

using namespace std;

typedef struct MyMusic{
    string title;
    char   genre;
    double file_size;
    int    bangsong, download;
} Music;

Music music[101];
int   MUSIC_SIZE, RANKING;

void get_input(){
    cin >> MUSIC_SIZE >> RANKING;

    for (int i=0; i<MUSIC_SIZE; i++){
        cin >> music[i].title >> music[i].genre >> music[i].bangsong
            >> music[i].file_size >> music[i].download;
    }
}
bool compareMusic(Music a, Music b){                  // sort by bangsong, download, file_size
    if (a.bangsong != b.bangsong) return a.bangsong > b.bangsong;
    if (a.download != b.download) return a.download > b.download;
    return a.file_size < b.file_size;
}

void sort_non_continuous(){
    for (int i=1; i<MUSIC_SIZE; i++){
        if (i == RANKING) return;                     // don't have to sort behind the RANKING
        if (music[i].genre != music[i-1].genre) continue;

        for (int j=i+1; j<MUSIC_SIZE; j++){           // if genre comes continuous
            if (music[i].genre != music[j].genre) {   // find the genre that is different
                swap(music[i],  music[j]);
                sort(music+i+1, music+j+1, compareMusic); // sort between the changed songs
                break;
            }
        }
    }
}

int main(){
    get_input();
    sort(music, music + MUSIC_SIZE, compareMusic);
    sort_non_continuous();
    cout << music[RANKING-1].title << endl;
    return 0;
}
