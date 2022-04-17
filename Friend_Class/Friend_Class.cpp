#include <iostream>

// Friend Class Practical Implementation...

// Class B is a friend of Class A
class A {
   friend class B;

  private:
   int x = 10;
};

class B {
  public:
   void show_data(A obj_1) {
      std::cout << " Value of x: " << obj_1.x  << "\n";
   }
};

int main() {
   A obj_1;
   B obj_2;
   
   obj_2.show_data(obj_1);
   return 0;
}