#include <iostream>
#include <vector> 
#include <algorithm> 
int n, numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    std::vector <int> a(n), b(n); 
    for (int i = 0; i < n; i++) {
      std::cin >> a[i]; 
    }
    for (int i = 0; i < n; i++) {
      std::cin >> b[i]; 
    }
    std::vector <int> rev_b = b;
    std::reverse(rev_b.begin(), rev_b.end()); 
    if (a == b || a == rev_b) {
      std::cout << "Bob"; 
    }
    else {
      std::cout << "Alice"; 
    }
    std::cout << std::endl;
  }
  return 0; 
}