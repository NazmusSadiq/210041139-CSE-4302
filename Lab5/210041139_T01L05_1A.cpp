#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Category
{
private:
    int id, quantity;
    float price;
    string category_name, product_name;
    static int total_inventory_val;
    unordered_map<string, int> products;
    float amounts[50], prices[50];
    string names[50];
    bool cat_dis_added;
public:
    Category()
    {
        price = 0;
        quantity = 0;
        cat_dis_added = false;
    }
    Category(string cat_name, int id)
    {
        this->category_name = cat_name;
        this->id = id;
        price = 0;
        quantity = 0;
        cat_dis_added = false;
    }
    int get_id() const
    {
        return id;
    }
    float get_price() const
    {
        return price;
    }

    void set_id(int id)
    {
        this->id = id;

    }
    void set_price(float price)
    {
        this->price = price;
    }
    void addProduct(string product_name, int Quantity, double price)
    {
        products.insert(make_pair(product_name,quantity++));
        names[products[product_name]] = product_name;
        prices[products[product_name]] = price;
        addToInventory(product_name, Quantity);
    }
    void addToInventory(string product_name, int added_quantity)
    {
        amounts[products[product_name]] += added_quantity;
    }
    void purchase(string product_name, int purchased_quantity)
    {
        amounts[products[product_name]] -= purchased_quantity;
        if (amounts[products[product_name]] <= 0)
        {
            cout << "This amount can not be purchased" << endl;
            amounts[products[product_name]] += purchased_quantity;
        }
    }
    void applyCategoryDiscount(float percent)
    {
        for (int i = 0; i < products.size(); i++)
        {
            prices[i] -= prices[i] * percent / 100;
        }
        cat_dis_added = true;
    }
    void applyProductDiscount(string product_name, float percent)
    {
        if (!cat_dis_added)
        {
            prices[products[product_name]] -= prices[products[product_name]] * percent / 100;
        }
    }
    void updatePrice(string product_name, int percent)
    {
        if (percent > 0)
            prices[products[product_name]] -= prices[products[product_name]] * percent / 100;
    }
    void displayInventoryValue(string product_name)
    {
        cout << "Inventory Value for:: " << product_name << " is: " << prices[products[product_name]] * amounts[products[product_name]] << endl;
    }
    void displayDetails() const
    {
        cout << "Category Name: " << category_name << endl;
        cout << "Category ID: " << id << endl;
        for (int i = 0; i < 2; i++)
        {
            cout << "Product Name: " << names[i] << endl;
            cout << "Product Price: " << prices[i] << endl;
            cout << "Product Quantity: " << amounts[i] << endl;
        }
    }
    void displayTotalInventoryValue()
    {
        for (int i = 0; i < products.size(); i++)
        {
            total_inventory_val += amounts[i] * prices[i];
        }
        cout << "Total Inventory Value is: " << total_inventory_val << endl;
    }
    ~Category()
    {
        cout<<"Destructor calling "<<endl;
        displayDetails();
    }
};
int Category::total_inventory_val = 0;
int main()
{
    Category cat1("Electronics", 1);
    Category cat2("Clothing", 2);
    Category cat3("Books", 3);

    cat1.addProduct("Laptop", 5, 800);
    cat1.addProduct("Smartphone", 10, 400.0);
    cat2.addProduct("Shirt", 20, 30.0);
    cat2.addProduct("Jeans", 15, 50.0);
    cat3.addProduct("Life Of Pi", 30, 15.0);
    cat3.addProduct("Linear Algebra", 15, 15.0);

    cat1.displayTotalInventoryValue();
    cat2.displayTotalInventoryValue();
    cat3.displayTotalInventoryValue();

    cat1.applyCategoryDiscount(10);
    cat2.applyCategoryDiscount(5);
    cat1.applyProductDiscount("Laptop", 5);
    cat2.applyProductDiscount("Shirt", 8);
    cat3.applyProductDiscount("Linear Algebra", 40);
    cat1.updatePrice("Smartphone", 5);
    cat2.updatePrice("Jeans", 10);
    cat3.updatePrice("Life Of Pi", 5);
    cat1.purchase("Laptop", 2);
    cat2.purchase("Shirt", 5);
    cat3.purchase("Linear Algebra", 1);



    return 0;
}