#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
int numTest; 
int n; 
std::vector <std::string> a; 
char good; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> good;
    good -= 'A'; 
    a.clear(); 
    a.resize(2 * n);
    for (int i = 0; i < 2 * n; i++) {
      std::cin >> a[i]; 
    }
    std::vector <std::vector <int> > group(26); 
    for (int i = 0; i < 2 * n; i++) {
      group[a[i][1] - 'A'].push_back(a[i][0] - '0'); 
    }
    for (int c = 0; c < 26; c++) {
      std::sort(group[c].begin(), group[c].end()); 
    }
    std::vector <std::pair <char, int> > ansFirst, ansSecond; 
    int noGood = 0; 
    for (int c = 0; c < 26; c++) {
      if (c != good && group[c].empty() == false) {
        int szGroup = (int) group[c].size();
        if (szGroup % 2 == 0) {
          int half = szGroup / 2; 
          for (int i = 0; i < half; i++) {
            ansFirst.push_back(std::make_pair((char) (c + 'A'), group[c][i])); 
          }
          for (int i = half; i < szGroup; i++) {
            ansSecond.push_back(std::make_pair((char) (c + 'A'), group[c][i])); 
          }
        }
        else {
          noGood++; 
          int half = szGroup / 2; 
          for (int i = 0; i < half; i++) {
            ansFirst.push_back(std::make_pair((char) (c + 'A'), group[c][i])); 
          }
          for (int i = half; i < szGroup - 1; i++) {
            ansSecond.push_back(std::make_pair((char) (c + 'A'), group[c][i])); 
          }
        }  
      }
    }
    int numbGood = (int) group[good].size(); 
    if (numbGood < noGood) {
      std::cout << "IMPOSSIBLE" << std::endl; 
    }
    else {
      for (int c = 0; c < 26; c++) {
        if (c != good && (int) group[c].size() % 2 == 1) {
          ansFirst.push_back(std::make_pair((char) (c + 'A'), group[c].back())); 
        }  
      }
      while (noGood > 0) {
        ansSecond.push_back(std::make_pair((char) (good + 'A'), group[good].back()));
        group[good].pop_back(); 
        noGood--; 
      }
      int szGroup = group[good].size(); 
      int half = szGroup / 2; 
      for (int i = 0; i < half; i++) {
        ansFirst.push_back(std::make_pair((char) (good + 'A'), group[good][i])); 
      }
      for (int i = half; i < szGroup; i++) {
        ansSecond.push_back(std::make_pair((char) (good + 'A'), group[good][i])); 
      }
      for (int i = 0; i < (int) ansFirst.size(); i++) {
        std::cout << ansFirst[i].second << ansFirst[i].first << ' ' << ansSecond[i].second << ansSecond[i].first << std::endl; 
      }
    }
  }
  return 0; 
}