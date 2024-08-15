#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <random>
#include <math.h>
#include <utility> 
#include <unordered_map>
struct point {
  int x, y; 
};
struct vecto {
  int x, y; 
};
std::vector <point> a;
std::vector <vecto> listVecto;  
int n;   
bool visited[16]; 
int ans = 0; 
void backTrack(int numbPairs, int last) {
  for (int i = last + 1; i < n; i++) {
    if (visited[i] == true) {
      continue; 
    }
    for (int j = i + 1; j < n; j++) {
      if (visited[j] == true) {
        continue; 
      }
      visited[i] = true;
      visited[j] = true; 
      listVecto.push_back((vecto) {a[j].x - a[i].x, a[j].y - a[i].y});
      if (numbPairs + 1 == n / 2) {
        std::unordered_map <double, int> cnt; 
        for (int i = 0; i < (int) listVecto.size(); i++) {
          if (listVecto[i].y == 0) {
            cnt[1000000000]++; 
          }
          else { 
            cnt[(double) listVecto[i].x / (double) listVecto[i].y]++; 
          }
        }
        int total = 0; 
        for (std::unordered_map <double, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
          total += it->second * (it->second - 1) / 2; 
        }
        ans = std::max(ans, total); 
      }
      else {
        backTrack(numbPairs + 1, i); 
      }
      visited[i] = false;
      visited[j] = false;
      listVecto.pop_back();  
    }
  }
}

int main () {
  std::cin >> n;
  a.resize(n); 
  for (int i = 0; i < n; i++) {
    std::cin >> a[i].x >> a[i].y; 
  }
  backTrack(0, -1); 
  std::cout << ans; 
  return 0; 
}