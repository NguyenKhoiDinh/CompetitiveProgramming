#include <bits/stdc++.h> 

using namespace std;

class BalancedAirplane {
  public:
  long long count(int S, int R, vector <int> Aprefix) {
    vector <long long> a;
    int L = (int) Aprefix.size();
    a.resize(L); 
    for (int i = 0; i < L; i++) {
      a[i] = Aprefix[i];
    }
    long long state = Aprefix[L-1];
    for (int i = L; i < R; i++) {
      state = (state * 1103515245LL + 12345LL) % (1LL << (long long) 31);
      a.push_back(state >> (31 - S));
    }
    if (S == 1) {
      return 1LL * R * (R + 1) / 2; 
    }            
    map <vector <int>, int> cnt; 
    vector <int> base; 
    vector <int> sum; 
    for (int i = 1; i < S; i++) {
      base.push_back(0);
      sum.push_back(0); 
    }
    sum.push_back(0);
    cnt[base]++; 
    long long ans = 0LL;
    for (int i = 0; i < R; i++) {
      for (int b = 0; b < S; b++) {
        if ((a[i] & (1 << b)) > 0) {
          sum[b]++; 
        }
      }
      base.clear();
      for (int b = 1; b < S; b++) {
        base.push_back(sum[b] - sum[b - 1]);   
      }
      ans += cnt[base];
      cnt[base]++; 
    }
    return ans; 
  }
};

BalancedAirplane B; 

int main () {
  freopen("output.txt", "w", stdout);
  cout << B.count(1    ,
100000                  ,
{1} );
  return 0;
}



      
                                       
