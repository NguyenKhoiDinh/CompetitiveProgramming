#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

const long long MOD = 1000000007;
const int MAX_N = 100005;
const int MAX_LENGTH = 55;
int n, numTest;
int weight[MAX_N];
int numStrings;
vector <string> words;
long long cnt[26][MAX_LENGTH];

void process() {
  long long res = 0LL;
  for (int i = 0; i < numStrings; i++) {
    string word = words[i];
    cnt[word[0] - 'a'][(int) word.size()]++;
  }
  for (int i = 0; i < numStrings; i++) {
    if ((int) words[i].size() != n) {
      continue;
    }
    string word = words[i];
    cnt[word[0] - 'a'][n]--;
    long long mul = 1LL;
    for (int j = 0; j < n; j++) {
      (mul *= cnt[word[j] - 'a'][weight[j]]) %= MOD;
      cnt[word[j] - 'a'][weight[j]]--;
    }
    (res += mul) %= MOD;
    for (int j = 0; j < n; j++) {
      cnt[word[j] - 'a'][weight[j]]++;
    }
    cnt[word[0] - 'a'][n]++;
  }
  cout << res << endl;
}

int main () {
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> weight[i];
    }
    words.clear();
    cin >> numStrings;
    for (int i = 1; i <= numStrings; i++) {
      string s;
      cin >> s;
      words.push_back(s);
    }
    for (int ch = 0; ch < 26; ch++) {
      for (int i = 0; i < MAX_LENGTH; i++) {
        cnt[ch][i] = 0;
      }
    }
    process();
  }
  return 0;
}