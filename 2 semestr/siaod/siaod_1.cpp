#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

float calculate_arr(int n, vector<double> &arr)
{
    for (int j = 0; j <= n; ++j)
    {
        double x = ((j - 1) / (j + 1)) + (sin(((j - 1) * (j - 1) * (j - 1)) / (j + 1))) * j;
        arr[j] = x;
    }
    float min_elem = *min_element(arr.begin(), arr.end(), [](double a, double b)
                                  { return a > 0 && (a < b || b <= 0); });
    return min_elem;
}

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    vector<double> arr(n);

    unsigned int start_time = clock();

    cout << "Answer: " << calculate_arr(n, arr) << "\narr: ";

    unsigned int end_time = clock();

    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << '\n';
    unsigned int search_time = end_time - start_time;
    cout << search_time;
}
