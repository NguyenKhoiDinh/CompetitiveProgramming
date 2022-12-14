#include <iostream> 

long long ask(long long a, long long b) {
  std::cout << "? " << a << ' ' << b << std::endl; 
  long long length;
  std::cin >> length; 
  return length; 
}

int main () {
  long long n; 
  long long dist1 = -1, dist2 = -1; 
  for (int i = 1; i <= 45; i++) {
    dist1 = ask(i, i + 1);
    dist2 = ask(i + 1, i);
    if (dist1 == -1) {
      std::cout << "! " << i << std::endl;
      return 0; 
    } 
    if (dist1 != dist2) {
      std::cout << "! " << dist1 + dist2 << std::endl; 
    }
  }  
  return 0; 
}