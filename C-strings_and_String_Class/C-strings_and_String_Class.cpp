#include <iostream>
// #include <string>

// Practical Implementation in differences of C-string and String Class 
int main() {
   char name[0];
   // char arr[10]; // C-string
   std::cout << " Enter Name: ";
   std::cin.getline(name, 100); // Include Spaces by Using getline()
   std::cout << "\n Name: " << name;

   std::string string_class = "\n String Class"; // String Class
   std::cout << string_class;

   return 0;
}