#include <iostream>

// Inheritance Practical Implementation...
// Types of Inheritance
// 1. Single Level Inheritance
// 2. Multi Level Inheritance
// 3. Multiple Inheritance
// 4. Heirarchial Inheritance
// 5. Hybrid Inheritance

// Base Class - or Original Class Template
class Shape {
  private:
   int sample;
   int sample_again;

  protected:
   int width;
   int height;

  public:
   void setWidth(int w) {
      width = w;
   }
   void setHeight(int h) {
      height = h;
   }
};

// Derived Class - Get or Inherit the data of Original Class
class Rectangle : public Shape {
  public:
   int getArea() {
      return (width * height);
   }
};

int main() {
   Rectangle Rect;

   Rect.setWidth(5);
   Rect.setHeight(7);

   std::cout << " Total Area: " << Rect.getArea() << std::endl;

   return 0;
}