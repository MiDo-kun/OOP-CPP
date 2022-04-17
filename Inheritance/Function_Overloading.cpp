#include <iostream>

// Function Overloading - same name but different parameters, arguments and return data type...
void print(int a) {
   std::cout << "a " << a << std::endl;
}
void print(int a, int b) {
   std::cout << "a " << a << std::endl;
   std::cout << "b " << b << std::endl;
}
void print(int a, int b, int c) {
   std::cout << "a " << a << std::endl;
   std::cout << "b " << b << std::endl;
   std::cout << "c " << c << std::endl;
}
int main() {
   print(5);
   print(3, 4);
   print(1, 2, 3);
   return 0;
}