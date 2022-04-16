#include <iostream>

// Practical Implementation of Virtual Functions and Abstract Classes...
class Base {
  public:
   void show() {
      std::cout << " Base show member function is called. \n";
   }
   virtual void print() {
      std::cout << " Base print member function is called. \n";
   }
};

class Derived : public Base {
  public:
   void show() {
      std::cout << " Derived show member function is called. \n";
   }

   void print() {
      std::cout << " Derived print member function is called. \n";
   }
};

int main() {
   Base* base_ptr;
   Derived derived_ptr;

   base_ptr = &derived_ptr;

   base_ptr->show();
   base_ptr->print();

   return 0;
}