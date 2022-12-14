#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <utility> 
const long long mod = 1000000007LL; 
long long fact[30], invFact[30];
int value[400005]; 

struct element {
  int x1, x2, y;
  int value;
  bool operator < (const element &other) const {
    return y < other.y; 
  } 
};
struct segment {
  int l, r;
  long long interpolation;   
};
std::vector <element> listElement; 
std::vector <segment> listSegments; 
std::pair <long long, int> it[4 * 400005]; 
int n, pw; 
long long prefix[30], suffix[30]; 
long long f[30]; 
long long prefixSum[400005]; 

long long fastPow(const long long &x, const long long &n) {
  if (n == 0) {
    return 1LL; 
  }
  long long ret = fastPow(x, n / 2);
  (ret *= ret) %= mod; 
  if (n % 2 == 1) {
    (ret *= x) %= mod; 
  }
  return ret; 
}

void init() {
  fact[0] = 1LL;
  invFact[0] = 1LL; 
  for (int i = 1; i <= 24; i++) {
    fact[i] = (fact[i - 1] * (long long) i) % mod;
    invFact[i] = fastPow(fact[i], mod - 2); 
  }
  f[1] = 1LL; 
  for (int i = 2; i <= 24; i++) {
    f[i] = (f[i - 1] + fastPow(i, pw)) % mod; 
  }                              
} 

long long interPolation(int n, int k) {
  k += 2; 
  prefix[0] = 1LL;
  for (int i = 1; i <= k; i++) {
    prefix[i] = (prefix[i - 1] * (long long) (n - i + mod)) % mod; 
  }
  suffix[k + 1] = 1LL; 
  for (int i = k; i >= 1; i--) {
    suffix[i] = (suffix[i + 1] * (long long) (n - i + mod)) % mod; 
  }
  long long ret = 0LL; 
  for (int i = 1; i <= k; i++) {
    long long value = prefix[i - 1];
    (value *= suffix[i + 1]) %= mod; 
    (value *= invFact[i - 1]) %= mod; 
    (value *= invFact[k - i]) %= mod; 
    (value *= f[i]) %= mod;
    if ((k - i) % 2 == 0) {
      (ret += value) %= mod; 
    }
    else {
      ret -= value;
      (ret += mod) %= mod; 
    }
  }                                                
  return ret;  
}

long long sum(int L, int R) {
  long long ret = interPolation(R, pw);
  ret -= interPolation(L - 1, pw);      
  (ret += mod) %= mod;
  return ret; 
}

void update(int index, int L, int R, int l, int r, int val) {
  if (l > R || L > r) {
    return; 
  }
  if (l <= L && R <= r) {
    it[index].second += val; 
    if (it[index].second > 0) {    
      it[index].first = (prefixSum[R] - prefixSum[L - 1] + mod) % mod;
    }
    else {
      if (L < R) {
        it[index].first = (it[2 * index].first + it[2 * index + 1].first) % mod; 
      }
      else {
        it[index].first = 0;
      }
    }
    return;
  }
  int mid = (L + R) / 2; 
  update(2 * index, L, mid, l, r, val);
  update(2 * index + 1, mid + 1, R, l, r, val);
  if (it[index].second > 0) {
    it[index].first = (prefixSum[R] - prefixSum[L - 1] + mod) % mod; 
  }
  else {
    it[index].first = (it[2 * index].first + it[2 * index + 1].first) % mod; 
  }
}
 
int main () {
  std::cin >> n >> pw;
  init();
  std::vector <int> save; 
  for (int i = 1; i <= n; i++) {
    int x1, y1, x2, y2; 
    std::cin >> x1 >> y1 >> x2 >> y2; 
    save.push_back(x1 - 1);
    save.push_back(x2); 
    listElement.push_back((element) {x1, x2, y1, 1}); 
    listElement.push_back((element) {x1, x2, y2 + 1, -1}); 
  } 
  std::sort(save.begin(), save.end()); 
  for (int i = 0; i < (int) save.size() - 1; i++) {
    if (save[i] != save[i + 1]) {
      listSegments.push_back((segment) {save[i] + 1, save[i + 1], sum(save[i] + 1, save[i + 1])}); 
    }
  }
  int sz = (int) listSegments.size(); 
  for (int i = 1; i <= sz; i++) {
    prefixSum[i] = (prefixSum[i - 1] + listSegments[i - 1].interpolation) % mod; 
  }
  std::sort(listElement.begin(), listElement.end()); 
  int column = listElement[0].y; 
  long long ans = 0LL;
  for (int i = 0; i < (int) listElement.size(); i++) {
    element e = listElement[i];
    int L = -1, R = -1; 
    int lo = 0;
    int hi = sz - 1; 
    while (lo <= hi) {
      int mid = (lo + hi) / 2; 
      if (listSegments[mid].l == e.x1) {
        L = mid; 
        break; 
      }
      else if (listSegments[mid].l < e.x1) {
        lo = mid + 1; 
      }
      else {
        hi = mid - 1; 
      }
    }
    lo = 0;
    hi = sz - 1; 
    while (lo <= hi) {
      int mid = (lo + hi) / 2; 
      if (listSegments[mid].r == e.x2) {
        R = mid; 
        break; 
      }
      else if (listSegments[mid].r < e.x2) {
        lo = mid + 1; 
      }
      else {
        hi = mid - 1; 
      }
    }
    L++;
    R++;
    if (column == e.y) {
      update(1, 1, sz, L, R, e.value); 
    }
    else {
      ans += (sum(column, e.y - 1) * it[1].first) % mod;
      ans %= mod;                       
      update(1, 1, sz, L, R, e.value);
      column = e.y; 
    }
  }
  std::cout << ans; 
  return 0; 
}                             