#include <iostream> 
#include <math.h> 
long long power10[6] = {1, 10, 100, 1000, 10000, 100000}; 

long long rev(long long N) {
  long long ret = 0; 
  while (N > 0) {
    int r = N % 10;
    N /= 10;
    ret = ret * 10LL + r; 
  }
  return ret; 
}

int calc10(int N) {
  if (N == 0) {
    return 0;
  }
  if (N < 10) {
    return 1; 
  }
  if (N < 100) {
    return 2; 
  }
  if (N < 1000) {
    return 3; 
  }
  if (N < 10000) {
    return 4; 
  }
  return 5; 
}

long long f(int N) {
  long long ret = 0LL; 
  for (long long i = 0; i < 100000; i++) {
    int len = calc10(i);
    long long cur = i;
    cur = cur * power10[len] + rev(cur);
    if (cur <= N) {
      ret += cur; 
    }  
    for (int x = 0; x <= 9; x++) {
      cur = i; 
      long long reve = rev(cur); 
      cur = cur * 10LL + (long long) x; 
      cur = cur * power10[len] + reve; 
      if (cur <= N) {                 
        ret += cur; 
      }
    }
  }  
  return ret; 
}

int main () {
  int L, R;
  std::cin >> L >> R;
  std::cout << f(R) - f(L - 1); 
  return 0; 
}