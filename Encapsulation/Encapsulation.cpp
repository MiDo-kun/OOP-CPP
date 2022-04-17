#include <iostream>
#include <string>

// Encapsulation Practical Implementation
// Encapsulation - wrapping or grouping of implementation details into one unit or data.
class Car {
   private: 
         std::string name;
      // char name[10];
   public:

      Car(std::string n) {
         name = n;
      }
      void show_name() {
         std::cout << " Car Name is: " << name;
      }
};

int main() {
   std::string car_name = "Toyota";
   Car car_1(car_name);

   car_1.show_name();

   return 0;
}