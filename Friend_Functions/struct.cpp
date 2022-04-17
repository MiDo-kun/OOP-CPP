#include <iostream>

// Struct
struct data
{
   void show() {
      std::cout << "This is a struct function. " << std::endl;
   }
};

void getStructFunc() {
   data obj1;
   obj1.show();
}

int main() {
   data obj;
   obj.show();

   getStructFunc();

   return 0;
}