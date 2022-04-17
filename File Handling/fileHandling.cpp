#include <fstream>
#include <iostream>
#include <string>

// File Handling in C++...
int main() {
   std::string name;
   std::string age;
   std::string list;

   std::cout << " Enter Name: ";
   getline(std::cin, name);
   name.push_back('\n');

   std::cout << " Enter Age: ";
   getline(std::cin, age);
   age.push_back('\n');

   while (true) {
      // Put data on the index.txt
      std::fstream inputFile; // identifier for the output stream

      // Check if file exist
      inputFile.open("index.txt", std::ios::out | std::ios::app);
      if (!inputFile.is_open()) {
         std::cout << "\n File Not Found!" << std::endl;
         break;
      } 
      else {
         inputFile << "Name: " + name;
         inputFile << "Age: " + age;
         inputFile.close();
         std::cout << " File write operations is successful!" << std::endl;
      } 

      char arr1[100];
      // Get data on the index.txt
      std::fstream outputFile;  // identifier for the input stream
      outputFile.open("index.txt", std::ios::in);
      if (!outputFile.is_open()) {
         std::cout << "\n File Not Found!" << std::endl;
         break;
      } else {
         int n = 0;
         int i = 1;
         std::cout << "\n Name/s in the index.txt" << std::endl;
         while(std::getline(outputFile, list)) {
            i++;
            if (i == 2) {
               std::cout << "\n Person No." << ++n << std::endl; 
               i = 0;
            }
            std::cout << " " << list << '\n';
         }
         outputFile.close();
         break;
      }
   }
   return 0;
}
