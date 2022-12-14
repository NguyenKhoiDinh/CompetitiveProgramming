#include <bits/stdc++.h> 

using namespace std;
map <long long, pair <long long, string> > M; 
string ans = ""; 
long long anssuma = -1; 

void backTrack1(int pos, const vector <int> a, long long suma, long long sumb, string s) {
  for (char c = 'A'; c <= 'C'; c++) {
    string nexts = s;
    long long nextsuma = suma;
    long long nextsumb = sumb;
    nexts += c; 
    if (c == 'A') {
      nextsuma += a[pos];   
    }
    else if (c == 'B') {
      nextsumb += a[pos]; 
    }
    if (pos == (int) a.size() - 1) {
      if (M[nextsuma - nextsumb].first <= nextsuma) {
        M[nextsuma - nextsumb] = make_pair(nextsuma, nexts); 
      }
    }
    else {
      backTrack1(pos + 1, a, nextsuma, nextsumb, nexts); 
    }
  }        
}

void backTrack2(int pos, const vector <int> a, long long suma, long long sumb, string s) {
  for (char c = 'A'; c <= 'C'; c++) {
    string nexts = s;
    long long nextsuma = suma;
    long long nextsumb = sumb;
    nexts += c; 
    if (c == 'A') {
      nextsuma += a[pos];   
    }
    else if (c == 'B') {
      nextsumb += a[pos]; 
    }
    if (pos == (int) a.size() - 1) {
      if (M.find(nextsumb - nextsuma) != M.end()) {
        if (anssuma < suma + M[nextsumb - nextsuma].first) {
          anssuma = suma + M[nextsumb - nextsuma].first; 
          ans = ""; 
          ans += M[nextsumb - nextsuma].second; 
          ans += nexts; 
        }
      }
    }
    else {
      backTrack2(pos + 1, a, nextsuma, nextsumb, nexts); 
    }
  }        
}

class ThreeWaySplit {
  public: 
  string split(vector <int> loot) {
    int n = (int) loot.size(); 
    if (n == 1) {
      return "C";
    }
    vector <int> half1, half2; 
    for (int i = 0; i < n / 2; i++) {
      half1.push_back(loot[i]); 
    }
    for (int i = n / 2; i < n; i++) {
      half2.push_back(loot[i]); 
    }
    backTrack1(0, half1, 0, 0, "");
    backTrack2(0, half2, 0, 0, "");  
    return ans; 
  }
};
ThreeWaySplit T; 

int main () {
  cout << T.split({1, 2});

  return 0; 
}
