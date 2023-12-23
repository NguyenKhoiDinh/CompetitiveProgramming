#include <iostream>
#include <string>
#include <math.h>
std::string s;
struct element {
  long long numbCorrect = 0LL; 
  int fOpen1 = 0, fClose1 = 0;
  int fOpen2 = 0, fClose2 = 0;
  int fOpen3 = 0, fClose3 = 0;
  int fOpen4 = 0, fClose4 = 0; 
};   

element solve(int L, int R) {
  if (L == R) {
    element ret;
    if (s[L] == '(') {
      ret.fOpen1++;   
    }  
    else if (s[L] == ')') {
      ret.fClose1++;
    }
    else if (s[L] == '[') {
      ret.fOpen2++;
    }
    else if (s[L] == ']') {
      ret.fClose2++; 
    }
    else if (s[L] == '{') {
      ret.fOpen3++;
    }
    else if (s[L] == '}') {
      ret.fClose3++; 
    }
    else if (s[L] == '<') {
      ret.fOpen4++;
    }
    else if (s[L] == '>') {
      ret.fClose4++; 
    }
    return ret; 
  }
  int mid = (L + R) / 2;
  element C1 = solve(L, mid);
  element C2 = solve(mid + 1, R);
  element ret;
  ret.numbCorrect = C1.numbCorrect + C2.numbCorrect;
  int valid1 = std::min(C1.fOpen1, C2.fClose1);
  ret.numbCorrect += valid1;
  ret.fOpen1 = C1.fOpen1 + C2.fOpen1 - valid1;
  ret.fClose1 = C1.fClose1 + C2.fClose1 - valid1;
  int valid2 = std::min(C1.fOpen2, C2.fClose2);
  ret.numbCorrect += valid2;
  ret.fOpen2 = C1.fOpen2 + C2.fOpen2 - valid2;
  ret.fClose2 = C1.fClose2 + C2.fClose2 - valid2;
  int valid3 = std::min(C1.fOpen3, C2.fClose3);
  ret.numbCorrect += valid3;
  ret.fOpen3 = C1.fOpen3 + C2.fOpen3 - valid3;
  ret.fClose3 = C1.fClose3 + C2.fClose3 - valid3;
  int valid4 = std::min(C1.fOpen4, C2.fClose4);
  ret.numbCorrect += valid4;
  ret.fOpen4 = C1.fOpen4 + C2.fOpen4 - valid4;
  ret.fClose4 = C1.fClose4 + C2.fClose4 - valid4;
  std::cout << L << "     " << R << "     " << ret.numbCorrect << std::endl;
  return ret;   
}                           

int main () {
  freopen("tbrackets.inp", "r", stdin);
  freopen("tbrackets.out", "w", stdout);
  std::cin >> s; 
  std::cout << solve(0, (int) s.size() - 1).numbCorrect; 
  return 0; 
}