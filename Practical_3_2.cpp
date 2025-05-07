#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

int addition(const vector<int>& number, int z, int y) {
    if (z == y)
        return 0;
    return number[z] + addition(number, z + 1, y);
}

int main() {
    int size;
    cout << "How many numbers: ";
    cin >> size;

    vector<int> number(size);
    cout << "\nEnter the numbers: ";
    for (int i = 0; i < size; i++) {
        cin >> number[i];
    }

    int repeat = 1000; // Repeat the function many times
    int result = 0;

    auto start = high_resolution_clock::now();
    for (int i = 0; i < repeat; i++) {
        result = addition(number, 0, size);
    }
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
  

    cout << "The sum is: " << result << endl;
    cout << "Total time for " << repeat << " runs: " << duration.count() << " microseconds" << endl;
    return 0;
}