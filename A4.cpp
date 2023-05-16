#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

bool in_vector(vector<int> &a, int b)
{
  for (int i = 0; i < 9; ++i)
    if (a[i] == b)
      return true;
  return false;
}

bool is_sudoku_square(vector<int> a)
{
  vector<int> b{1, 2, 3, 4, 5, 6, 7, 8, 9};

  int n = a.size();

  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
      if (a[i] > a[j])
        swap(a[i], a[j]);

  return a == b;
}

bool is_sudoku(vector<vector<int>> &a)
{
  for (int i = 0; i < 9; i += 3)
  {
    for (int j = 0; j < 9; j += 3)
    {
      vector<int> square;

      for (int x = i; x < i + 3; x++)
      {
        for (int y = j; y < j + 3; y++)
        {
          square.push_back(a[x][y]);
        }
      }

      if (!is_sudoku_square(square))
        return false;
    }
  }

  for (int i = 0; i < 9; ++i)
  {
    vector<int> horizontal(9), vertical(9);

    for (int j = 0; j < 9; ++j)
    {
      if (in_vector(horizontal, a[i][j]) || in_vector(vertical, a[j][i]))
        return false;

      horizontal[j] = a[i][j];
      vertical[j] = a[j][i];
    }
  }

  return true;
}

int main()
{

  for (int i = 1; i < 5; ++i)
  {
    vector<vector<int>> a(9, vector<int>(9));
    ifstream input("sudoku" + to_string(i) + ".txt");

    for (int j = 0; j < 9; ++j)
    {
      for (int k = 0; k < 9; ++k)
        input >> a[j][k];
    }

    cout << "File number " << i << (is_sudoku(a) ? " is valid." : " isn't valid.") << endl;

    input.close();
  }
}