#include <iostream>
#include <string>

// Class Template Practical Implementation...

// Class for Dersonal Details
template <typename P_name, typename P_age>
class Personal_Details {
   private:
      P_name name;
      P_age age;
      
   public:
      Personal_Details() {
         name = "No Name";
         age = 0;
      }

      Personal_Details(P_name n, P_age a) {
         name = n;
         age = a;
      }

      void show_data() {
         std::cout << " Name: " << name << "\n";
         std::cout << " Age: " << age << "\n";
      }
};

int main() {
   Personal_Details <std::string, int>person_1("Jerson Dela Cerna", 19);
   person_1.show_data();

   return 0;
}