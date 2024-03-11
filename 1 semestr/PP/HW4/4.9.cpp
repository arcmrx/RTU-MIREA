#include <iostream>
#include <string>

using namespace std;

int main()
{
  cout << "\x1B[2J\x1B[H";
  string number, newNumber;
  int oldBase, newBase, decimalNumber = 0;

  cout << "Введите:\n 1)исходное число\n 2)его систему счисления(до 16)\n 3)систему счисления, в которую надо перевести: \n";
  if (!(cin >> number >> oldBase >> newBase))
  {
    printf("\e[1;1H\e[2J");
    cout << "Некорректные данные";
    return 0;
  }

  bool negativity = false, isValid = true;
  if (number[0] == '-')
  {
    negativity = true;
  }
  if (negativity == true)
  {
    number = number.substr(1);
  }

  if (number == "0")
  {
    cout << 0;
    return 0;
  }

  if (number > "F")
  {
    cout << "Система счисления должна быть до 16";
    return 0;
  }

  for (int i = 0; i < number.length(); i++)
  {
    int digit = number[i] - '0';
    if (digit >= 10)
    {
      digit -= 7;
    }
    if (digit >= oldBase)
    {
      isValid = false;
      break;
    }
  }

  if (!isValid)
  {
    cout << "Некорректные данные";
    return 0;
  }

  for (int i = 0; i < number.length(); i++)
  {
    int digit = number[i] - '0';
    if (digit >= 10)
    {
      digit -= 7;
    }
    decimalNumber = decimalNumber * oldBase + digit;
  }

  while (decimalNumber > 0)
  {
    int digit = decimalNumber % newBase;
    if (digit >= 10)
    {
      digit += 7;
    }
    newNumber = char(digit + '0') + newNumber;
    decimalNumber /= newBase;
  }
  if (negativity == true)
  {
    newNumber = "-" + newNumber;
  }
  cout << newNumber << endl;

  return 0;
}
