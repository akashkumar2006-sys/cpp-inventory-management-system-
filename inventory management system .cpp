#include <iostream>
using namespace std;

class Product
{
public:
    int id;
    string name;
    int quantity;
    double price;
};

Product products[100];
int totalProducts = 0;

void addProduct()
{
    cout << "\nEnter Product ID: ";
    cin >> products[totalProducts].id;

    cin.ignore();

    cout << "Enter Product Name: ";
    getline(cin, products[totalProducts].name);

    cout << "Enter Quantity: ";
    cin >> products[totalProducts].quantity;

    cout << "Enter Price: ";
    cin >> products[totalProducts].price;

    totalProducts++;

    cout << "\nProduct Added Successfully!\n";
}

void displayProducts()
{
    if(totalProducts == 0)
    {
        cout << "\nNo Products Available!\n";
        return;
    }

    cout << "\n===== PRODUCT LIST =====\n";

    for(int i = 0; i < totalProducts; i++)
    {
        cout << "\nID       : " << products[i].id;
        cout << "\nName     : " << products[i].name;
        cout << "\nQuantity : " << products[i].quantity;
        cout << "\nPrice    : Rs. " << products[i].price;
        cout << "\n------------------------";
    }
}

void searchProduct()
{
    int searchId;
    bool found = false;

    cout << "\nEnter Product ID: ";
    cin >> searchId;

    for(int i = 0; i < totalProducts; i++)
    {
        if(products[i].id == searchId)
        {
            cout << "\nProduct Found!\n";
            cout << "Name     : " << products[i].name << endl;
            cout << "Quantity : " << products[i].quantity << endl;
            cout << "Price    : Rs. " << products[i].price << endl;

            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "\nProduct Not Found!\n";
    }
}

void updateProduct()
{
    int id;
    bool found = false;

    cout << "\nEnter Product ID: ";
    cin >> id;

    for(int i = 0; i < totalProducts; i++)
    {
        if(products[i].id == id)
        {
            cout << "\nEnter New Quantity: ";
            cin >> products[i].quantity;

            cout << "Enter New Price: ";
            cin >> products[i].price;

            cout << "\nProduct Updated Successfully!\n";

            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "\nProduct Not Found!\n";
    }
}

void deleteProduct()
{
    int id;
    bool found = false;

    cout << "\nEnter Product ID: ";
    cin >> id;

    for(int i = 0; i < totalProducts; i++)
    {
        if(products[i].id == id)
        {
            for(int j = i; j < totalProducts - 1; j++)
            {
                products[j] = products[j + 1];
            }

            totalProducts--;

            cout << "\nProduct Deleted Successfully!\n";

            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "\nProduct Not Found!\n";
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n\n===== INVENTORY MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Product";
        cout << "\n2. Display Products";
        cout << "\n3. Search Product";
        cout << "\n4. Update Product";
        cout << "\n5. Delete Product";
        cout << "\n6. Exit";

        cout << "\n\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                addProduct();
                break;

            case 2:
                displayProducts();
                break;

            case 3:
                searchProduct();
                break;

            case 4:
                updateProduct();
                break;

            case 5:
                deleteProduct();
                break;

            case 6:
                cout << "\nThank You!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 6);

    return 0;
}