#include <bits/stdc++.h>

using namespace std;
int numTest;
int pos[26];
int cnt[26];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
const long long MOD = 1000000000;

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  pos['N' - 'A'] = 0;
  pos['W' - 'A'] = 1;
  pos['S' - 'A'] = 2;
  pos['E' - 'A'] = 3;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    for (int c = 0; c < 26; c++) {
      cnt[c] = 0;
    }
    string command;
    cin >> command;
    stack <long long> st;
    st.push(1LL);
    for (int i = 0; i < (int) command.size(); i++) {
      if ('2' <= command[i] && command[i] <= '9') {
        int number = command[i] - '0';
        long long value = st.top();
        value *= 1LL * number;
        value %= MOD;
        st.push(value);
      }
      else if (command[i] == ')') {
        st.pop();
      }
      else if (command[i] == 'N' || command[i] == 'W' || command[i] == 'S' || command[i] == 'E') {
        (cnt[command[i] - 'A'] += st.top()) %= MOD;
      }
    }
    long long w = 0LL, h = 0LL;
    vector <char> save;
    save.push_back('N');
    save.push_back('E');
    save.push_back('W');
    save.push_back('S');
    for (int i = 0; i < 4; i++) {
      (w += (1LL * cnt[save[i] - 'A'] * dx[pos[save[i] - 'A']] + 10LL * MOD) % MOD) %= MOD;
      (h += (1LL * cnt[save[i] - 'A'] * dy[pos[save[i] - 'A']] + 10LL * MOD) % MOD) %= MOD;
    }
    cout << h + 1 << ' ' << w + 1 << endl;
  }
  return 0;
}