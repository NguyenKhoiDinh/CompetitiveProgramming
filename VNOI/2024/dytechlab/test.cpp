#include <bits/stdc++.h> 

using namespace std;
vector <int> sum; 
int a[16]; 
long long ans = 0LL;
int n;  
void backTrack(int pos) {
  if (pos == n) {
    int value = sum[0];
    for (int i = 1; i < (int) sum.size(); i++) {
      value = __gcd(value, sum[i]); 
    }
    ans += value; 
    return; 
  }
  for (int i = 0; i < (int) sum.size(); i++) {
    sum[i] += a[pos];
    backTrack(pos + 1);
    sum[i] -= a[pos];    
  }
  sum.push_back(a[pos]);
  backTrack(pos + 1);
  sum.pop_back();  
}

int main () {
  freopen("input.txt", "r", stdin); 
  freopen("output.txt", "w", stdout); 
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i]; 
  }
  backTrack(0);  
  cout << ans; 
  return 0; 
}