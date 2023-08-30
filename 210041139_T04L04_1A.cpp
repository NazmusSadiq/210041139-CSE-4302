#include <iostream>

using namespace std;

class Product
{
private:
    int id, quantity, maxqty;
    float price;
    string name;
    bool availability_status;

public:
    static int total_inventory_val;
    Product()
    {
        price = 0;
        quantity = 0;
    }
    Product(string name, int id, float price, int quantity)
    {
        this->name = name;
        this->id = id;
        this->price = price;
        this->quantity = quantity;
        availability_status = true;
    }
    int get_id()
    {
        return id;
    }
    int get_quantity()
    {
        return quantity;
    }
    float get_price()
    {
        return price;
    }
    string get_name()
    {
        return name;
    }
    void set_id(int id)
    {
        this->id = id;
    }
    void set_price(float price)
    {
        this->price = price;
    }
    void set_quantity(int quantity)
    {
        if (quantity <= maxqty)
            this->quantity = quantity;
        else
            quantity = 0;
    }
    void set_name(string name)
    {
        this->name = name;
    }
    void setmaxQuantity(int qty)
    {
        maxqty = qty;
    }
    void addToInventory(int added_quantity)
    {
        quantity += added_quantity;
        if (quantity > maxqty)
        {
            cout << "Exceeded max quantity value" << endl;
            quantity -= added_quantity;
        }
    }
    bool isAvailable()
    {
        if (quantity <= 0)
            availability_status = false;
        else if (quantity > 0)
            availability_status = true;
        return availability_status;
    }
    void purchase(int purchased_quantity)
    {
        quantity -= purchased_quantity;
        if (!isAvailable())
        {
            cout << "This amount can not be purchased" << endl;
            quantity += purchased_quantity;
        }
    }
    void updatePrice(int percent)
    {
        if (percent > 0)
            price += price * percent / 100;
    }
    void displayInventoryValue()
    {
        cout << "Inventory Value for:: "<<name<<" is: " << quantity * price << endl;
    }
    void displayDetails()
    {
        cout << "Product Name: " << name << endl;
        cout << "Product ID: " << id << endl;
        cout << "Product Price: " << price << endl;
        cout << "Product quantity: " << quantity << endl;
    }
    void displayTotalInventoryValue()
    {
        total_inventory_val += quantity * price;
        cout << "Total Inventory Value for "<<name<<" is: " << total_inventory_val<<endl;
    }
    ~Product()
    {
    }
};
int Product::total_inventory_val = 0;
int main()
{
    Product Prod1;
    Prod1.setmaxQuantity(7);
    Prod1.set_name("Apple");
    Prod1.set_id(1);
    Prod1.addToInventory(5);
    Prod1.set_price(50);
    Prod1.purchase(3);
    Prod1.updatePrice(5);
    Prod1.displayInventoryValue();
    Prod1.displayDetails();
    Product Prod2("Banana", 2, 15, 3);
    Prod2.setmaxQuantity(15);
    Prod2.addToInventory(5);
    Prod2.purchase(2);
    Prod2.displayInventoryValue();
    Prod2.displayDetails();
    Prod1.displayTotalInventoryValue();
    Prod2.displayTotalInventoryValue();
}