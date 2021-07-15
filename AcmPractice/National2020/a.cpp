#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int numTest;
int day;
string month;

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> day >> month;
    if ((month == "Mar" && day >= 21) || (month == "Apr" && day <= 20)) {
      cout << "Aries";
    }
    if ((month == "Apr" && day >= 21) || (month == "May" && day <= 20)) {
      cout << "Taurus";
    }
    if ((month == "May" && day >= 21) || (month == "Jun" && day <= 21)) {
      cout << "Gemini";
    }
    if ((month == "Jun" && day >= 22) || (month == "Jul" && day <= 22)) {
      cout << "Cancer";
    }
    if ((month == "Jul" && day >= 23) || (month == "Aug" && day <= 22)) {
      cout << "Leo";
    }
    if ((month == "Aug" && day >= 23) || (month == "Sep" && day <= 21)) {
      cout << "Virgo";
    }
    if ((month == "Sep" && day >= 22) || (month == "Oct" && day <= 22)) {
      cout << "Libra";
    }
    if ((month == "Oct" && day >= 23) || (month == "Nov" && day <= 22)) {
      cout << "Scorpio";
    }
    if ((month == "Nov" && day >= 23) || (month == "Dec" && day <= 21)) {
      cout << "Sagittarius";
    }
    if ((month == "Dec" && day >= 22) || (month == "Jan" && day <= 20)) {
      cout << "Capricorn";
    }
    if ((month == "Jan" && day >= 21) || (month == "Feb" && day <= 19)) {
      cout << "Aquarius";
    }
    if ((month == "Feb" && day >= 20) || (month == "Mar" && day <= 20)) {
      cout << "Pisces";
    }
    cout << endl;
  }
  return 0;
}