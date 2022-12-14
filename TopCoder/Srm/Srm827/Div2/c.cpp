#include <bits/stdc++.h> 

using namespace std;

class CoinFlipping {
  public:
  int mostHeads(vector <string> a) {
    int ans = -1; 
    int n = (int) a.size();
    int m = (int) a[0].size(); 
    for (int mask = 0; mask < (1 << n); mask++) {
      int sum = 0; 
      for (int j = 0; j < m; j++) {
        int maxi = -1; 
        for (int change = 0; change <= 1; change++) {
          int numbH = 0; 
          for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) > 0) {
              if (change == 1 && a[i][j] == 'H') {
                numbH++;   
              }
              else if (change == 0 && a[i][j] == 'T') {
                numbH++; 
              }
            }
            else {
              if (change == 1 && a[i][j] == 'T') {
                numbH++; 
              }
              else if (change == 0 && a[i][j] == 'H') {
                numbH++; 
              }
            }  
          }
          maxi = max(maxi, numbH); 
        }
        sum += maxi; 
      }
      ans = max(ans, sum);   
    } 
    return ans; 
  }
};

CoinFlipping C; 

int main () {
  cout << C.mostHeads({"HT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HT",
 "HT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HT",
 "HT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HT",
 "HT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HT","HT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HT",
 "HT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HT",
 "HT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HT",
 "HT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HT","HT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HT",
 "HT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HT",
 "HT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HT",
 "HT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HTHT.HT"});
  return 0; 
}