#include <iostream>
#include <cmath>
#include <ctime>

// Swapping values without using temporary variable;
int main() {
   srand(time(NULL));
   int num_1 = rand() % 10 ;
   int a = num_1;
   int num_2 = rand() % 10;
   int b = num_2;
   std::cout << a << ", " << b << std::endl;

   // Swapping values
   a += b;
   b = a - b; 
   a = a - b;
   
   std::cout << a << ", " << b;

   return 0;
}