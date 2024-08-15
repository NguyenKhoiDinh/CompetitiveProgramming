#include <iostream>
#include <string>
#include <vector>
std::vector <std::string> day = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"}; 
int n; 
bool isLeap(int y) {
  if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
    return true; 
  }
  return false; 
}

int main () {               
  std::cin >> n;
  int days = 0; 
  int year = 1867; 
  for (int i = 1; i <= n; i++) {
    days += 365;
    year++; 
    if (isLeap(year) == true) {
      days++;
    }    
  }
  days %= 7; 
  int current = 6; 
  current += days; 
  current %= 7;
  std::cout << day[current];  
  return 0; 
}