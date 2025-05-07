#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
class Loan
{
    string Name;
    int Id;
    int Price;
    float Rate;
    float Time;
    double Monthly_Interest;
    double EMI;

public:
    Loan()
    {
        Name = "Default Name";
        Id = 0;
        Price = 0;
        Rate = 0;
        Time = 0;
    }

    Loan(int id, string name, int price, int rate, int time)
    {
        Name = name;
        Id = id;
        Price = price;
        Rate = rate;
        Time = time;
    }

    void Calculate_EMI()
    {
        Monthly_Interest = Rate / (12 * 100);
        EMI = (Price * Monthly_Interest * pow((1 + Monthly_Interest), Time)) /
              (pow((1 + Monthly_Interest), Time) - 1);
        cout << "\nEMI = " << EMI;
    }

    void Display_Detail()
    {
        cout << "\n======== Detail of Applicant : ========\n";
        cout << "\nApplicant Name : " << Name
             << "\nApplicant ID Number : " << Id
             << "\nAmmount for Loan : " << Price
             << "\nDuration of Loan : " << Time << " Months"
             << "\nInterest rate (%) : " << Rate << endl;
    }
} Detail[5];

int main()
{

    int i, Person, choice = 0;
    string name;

    cout << "\nEnter No. of person : ";
    cin >> Person;

    while (choice != 4)
    {

        cout << "\n1. For Enter The Data for Loan .";
        cout << "\n2. For Display Detail of accountant.";
        cout << "\n3. For EMI.\n";

        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            for (i = 0; i < Person; i++)
            {
                int price, rate, time, id;
                cout << "\nEnter Detail of " << i + 1 << " Person : \n";

                cout << "Enter Name of Accountant : ";
                cin >> name;

                cout << "Enter id of Accountant : ";
                cin >> id;

                cout << "Enter Ammount : ";
                cin >> price;

                cout << "Enter Interest rate (%) : ";
                cin >> rate;

                cout << "Enter Loan months : ";
                cin >> time;

                Detail[i] = Loan(id, name, price, rate, time);
            }
            break;
        case 2:
            for (i = 0; i < Person; i++)
            {
                Detail[i].Display_Detail();
            }
            break;
        case 3:
            for (i = 0; i < Person; i++)
            {
                Detail[i].Calculate_EMI();
            }
            break;
        case 4:
            cout << "Existing!!";
            break;
        default:
            cout << "Invalid choice!";
            break;
        }
    }
}