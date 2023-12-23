#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>
#include <ctime>        
#include <cstdlib>
#include <utility>       
long long n, m, k;
long long cnt[100005][4];  
std::vector <std::pair <std::string, int> > a; 

int main () {
  std::srand (unsigned(std::time(0)));
  std::cin >> n >> m >> k;
  a.resize(n); 
  for (int i = 0; i < n; i++) {
    std::string s; 
    std::cin >> s;
    a[i] = std::make_pair(s, i);  
  }
  std::random_shuffle(a.begin(), a.end()); 
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      cnt[j][a[i].first[j] - 'A']++; 
    }
  }
  for (int i = 0; i < n; i++) {
    long long totalDiff = 0; 
    for (int j = 0; j < m; j++) {
      totalDiff += (long long) (n - cnt[j][a[i].first[j] - 'A']); 
    }
    if (totalDiff != (long long) (n - 1) * k) {
      continue; 
    }
    bool check = true; 
    for (int x = 0; x < n; x++) {
      if (x != i) {
        long long numbDiff = 0; 
        for (int j = 0; j < m; j++) {
          if (a[i].first[j] != a[x].first[j]) {
            numbDiff++; 
          }
        }
        if (numbDiff != k) {
          check = false;
          break; 
        }
      }
    }
    if (check == true) {
      std::cout << a[i].second + 1; 
      return 0; 
    }
  }
  return 0; 
}