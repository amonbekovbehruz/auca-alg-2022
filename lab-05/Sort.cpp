#include "Sort.hpp"

int binarySearch(std::vector<int> &vector, int left, int right, int n)
{
    if (left >= right)
    {
        return -1;
    }

    int middle = (int)(left + right) / 2;

    if (vector[middle] == n)
    {
        return middle;
    }
    else if (vector[middle] > n)
    {
        return binarySearch(vector, left, middle, n);
    }
    else
    {
        return binarySearch(vector, middle + 1, right, n);
    }
}

void insertionSort(std::vector<int> &v, int n)
{
    if (n < 1)
    {
        return;
    }

    insertionSort(v, n - 1);
    int k = v[n];
    int j = n - 1;
    while (j >= 0 && v[j] > k)
    {
        v[j + 1] = v[j];
        j--;
    }
    v[j + 1] = k;
}

void subMerge(std::vector<int> &v, int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    std::vector<int> left(n1 + 1);
    std::vector<int> right(n2 + 1);

    left[n1] = INT32_MAX;
    right[n2] = INT32_MAX;

    for (int i = 0; i < n1; i++)
    {
        left[i] = v[low + i];
    }
    for (int j = 0; j < n2; j++)
    {
        right[j] = v[mid + j + 1];
    }

    int i = 0;
    int j = 0;

    for (int k = low; k <= high; k++)
    {
        if (left[i] <= right[j])
        {
            v[k] = left[i];
            i++;
        }
        else
        {
            v[k] = right[j];
            j++;
        }
    }
}