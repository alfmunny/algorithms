#define MAX_N 500000
#include <limits>
#include <algorithm>
#include <iostream>

const int int_max = std::numeric_limits<int>::max();
int n, dat[2 * MAX_N - 1];

void init(int N)
{
  // Calculate a power of 2 that equal or greater than N
  // The total element would be 2 * n - 1
  // That is the max length of the segment tree array we need
  n = 1;
  while(n < N) n *= 2;
  for (int i = 0; i < 2*n-1; ++i) 
    dat[i] = int_max;
}

void update(int k, int v)
{
  // the index in array
  k += n-1;
  dat[k] = v;

  while (k > 0) {
    k = (k-1)/2;
    dat[k] = std::min(dat[2*k+1], dat[2*k+2]);
  }
}

int query(int a, int b, int k, int l, int r)
{
  // [a, b), [l, r)
  // If not in range
  if (a >= r || l >= b) return int_max;
  // If in range
  if (a <= l && r <= b) return dat[k];

  int lmin = query(a, b, 2*k+1, l, (l+r)/2);
  int rmin = query(a, b, 2*k+2, (l+r)/2, r);
  return std::min(lmin, rmin);
}

int query(int a, int b)
{
  return query(a, b, 0, 0, n);
}

int main() 
{
  init(8);
  update(0, 5);
  update(1, 3);
  update(2, 7);
  update(3, 9);
  update(4, 6);
  update(5, 4);
  update(6, 1);
  update(7, 2);
  for (int i = 1; i <= 8; i *= 2) {
    for (int k = 0; k < n/2 - i/2; ++k)
      std::cout << " ";
    for (int j = 0; j < i; ++j)
    {
      std::cout << dat[j+i-1] << " ";
    }
    std::cout << std::endl;
  }

  std::cout << "Start querying:" << std::endl;
  std::cout << "min from 0 to 1: " << query(0, 1) << std::endl;
  std::cout << "min from 4 to 8: " << query(4, 8) << std::endl;
  std::cout << "min from 4 to 6: " << query(4, 6) << std::endl;
  std::cout << "min from 0 to 8: " << query(0, 8) << std::endl;
  std::cout << "min from 4 to 5: " << query(4, 5) << std::endl;
  std::cout << "min from 6 to 7: " << query(6, 7) << std::endl;
  std::cout << "min from 7 to 8: " << query(7, 8) << std::endl;
  std::cout << "min from 8 to 8: " << query(8, 8) << std::endl;
  return 0;
}
