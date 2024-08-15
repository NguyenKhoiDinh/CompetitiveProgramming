#include <iostream>
#include <vector>
#include <algorithm>
int next[1000005]; 
int a[1000005]; 
int n; 
void kmp() {
  for (int i = 2, j = 0; i <= n; i++) {
    while (j && a[j + 1] != a[i]) {
      j = next[j]; 
    }
    if (a[j + 1] == a[i]) {
      j++; 
    }
    next[i] = j; 
  }
}

int main () {
  std::ios_base::sync_with_stdio(false); 
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  std::reverse(a + 1, a + n + 1); 
  kmp(); 
  int p = 1; 
  int k = n - 1; 
  for (int i = 1; i <= n; i++) {
    int tp = i - next[i]; 
    int tk = n - i; 
    if (tp + tk < p + k) {
      p = tp;
      k = tk; 
    }
    else if (tp + tk == p + k) {
      if (tp < p) {
        tp = p; 
      }
    }
  }
  std::cout << k << ' ' << p; 
  return 0; 
}