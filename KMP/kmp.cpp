#include <iostream>

using namespace std;

int pmt[1000005];
string s, p;

int main() {

  cin >> s >> p;

  int j = 0;

  for (int i = 1; i < p.length(); i++) {
    while (p[i] != p[j] && j > 0)
      j = pmt[j - 1];
    if (p[i] == p[j])
      j++;
    pmt[i] = j;
  }

  j = 0;

  for (int i = 0; i < s.length(); i++) {
    while (s[i] != p[j] && j != 0)
      j = pmt[j - 1];

    if (s[i] == p[j])
      j++;

    if (j == p.length()) {
      cout << i - j + 1 << endl;
      j = pmt[j - 1];
    }
  }
}
