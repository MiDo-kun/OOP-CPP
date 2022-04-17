#include <iostream>

// Compute for Real and Complex Numbers
class Real_and_Complex {
   private: 
   public:
      int real;
      float complex;
      Real_and_Complex() {
         std::cout << " Result is: " << std::endl;
      }

      Real_and_Complex(int r, int c) {
         real = r;
         complex = c;
      }

      void print_initial_values() {
         std::cout << " Real: " << real << std::endl;
         std::cout << " Complex: " << complex << "i " << std::endl;
      }
};

Real_and_Complex compute_real_and_complex_num(Real_and_Complex n1, Real_and_Complex n2) {
   int real = n1.real + n2.real;
   float complex = n1.complex + n2.complex;

   Real_and_Complex temp(real, complex);

   return temp;
}

int main() {
   Real_and_Complex number_1(5, 4), number_2(3, 1), result;
   result = compute_real_and_complex_num(number_1, number_2);
   result.print_initial_values();
   return 0;
}