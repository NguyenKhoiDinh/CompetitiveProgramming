#include <iostream>
#include <assert.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <set>
#include <stdlib.h> 
#include <time.h>
int numTest;
const long long LIM = 2600005LL; 
bool prime[LIM + 2]; 
std::vector <int> listPrime;
std::set <unsigned long long> canAnswer;  
unsigned long long n;

unsigned long long mulMod(unsigned long long a, unsigned long long b, unsigned long long mod) {  
  return __int128_t(a) * b % mod;
}
   
unsigned long long power(unsigned long long x, unsigned long long y, unsigned long long p) {
  unsigned long long res = 1;     
  x = x % p; 
  while (y > 0) {
    if (y % 2 == 1) {
      res = mulMod(res, x, p);
    }
    y = y >> 1;
    x = mulMod(x, x, p); 
  }
  return res;
}

bool millerTest(unsigned long long d, unsigned long long n) {
  unsigned long long a = 2ULL + std::rand() % (n - 4);
  unsigned long long x = power(a, d, n);
  if (x == 1 || x == n - 1) {
    return true;
  }
  while (d != n - 1) {
    x = mulMod(x, x, n); 
    d *= 2;
    if (x == 1)  {
      return false;
    }
    if (x == n - 1) {
      return true;
    }
  }
  return false;
}

bool isPrime(unsigned long long n, int k) {
  if (n <= 1 || n == 4) {
    return false;
  }
  if (n <= 3) {
    return true;
  }
  unsigned long long d = n - 1;
  while (d % 2 == 0) {
    d /= 2;
  }
  for (int i = 0; i < k; i++) {
    if (millerTest(d, n) == false) {
      return false;
    }
  }
  return true;
}

void erathones() {              
  for (int p = 2; p <= LIM; p++) {
    prime[p] = true; 
  }
  for (int p = 2; p * p <= LIM; p++) {
    if (prime[p] == true) {
      for (int j = p * p; j <= LIM; j += p) {
        prime[j] = false;   
      }
    }
  }
  for (int p = 2; p <= LIM; p++) {
    if (prime[p] == true) {
      listPrime.push_back(p); 
    }
  }
  for (int i = 0; i < (int) listPrime.size(); i++) {
    unsigned long long mul = 1ULL; 
    for (int j = i; j < (int) listPrime.size(); j++) {
      if (mul <= 10000000000000000000ULL / listPrime[j]) {
        mul *= 1ULL * listPrime[j]; 
        canAnswer.insert(mul); 
      }
      else {
        break;
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::srand(time(NULL));
  erathones(); 
  int k = 10;
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    std::set <unsigned long long>::iterator it = canAnswer.find(n); 
    if (it != canAnswer.end()) {
      std::cout << "NICE" << std::endl;
      continue; 
    }
    unsigned long long sqrtn = (unsigned long long) std::sqrt(n); 
    if (sqrtn * sqrtn == n) {
      std::cout << "UGLY" << std::endl;
      continue; 
    }
    bool isUgly = false; 
    for (int i = 0; i < 30; i++) {
      if (n % listPrime[i] == 0) {
        std::cout << "UGLY" << std::endl; 
        isUgly = true; 
        break; 
      }
    }
    if (isUgly == true) {
      continue;
    }
    unsigned long long p1 = sqrtn;
    if (p1 % 2 == 0) {
      p1--; 
    } 
    while (p1 > 0 && isPrime(p1, k) == false) {
      p1 -= 2; 
    }
    unsigned long long p2 = sqrtn + 1;
    if (p2 % 2 == 0) {
      p2++; 
    } 
    while (p2 <= n && isPrime(p2, k) == false) {
      p2 += 2; 
    }
    if (p1 * p2 == n) {
      std::cout << "NICE" << std::endl;
      continue; 
    }
    if (isPrime(n, k) == true) {
      std::cout << "NICE" << std::endl; 
      continue; 
    }
    std::cout << "UGLY" << std::endl;
  }
  return 0;
}