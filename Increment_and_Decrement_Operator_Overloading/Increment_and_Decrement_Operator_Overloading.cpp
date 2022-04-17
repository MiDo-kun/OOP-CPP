#include <iostream>

// Increment and Decrement Operator Overloading Practical Implementation...
class Weight {
  private:
   int kg;

  public:
   Weight() {
      kg = 0;
   }

   Weight(int x) {
      kg = x;
   }

   // Pre Increment with one operand 
   // void operator++() {
   //    ++kg;
   // }

   // Pre Increment by returning an object
   Weight operator++() {
      Weight temp;
      temp.kg = ++kg;

      return temp;
   }

   // Pre Decrement 
   void operator--() {
      ++kg;
   }

   // Post Increment 
   void operator ++(int) {
      kg++;
   }

   // Post Decrement 
   void operator --(int) {
      kg++;
   }

   void print_weight() {
      std::cout << " Weight in kg is: " << kg << '\n';
   }
};

int main() {
   Weight obj, obj_2;
   obj = ++obj_2; // Pre Increment by returning an object
 
   // obj++; // Post Increment
   // obj--; // Post Decrement
   // ++obj; // Pre Increment
   // --obj; // Pre Decrement
 
   obj.print_weight();
   
   return 0;
}