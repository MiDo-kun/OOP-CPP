#include <iostream>

// Hybrid Inheritance Practical Implementation and the diamond problem...

// Base Class
class base {
  public:
   int val = 0;
};

// Derived class 1
class derived_1 : public base {
  public:
   void get_val() {
      std::cout << " derived_1 value is " << val + 1 << std::endl;
   }
};

// Derived class 2
class derived_2 : public base {
  public:
   void getVal() {
      std::cout << " derived_2 value is " << val + 2 << std::endl;
   }
};

class multiple_derived : public derived_1, public derived_2 {
  public:
   void getVal() {
      derived_1::get_val();
      derived_2::getVal();
      std::cout << " default base class value " << derived_1::val << std::endl;
   }
};

int main() {
   multiple_derived obj;

   obj.getVal();

   return 0;
}