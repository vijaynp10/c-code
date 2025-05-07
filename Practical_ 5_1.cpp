#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Calculator {
private:
    vector<string> results;

public:
    // Overloaded add functions
    int add(int a, int b) {
        int result = a + b;
        storeResult("add(int, int)", result);
        return result;
    }

    float add(float a, float b) {
        float result = a + b;
        storeResult("add(float, float)", result);
        return result;
    }

    double add(double a, double b) {
        double result = a + b;
        storeResult("add(double, double)", result);
        return result;
    }

    double add(int a, double b) {
        double result = a + b;
        storeResult("add(int, double)", result);
        return result;
    }

    double add(float a, int b) {
        double result = a + b;
        storeResult("add(float, int)", result);
        return result;
    }

    // Store result with description
    void storeResult(const string& operation, double result) {
        results.push_back(operation + " = " + to_string(result));
    }

    // Display all results
    void displayResults() {
        cout << "Calculation Results:" << endl;
        for (const auto& entry : results) {
            cout << entry << endl;
        }
    }
};
int main() {
    Calculator calc;

    // Various test cases with different input types
    calc.add(5, 10);
    calc.add(3.5f, 2.5f);
    calc.add(2.1, 3.9);
    calc.add(7, 4.3);
    calc.add(1.2f, 3);

    // Display results
    calc.displayResults();

    return 0;
}
