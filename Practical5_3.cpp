#include <iostream>
#include<stack>
using namespace std;

class point
{
    double x, y;

public:
    point(double xCord = 0, double yCord = 0) : x(xCord), y(yCord) {}

    // Overload unary -
    point operator-() const
    {
        point temp;
        temp.x = -x;
        temp.y = -y;
        return temp;
    }

    // Overload binary +
    point operator+(const point &p) const
    {
        point temp;
        temp.x = x + p.x;
        temp.y = y + p.y;
        return temp;
    }

    // Overload ==
    bool operator==(const point &p) const
    {
        x == p.x;
        y == p.y;
    }

    void display() const
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main()
{
    stack<point> history;
    point p1(1, 2);
    point p2(3, 4);
    point p;

    // Operator + overloading
    p = p1 + p2; // here p1 is invoking object
    history.push(point.())
    p.display();

    // Operator unary(-) overloading
    p1 = -p1;
    p1.display();

    // Operator == overloading
    point p3(1, 2);
    bool x;
    x = (p1 == p3);
    if (x == 1)
        cout << "p1 and p3 are equal" << endl;
    else
        cout << "p1 and p3 are not equal" << endl;

    return 0;
}