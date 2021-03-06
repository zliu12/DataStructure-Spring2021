/**
 * Programming Project.
 *
 * Copyright (c) [2021], Zhao Liu.
 */

/* Find Your Chinese Zodiac - The Twelve Animal Guardians 
Description:
  The program reads in the user's year of birth and output the animal guardian
of Chinese Zodiac of that year, then calculates and prints out the next
Zodiac year of this guardian.
*/

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <ctime>

// Define the string type vector
typedef std::vector<std::string> str_vec;

const int YEAR_LOWER_BOUND = 1900;
const int YEAR_UPPER_BOUND = 2021;
const int ZODIAC_SIZE = 12;
const int INPUT_LENGTH = 4;

class ChineseZodiac {
 private:
  str_vec _zodiac_list = {"Monkey", "Rooster", "Dog", "Pig", "Rat", "Ox",
    "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat"};

 public:  
  // Access private _zodiac_list
  str_vec get_zodiac_list() const {
    return _zodiac_list;
  }

  // This funcion takes a default string and reads in the user input into that
  // string, and then outputs the string as long as the input is valid
  // @param: an empty string
  std::string get_year_input(std::string s) {
    std::cout << "\nWelcome to Find Your Chinese Zodiac - The Twelve Animal "
                << "Guardians\n" << std::endl;
    do {
      std::cout << "Please enter your year of birth (YYYY), then press enter: ";
      std::getline(std::cin, s);
      std::cout << std::endl;
    }while (!validate_year_of_birth(s));
    return s;
  }

  // This function checks whether the string contain any non-digit characters,
  // and returns false if it does, otherwise returns true
  // @param
  bool checkDigit(const std::string &s) const {
    for (unsigned i = 0; i < s.size(); i++) {
      if (!isdigit(s[i])) {
        std::cout << "You entered: " << s << std::endl;
        std::cout << "Invalid input: Non-numerical character exists.\n"
                  << std::endl;
        return false;
      }
    }
    return true;
  }

  // Check input length to avoid crazy long input like 1111111111
  bool checkLength(const std::string &s) const {
    if (s.size() != INPUT_LENGTH) {
      std::cout << "You entered: " << s << std::endl;
      std::cout << "Invalid input: Wrong number of characters.\n" << std::endl;
      return false;
    }
    return true;
  }

  // Check if input is within the time frame
  bool checkTime(const std::string &s) const {
    if (0 <= std::stoi(s) && std::stoi(s) < YEAR_LOWER_BOUND) {
      std::cout << "You entered: " << s << std::endl;
      std::cout << "Invalid input: Out of time frame. The Man From Earth?\n"
                << std::endl;
      return false;
    } else if (std::stoi(s) > YEAR_UPPER_BOUND) {
      std::cout << "You entered: " << s << std::endl;
      std::cout << "Invalid input: Out of time frame. Back To The Future!\n"
                << std::endl;
      return false;
    }
    return true;
  }

  // Validate input
  bool validate_year_of_birth(const std::string &s) const {
    if (checkDigit(s) && checkLength(s) && checkTime(s)) {
      return true;
    }
    return false;
  }

  // Find your animal guardian
  void animal_guardian(const std::string &s, const str_vec &v) const {
    int n = std::stoi(s);
    int result = n % v.size();
    std::cout << "You entered: " << s << std::endl;
    switch (result) {
      case 0:
        std::cout << "Your animal guardian is: "  << v[result] << std::endl;
        break;
      case 1:
        std::cout << "Your animal guardian is: "  << v[result] << std::endl;
        break;
      case 2:
        std::cout << "Your animal guardian is: "  << v[result] << std::endl;
        break;
      case 3:
        std::cout << "Your animal guardian is: "  << v[result] << std::endl;
        break;
      case 4:
        std::cout << "Your animal guardian is: "  << v[result] << std::endl;
        break;
      case 5:
        std::cout << "Your animal guardian is: "  << v[result] << std::endl;
        break;
      case 6:
        std::cout << "Your animal guardian is: "  << v[result] << std::endl;
        break;
      case 7:
        std::cout << "Your animal guardian is: "  << v[result] << std::endl;
        break;
      case 8:
        std::cout << "Your animal guardian is: "  << v[result] << std::endl;
        break;
      case 9: 
        std::cout << "Your animal guardian is: "  << v[result] << std::endl;
        break;     
      case 10: 
        std::cout << "Your animal guardian is: "  << v[result] << std::endl;
        break;
      case 11:
        std::cout << "Your animal guardian is: "  << v[result] << std::endl;
        break;
    }
  }

  // find the next guardian year
  void next_guardian_year (const std::string &s) const {
    int n = std::stoi(s);
    time_t t = time(NULL);
    tm *tptr = localtime(&t);
    while (n < tptr->tm_year + 1900) {
      n += 12;
    }

    if (n == (tptr->tm_year + 1900)) {
      std::cout << "Hey, it is the year of Ox now!\n";
      std::cout << "The next time will be year of " << n + 12 << "." 
                << std::endl;
    } else {
      std::cout << "The next year of your animal guardian will be " << n
                << ". " << std::endl;
    }
    std::cout << "Remember, wearing a red in your zodiac year will bring you "
              << "good luck!\n" << std::endl;
  }
};

char repeat() {
  char a;
  do {
    std::cout << "1. Press [Y/y] to test a different year.\n" 
              << "2. Press [N/n] to quit." << std::endl
              << "Please enter your choice, then press enter: ";
    std::cin >> a;
    std::cin.ignore();
    std::cout << std::endl;
    a = tolower(a);
  } while (a != 'n' && a != 'y' && a != '1' && a != '2');
  return a;
}

int main() {
  // Create an object
  ChineseZodiac user; 
  std::string year_input;
  char repeat_input;

  while (true) {
    // Take and validate input
    year_input = user.get_year_input(year_input);

    // Output animal guardian result
    user.animal_guardian(year_input, user.get_zodiac_list());

    // Output the next animal guardian year
    user.next_guardian_year(year_input);

    // Check if the user would like to test again
    repeat_input = repeat();

    // Output game end message
    if (repeat_input == 'y' || repeat_input == '1') {
      continue;
    } else if (repeat_input == 'n' || repeat_input == '2') {
      std::cout << "\nBye bye.\n" << std::endl;
      break;
    }
  }
  return 0;
}