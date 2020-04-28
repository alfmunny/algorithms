#include <string>
#include <iostream>

using namespace std;

int main() {
  string s = "abcababc";
  string p = "abc";

  int i = 0, j = 0;

  while (i < s.length())
  {
    if (s[i] == p[j]) {
      i++;
      j++;
    }
    else
    {
      i = i - j + 1;
      j = 0;
    }

    if (j == p.length())
    {
      cout << i - j << endl;
      i = i - j + 1;
      j = 0;
    }
  }

}
