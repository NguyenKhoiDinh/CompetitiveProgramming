#include <bits/stdc++.h> 

using namespace std;

class BearSong {
  public: 
  int countRareNotes(vector <int> notes) {
    vector <int> cnt(1005, 0);
    for (int i = 0; i < (int) notes.size(); i++) {
      cnt[notes[i]]++;
    }
    int ans = 0; 
    for (int i = 1; i <= 1000; i++) {
      if (cnt[i] == 1) {
        ans++;
      }
    }
    return ans;
  }
};

int main () {
  return 0;
}