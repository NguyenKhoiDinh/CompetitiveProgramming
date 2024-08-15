#include <iostream> 

using namespace std; 
int numTest; 
int p[200005]; 
int n; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    std::cin >> n; 
    for (int i = 1; i <= n; i++) {
      std::cin >> p[i]; 
    }
    std::cout << p[n] << ' '; 
    for (int i = 1; i < n; i++) {
      std::cout << p[i] << ' '; 
    }
    std::cout << std::endl;
  }
  return 0; 
}