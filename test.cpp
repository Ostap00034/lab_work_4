#include <iostream>
#include <vector>

using namespace std;

bool is_square(vector<vector<int>> a)
{
  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < 3; ++j)
      cout << a[i][j] << " ";
    cout << endl;
  }
}

int main()
{
  vector<vector<int>> sudoku(9, vector<int>(9));

  for (int i = 0; i < 9; ++i)
    for (int j = 0; j < 9; ++j)
    {
      if (j + 1 + i > 9)
        sudoku[i][j] = (j + 1 + i) - 9;
      else
        sudoku[i][j] = j + 1 + i;
    }

  // Обход квадратов 3x3 через цикл

  for (int i = 0; i < 9; i += 3)
  {
    for (int j = 0; j < 9; j += 3)
    {
      // Вывод текущего квадрата 3x3
      cout << "Squares " << (i / 3) * 3 + (j / 3) + 1 << ":" << endl;
      for (int x = i; x < i + 3; x++)
      {
        for (int y = j; y < j + 3; y++)
        {
          cout << sudoku[x][y] << " ";
        }
        cout << endl;
      }
      cout << endl;
    }

    // if (i == 0)
    //   is_square(any);
    cout << endl;
  }

  // for (int i = 0; i < 9; i += 3)
  // {
  //   vector<vector<int>> a(3, vector<int>(3));
  //   for (int j = 0; j < 3; ++j)
  //   {
  //     for (int k = 0; k < 3; ++k)
  //     {
  //       cout << i + j << " " << k << " | " << j << " " << k << " | ";
  //     }

  //     // cout << j << " " << k << endl;
  //     // for (int k = 0; k < 3; ++k)
  //     //   a[j][k] = sudoku[i][k + j * 3];
  //   }
  // cout << "_____________________________________________" << endl;
  // is_square(a);
  // cout << "_____________________________________________" << endl;
  // }

  // for (int i = 0; i < 9; ++i)
  // {
  //   vector<vector<int>> a(3, vector<int>(3));
  //   for (int j = 0; j < 9; ++j)
  //   {
  //     for (int k = 0; k < 3; ++k)
  //     {
  //       a[j][k] = sudoku[i][k];
  //     }
  //   }
  //   if (i == 6)
  //     is_square(a);
  // }

  // for (int i = 0; i < 9; ++i)
  // {
  //   for (int j = 0; j < 9; ++j)
  //     cout << sudoku[i][j] << " ";
  //   cout << endl;
  // }
}