#include <iostream>
#include <vector>

using namespace std;

// 4 ! = 4 * 3 * 2 * 1

long long int fac(long long int n)
{
  if (n <= 1)
    return 1;
  return n * fac(n - 1);
}

int main()
{
  cout << "Enter number for factorial function: ";
  long long int n;
  cin >> n;
  cout << n << "! = " << fac(n) << endl;
}