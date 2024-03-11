#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
  cout << "\x1B[2J\x1B[H";
  string strX = "";

  ofstream file("file25.txt");
  while (strX != "0")
  {
    cout << "Введите строки(для окончания введите 0): ";
    getline(cin, strX);
    file << strX << "\n";
  }
  file.close();

  int k = 0, tab = 0;
  ifstream ifile("file25.txt");
  string str, end;
  while (getline(ifile, str))
  {
    if (is_sorted(str.begin(), str.end()))
    {
      k++;
      end = end + str + " ";
    }
    for (int i = 0; i < str.length(); i++)
    {
      if (str[i] == ' ')
      {
        tab++;
      }
    }
    if (tab > 0)
    {
      k -= 1;
      while (tab != 0)
      {
        end.pop_back();
        tab--;
      }
      end.pop_back();
    }
    if (str == "")
    {
      k -= 1;
      end.pop_back();
    }
  }
  end.pop_back();
  end.pop_back();
  end.pop_back();
  ifile.close();
  if (k - 1 == 0)
  {
    cout << "Количество строк: 0 " << endl;
    return 0;
  }
  cout << "Количество отсортированных строк: " << k - 1 << endl;
  cout << end;
  return 0;
}