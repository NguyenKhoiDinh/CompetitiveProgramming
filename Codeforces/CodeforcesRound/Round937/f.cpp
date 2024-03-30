#include <iostream>
#include <vector>
#include <queue>
#include <functional> 
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int a, b, c;
    std::cin >> a >> b >> c;
    if (c == 0 && (a > 0 || b > 0)) {
      std::cout << -1 << std::endl; 
      continue; 
    }
    std::priority_queue <int, std::vector <int>, std::greater <int> > pq; 
    for (int i = 1; i <= c; i++) {
      pq.push(0); 
    }
    for (int i = 1; i <= b; i++) {
      int element = pq.top();
      pq.pop(); 
      element++; 
      pq.push(element); 
    }
    bool ok = true; 
    for (int i = 1; i <= a; i++) {
      if ((int) pq.size() > 1) {
        int element1 = pq.top();
        pq.pop();
        int element2 = pq.top();
        pq.pop();  
        element2++;
        pq.push(element2); 
      }
      else {
        ok = false;
        break; 
      }
    }
    if ((int) pq.size() > 1) {
      ok = false;
    }
    if (ok == false) {
      std::cout << -1 << std::endl; 
    }
    else {
      std::cout << pq.top() << std::endl;
    }
  }
  return 0; 
}