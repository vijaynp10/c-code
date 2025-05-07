#include <iostream>
#include <vector>
using namespace std;

int Bill = 0;

class Inventory {
    string Name;
    int ID;
    int Quantity;
    int Price;

public:
    Inventory() : Name("Default Name"), ID(0), Quantity(0), Price(0) {}

    Inventory(int id, string name, int quantity, int price)
        : ID(id), Name(name), Quantity(quantity), Price(price) {
        cout << "\n======== Item added successfully!! ========\n";
    }

    void UpdateQuantity(int x) {
        Quantity = x;
    }

    int GetId() const {
        return ID;
    }

    void DetailOfProduct() const {
        cout << "\nItem Name: " << Name
             << " | Product ID: " << ID
             << " | Price: " << Price
             << " | Quantity: " << Quantity;
    }

    int BillOfProduct() const {
        return Quantity * Price;
    }

    void Add_Stock() {
        cout << "Enter name of the product: ";
        cin >> Name;
        cout << "Enter id of the product: ";
        cin >> ID;
        cout << "Enter price of the product: ";
        cin >> Price;
        cout << "Enter quantity of the product: ";
        cin >> Quantity;
        cout << "\n======== Stock Added Successfully!! ========\n";
    }

    bool Remove_Stock(int pid) {
        if (ID == pid) {
            Name = "Default Name";
            ID = 0;
            Quantity = 0;
            Price = 0;
            cout << "\n======== Stock Removed successfully!! ========\n";
            return true;
        }
        return false;
    }
};

int main() {
    vector<Inventory> Details;
    int choice;

    do {
        cout << "\n\n===== Inventory Menu =====\n";
        cout << "1. Enter Product Data\n";
        cout << "2. Change Quantity\n";
        cout << "3. Display Bill & Product Info\n";
        cout << "4. Add Stock\n";
        cout << "5. Remove Stock\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int n;
            cout << "Enter number of items: ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                int id, qty, price;
                string name;
                cout << "Enter Product ID: ";
                cin >> id;
                cout << "Enter Product Name: ";
                cin >> name;
                cout << "Enter Quantity: ";
                cin >> qty;
                cout << "Enter Price: ";
                cin >> price;

                Details.emplace_back(id, name, qty, price);
            }
            break;
        }
        case 2: {
            int id, qty;
            cout << "Enter Product ID to update quantity: ";
            cin >> id;
            for (auto &item : Details) {
                if (item.GetId() == id) {
                    cout << "Enter new quantity: ";
                    cin >> qty;
                    item.UpdateQuantity(qty);
                    cout << "Quantity Updated!";
                }
            }
            break;
        }
        case 3: {
            Bill = 0;
            for (const auto &item : Details) {
                Bill += item.BillOfProduct();
            }
            for (const auto &item : Details) {
                item.DetailOfProduct();
            }
            cout << "\nTotal Bill is: " << Bill << "\n";
            break;
        }
        case 4: {
            Inventory newItem;
            newItem.Add_Stock();
            Details.push_back(newItem);
            break;
        }
        case 5: {
            int pid;
            cout << "Enter Product ID to remove: ";
            cin >> pid;
            for (auto it = Details.begin(); it != Details.end(); ++it) {
                if (it->Remove_Stock(pid)) {
                    Details.erase(it);
                    break;
                }
            }
            break;
        }
        case 6:
            cout << "Exiting...";
            break;
        default:
            cout << "Invalid choice!";
        }

    } while (choice != 6);

    return 0;
}
