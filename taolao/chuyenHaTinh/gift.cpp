#include <bits/stdc++.h> 
using namespace std;
int numTest, A, B, C; 
bool f[33][2]; 

int main () {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> A >> B >> C; 
    for (int i = 0; i <= 29; i++) {
      f[i][0] = false; 
      f[i][1] = false; 
    }
    f[0][0] = true;
    for (int i = 0; i < 29; i++) {
      int ba = (A & (1 << i)) > 0; 
      int bb = (B & (1 << i)) > 0; 
      int bc = (C & (1 << i)) > 0; 
      for (int rem = 0; rem <= 1; rem++) {
        if (f[i][rem] == false) {
          continue;
        }
        for (int b = 0; b <= 1; b++) {
          if (((ba ^ b) + (bb ^ b) + rem) % 2 == (bc ^ b)) {
            int nextRem = ((ba ^ b) + (bb ^ b) + rem) / 2;
            f[i + 1][nextRem] = true;  
          }
        }
      }
    }
    cout << (f[29][0] == true ? "YES" : "NO") << endl; 
  }
  return 0;
}