#include <iostream>

// Friend Function Practical Implementation...
// - Used to Access Data Members....

class Distance {
  private:
   int meters;

  public:
   Distance() {
      meters = 5;
   }

   void displayData() {
      std::cout << "\n Meters is: " << meters << std::endl;
   }

   friend void addValue(Distance &d);
};

void addValue(Distance &d) {
   d.meters = d.meters + d.meters;
   std::cout << "\n Meters is: " << d.meters;
}

int main() {
   Distance meter;

   std::cout << " Accessing private data memeber/s by dot operator: ";
   meter.displayData();

   std::cout << " Accessing private data member/s by friend function: ";
   addValue(meter);

   return 0;
}