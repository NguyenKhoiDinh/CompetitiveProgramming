#include <iostream>
#include <string> 
#include <iomanip>
int numTest; 
int convertToInt(const std::string &s) {
  int ret = 0;
  for (int i = 0; i < (int) s.size(); i++) {
    ret = ret * 10 + s[i] - '0'; 
  }
  return ret; 
}

void convertTo12HourFormat(int hour, int minute) {
  std::string period = (hour < 12) ? "AM" : "PM";
  if (hour == 0) {
    hour = 12;
  } else if (hour > 12) {
    hour -= 12;
  }
  std::cout << std::setw(2) << std::setfill('0') << hour << ":" << std::setw(2) << std::setfill('0') << minute << " " << period << std::endl;
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::string s;
    std::cin >> s; 
    std::string sh = "";
    sh += s[0];
    sh += s[1]; 
    std::string sm = "";
    sm += s[3];
    sm += s[4];
    convertTo12HourFormat(convertToInt(sh), convertToInt(sm)); 
  }
  return 0; 
}