#include <iostream>
#include <cstring>

using namespace std;

class Medicine
{
private:
    string name;
    string genericName;
    double discountPercent;
    double unitPrice;
    int no_of_items;
    int init_no_of_items, init_price;

public:
    Medicine()
    {
        unitPrice = init_price = 0;
        discountPercent = 5;
    }
    Medicine(string name, string generic_name, double unit_price = 0)
    {
        this->name = name;
        this->genericName = generic_name;
        this->unitPrice = init_price = unit_price;
        discountPercent = 5;
    }
    void assignName(string name, string genericName)
    {
        this->name = name;
        this->genericName = genericName;
    }
    void setPrice(double price)
    {
        unitPrice = init_price = price;
    }
    double updatedPrice(int percent)
    {
        unitPrice -= unitPrice * percent / 100;
        return unitPrice;
    }
    double getSellingPrice(int nos)
    {
        return updatedPrice(discountPercent) * nos;
    }
    double readjustedPrice(int sold_amount)
    {
        double total_cost = unitPrice * no_of_items;
        no_of_items -= sold_amount;
        double selling_price = getSellingPrice(sold_amount);
        return (total_cost - selling_price) / (no_of_items - sold_amount);
    }
    void setDiscount(double percent)
    {
        if (percent > 0 && percent <= 45)
        {
            discountPercent = percent;
        }
    }
    void set_no_of_items(int nos)
    {
        no_of_items = nos;
        init_no_of_items = nos;
    }

    void resetPrice()
    {
        unitPrice = init_price;
        cout << "Price after Reset: BDT " << unitPrice << endl;
    }
    ~Medicine()
    {
        cout << name << " (" << genericName << ") "
             << "has a selling Price BDT " << unitPrice << ". Current discount " << discountPercent << "%." << endl;
    }
};

int main()
{
    Medicine medicine1("Med1", "Generic1", 10.0);
    Medicine medicine2("Med2", "Generic2", 15.0);
    Medicine medicine3("Med3", "Generic3", 20.0);

    double price1 = medicine1.getSellingPrice(5);
    double price2 = medicine2.getSellingPrice(3);
    double price3 = medicine3.getSellingPrice(2);

    std::cout << "Total Price of Sold Medicines: BDT" << price1 + price2 + price3 << std::endl;

    medicine1.resetPrice();

    std::cout << "Readjusted Price of Medicine1: BDT" << medicine1.readjustedPrice(1) << std::endl;
}