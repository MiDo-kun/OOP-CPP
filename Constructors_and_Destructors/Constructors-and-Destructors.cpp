#include <iostream>
#include <string>

// Objects and Classes Practical Implementation...
class Car {
  private:
   std::string company_name;
   std::string model_name;
   std::string fuel_type;
   float mileage;
   double price;

  public:
   // Default Constructor...
   Car() {
      std::cout << "\n Default constructor call: \n";
   }

   // Parametized Constructor...
   Car(std::string cname, std::string mname, std::string ftype, float m, double p) {
      company_name = cname;
      model_name = mname;
      fuel_type = ftype;
      mileage = m;
      price = p;
   }

   // Copy Constructor...
   Car(Car &copy) {
      company_name = copy.company_name;
      model_name = copy.model_name;
      fuel_type = copy.fuel_type;
      mileage = copy.mileage;
      price = copy.price;
   }

   // void setData(std::string cname, std::string mname, std::string ftype, float m, double p) {
   //    company_name = cname;
   //    model_name = mname;
   //    fuel_type = ftype;
   //    mileage = m;
   //    price = p;
   // }

   void displayData() {
      std::cout << " Car Properties: \n";
      std::cout << "\n Company Name: " << company_name;
      std::cout << "\n Model Name: " << model_name;
      std::cout << "\n Fuel Type: " << fuel_type;
      std::cout << "\n Car Mileage: " << mileage;
      std::cout << "\n Car Price: " << price << std::endl;
   }

   ~Car() {
      std::cout << " Destructor is Called!";
   }
};

int main() {
   // car1, is default constructor...
   Car car1;
   car1.displayData();

   // car2, is parametized constructor...
   std::cout << "\n Parametized constructor call...\n";
   Car car2("Toyota", "Altis", "Petrol", 17, 17000);
   car2.displayData();

   // car3, is copy constructor...
   Car car3;
   std::cout << "\n Copy Constructor call: \n";
   car3 = car2;
   car3.displayData();

   return 0;
}