#include <iostream>
#include <vector> 
int numTest; 
int n; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {                  
    std::cin >> n;
    int maxPos = 0; 
    for (int i = 1; i < n; i++) {
      std::cout << "? " << maxPos << ' ' << maxPos << ' ' << i << ' ' << i << std::endl; 
      fflush(stdout); 
      char c;
      std::cin >> c; 
      if (c == '<') {
        maxPos = i; 
      }
    }
    std::vector <int> index; 
    index.push_back(0); 
    for (int i = 1; i < n; i++) {
      std::cout << "? " << index[0] << ' ' << maxPos << ' ' << i << ' ' << maxPos << std::endl;
      fflush(stdout);
      char c;
      std::cin >> c;
      if (c == '=') {
        index.push_back(i); 
      }  
      else if (c == '<') {
        index.clear(); 
        index.push_back(i); 
      }
    }
    int minPos = index[0]; 
    for (int i = 1; i < (int) index.size(); i++) {
      std::cout << "? " << minPos << ' ' << minPos << ' ' << index[i] << ' ' << index[i] << std::endl;
      fflush(stdout);
      char c;
      std::cin >> c;
      if (c == '>') {
        minPos = index[i]; 
      }  
    }
    std::cout << "! " << minPos << ' ' << maxPos << std::endl;
    fflush(stdout); 
  }
  return 0; 
}