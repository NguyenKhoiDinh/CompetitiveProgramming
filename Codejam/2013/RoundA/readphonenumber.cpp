#include <bits/stdc++.h> 

using namespace std;
int numTest; 
string number[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string group[11] = {"-", "-", "double", "triple", "quadruple", "quintuple", "sextuple", "septuple", "octuple", "nonuple", "decuple"};
string phone, format;

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> phone >> format; 
    format += '-';
    vector <int> save; 
    int value = 0;
    for (int i = 0; i < (int) format.size(); i++) {
      if (format[i] == '-') {
        save.push_back(value);
        value = 0;
      }
      else {
        value = value * 10 + format[i] - '0';
      }
    }
    stack <pair <int, int> > st; 
    int cnt = 0;
    int p = 0; 
    for (int i = 0; i < (int) phone.size(); i++) {
      cnt++; 
      if (!st.empty() && st.top().first == phone[i] - '0') {
        pair <int, int> sTop = st.top();
        st.pop();
        sTop.second++;
        st.push(sTop);
      }
      else {
        st.push(make_pair(phone[i] - '0', 1));
      }
      if (cnt == save[p]) {
        stack <pair <int, int> > other; 
        while (!st.empty()) {
          pair <int, int> sTop = st.top();
          st.pop(); 
          other.push(sTop);
        }
        while (!other.empty()) {
          pair <int, int> sTop = other.top(); 
          other.pop();
          if (sTop.second >= 2 && sTop.second <= 10) {
            cout << group[sTop.second] << ' ' << number[sTop.first] << ' ';
          }
          else {
            for (int j = 1; j <= sTop.second; j++) {
              cout << number[sTop.first] << ' ';
            }
          }
        }
        cnt = 0; 
        p++;
      }
    }
    cout << endl;
  }
  return 0; 
}