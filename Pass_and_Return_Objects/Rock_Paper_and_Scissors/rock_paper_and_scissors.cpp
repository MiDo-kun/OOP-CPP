#include <windows.h>

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

// Rock, Paper, and Scissors By Passing and Returning Objects from a Function...
// Class: Bot Option, Computation and Result, Scores(File Handling)
// Scores Function: Retains last match data, save score(user and bot)
// Pass object to a particular user defined function and use file handling

// Keep track of the score and logs in the runtime...
int bot_count = 0;
int user_count = 0;
std::string match_logs = "";
int matches = 0;

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
      else if (user == paper && bot == rock || user == rock && bot == scissors || user == scissors && bot == paper) {
         ++user_count;
         ++matches;
         std::cout << " User Wins!" << std::endl;
         match_logs = "Match " + std::to_string(matches) + ": User Wins! \n" + match_logs;
      } else {
         ++bot_count;
         ++matches;
         std::cout << " Bot Wins!" << std::endl;
         match_logs = "Match " + std::to_string(matches) + ": Bot Wins! \n" + match_logs;
      }
   }
};

class Logs {
  private:
   std::string log;

  public:
   Logs(std::string data) {
      log = data;
   }
   void showData() {
      system("cls");
      if (log == "") 
         std::cout << " Logs is Empty! \n";
      else 
         std::cout << log << std::endl;
   }
};

class Score {
  private:
   int bot_score;
   int user_score;

  public:
   Score() {
      bot_score = 0;
      user_score = 0;
   }

   void get_scores() {
      system("cls");

      Computation data;
      std::cout << " Scores in the run time. \n\n";
      std::cout << " User Won: " << user_count << std::endl;
      std::cout << " Bot Won: " << bot_count << std::endl;

      if (user_count == bot_count)
         std::cout << "\n Current Status: Tie \n";
      if (user_count > bot_count)
         std::cout << "\n Player is in the lead! Keep it up! \n";
      if (bot_count > user_count)
         std::cout << "\n Bot is the lead! \n";

      Sleep(6000);
      system("cls");
   }
};

class FileHandling {
  private:
   std::string logs;
   int rounds;
   int user;
   int bot;

  public:
   FileHandling() {
      rounds = 0;
      user = 0;
      bot = 0;
   }

   FileHandling(std::string match_logs, int matches, int user_count, int bot_count) {
      logs = match_logs;
      rounds = matches;
      user = user_count;
      bot = bot_count;
   }

   void showData() {
      std::fstream output_score("score.txt", std::ios::out);
      if (!output_score.is_open()) {
         std::cout << "\n File not found!";
      } else {
         output_score << "Hello World!";
         output_score.close();
      }

      std::fstream input_score("score.txt", std::ios::in);
      if (!input_score.is_open()) {
         std::cout << "\n File not found!";
      } else {
         std::string text;
         while (std::getline(input_score, text)) {
            std::cout << text << '\n';
         }
         input_score.close();
      }
   }
};

int main() {
   Bot bot1;
   Score viewScore;
   FileHandling savedData(match_logs, matches, user_count, bot_count);
   int user_option = -1;
   
   std::cout << " Welcome to Rock, Paper, and Scissors Game! \n";
   while (!user_option == 0) {
      srand(time(0));

      std::cout << " Enter the following options. Enter 0 to stop the program.\n\n";
      std::cout << " Player Option \n";
      std::cout << " 1 => Rock \n";
      std::cout << " 2 => Paper \n";
      std::cout << " 3 => Scissors \n";
      std::cout << "\n Other Options \n";
      std::cout << " 4 => Show Logs \n";
      std::cout << " 5 => Scores \n";
      std::cout << "\n Option: ";
      std::cin >> user_option;

      Logs round(match_logs);
      Computation result(bot1.generate_option(), user_option);
      switch (user_option) {
         case 0:
            system("cls");
            std::cout << " Thank You For Playing! \n";
            break;

         case 1:
         case 2:
         case 3:
            system("cls");

            result.show_option();

            std::cout << "\n Result:";
            result.show_result();
            Sleep(6000);
            system("cls");

            break;

         case 4:
            round.showData();
            savedData.showData();

            Sleep(6000);
            system("cls");
            break;

         case 5:
            viewScore.get_scores();
            break;

         default:
            std::cout << " Not a Option! \n";
            Sleep(1000);
            system("cls");
            break;
      }
   }

   return 0;
}