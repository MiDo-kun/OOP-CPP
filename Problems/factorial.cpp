#include <iostream>

int main() {
   int n = 5, result = 1;

   for (int i = 1; i <= n; n--)   
      result = result * n;

   std::cout << result;

   return 0;
}