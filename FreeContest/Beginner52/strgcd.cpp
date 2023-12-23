#include <iostream> 
#include <algorithm>
#include <math.h>
#include <string> 
#include <vector> 
std::string A, B; 
std::vector <int> listDivisors; 
std::vector <long long> hashA, hashB; 
long long power27[100005]; 
int n, m;

void init() {
  power27[0] = 1LL;
  hashA.resize(n + 1); 
  hashB.resize(m + 1); 
  hashA[0] = 0LL;
  hashB[0] = 0LL; 
  for (int i = 1; i <= m; i++) {
    power27[i] = power27[i - 1] * 27LL;
  }  
  for (int i = 1; i <= n; i++) {
    hashA[i] = hashA[i - 1] + power27[i - 1] * (A[i - 1] - 'a' + 1);  
  }
  for (int i = 1; i <= m; i++) {
    hashB[i] = hashB[i - 1] + power27[i - 1] * (B[i - 1] - 'a' + 1); 
  }
}

long long calcHash(int divisor, const std::string &s) {
  long long ret = 0LL; 
  for (int i = 0; i < divisor; i++) {
    ret += power27[i] * (s[i] - 'a' + 1);  
  }
  return ret; 
}

bool check(const int &divisor, const long long &hashValue, const std::vector <long long> &f, const std::string &s) {
  for (int i = 0; i < (int) s.size(); i += divisor) {
    int l = i;
    int r = i + divisor - 1;
    if (r >= (int) s.size()) {
      break; 
    } 
    long long hash = f[r + 1] - f[l]; 
    if (hash != power27[l] * hashValue) {
      return false; 
    }
  }  
  return true; 
}

int main () {
  std::cin >> A >> B;
  if ((int) A.size() > (int) B.size()) {
    std::swap(A, B); 
  } 
  n = (int) A.size(); 
  m = (int) B.size(); 
  init(); 
  for (int i = 1; i <= (int) std::sqrt(n); i++) {
    if (n % i == 0) {
      listDivisors.push_back(i); 
      if (i != n / i) {
        listDivisors.push_back(n / i); 
      }
    }
  }
  std::sort(listDivisors.begin(), listDivisors.end()); 
  std::reverse(listDivisors.begin(), listDivisors.end()); 
  for (int i = 0; i < (int) listDivisors.size(); i++) {
    int divisor = listDivisors[i]; 
    if (m % divisor != 0) {
      continue; 
    }                                 
    long long hashValue = calcHash(divisor, A); 
    if (check(divisor, hashValue, hashA, A) == true && check(divisor, hashValue, hashB, B) == true) {
      for (int j = 0; j < divisor; j++) {
        std::cout << A[j];
      }
      return 0; 
    }
  }
  std::cout << "NOT FOUND"; 
  return 0;
}