#include <bits/stdc++.h>

using namespace std;
const long long mod = 1000000007LL; 
long long p[200005]; 
long long ways[1024][2][2];
vector <int> save[1024];  
int a[200005]; 
long long f[2][1024]; 
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
long long inv10000 = fastPow(10000LL, mod - 2); 
int n; 

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    for (int v = 0; v <= 1023; v++) {
      save[v].clear(); 
    }
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
    }
    for (int i = 1; i <= n; i++) {
      cin >> p[i];
      save[a[i]].push_back(p[i]);  
    }
    memset(f, 0LL, sizeof(f));
    memset(ways, 0LL, sizeof(ways));
    vector <int> listElements; 
    for (int v = 0; v <= 1023; v++) {
      if (save[v].empty() == true) {
        continue; 
      }
      listElements.push_back(v);
      ways[v][0][0] = 1LL;
      for (int i = 0; i < (int) save[v].size(); i++) {
        int now = i % 2; 
        int nxt = !now; 
        ways[v][nxt][0] = ways[v][nxt][1] = 0LL;  
        for (int even = 0; even <= 1; even++) {
          if (ways[v][now][even] == 0) {
            continue; 
          }
          (ways[v][nxt][even] += (((ways[v][now][even] * (10000LL - save[v][i])) % mod) * inv10000) % mod) %= mod;
          (ways[v][nxt][1 - even] += (((ways[v][now][even] * (save[v][i])) % mod) * inv10000) % mod) %= mod;
        }
      }
      int sz = (int) save[v].size(); 
    //  cout << v << "      " << ways[v][sz % 2][0] << "     " << ways[v][sz % 2][1] << endl; 
    }
    int szElement = (int) listElements.size();
    f[0][0] = 1LL; 
    for (int i = 0; i < szElement; i++) {
      int element = listElements[i]; 
      int sz = (int) save[element].size(); 
      int now = i % 2;
      int nxt = !now;  
      memset(f[nxt], 0LL, sizeof(f[nxt])); 
      for (int value = 0; value <= 1023; value++) {
        if (f[now][value] == 0) {
          continue; 
        }
        (f[nxt][value] += (f[now][value] * ways[element][sz % 2][0]) % mod) %= mod;  
        (f[nxt][value ^ element] += (f[now][value] * ways[element][sz % 2][1] % mod)) %= mod; 
      }
    }
    long long ans = 0LL; 
    for (long long value = 1; value <= 1023; value++) {
      long long mul = value;
      (mul *= value) %= mod;
      (mul *= f[szElement % 2][value]) %= mod;
      (ans += mul) %= mod;   
    }
    cout << ans << endl; 
  }
  return 0; 
}