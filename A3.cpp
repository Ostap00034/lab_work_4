#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> dictionary;

class Nonsense_Gen
{
  int i = 1;
  public:
    Nonsense_Gen() 
    {
      ifstream input("Cool-dictionary.txt");
      
      string line;
      while(getline(input, line))
      {
        string temp = "";

        int i = 0;

        while (line[i] != '\0')
        {
          if (line[i] != ' ')
            temp += line[i];
          else 
          {
            dictionary.push_back(temp);
            temp = "";
          }
          ++i;
        }
      }
      
      input.close();
    }

    void generate() 
    {
      string name = "nonsense_" + to_string(i) + ".txt";
      ofstream output(name);
      i = i + 1;

      for (int i = 0; i < 10; ++i) 
      {
        int random = rand();
        output << dictionary[random % 19] << " ";
      }

      output.close();
    }
};


int main()
{
  Nonsense_Gen test;
  test.generate();
  test.generate();
  test.generate();
}