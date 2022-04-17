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
      void setData(std::string cname, std::string mname, std::string ftype, float m, double p) {
         company_name = cname;
         model_name = mname;
         fuel_type = ftype;
         mileage = m;
         price = p;
      }

      void displayData() {
         std::cout << " Car Properties...\n";
         std::cout << "\n Company Name: " << company_name;
         std::cout << "\n Model Name: " << model_name;
         std::cout << "\n Fuel Type: " << fuel_type;
         std::cout << "\n Car Mileage: " << mileage;
         std::cout << "\n Car Price: " << price;
      }
};

int main() {
   Car car1;
   car1.setData("Toyota", "Altis", "Petrol", 17, 17000);
   car1.displayData();
   return 0;
}