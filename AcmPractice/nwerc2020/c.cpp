#include <bits/stdc++.h> 

using namespace std;
int n, k; 
long long s, d; 

int main () {
  cin >> n >> k >> s >> d; 
  long long total = s * n;
  long long totalSolved = d * k; 
  long long diff = total - totalSolved; 
  if (diff < 0 || diff > (n - k) * 100) {
    cout << "impossible"; 
  }
  else {
    double ans = 1.0 * diff; 
    ans /= (double) (n - k); 
    cout << fixed << setprecision(12) << ans; 
  }
  return 0; 
}