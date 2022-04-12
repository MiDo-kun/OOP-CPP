#include <iostream>

// Public, Private and Protected Access Specifiers to Practical Implimentation...
// Public - inherited data is the same on original class template
// Protected - public turns into protected and protected remains the same
// Private - public and protected turns into private class specifiers
// 
class myBaseClass {
  private:
   int z;

  protected:
   int y;

  public:
   int x;
   myBaseClass() {
      x = 5;
      y = 5;
      z = 5;
   }

   void printProtectedData() {
      std::cout << "y: " << y << std::endl;
      // return y;
   };
};

class myPublicClass : public myBaseClass {
   // Inherited as int x(public) and y(private) 
};

class myProtectedClass : protected myBaseClass {
   // Inherited as int x(protected) and y(protected)
};

class myPrivateClass : private myBaseClass {
   // Inherited as int x(private) and y(private)
};

void myOutsideFunction(myBaseClass obj) {
   std::cout << "x: " << obj.x << std::endl;
   obj.printProtectedData();

   // std::cout << "y: " <<  << std::endl;
   // std::cout << "z: " << obj.z << std::endl;
}

int main() {
   myBaseClass obj;
   myPublicClass obj1;

   // myOutsideFunction(obj);
   std::cout << "x: " << obj1.x << std::endl;

   return 0;
}