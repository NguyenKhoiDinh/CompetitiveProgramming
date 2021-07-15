#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 1000005; 
int n; 
string a[MAX_N];

struct node {
  int cnt; 
  node *child[10]; 
};

node *root; 

node *createNode() {
  node *ret = new node();
  ret->cnt = 0; 
  for (int i = 0; i <= 9; i++) {
    ret->child[i] = NULL; 
  }
  return ret; 
}

void add(const string &number) {
  node *p = root; 
  int len = (int) number.size();
  for (int i = 0; i < len; i++) {
    int digit = number[i] - '0'; 
    if (p->child[digit] == NULL) {
      p->child[digit] = createNode(); 
    }
    p = p->child[digit]; 
    p->cnt++;
  }
}

string getMin(const string &number) {
  node *p = root; 
  string res = "";
  int len = (int) number.size();
  bool found = false;
  for (int i = 0; i < len; i++) {
    int minDigit = 11; 
    int chooseDigit = -1; 
    int currentDigit = number[i] - '0';
    for (int digit = 0; digit <= 9; digit++) {
      if (p->child[digit] != NULL) {
        if (found == false && currentDigit == digit && p->child[digit]->cnt == 1) {
          continue; 
        }
        int r = (currentDigit + digit) % 10; 
        if (minDigit > r) {
          minDigit = r;
          chooseDigit = digit; 
        } 
      }
    }
    if (chooseDigit != currentDigit) {
      found = true; 
    }
    res += (char) (minDigit + '0'); 
    p = p->child[chooseDigit]; 
  }
  return res; 
}

string getMax(const string &number) {
  node *p = root; 
  string res = "";
  int len = (int) number.size();
  bool found = false;
  for (int i = 0; i < len; i++) {
    int maxDigit = -1; 
    int chooseDigit = -1; 
    int currentDigit = number[i] - '0'; 
    for (int digit = 0; digit <= 9; digit++) {
      if (p->child[digit] != NULL) {
        if (found == false && currentDigit == digit && p->child[digit]->cnt == 1) {
          continue; 
        }
        int r = (currentDigit + digit) % 10; 
        if (maxDigit < r) {
          maxDigit = r;
          chooseDigit = digit;
        } 
      }
    }
    if (chooseDigit != currentDigit) {
      found = true; 
    }
    res += (char) (maxDigit + '0'); 
    p = p->child[chooseDigit]; 
  }
  return res; 
}

int main () {
  cin >> n; 
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; 
  }
  int maxLength = -1; 
  for (int i = 1; i <= n; i++) {
    if (maxLength < (int) a[i].size()) {
      maxLength = (int) a[i].size(); 
    }
  }
  for (int i = 1; i <= n; i++) {
    while ((int) a[i].size() < maxLength) {
      a[i] = "0" + a[i];
    }
  }
  root = createNode();
  for (int i = 1; i <= n; i++) {
    add(a[i]); 
  }
  string minValue = "99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
  string maxValue = "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
  for (int i = 1; i <= n; i++) {
    minValue = min(minValue, getMin(a[i]));
    maxValue = max(maxValue, getMax(a[i]));
  }
  int pos = -1; 
  for (int i = 0; i < (int) minValue.size(); i++) {
    if (minValue[i] != '0') {
      pos = i; 
      break;
    }
  }
  if (pos == -1) {
    minValue = "0"; 
  }
  else {
    string tmp = "";
    for (int i = pos; i < (int) minValue.size(); i++) {
      tmp += minValue[i]; 
    }
    minValue = tmp; 
  }
  pos = -1; 
  for (int i = 0; i < (int) maxValue.size(); i++) {
    if (maxValue[i] != '0') {
      pos = i; 
      break;
    }
  }
  if (pos == -1) {
    maxValue = "0"; 
  }
  else {
    string tmp = "";
    for (int i = pos; i < (int) maxValue.size(); i++) {
      tmp += maxValue[i]; 
    }
    maxValue = tmp; 
  }
  cout << minValue << ' ' << maxValue;
  return 0; 
}