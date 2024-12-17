#include <bits/stdc++.h> 

using namespace std;
const long long mod = 2147483647LL; 
int n;
string s; 
unordered_map <long long, int> cnt; 
long long power31[5005], inv_power31[5005]; 
long long prefix1[5005], prefix2[5005];
long long cp[5005][5005]; 
long long fastpow(const long long &x, const long long &n) {
  if (n == 0) {
    return 1LL;
  }
  long long ret = fastpow(x, n / 2);
  (ret *= ret) %= mod; 
  if (n % 2 == 1) {
    (ret *= x) %= mod; 
  }
  return ret; 
} 
//abcdeba 
void subtask2() {
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int l = i;
      int r = j; 
      while (s[l - 1] == s[r - 1] && l + 1 <= r - 1) {
        cp[i][j] += 3; 
        l++;
        r--; 
      }
      if (l + 1 == r && s[l - 1] == s[r - 1]) {
        cp[i][j] += j - i;
      }
    } 
  }                        
  long long ans = 0LL;
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      ans += cp[i][j]; 
    }
  }
  cout << ans;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL); 
  freopen("vastr.inp", "r", stdin);
  freopen("vastr.out", "w", stdout); 
  cin >> n;
  cin >> s;
  if (n <= 500) {
    subtask2();
    return 0; 
  }
  string st = s; 
  reverse(st.begin(), st.end());
  power31[0] = 1LL;
  inv_power31[0] = 1LL; 
  for (int i = 1; i <= 5000; i++) {
    power31[i] = (power31[i - 1] * 31LL) % mod;
    inv_power31[i] = fastpow(power31[i], mod - 2);  
  } 
  prefix1[0] = 0LL;
  for (int i = 1; i <= n; i++) {
    prefix1[i] = (prefix1[i - 1] + (1LL * (s[i - 1] - 'a' + 1) * power31[i]) % mod) % mod; 
  }
  prefix2[0] = 0LL;
  for (int i = 1; i <= n; i++) {
    prefix2[i] = (prefix2[i - 1] + (1LL * (st[i - 1] - 'a' + 1) * power31[i]) % mod) % mod; 
  }
  long long ans = 0LL; 
  for (int j = n; j >= 1; j--) {
    for (int i = j; i >= 1; i--) {
      long long firstHash = prefix1[j]; 
      firstHash -= prefix1[i - 1];
      if (firstHash < 0) {
        firstHash += mod; 
      }
      (firstHash *= inv_power31[i]) %= mod;
      ans += cnt[firstHash];  
    }
    for (int i = j; i <= n; i++) {
      int x = n - j + 1;
      int y = n - i + 1; 
      long long secondHash = prefix2[y]; 
      secondHash -= prefix2[x - 1];
      if (secondHash < 0) {
        secondHash += mod; 
      } 
      (secondHash *= inv_power31[x]) %= mod;
      cnt[secondHash]++;  
    }
  }
  cout << ans; 
  return 0; 
}