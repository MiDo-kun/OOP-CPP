#include <iostream>

// Abstraction Practical Implementation...
class AB {
   private:
      int x, y;
   public:
      AB(int a, int b) {
         x = a;
         y = b;
      }

      void show_data() {
         std::cout << "x: " << x << ", y: " << y;
      }
};

int main() {
      AB obj(10, 20);

      obj.show_data();
   return 0;
}