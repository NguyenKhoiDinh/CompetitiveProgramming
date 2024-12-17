#include <iostream> 
#include <vector> 
#include <unordered_map> 
const long long mod = 998244353LL;
std::unordered_map <long long, long long> ways;  
long long f[200005];
long long power[20]; 
std::vector <int> listPrimes[1000005];
int n;
int a[200005];
bool isPrime[1000005]; 
void erathones() {
  power[0] = 1LL;
  for (int i = 1; i <= 19; i++) {
    power[i] = power[i - 1] * 1000000007LL; 
  }
  for (int i = 2; i <= 1000000; i++) {
    isPrime[i] = true; 
  }  
  for (int p = 2; p <= 1000000; p++) {
    if (isPrime[p] == true) {
      for (int j = 2 * p; j <= 1000000; j += p) {
        isPrime[j] = false; 
      }
    }
  }
  for (int p = 2; p <= 1000000; p++) {
    if (isPrime[p] == true) {
      for (int j = p; j <= 1000000; j += p) {
        listPrimes[j].push_back(p); 
      }
    }
  }
}   

int main () {
  erathones();
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  } 
  f[1] = 1; 
  for (int i = 1; i <= n; i++) { 
    std::vector <int> &v = listPrimes[a[i]];
    int sz = (int) v.size();
    for (int mask = 1; mask < (1 << sz); mask++) {
      long long hashValue = 0LL;
      int pos = 0;
      for (int j = 0; j < sz; j++) {
        if ((mask & (1 << j)) > 0) {
          hashValue += (long long) v[j] * power[pos + 1]; 
          pos++; 
        }
      }
      if (pos % 2 == 1) {
        (f[i] += ways[hashValue]) %= mod; 
      }  
      else {
        f[i] -= ways[hashValue]; 
        if (f[i] < 0) {
          (f[i] += mod) %= mod; 
        }
      }
    }
    for (int mask = 1; mask < (1 << sz); mask++) {
      long long hashValue = 0LL;
      int pos = 0;
      for (int j = 0; j < sz; j++) {
        if ((mask & (1 << j)) > 0) {
          hashValue += (long long) v[j] * power[pos + 1]; 
          pos++; 
        }
      }  
      (ways[hashValue] += f[i]) %= mod; 
    } 
  }
  std::cout << f[n]; 
  return 0; 
}