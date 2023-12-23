#include <iostream> 
#include <vector>
#include <algorithm> 
int numTest; 
int n; 
int a[200005]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    std::vector <int> even, odd; 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
      if (a[i] % 2 == 0) {
        even.push_back(a[i]); 
      }  
      else {
        odd.push_back(a[i]); 
      }
    }
    std::sort(even.begin(), even.end());
    std::sort(odd.begin(), odd.end());
    if (even.empty() == true || odd.empty() == true) {
      std::cout << "YES" << std::endl; 
      continue; 
    }
    if (even[0] > odd[0]) {
      std::cout << "YES"; 
    }
    else {
      std::cout << "NO"; 
    }
    std::cout << std::endl; 
  }
  return 0; 
}