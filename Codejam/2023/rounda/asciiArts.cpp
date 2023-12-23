#include <bits/stdc++.h> 
int numTest; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": "; 
    long long n;
    cin >> n; 
    long long pos = 0; 
    for (long long i = 0; i <= 1000000; i++) {
      if (n > 26LL * i * (i + 1) / 2) {
        pos = i; 
      }
      else {
        break; 
      }
    }
    n -= 26LL * pos * (pos + 1) / 2;
    pos++;
    int ans = -1;
    for (int c = 0; c < 26; c++) {
      if (n > pos) {
        n -= pos; 
      }
      else {
        cout << (char) (c + 'A') << endl; 
        break;
      }
    } 
  }
  return 0; 
}