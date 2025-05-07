#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter size of the first and second array -> ";
    cin >> n >> m;
    int *arr1 = new int[n];
    int *arr2 = new int[m];

    cout << "Enter elements of arr 1-> " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Element [" << i << "] -> ";
        cin >> arr1[i];
    }

    cout << "Enter elements of arr 2-> " << endl;
    for (int i = 0; i < m; i++)
    {
        cout << "Element [" << i << "] -> ";
        cin >> arr2[i];
    }

    int i = 0, j = 0, k = 0;

    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            merge[k++] = arr1[i++];
        }
        else
        {
            merge[k++] = arr2[j++];
        }
    }
    int *merge = new int[n + m];

    cout << "\nSorted & Merged Array is -> " << endl;
    for (int i = 0; i < (n + m); i++)
    {
        cout << "Element [" << i << "] -> " << merge[i] << endl;
    }
    return 0;
}