#include <iostream>
#include <cstring>

using namespace std;

class Medicine
{
    private:
        char name[50];
        char genericName[50];
        double discountPercent{5};
        double unitPrice{0};
        
    public:
    
        void assignName(char name[],char genericName[])
        {
            strcpy(this->name,name);
            strcpy(this->genericName,genericName);
        }

        void assignPrice(double price)
        {
            if(price>=0)
            {
                unitPrice=price;
            }
            else
            {
                unitPrice=0;
            }
        }
        void setDiscountPercent(double percent)
        {
            if(percent>=0 && percent<=45)
            {
                discountPercent=percent;
            }
        }
        double getSellingPrice(int nos)
        {
            double price=unitPrice-unitPrice*discountPercent/100;
            price*=nos;
            return price;
        }

        void display()
        {
            cout<<name<<" ("<<genericName<<") "<<"has a unit Price BDT "<<unitPrice<<". Current discount "<<discountPercent<<"%."<<endl;
        }
};

int main()
{
    Medicine med1;
    med1.assignName("Napa","Paracetamol");
    med1.assignPrice(0.8);
    med1.setDiscountPercent(10);
    med1.display();
    cout<<"Selling Price of 5 Napa is BDT "<<med1.getSellingPrice(5)<<endl;
}