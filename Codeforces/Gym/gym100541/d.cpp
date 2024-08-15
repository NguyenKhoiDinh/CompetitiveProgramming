#include <iostream>
#include <algorithm> 
#include <vector> 
int k, numTest; 
long long n; 
bool visited[100];
std::vector <int> cycle;  
int trace[100]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k;
    for (int i = 0; i < 100; i++) {
      visited[i] = false;
      trace[i] = -1;  
    }
    cycle.clear(); 
    int x = n % 100;
    int len = 0;
    visited[x] = true;
    while (true) {
      int prev = x; 
      x = 2 * x;
      x %= 100;
      if (visited[x] == true) {
        int start = x;
        x = prev;  
        while (x != start) {
          cycle.push_back(x); 
          x = trace[x]; 
        }
        cycle.push_back(start);
        std::reverse(cycle.begin(), cycle.end()); 
        break; 
      }  
      visited[x] = true;
      trace[x] = prev; 
    }
    x = n % 100;
    while (x != cycle[0] && k > 0) {
      n += x; 
      x *= 2; 
      x %= 100;
      k--;  
    }  
    len = (int) cycle.size(); 
    for (int i = 0; i < len; i++) {
      n += (long long) (k / len) * (cycle[i]);   
    }
    k %= len;
    for (int i = 0; i < k; i++) {
      n += cycle[i];
    } 
    std::cout << n << std::endl;
  }
  return 0; 
}