#include <iostream> 
bool take[100005]; 
int n, query;
int a[100005];  

int main () {
  std::cin >> n >> query;
  for (int i = 1; i <= query; i++) {
    std::cin >> a[i];
  }
  for (int i = query; i >= 1; i--) {
    if (take[a[i]] == false) {
      take[a[i]] = true;
      std::cout << a[i] << ' '; 
    }
  }
  for (int i = 1; i <= n; i++) {
    if (take[i] == false) {
      std::cout << i << ' '; 
    }
  }
  return 0; 
}