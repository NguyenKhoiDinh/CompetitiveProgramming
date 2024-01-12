#include <iostream> 
#include <vector> 
int numTest; 
int p[2005]; 
int n; 

void process(std::vector <int> &a) {
  if (a.empty() == true) {
    return;   
  }
  if ((int) a.size() == 1) {
    std::cout << a[0];
    return; 
  }
  if ((int) a.size() == 2) {
    std::cout << a[1] << ' ' << a[0]; 
    return; 
  }
  for (int i = (int) a.size() - 2; i >= 0; i--) {
    if (a[i] <= a[0]) {
      for (int j = (int) a.size() - 1; j > i; j--) {
        std::cout << a[j] << ' ';
      }
      for (int j = 0; j <= i; j++) {
        std::cout << a[j] << ' '; 
      }
      return;  
    }
  }
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> p[i]; 
    }
    int posN = 1;
    int posN1 = 1;  
    for (int i = 1; i <= n; i++) {
      if (p[i] == n) {
        posN = i;
      }
      if (p[i] == n - 1) {
        posN1 = i; 
      }
    }
    std::vector <int> a;
    if (posN == n) {
      for (int i = 1; i <= n; i++) {
        a.push_back(p[i]); 
      } 
      process(a); 
      std::cout << std::endl; 
      continue; 
    } 
    if (posN > 1) {
      for (int i = posN; i <= n; i++) {
        std::cout << p[i] << ' '; 
      }
      for (int i = 1; i < posN; i++) {
        a.push_back(p[i]); 
      }
    }
    else {
      if (posN1 == n) {
        for (int i = 1; i <= n; i++) {
          a.push_back(p[i]); 
        } 
        process(a); 
        std::cout << std::endl; 
        continue; 
      }
      for (int i = posN1; i <= n; i++) {
        std::cout << p[i] << ' '; 
      }  
      for (int i = 1; i < posN1; i++) {
        a.push_back(p[i]); 
      }
    }
    process(a);
    std::cout << std::endl;  
  }
  return 0; 
}