#include <iostream>

// Function Overloading Practical Implementation...
class Complex {
  private:
   int real;
   int imag;

  public:
   Complex() {
      real = 0;
      imag = 0;
   }

   Complex(int r, int i) {
      real = r;
      imag = i;
   }

   // Operator Overloading Implementation here...
   // equivalent to operand_1.add(operand_2)
   Complex operator +(Complex operand_2) {
      Complex temp;
      temp.real = real + operand_2.real;
      temp.imag = imag + operand_2.imag;

      return temp;
   }

   void print() {
      std::cout << real << " + " << imag << "i " << std::endl;
   }
};

int main() {
   Complex c1(5, 4);
   Complex c2(2, 3);
   Complex c3;  // Operator Overloading

   c3 = c1 + c2;

   int x = 5;
   int y = 4;
   int z = x + y;

   std::cout << "Z value is: " << z << '\n';
   c3.print();

   return 0;
}