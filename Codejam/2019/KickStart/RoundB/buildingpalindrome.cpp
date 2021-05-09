#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 100005; 
const int BLOCK = 305; 
struct segment {
  int L, R; 
};

bool compare(segment &a, segment &b) {
  if (a.R / BLOCK != b.R / BLOCK) {
    return (a.L / BLOCK < b.L / BLOCK);
  }
  return (a.R < b.R);
}
int n, numQuery;
vector <segment> save; 
string s; 
int cnt[26];

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n >> numQuery;
    cin >> s; 
    save.clear(); 
    for (int c = 0; c < 26; c++) {
      cnt[c] = 0; 
    }
    for (int i = 1; i <= numQuery; i++) {
      int L, R; 
      cin >> L >> R;
      L--;
      R--; 
      save.push_back((segment) {L, R});
    }
    sort(save.begin(), save.end(), compare);
    int curL = save[0].L; 
    int curR = save[0].R; 
    int ans = 0;
    for (int i = curL; i <= curR; i++) {
      cnt[s[i] - 'A']++;
    }
    int numbOdd = 0; 
    for (int c = 0; c < 26; c++) {
      if (cnt[c] % 2 == 1) {
        numbOdd++; 
      }
    }
    if (numbOdd <= 1) {
      ans++; 
    }
    for (int i = 1; i < numQuery; i++) {
      while (curL < save[i].L) {
        cnt[s[curL] - 'A']--; 
        curL++;
      }
      while (curL > save[i].L) {
        curL--; 
        cnt[s[curL] - 'A']++; 
      }
      while (curR < save[i].R) {
        curR++;
        cnt[s[curR] - 'A']++; 
      }
      while (curR > save[i].R) {
        cnt[s[curR] - 'A']--;
        curR--; 
      }
      numbOdd = 0; 
      for (int c = 0; c < 26; c++) {
        if (cnt[c] % 2 == 1) {
          numbOdd++; 
        }
      }
      if (numbOdd <= 1) {
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0; 
}