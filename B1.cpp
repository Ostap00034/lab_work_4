#include <iostream>

using namespace std;

int A(int m, int n)
{
  if (!(m >= 0 && m <= 3 && n >= 0 && n <= 7))
    return -1;
  if (m == 0)
    return n + 1;
  if (m > 0)
  {
    if (n == 0)
      return A(m - 1, 1);
    if (n > 0)
      return A(m - 1, A(m ,n - 1));
  }
}

int main()
{
  cout << "Enter 2 numbers for Accerman's function: ";
  int m, n; cin >> m >> n;
  cout << A(m, n) << endl;
}