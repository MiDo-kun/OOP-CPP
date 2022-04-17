#include <iostream>

int main() {
   // Enter an char instead of an int
   try {
      int n = 0;
      std::cout << " Input a value of int: ";
      std::cin >> n;

      if (!n) {
         throw n;
      }

   }  catch(int exception) {
      std::cout << " Not a Number Please Try again!";
   } 
   
   return 0;
}