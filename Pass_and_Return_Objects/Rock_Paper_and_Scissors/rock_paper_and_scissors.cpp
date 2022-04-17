#include <windows.h>

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

// Rock, Paper, and Scissors By Passing and Returning Objects from a Function...
// Class: Bot Option, Computation and Result, Scores(File Handling)
// Scores Function: Retains last match data, save score(user and bot)
// Pass object to a particular user defined function and use file handling

// Keep track of the score and logs in the runtime...
int user_previous_count = 0;
int bot_previous_count = 0;
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

   Computation (int b, int u) {
      bot = b;
      user = u;
   }

   void get_option(int b, int u) {
      bot = b;
      user = u;
   }

   void show_option() {
      std::string option[] = {"Rock", "Paper", "Scissors"};
      std::cout << " User: " << option[user] << std::endl;
      std::cout << " Bot: " << option[bot] << std::endl;
   }

   bool show_result() {
      int rock = 0, paper = 1, scissors = 2;
      if (user == bot) {
         match_logs = "Match " + std::to_string(matches) + ": Tie \n" + match_logs;
         std::cout << " Tie" << std::endl;
         return true;
      } else if (user == paper && bot == rock || user == rock && bot == scissors || user == scissors && bot == paper) {
         std::cout << " User Wins!" << std::endl;
         match_logs = "Match " + std::to_string(matches) + ": User Wins! \n" + match_logs;
         matches++;
         ++user_count;
      } else {
         std::cout << " Bot Wins!" << std::endl;
         match_logs = "Match " + std::to_string(matches) + ": Bot Wins! \n" + match_logs;
         matches++;
         ++bot_count;
      }
      return false;
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
      if (user_count == 0 && bot_count == 0)
         std::cout << " You haven't play the game. Score in the runtime is empty. \n";
      else {
         std::cout << " Score in the runtime \n\n";
         std::cout << " User Won: " << user_count << std::endl;
         std::cout << " Bot Won: " << bot_count << std::endl;
         if (user_count == bot_count)
            std::cout << "\n Current Status: Tie \n";
         if (user_count > bot_count)
            std::cout << "\n Player is in the lead! Keep it up! \n";
         if (bot_count > user_count)
            std::cout << "\n Bot is in the lead! \n";
      }
   }
};

class FileHandling {
  public:
   // FileHandling() {
   //    std::fstream get_data("score.txt", std::ios::in);
   //    get_data >> matches;  // Get the stored total rounds
   // }

   void save_logs(std::string data) {
      std::fstream matches("logs.txt", std::ios::out | std::ios::app);
      matches << data;
   }

   void show_logs() {
      std::string text;
      // Get the data of matches
      std::fstream get_logs("logs.txt", std::ios::in);
      if (!get_logs.is_open()) {
         std::cout << " File doesn't exist!";
      } else {
         while (std::getline(get_logs, text)) {
            std::cout << text << '\n';
         }
         get_logs.close();
      }
   }

   void save_data(int saved_matches, int runtime_user_score, int runtime_bot_score) {
      // Get current file data
      int saved_user_data = 0;
      int saved_bot_data = 0;
      std::fstream get_data("score.txt", std::ios::in);
      get_data >> saved_matches >> saved_user_data >> saved_bot_data;

      // Updating game data
      if (runtime_user_score != user_previous_count)
         saved_user_data++;
      if (runtime_bot_score != bot_previous_count)
         saved_bot_data++;

      // Saving Changes to the file
      std::fstream output_score("score.txt", std::ios::out);
      if (!output_score.is_open()) {
         std::cout << "\n File not found!";
      } else {
         output_score << ++saved_matches << " " << saved_user_data << " " << saved_bot_data;
         user_previous_count = runtime_user_score;
         bot_previous_count = runtime_bot_score;
         matches = saved_matches;
         output_score.close();
      }
   }

   void get_scores() {
      int total_file_matches = 0;
      int user_file_score = 0;
      int bot_file_score = 0;

      std::fstream input_score("score.txt", std::ios::in);
      if (!input_score.is_open()) {
         std::cout << "\n File not found!";
      } else {
         input_score >> total_file_matches >> user_file_score >> bot_file_score;
         std::cout << "\n Score in the file \n\n";
         std::cout << " User Won: " << user_file_score << std::endl;
         std::cout << " Bot Won: " << bot_file_score << std::endl;
         std::cout << "\n Total Matches: " << total_file_matches << std::endl;

         input_score.close();
      }
   }
};

int main() {
   Bot bot1;
   Score viewScore;
   FileHandling savedData;

   std::cout << " Welcome to Rock, Paper, and Scissors Game! \n";
   int user_option = -1;
   while (!user_option == 0) {
      srand(time(0));
      user_option = rand() % 3 + 1;
      std::cout << " Enter the following options. Enter 0 to stop the program.\n\n";
      std::cout << " Player Option \n";
      std::cout << " 1 => Rock \n";
      std::cout << " 2 => Paper \n";
      std::cout << " 3 => Scissors \n";
      std::cout << "\n Other Options \n";
      std::cout << " 4 => Show Logs \n";
      std::cout << " 5 => Scores \n";
      std::cout << "\n Option: ";
      // std::cin >> user_option;
      Sleep(1000);

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
            // If its not tie then save data
            std::cout << "\n Result:";
            if (!result.show_result()) {
               savedData.save_data(matches, user_count, bot_count);
            }

            savedData.save_logs(match_logs);
            match_logs = "";

            Sleep(6000);
            system("cls");
            break;

         case 4:
            system("cls");
            savedData.show_logs();

            Sleep(6000);
            system("cls");
            break;

         case 5:
            viewScore.get_scores();
            std::cout << "\n " << std::setfill('=') << std::setw(40) << "\n";
            savedData.get_scores();

            Sleep(6000);
            system("cls");
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