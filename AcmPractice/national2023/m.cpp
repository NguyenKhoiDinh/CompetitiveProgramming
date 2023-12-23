#include <iostream>
#include <string>
int n; 
std::string s; 
int ask(const std::string &s) {
  std::cout << "? " << s << std::endl; 
  fflush(stdout);
  int ok;
  std::cin >> ok;
  return ok; 
}

std::string flip(int position) {
  std::string ret = s; 
  for (int i = 0; i <= position; i++) {
    if (ret[i] == '0') {
      ret[i] = '1';
    }
    else {
      ret[i] = '0';                  
    }
  }
  return ret; 
}

int main () {
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    s += '0'; 
  }
  int ok = ask(s); 
  if (ok == 1) {
    s = flip(n - 1); 
  }
  int lo = -1;  
  int hi = n - 1; 
  int position = -1; 
  while (lo <= hi) {
    int mid = (lo + hi) / 2; 
    std::string tmp = flip(mid);
    ok = ask(tmp);
    if (ok == 0) {               
      position = mid;
      lo = mid + 1; 
    } 
    else {
      hi = mid - 1; 
    }
  }
  s = flip(position); 
  std::string ans = ""; 
  for (int i = 0; i < n; i++) {
    int c = s[i] - '0';
    std::string tmp = s;
    if (c == 0) {
      tmp[i] = '1'; 
    }   
    else {
      tmp[i] = '0'; 
    }          
    ok = ask(tmp); 
    if (ok == 0) {
      ans += (char) (!c + '0');
    }
    else {
      ans += (char) (c + '0');  
    }
  }
  std::cout << "! " << ans << std::endl;
  fflush(stdout); 
  return 0; 
}