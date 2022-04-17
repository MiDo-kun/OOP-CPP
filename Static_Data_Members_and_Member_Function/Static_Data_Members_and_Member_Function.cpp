#include <iostream>

// Static Data Members and Member Function Practical Implementation...
class my_class{
   public:
      static const int x = 10;
      static int count;

      my_class () {
         count++;
      } 

      static void show_count() {
         std::cout << " Value of x is: " << x << std::endl;
      }
};

int my_class::count = 0;

int main() {
   // Implementing Static Data Members
   std::cout << " Initial count: " << my_class::count << std::endl;
   my_class obj, obj_2;
   std::cout << " Incrementing count after one object is created: " << my_class::count << std::endl;

   // Implementing Static Member Functions
   my_class::show_count();

   return 0;
}