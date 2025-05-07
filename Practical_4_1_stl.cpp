#include <iostream>
#include <vector>
using namespace std;
class Derived_Circle;
class Base_Circle
{
protected:
    float Radius;

public:
    void GetRadius()
    {
        cout << "\nEnter Radius: ";
        cin >> Radius;
    }
};

class Derived_Circle : public Base_Circle
{
public:
    void CalculateArea()
    {
        float Area = 3.14 * Radius * Radius;
        cout << "\nArea of Circle is : " << Area << endl;
    }
};

int main()
{
    vector<Derived_Circle> D1(5);
    for (auto &i : D1)
    {
        i.GetRadius();
        i.CalculateArea();
    }
    return 0;
}