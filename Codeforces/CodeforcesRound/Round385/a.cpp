#include <iostream>
#include <string>
#include <set>

int main () {
  std::string s;
  std::set <std::string> myset;
  std::cin >> s;
  for (int i = 1; i <= 1000; i++) {
    char lastChar = s.back();
    s.pop_back();
    s = lastChar + s;
    myset.insert(s);
  }
  std::cout << (int) myset.size();
  return 0;
}