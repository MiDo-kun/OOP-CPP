#include <iostream>

// Multiple Inheritance Practical Implementation and the ambiguous problem...

// Base 1 
class A{
   public:
      void printMessage() {
         std::cout << " Class A print message function.\n";
      }
};


// Base 2
class B {
   public:
      void printMessage() {
         std::cout << " Class B print message function. \n";
      }
};

// Derived Class 
class AB : public A, public B {
   public:
      void printMessage() {
         // std::cout << " Class AB print message function. \n";
         A::printMessage();
         B::printMessage();
      }
};

int main() { 
   AB obj;

   obj.printMessage();
 
   return 0;
}