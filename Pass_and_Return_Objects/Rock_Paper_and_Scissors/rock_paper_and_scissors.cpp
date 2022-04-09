#include <cstdlib>
#include <iostream>
#include <string>

// Rock, Paper, and Scissors By Passing and Returning Objects from a Function...
// Class: Bot Option, Computation and Result, Scores(File Handling)
// Scores Function: Retains last match data, save score(user and bot)
// Pass object to a particular user defined function and use file handling

class Bot {
  public:
   int generate_option() {
      return rand() % 3 + 1;
   }
};

class Computation {
  private:
   int bot;
   int user;

  public:
   Computation() {
      bot = 0;
      user = 0;
   }

   Computation(int b, int u) {
      bot = (b - 1);
      user = (u - 1);
   }

   void show_option() {
      std::string option[] = {"Rock", "Paper", "Scissors"};
      std::cout << " User: " << option[user] << std::endl;
      std::cout << " Bot: " << option[bot] << std::endl;
   }

   void show_result() {
      int rock = 0, paper = 1, scissors = 2;
      if (user == bot)
         std::cout << " Tie" << std::endl;
      else if (user == paper && bot == rock || user == rock && bot == scissors || user == scissors && bot == paper)
         std::cout << " User Wins! " << std::endl;
      else
         std::cout << " Bot Wins! " << std::endl;
   }
};

int main() {
   Bot bot1;

   int user_option = -1;
   while (!user_option == 0) {
      srand(time(0));
      std::cout << " Enter the following options. Enter 0 to stop the program.\n\n";
      std::cout << " 1 => Rock \n";
      std::cout << " 2 => Paper \n";
      std::cout << " 3 => Scissors \n";
      std::cout << "\n Option: ";
      std::cin >> user_option;

      if (user_option == 0) {
         system("CLS");
         std::cout << " Thank You For Playing! \n";
      } else if (!user_option || user_option > 3 || user_option < 0) {
         std::cout << " Not a Option! \n";

         _sleep(1000);
         system("CLS");
      } else {
         Computation result(bot1.generate_option(), user_option);
         system("CLS");

         result.show_option();
         std::cout << "\n Result:";
         result.show_result();

         _sleep(6000);
         system("CLS");
      }
   }

   return 0;
}