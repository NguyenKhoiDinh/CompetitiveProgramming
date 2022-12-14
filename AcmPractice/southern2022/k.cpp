#include <iostream>
#include <map>
#include <string>
#include <math.h> 
struct element {
  int r, g, b; 
};
std::map <std::string, element> mymap; 

int main () {
  mymap["White"] = (element) {255, 255, 255};
  mymap["Silver"] = (element) {192, 192, 192};
  mymap["Gray"] = (element) {128, 128, 128};
  mymap["Black"] = (element) {0, 0, 0};
  mymap["Red"] = (element) {255, 0, 0};
  mymap["Maroon"] = (element) {128, 0, 0};
  mymap["Yellow"] = (element) {255, 255, 0};
  mymap["Olive"] = (element) {128, 128, 0};
  mymap["Lime"] = (element) {0, 255, 0};
  mymap["Green"] = (element) {0, 128, 0};
  mymap["Aqua"] = (element) {0, 255, 255};
  mymap["Teal"] = (element) {0, 128, 128};
  mymap["Blue"] = (element) {0, 0, 255};
  mymap["Navy"] = (element) {0, 0, 128};
  mymap["Fuchsia"] = (element) {255, 0, 255};
  mymap["Purple"] = (element) {128, 0, 128};
  while (true) {
    int r, g, b; 
    double mini = 10005.0000;
    std::string ans; 
    std::cin >> r >> g >> b; 
    if (r == -1 && g == -1 && b == -1) {
      break; 
    }
    for (std::map <std::string, element>::iterator it = mymap.begin(); it != mymap.end(); it++) {
      element e = it->second; 
      double d = std::sqrt((e.r - r) * (e.r - r) + (e.g - g) * (e.g - g) + (e.b - b) * (e.b - b)); 
      if (mini > d) {
        mini = d;
        ans = it->first; 
      }
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}