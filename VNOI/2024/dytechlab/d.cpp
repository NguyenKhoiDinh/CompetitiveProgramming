#include <bits/stdc++.h> 

using namespace std;
int numTest;
string s;
int cnt[26];  

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> s;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < (int) s.size(); i++) {
      cnt[s[i] - 'a']++; 
    }   
    int numbOdd = 0;
    int maxCnt = 0;
    for (int c = 0; c < 26; c++) {
      maxCnt = max(maxCnt, cnt[c]); 
      if (cnt[c] % 2 == 1) {
        numbOdd++; 
      }
    } 
    if (maxCnt == (int) s.size() || numbOdd == 1) {
      cout << "Amidala" << endl; 
    }
    else {
      cout << "Skywalker" << endl; 
    }
  }
  return 0; 
}