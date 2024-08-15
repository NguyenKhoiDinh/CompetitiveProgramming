#include <iostream>
#include <algorithm> 
#include <vector> 
int n; 
int a[100005]; 

int main () {
  int numTest; 
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    std::vector <int> v;
    for (int i = 2; i <= n; i++) {
      if (a[i] < a[i - 1]) {
        v.push_back(a[i - 1] - a[i]);
        a[i] = a[i - 1]; 
      }
    } 
    long long ans = 0LL; 
    std::sort(v.begin(), v.end()); 
    std::reverse(v.begin(), v.end());
    int numb = 0; 
    while (v.empty() == false) {
      int last = v.back();
      int sz = (int) v.size(); 
      while (v.empty() == false && v.back() == last) {
        v.pop_back(); 
      }
      ans += (long long) (last - numb) * (sz + 1); 
      numb = last;
    } 
    std::cout << ans << std::endl; 
  }
  return 0; 
}