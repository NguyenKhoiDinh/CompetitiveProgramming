#include <bits/stdc++.h>

using namespace std;
char vo[5] = {'a', 'e', 'i', 'o', 'u'}; 

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    cin >> n;
    int cnt[26] = {0}; 
    for (int i = 0; i < n; i++) {
      cnt[vo[i % 5] - 'a']++; 
    }
    for (int i = 0; i < 26; i++) {
      while (cnt[i] > 0) {
        cout << (char) (i + 'a'); 
        cnt[i]--; 
      }
    }
    cout << endl;
  }
  return 0; 
}