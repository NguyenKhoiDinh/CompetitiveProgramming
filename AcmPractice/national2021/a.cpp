#include <bits/stdc++.h> 

using namespace std; 
int cnt[1005]; 
int n; 
set <pair <int, int> > S; 
vector <int> listColor[1005]; 
int c[1000005]; 

int main () {
  cin >> n;
  for (int i = 1; i <= n * n; i++) {
    cin >> c[i]; 
    cnt[c[i]]++; 
  }
  for (int i = 1; i <= n + 1; i++) {
    if (cnt[i] > 0) {
      S.insert(make_pair(cnt[i], i)); 
    }
  }
  bool result = true; 
  for (int group = 1; group <= n; group++) {
    int numb = n; 
    set <pair <int, int> > :: iterator itHead = S.begin();
    pair <int, int> element = *itHead;
    S.erase(itHead); 
    int mini = min(numb, element.first);
    element.first -= mini;
    numb -= mini;
    if (element.first > 0) {
      S.insert(element); 
    } 
    int color = element.second; 
    for (int i = 1; i <= mini; i++) {
      listColor[color].push_back(group); 
    }
    if (numb > 0) {
      set <pair <int, int> > :: iterator itTail = S.end(); 
      itTail--;
      element = *itTail;  
      S.erase(itTail); 
      int mini = min(numb, element.first);
      element.first -= mini;
      numb -= mini;
      if (element.first > 0) {
        S.insert(element); 
      } 
      int color = element.second; 
      for (int i = 1; i <= mini; i++) {
        listColor[color].push_back(group); 
      }
    }  
    if (numb > 0) {
      result = false;
      break; 
    }
  }
  if (result == false) {
    cout << "NO"; 
  }
  else {
    cout << "YES" << endl; 
    for (int i = 1; i <= n * n; i++) {
      cout << listColor[c[i]].back() << ' '; 
      listColor[c[i]].pop_back(); 
    }
  }
  return 0; 
}