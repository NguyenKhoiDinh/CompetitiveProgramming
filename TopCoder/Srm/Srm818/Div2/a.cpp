#include <bits/stdc++.h> 

using namespace std;
long long T[1000005]; 
long long sum[1000005];

class GlobalWarmingCheck {
  public:
  vector <int> solve(int N, int M, int Y) {
    for (int i = 0; i < N; i++) {
      T[i] = (1LL * i * i + 4LL * i + 7) % M;
      if (i == 0) {
        sum[i] = T[i];
      }  
      else {
        sum[i] = sum[i - 1] + T[i]; 
      }
    }
    int lo, hi;
    long long mini = 100000000000000007LL;
    long long maxi = -mini;
    for (int i = 0; i + Y - 1 < N; i++) {
      if (mini > sum[i + Y - 1] - sum[i] + T[i]) {
        mini = sum[i + Y - 1] - sum[i] + T[i];
        lo = i; 
      }  
      if (maxi <= sum[i + Y - 1] - sum[i] + T[i]) {
        maxi = sum[i + Y - 1] - sum[i] + T[i];
        hi = i;   
      }
    }
    vector <int> ans;
    ans.push_back(lo);
    ans.push_back(hi);
    return ans; 
  }
};
GlobalWarmingCheck G;

int main () {
  vector <int> ans = G.solve(12, 20, 4); 
  cout << ans[0] << ' ' << ans[1];
  return 0; 
}