#include <iostream>

// Public, Private and Protected Access Specifiers to Practical Implimentation...
// Private - public and protected turns into private specifiers
// Protected - public turns into protected and protected remains the same
// Public - inherited data is the same on original class template
// You cannot convert the mode of Derived Private Class into Private nor Public

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

class convertMyPrivateClassToPublic : public myPrivateClass {

};

class convertMyProtectedToPublic : public myProtectedClass {

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
   convertMyPrivateClassToPublic convertedPrivate;
   convertMyProtectedToPublic convertToPublic;
   // Accessing Private, Public and Protected Access Specifier Using Class
   // myOutsideFunction(obj);

   // Accessing Public Class
   std::cout << "x: " << obj1.x << std::endl;

   // Accessing Converted Private to Public Class
   // std::cout << "convertedPrivate x: " << convertedPrivate.x << std::endl;  // Returns an error - Inaccessible

   // std::cout << convertToPublic.x << std::endl;

   return 0;
}