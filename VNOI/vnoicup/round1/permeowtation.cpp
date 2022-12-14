#include <iostream> 
int a[100005], b[100005];
int n; 

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i]; 
  }
  if (a[n] == b[1]) {
    std::cout << 'b'; 
    for (int i = 1; i <= n; i++) {
      std::cout << 'a'; 
    }
    for (int i = 1; i < n; i++) {
      std::cout << 'b'; 
    }
  }
  else {
    for (int i = 1; i <= n; i++) {
      std::cout << 'a'; 
    }
    for (int i = 1; i <= n; i++) {
      std::cout << 'b';
    }
  }
  return 0; 
}