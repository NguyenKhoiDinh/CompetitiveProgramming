#include <iostream> 
#include <vector> 
#include <algorithm>
#include <math.h> 
#include <cstring> 
const long long mod = 1169996969LL;
std::vector <int> listPrimes; 
bool isPrime[1000005];
std::vector <long long> sum; 
long long f[2][16274630];
long long total[32][32]; 
void erathones() {
  for (int i = 1; i <= 1000000; i++) {
    isPrime[i] = true; 
  }
  isPrime[1] = false; 
  for (int i = 2; i <= 1000000; i++) {
    if (isPrime[i] == true) {
      for (int j = 2 * i; j <= 1000000; j += i) {
        isPrime[j] = false; 
      }
    } 
  }
  for (int i = 2; i <= 1000000; i++) {
    if (isPrime[i] == true) {
      listPrimes.push_back(i); 
    }
    if ((int) listPrimes.size() == 2000) {
      break; 
    }
  }
  sum.push_back(0LL);
  for (int i = 0; i < (int) listPrimes.size(); i++) {
    sum.push_back(sum.back() + listPrimes[i]); 
  }
  std::cout << sum.back() << std::endl; 
} 
void solve() {
  std::cout << '{' << std::endl; 
  const int LIM = 2000;
  f[0][0] = 1LL;
  for (int i = 0; i <= LIM; i++) {
    std::cerr << i << "  DONE!!!" << std::endl;
    int now = i % 2; 
    int nxt = !now; 
    std::memset(f[nxt], 0LL, sizeof(f[nxt])); 
    for (int s = 0; s <= sum[i]; s++) {
      if (f[now][s] == 0) {
        continue; 
      }
      (f[nxt][s] += f[now][s]) %= mod; 
      (f[nxt][s + listPrimes[i]] += f[now][s]) %= mod; 
    }
    std::memset(total, 0, sizeof(total)); 
    std::cout << '{'; 
    for (int s = 2; s < sum[i]; s++) {
      int p = s; 
      int q = sum[i] - s;
      int gcd = std::__gcd(p, q);
      p /= gcd;
      q /= gcd;
      if (p <= 30 && q <= 30) {
        (total[p][q] += f[now][s]) %= mod;   
      } 
    }
    for (int p = 1; p <= 30; p++) {
      for (int q = 1; q <= 30; q++) {
        int gcd = std::__gcd(p, q);
        if (gcd == 1) {
          std::cout << total[p][q]; 
          if (p != 30 || q != 29) {
            std::cout << ", "; 
          }
        }
      }
    }
    std::cout << "}," << std::endl; 
  } 
  std::cout << '}'; 
}

int main () {
  freopen("output.txt", "w", stdout); 
  erathones(); 
  solve(); 
  return 0; 
}