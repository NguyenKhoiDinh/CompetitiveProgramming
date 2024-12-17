#include <iostream> 
#include <string> 
#include <algorithm> 
#include <vector> 
#include <utility> 
#include <set>
#include <map>
struct question {
  std::string type; 
  int id; 
  std::string pattern; 
};
std::vector <question> listQuestions; 
bool compare(const std::pair <std::string, int> &a, const std::pair <std::string, int> &b) {
  if ((int) a.first.size() > (int) b.first.size()) {
    return true; 
  }
  else if ((int) a.first.size() < (int) b.first.size()) {
    return false; 
  }
  return a.second < b.second; 
}
std::vector <std::pair <std::string, int> > listPatterns;
std::vector <int> process(const std::vector <std::pair <std::string, int> > &a) {
  std::vector <int> ret; 
  int n = (int) a.size(); 
  ret.resize(n); 
  int len = (int) a[0].first.size();
  for (int j = len - 1; j >= 0; j--) {
    std::map <int, std::vector <std::pair <std::string, int> > > listPatterns;
    for (int i = 0; i < n; i++) {
      listPatterns[a[i].first[j]].push_back(a[i]); 
    }
    int p = 0; 
    for (std::map <int, std::vector <std::pair <std::string, int> > >::iterator it = listPatterns.begin(); it != listPatterns.end(); it++) {
      std::vector <std::pair <std::string, int> > &v = it->second;
      for (int i = 0; i < (int) v.size(); i++) {
        ret[p] = v[i].second;
        p++; 
      } 
    }
  }  
  return ret; 
}
struct node {          
  std::map <int, node*> child;
  std::set <int> myset;  
};
node* createNode() {
  node *ret = new node(); 
  ret->child.clear(); 
  ret->myset.clear();  
  return ret; 
}  
node* pRoot; 
int main () {
  std::vector <std::string> pattern;
  int n; 
  std::cin >> n;
  pattern.resize(n + 1); 
  for (int i = 1; i <= n; i++) {
    question element; 
    std::string type;
    std::cin >> type;
    element.type = type;  
    if (type == "delete" || type == "backspace") {
      std::cin >> element.id;   
    }
    else if (type == "append") {
      std::cin >> element.pattern; 
    }
    else {
      std::cin >> element.id >> element.pattern;
      listPatterns.push_back(std::make_pair(element.pattern, element.id));
      pattern[element.id] = element.pattern;   
    }                                                                     
    listQuestions.push_back(element); 
  }
  std::sort(listPatterns.begin(), listPatterns.end(), compare);
  listPatterns.push_back(std::make_pair("", -1)); 
  std::vector <int> finalId;  
  std::vector <std::pair <std::string, int> > tmp; 
  for (int i = 0; i < (int) listPatterns.size(); i++) {
    if (tmp.empty() == true) {
      tmp.push_back(listPatterns[i]); 
    }
    else {
      if ((int) listPatterns[i].first.size() == (int) tmp[0].first.size()) {
        tmp.push_back(listPatterns[i]); 
      }
      else {
        std::vector <int> v = process(tmp);
        for (int j = 0; j < (int) v.size(); j++) {
          finalId.push_back(v[j]); 
        }  
        tmp.clear();
        tmp.push_back(listPatterns[i]);  
      }
    }
  }
  listPatterns.pop_back();
  std::vector <int> position(n + 5);
  for (int i = 0; i < (int) finalId.size(); i++) {
    position[finalId[i]] = i; 
  }
  pRoot = createNode();
  std::vector <node *> listAddress;
  listAddress.push_back(pRoot);   
  std::string currentString = ""; 
  for (int i = 0; i < n; i++) {
    question element = listQuestions[i];
    if (element.type == "add") {
      int pS = 0;
      std::string s = element.pattern; 
      int id = position[element.id]; 
      node *p = pRoot;
      p->myset.insert(id);  
      for (int j = 0; j < (int) s.size(); j++) {
        int ch = s[j];
        if (p->child.find(ch) == p->child.end()) {
          p->child[ch] = createNode(); 
        }      
        p = p->child[ch];
        p->myset.insert(id); 
        if (pS < (int) currentString.size() && currentString[pS] == s[j]) {
          listAddress[pS + 1] = p;
          pS++;      
        } 
      }                                           
    }
    else if (element.type == "delete") {
      std::string s = pattern[element.id]; 
      node *pTmp = pRoot;                                                    
      for (int j = 0; j < (int) s.size(); j++) {
        pTmp->myset.erase(pTmp->myset.find(position[element.id])); 
        int ch = s[j];
        pTmp = pTmp->child[ch];  
      }
      pTmp->myset.erase(pTmp->myset.find(position[element.id]));
    }
    else if (element.type == "append") {
      std::string s = element.pattern;
      for (int j = 0; j < (int) s.size(); j++) {
        currentString.push_back(s[j]); 
        if (listAddress.back() == NULL) {
          listAddress.push_back(NULL); 
        }
        else {
          node *pTmp = listAddress.back();
          if (pTmp->child.find(s[j]) != pTmp->child.end()) {
            pTmp = pTmp->child[s[j]]; 
            listAddress.push_back(pTmp); 
          }       
          else {
            listAddress.push_back(NULL); 
          }
        }
      } 
    }
    else {
      int numb = element.id;
      while (numb > 0) {
        listAddress.pop_back();
        currentString.pop_back();
        numb--; 
      }   
    }                                         
    node *pTmp = listAddress.back();
    if (pTmp == NULL) {
      std::cout << -1 << std::endl;
    }
    else {
      std::set <int> &myset = pTmp->myset;
      if (myset.empty() == true) {
        std::cout << -1 << std::endl; 
      }
      else {                                       
        std::cout << finalId[*(myset.begin())] << std::endl;
      }
    } 
  }                    
  return 0; 
}