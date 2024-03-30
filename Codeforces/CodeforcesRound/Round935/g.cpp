#include <iostream>
#include <utility>
#include <queue> 
#include <functional> 
#include <vector>
#include <queue> 
int numTest; 
int n, D; 
std::priority_queue <std::pair <int, int> > pq[300005]; 
int k[300005], s[300005];
bool ok[300005];  

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> D;
    for (int i = 1; i <= n; i++) {
      ok[i] = false; 
    }
    for (int i = 1; i <= D; i++) {
      while (pq[i].empty() == false) {
        pq[i].pop(); 
      }
    }
    for (int i = 1; i <= n; i++) {
      std::cin >> k[i] >> s[i]; 
    }
    std::queue <int> myqueue; 
    for (int i = 1; i <= n; i++) {
      myqueue.push(i); 
    }
    int ans = -1; 
    int cnt = 0; 
    for (int i = 1; i <= D; i++) {
      if (myqueue.empty() == false) {
        int fr = myqueue.front();
        myqueue.pop();
        if (ok[fr] == false) {
          cnt++;
          ok[fr] = true; 
        }
        if (cnt == n) {
          ans = i;
          break; 
        }
        if (i + s[fr] <= D) {
          pq[i + s[fr]].push(std::make_pair(k[fr], fr)); 
        } 
      }
      while (pq[i].empty() == false) {
        std::pair <int, int> element = pq[i].top();
        pq[i].pop(); 
        myqueue.push(element.second); 
      }
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}