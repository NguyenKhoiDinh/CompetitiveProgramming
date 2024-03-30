#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector> 
#include <map> 
int numTest; 
int weight[200005];
int fw[200005]; 
int n; 
int p[200005]; 
std::vector <int> save; 
std::map <int, int> id; 
int value[200005]; 
void update(int index, int value) {
  for (; index <= n; index += index & -index) {
    fw[index] += value;   
  }
}

int get(int index) {
  int ret = 0;
  for (; index > 0; index -= index & -index) {
    ret += fw[index];
  }
  return ret; 
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    save.clear(); 
    id.clear(); 
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      fw[i] = 0; 
      value[i] = 0; 
      std::cin >> weight[i]; 
      save.push_back(weight[i]); 
    }
    for (int i = 1; i <= n; i++) {
      std::cin >> p[i]; 
    }
    std::sort(save.begin(), save.end()); 
    for (int i = 0; i < (int) save.size(); i++) {
      if (id.find(save[i]) == id.end()) {
        int sz = (int) id.size(); 
        id[save[i]] = sz + 1; 
        value[sz + 1] = save[i]; 
      }
    }
    for (int i = 0; i < (int) save.size(); i++) {
      update(id[save[i]], 1); 
    }
    long long ans = -1;
    int ansNumb = -1;  
    for (int numb = 1; numb <= n; numb++) {
      int lo = 1;
      int hi = n;
      int total = get(n); 
      int pos = -1;
      while (lo <= hi) {
        int mid = (lo + hi) / 2; 
        int cnt = total - get(mid - 1); 
        if (cnt >= numb) {
          pos = mid;
          lo = mid + 1;     
        }
        else {
          hi = mid - 1; 
        }
      }
      if (pos != -1) {
        if (ans < std::max(ans, (long long) numb * value[pos])) {
          ans = std::max(ans, (long long) numb * value[pos]);
          ansNumb = numb;
        } 
      }     
      update(id[weight[p[numb]]], -1);  
    }
    std::cout << ans << ' ' << ansNumb << std::endl; 
  }
  return 0; 
}