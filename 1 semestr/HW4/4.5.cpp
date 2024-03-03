#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
  cout << "\x1B[2J\x1B[H";
  setlocale(LC_ALL, "ru");
  int size = 100;
  int height = 21;

  vector<string> sinGraph(height, string(size, ' '));
  sinGraph[height / 2] = string(size, '-');

  for (int i = 0; i < size; i++)
  {
    sinGraph[(round(10 * sin(i / 4.5) + 10))][i] = '*';
  }

  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < size; j++)
    {
      if (sinGraph[i][j] == '*' && sinGraph[i][j + 1] == '*' && sinGraph[i][j + 2] == '*')
      {
        sinGraph[i][j] = ' ';
        sinGraph[i][j + 2] = ' ';
      }
      if (sinGraph[i][j] == '*' && sinGraph[i][j + 1] == '*')
      {
        sinGraph[i][j + 1] = ' ';
      }
      if (i != 10 && j == 14)
      {
        sinGraph[i][j] = '|';
      }
    }
  }
  for (auto s : sinGraph)
  {
    cout << s << '\n';
  }
}