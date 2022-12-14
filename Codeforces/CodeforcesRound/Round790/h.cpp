#include <iostream>
#include <cstring>  
int numTest; 
int fw[200005]; 
int n; 

void update(int index, int value) {
  for (; index <= 200000; index += index & -index) {
    fw[index] += value; 
  }
}

int get(int index) {
  int ret = 0; 
  for (; index > 0; index -= index & -index) {
    ret += fw[index]; 
  }
  return ret; 
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    std::memset(fw, 0, sizeof(fw)); 
    long long ans = 0LL; 
    for (int i = 1; i <= n; i++) {
      int value; 
      std::cin >> value; 
      ans += i - 1 - get(value - 1); 
      update(value, 1); 
    } 
    std::cout << ans << std::endl;
  }
  return 0; 
}