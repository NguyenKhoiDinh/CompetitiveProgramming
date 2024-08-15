#include <iostream>
#include <vector> 
#include <string>
#include <set> 
std::string s1 = "QWERTYUIOP", s2 = "ASDFGHJKL", s3 = "ZXCVBNM"; 
std::string st1, st2, st3;
bool lost[26];  
int numQueries; 
std::set <char> v; 

int main () {
  std::cin >> st1 >> st2 >> st3; 
  for (int i = 0; i < (int) st1.size(); i++) {
    if (st1[i] == '*') {
      lost[s1[i] - 'A'] = true;
      v.insert(s1[i]); 
    }
  }
  for (int i = 0; i < (int) st2.size(); i++) {
    if (st2[i] == '*') {
      lost[s2[i] - 'A'] = true; 
      v.insert(s2[i]); 
    }
  }
  for (int i = 0; i < (int) st3.size(); i++) {
    if (st3[i] == '*') {
      lost[s3[i] - 'A'] = true;
      v.insert(s3[i]); 
    }
  }
  std::cin >> numQueries;
  for (int query = 1; query <= numQueries; query++) {
    std::string pass; 
    std::cin >> pass; 
    bool ok = true; 
    std::set <char> tmp; 
    for (int i = 0; i < (int) pass.size(); i++) {
      if (lost[pass[i] - 'A'] == false) {
        ok = false;
        break; 
      }  
      tmp.insert(pass[i]); 
    }
    std::cout << ((ok == true && ((int) v.size() == (int) tmp.size())) ? "POSSIBLE" : "IMPOSSIBLE") << std::endl;
  } 
  return 0; 
}