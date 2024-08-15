#include <iostream>
#include <vector> 
int cnt[200005]; 
int a[200005]; 
std::vector <int> ans;
bool visited[200005]; 

int main () {
  int n, k; 
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    cnt[a[i]]++; 
  } 
  for (int i = 1; i <= n; i++) {
    cnt[a[i]]--; 
    while (visited[a[i]] == false && ans.empty() == false && ans.back() > a[i] && cnt[ans.back()] > 0) { 
      visited[ans.back()] = false; 
      ans.pop_back();
    }
    if (visited[a[i]] == false) {
      ans.push_back(a[i]); 
      visited[a[i]] = true; 
    }
  }
  for (int i = 0; i < (int) ans.size(); i++) {
    std::cout << ans[i] << ' ';
  }
  return 0; 
}