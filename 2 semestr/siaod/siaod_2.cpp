#include <iostream>
#include <vector>

bool check_prime(long long n)
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (long long i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int find_position(const std::vector<int> &arr)
{
    for (size_t i = 0; i < arr.size(); ++i)
    {
        long long sum = 0;
        long long num = arr[i];
        while (num != 0)
        {
            sum += num % 10;
            num /= 10;
        }
        if (check_prime(sum))
        {
            return i;
        }
    }
    return -1;
}

int insert_before_prime_root(std::vector<int> &arr, int new_element)
{
    for (size_t i = 0; i < arr.size(); ++i)
    {
        long long sum = 0;
        long long num = arr[i];
        while (num != 0)
        {
            sum += num % 10;
            num /= 10;
        }
        if (check_prime(sum))
        {
            arr.insert(arr.begin() + i, new_element);
            return i;
        }
    }
    return -1;
}

void remove_prime_root(std::vector<int> &arr)
{
    for (size_t i = 0; i < arr.size();)
    {
        long long sum = 0;
        long long num = arr[i];
        while (num != 0)
        {
            sum += num % 10;
            num /= 10;
        }
        if (check_prime(sum))
        {
            arr.erase(arr.begin() + i);
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    // Task 1
    int pos = find_position(arr);
    if (pos != -1)
    {
        std::cout << "Position of element with digit root 7: " << pos << std::endl;
    }
    else
    {
        std::cout << "No such element found" << std::endl;
    }

    // Task 2
    int new_element = 21;
    int pos2 = insert_before_prime_root(arr, new_element);
    if (pos2 != -1)
    {
        std::cout << "New element inserted at position: " << pos2 << std::endl;
        for (int num : arr)
        {
            std::cout << num << " ";
        }
    }
    else
    {
        std::cout << "No such element found" << std::endl;
    }

    // Task 3
    std::cout << std::endl;
    remove_prime_root(arr);
    std::cout << "Array after removing elements with digit root 7:" << std::endl;
    for (int num : arr)
    {
        std::cout << num << " ";
    }

    return 0;
}