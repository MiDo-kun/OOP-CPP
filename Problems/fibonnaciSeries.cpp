#include <iostream>

int main() {
   int n1 = 0, n2 = 1; // 0, 1, 1, 2, 3, 5, 8, 13
   int fib, terms = 8;

   // n2 = n1
   std::cout << n1 << ", " << n2;
   for (int i = 0; i < terms - 2; i++) { // terms - 2, because n1 and n2 is already printed 
      fib = n1 + n2;
      n1 = n2;
      n2 = fib;
      std::cout << ", " << fib;
   }

   return 0;
}