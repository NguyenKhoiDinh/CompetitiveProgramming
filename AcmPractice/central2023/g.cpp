#include <iostream>
#include <vector>
#include <set>
std::vector <int> grundy = {0,1,2,4,3,5,6,8,7,9,10};  
int g[10005];

void createGrundy() {
  int cur = 12;
  bool flag = true;  
  for (int i = 1; i <= 10000; i++) {
    grundy.push_back(cur);
    if (flag == true) {
      cur--;
    }
    else {
      cur++; 
    }
    grundy.push_back(cur);
    cur += 2;
    flag = !flag;     
  }  
}

int main () {
  createGrundy();
  int n;
  std::cin >> n;
  int ans = 0; 
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    ans ^= grundy[x]; 
  } 
  std::cout << (ans > 0 ? "Alice" : "Bob");
  return 0; 
}