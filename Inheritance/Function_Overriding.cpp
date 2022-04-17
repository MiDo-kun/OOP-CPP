#include <iostream>

// Function Overriding - rewriting or modifying the base class function in derived class
class Base {
  public:
   void display() {
      std::cout << " Original display()" << std::endl;
   }
};

class Derived : public Base {
  public:
   void display() {
      // Base::display(); // Getting base class function
      std::cout << " Overriding display()" << std::endl;
   }
};

int main() {
   Base show;
   Derived show_overriding;

   show.display();
   show_overriding.display();

   return 0;
}