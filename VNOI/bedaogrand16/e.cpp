#include <iostream>
#include <vector>
const long long mod = 998244353; 
long long fact[2000005], inv_fact[2000005];
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
void init() {
  fact[0] = 1LL;
  inv_fact[0] = 1LL;
  for (int i = 1; i <= 2000000; i++) {
    fact[i] = (fact[i - 1] * i) % mod; 
    inv_fact[i] = fastpow(fact[i], mod - 2); 
  }
}
long long C(int n, int k) {
  long long ret = fact[n];
  (ret *= inv_fact[k]) %= mod;
  (ret *= inv_fact[n - k]) %= mod; 
  return ret; 
}
std::vector <int> adj[3005];
int p[3005];
int n, m;   
int salary[3005];
int a[3005];
long long ans = 0LL;  
bool check[10]; 
bool isValid() {
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (int) adj[i].size(); j++) {
      int neighbor = adj[i][j];
      if (a[neighbor] < a[i] && salary[neighbor] > salary[i]) {
        return false; 
      } 
    }
  }
  return true; 
}
void backTrack(int p) {
  for (int i = 1; i <= m; i++) {
    if (check[i] == true) {
      continue;  
    }
    check[i] = true; 
    salary[p] = i;
    if (p == n) {
      if (isValid() == true) {
        ans++; 
      }
    }
    else {
      backTrack(p + 1); 
    }  
    check[i] = false; 
  }
}

int main () {
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    std::cin >> p[i];
    if (p[i] != 0) {
      adj[p[i]].push_back(i);
      adj[i].push_back(p[i]); 
    }
  } 
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  if (n <= 9 && m <= 9) {
    backTrack(1);
    std::cout << ans;
    return 0;  
  }
  init(); 
  long long ret = C(m, n); 
  (ret *= fact[n]) %= mod; 
  std::cout << ret; 
  return 0; 
}