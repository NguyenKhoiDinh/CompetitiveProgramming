#include <iostream> 
#include <math.h>
#include <vector> 
#include <string> 
int f[105][105][105]; 
int convertToInt(const std::string s) {
  int ret = 0;
  for (int i = 0; i < (int) s.size(); i++) {
    ret = ret * 10 + s[i] - '0'; 
  }
  return ret; 
}
std::vector <int> process() {
  std::cin.clear(); 
  std::string s; 
  std::getline(std::cin, s);
  std::vector <int> ret;
  std::string st = ""; 
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == ' ') {
      ret.push_back(convertToInt(st));
      st = "";  
    }
    else {
      st += s[i]; 
    }
  }  
  ret.push_back(convertToInt(st));
  return ret; 
}

int main () {
  std::vector <int> a = process();
  std::vector <int> b = process();
  std::vector <int> c = process();  
  int sza = (int) a.size();
  int szb = (int) b.size(); 
  int szc = (int) c.size(); 
  for (int i = 1; i <= sza; i++) {
    for (int j = 1; j <= szb; j++) {
      for (int k = 1; k <= szc; k++) {
        f[i][j][k] = std::max(f[i - 1][j][k], std::max(f[i][j - 1][k], f[i][j][k - 1])); 
        if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1]) {
          f[i][j][k] = std::max(f[i][j][k], f[i - 1][j - 1][k - 1] + 1); 
        }
      }
    }
  }
  std::cout << f[sza][szb][szc]; 
  return 0; 
}