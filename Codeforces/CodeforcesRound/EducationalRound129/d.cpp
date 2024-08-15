#include <iostream>
#include <map>
#include <queue>
long long reach = 1LL; 
int n; 
long long x; 
std::queue <long long> myqueue; 
std::map <long long, int> dist; 

int main () {
  std::cin >> n >> x; 
  for (int i = 1; i < n; i++) {
    reach *= 10LL; 
  }
  int len = 0;
  long long t = x; 
  while (t > 0) {
    len++; 
    t /= 10; 
  }
  if (len == n) {
    std::cout << 0; 
    return 0; 
  }
  myqueue.push(x); 
  dist[x] = 0; 
  while (myqueue.empty() == false) {
    long long v = myqueue.front();
    myqueue.pop(); 
    long long tmp = v; 
    while (tmp > 0) {
      int x = tmp % 10;
      tmp /= 10; 
      if (x != 0 && (reach / x < v || (reach / x == v && reach % v == 0))) {
        std::cout << dist[v] + 1; 
        return 0; 
      }
      long long nxtv = v * x; 
      if (dist.find(nxtv) == dist.end()) {
        dist[nxtv] = dist[v] + 1; 
        myqueue.push(nxtv); 
      }
    }
  }
  std::cout << -1; 
  return 0; 
}