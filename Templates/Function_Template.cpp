#include <iostream>

// Function Templates Practical Implementation...

// typename - represents the data type of the templates
template <typename C> // C == int
C add(C a, C b) {
   return (a + b);
}

// two typename data type
template <typename T, typename U> // T == int, U == double
U multiply(T a, U b) {
   return (a * b);
}

int main() {
   std::cout << " Addition using function template: " << add<int>(10, 20) << '\n';
   std::cout << " Multiplication using function template: " << multiply<int, double>(10, 2.3);

   return 0;
}