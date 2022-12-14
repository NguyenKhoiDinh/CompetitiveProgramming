#include <bits/stdc++.h> 

using namespace std;
struct worker {
  long long A, B; 
};

worker a[105]; 
long long M; 
int n; 

int main () {
  cin >> n >> M;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].A >> a[i].B; 
  }
  long long lo = 1; long long hi = 100000000000000007LL; 
  long long ans = -1LL; 
  while (lo <= hi) {
    long long mid = (lo + hi) >> 1; 
    long long total = 0LL; 
    for (int i = 1; i <= n; i++) {
      long long numDays = mid / (a[i].B + 1); 
      long long rem = mid % (a[i].B + 1); 
      total += numDays * a[i].A * a[i].B; 
      total += rem * a[i].A; 
    }
    if (total >= M) {
      ans = mid;
      hi = mid - 1; 
    }
    else {
      lo = mid + 1;
    }
  }
  cout << ans;
  return 0;
}
