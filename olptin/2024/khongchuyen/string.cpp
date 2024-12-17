#include <iostream>
#include <string> 
int n;             
std::string s; 
std::string ans1 = "", ans2 = ""; 
bool check(const std::string &s1, const std::string &s2) {
  int p1 = 0;
  int p2 = 0; 
  while (p1 < (int) s1.size()) {
    while (p2 < (int) s2.size() && s1[p1] != s2[p2]) {
      p2++; 
    }                                            
    if (p2 < (int) s2.size()) {
      p1++;
      p2++; 
    }
    else {
      break;
    }
  }
  if (p1 == (int) s1.size()) {
    return true; 
  }
  return false; 
}
void solve(int mid, std::string &ans, bool ok) {
  std::string st = "";
  if (ok == false) {
    for (int i = 0; i < mid; i++) {
      st += s[i]; 
    }
  }
  else {
    for (int i = mid + 1; i < n; i++) {
      st += s[i]; 
    }
  }                         
  if (ok == false && check(st + st, s) == true) {
    ans = st;     
  }
  else if (ok == true && check(st + st, s) == true) {
    ans = st; 
  }
}

int main () {
  std::cin >> n;
  std::cin >> s; 
  if (n % 2 == 0) {
    std::cout << "No Solution"; 
    return 0; 
  }
  int mid = n / 2; 
  solve(mid, ans1, false);
  solve(mid, ans2, true);
  if (ans1 == "" && ans2 == "") {
    std::cout << "No Solution"; 
  }  
  else if (ans1 != "" && ans2 != "") {
    if (ans1 == ans2) {
      std::cout << ans1;
    }
    else {
      std::cout << "Multiple Solutions"; 
    }
  }
  else if (ans1 != "") {
    std::cout << ans1; 
  }
  else {
    std::cout << ans2; 
  }
  return 0; 
}