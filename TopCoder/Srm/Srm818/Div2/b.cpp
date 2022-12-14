#include <bits/stdc++.h> 

using namespace std;
map <long long, int> cnt; 

class EqualPiles {
  public:
  int equalize(int N, int M, int T) {
    for (int i = 0; i < N; i++) {
      cnt[(1 + 1LL * i * i % M)]++; 
    }  
    int numCandies = N;
    int ans = -1;  
    for (map <long long, int> :: iterator it = cnt.begin(); it != cnt.end(); it++) {
      //cout << it->second << endl;
      if (numCandies >= T) {
        int cntCandy = it->second;
        ans = max(ans, min(cntCandy + T, N));
        numCandies -= cntCandy;
      }
      else {
        break; 
      }
    }
    return ans;
  }
};

EqualPiles E; 
                 
int main () {
  cout << E.equalize(100000,
7                           ,
1);
  return 0; 
}

// 14286