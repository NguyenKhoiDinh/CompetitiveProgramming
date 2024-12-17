#include <bits/stdc++.h> 

using namespace std;
const long long mod = 1000000007LL; 
int n;
int a[16]; 
bool check[1605]; 
int pos[1605];
vector <int> listNumbers;
int sum[(1 << 16) + 5]; 

int main () {
  cin >> n;
  assert(1 <= n && n <= 16); 
  for (int i = 0; i < n; i++) {
    cin >> a[i]; 
    assert(1 <= a[i] && a[i] <= 100); 
  }
  for (int mask = 0; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
      if ((mask & (1 << i)) > 0) {
        sum[mask] += a[i]; 
      }
    }
    check[sum[mask]] = true; 
  }
  for (int s = 0; s <= 1600; s++) {
    if (check[s] == true) {
      for (int j = 1; j <= s; j++) {
        if (s % j == 0) {
          check[j] = true; 
        }
      }     
    }
  }
  for (int s = 0; s <= 1600; s++) {
    if (check[s] == true) {
      pos[s] = (int) listNumbers.size(); 
      listNumbers.push_back(s);
    }
  }                                                                  
  int sz = (int) listNumbers.size();
  vector <vector <long long> > f((1 << n) + 5);
  for (int mask = 0; mask < (1 << n); mask++) {
    f[mask].resize(sz, 0LL);
  } 
  f[0][0] = 1;
  for (int mask = 0; mask < (1 << n); mask++) {
    int t = -1;
    for (int x = 0; x < n; x++) {
      if ((mask & (1 << x)) == 0) {
        t = x; 
        break; 
      }
    }
    if (t == -1) {         
      break; 
    }
    for (int i = 0; i < sz; i++) {
      if (f[mask][i] == 0) {
        continue; 
      }
      int other = (1 << n) - 1 - mask - (1 << t);
      for (int submask = other; ; submask = (submask - 1) & other) {
        int nextMask = submask | (1 << t);
        int number = listNumbers[pos[sum[nextMask]]];
        number = (i == 0 ? number : __gcd(number, listNumbers[i]));
        f[mask | nextMask][pos[number]] += f[mask][i];
        if (submask == 0) {
          break;
        }  
      }  
    }
  }
  long long ans = 0LL;
  for (int i = 0; i < sz; i++) {
    int number = listNumbers[i];
    ans += f[(1 << n) - 1][i] * (long long) number;  
  }  
  cout << ans;    
  return 0; 
}