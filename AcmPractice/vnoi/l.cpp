#include <bits/stdc++.h> 

using namespace std;
int numTest;
long long N; 
vector <pair <long long, int> > save; 
set <long long> res;

void backTrack(int pos, long long divisor) {
  if (pos == (int) save.size()) {
    long long right = N / divisor;
    long long delta = 1LL + 4LL * right; 
    long long sqrtDelta = (long long) sqrt(delta);
    if (sqrtDelta * sqrtDelta == delta) {
      res.insert((-1 + sqrtDelta) / 2);
    }
    return;  
  }
  backTrack(pos + 1, divisor); 
  if (save[pos].second > 0) {
    save[pos].second--; 
    backTrack(pos, divisor * save[pos].first); 
    save[pos].second++; 
  }
}    

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> N; 
    if (N % 2 == 1) {
      cout << -1 << endl; 
      continue; 
    }
    save.clear(); 
    long long lim = 1000000; 
    long long K = N; 
    for (int p = 2; p <= min(N, lim); p++) {
      int cnt = 0; 
      while (K % p == 0) {
        cnt++; 
        K = K / p; 
      }
      if (cnt != 0) {
        save.push_back(make_pair(p, cnt)); 
      }
    }
    if (K > 1) {
      save.push_back(make_pair(K, 1)); 
    }
    res.clear();
    backTrack(0, 1LL);
    for (set <long long> :: iterator it = res.begin(); it != res.end(); it++) {
      cout << *it << ' '; 
    } 
    cout << endl; 
  }
  return 0; 
}