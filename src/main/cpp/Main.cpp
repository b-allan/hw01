/**
 * CSC232 Data Structures with C++
 * Missouri State University, Fall 2017
 *
 * @file Main.cpp
 * @authors Jim Daehn <jdaehn@missouristate.edu>
 *          Blake Rall <bar92@live.missouristate.edu>
 * @brief   Entry point for this application. This is nothing more than a playground.
 */
 
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
 
std::string PasswordGenerator(std::string name);
 
void PasswordValidator(std::string response);
 
void ErrorMessage(int error);
 
int main(int argc, char **argv)
{
  std::string name;
  std::string response;
  std::cout << "Enter your full name, including middle initial: ";
  std::getline(std::cin, name);
  std::cout << PasswordGenerator(name);
  std::cout << "Would you like to change your password now [Y|N]? ";
  std::cin >> response;
  PasswordValidator(response);
 
  return EXIT_SUCCESS;
}
 
std::string PasswordGenerator(std::string name)
{
  size_t nameLength{name.length()};
  std::string nameLengthString{std::to_string(int(nameLength))};
  name.erase(remove(name.begin(), name.end(), ' '), name.end());
  name.erase(remove(name.begin(), name.end(), '.'), name.end());
  std::reverse(name.begin(), name.end());
 
  return "Your auto-generated password is: " + name + nameLengthString + '\n';
}
 
void PasswordValidator(std::string response)
{
  std::string password;
  // if (response == "N")
  // {
  //   return "Thank you. It is recommended that you change your password the next time you log into our system.";
  // }
 
  std::cout << "Enter your password: ";
  std::cin >> password;
 
  if (password.length() < 6)
  {
    std::cout << "We're sorry. Your password does not meet our requirements:\n";
    ErrorMessage(1);
  }
 
  for (size_t i = 0; i < password.length(); i++)
  {
    if (isupper(password[i]))
    {
      continue;
    }
    else
    {
      std::cout << "We're sorry. Your password does not meet our requirements:\n";
      ErrorMessage(2);
    }
    break;
  }
 
  for (size_t i = 0; i < password.length(); i++)
  {
    if (islower(password[i]))
    {
      continue;
    }
    else
    {
      std::cout << "We're sorry. Your password does not meet our requirements:\n";
      ErrorMessage(2);
    }
    break;
  }
}
 
void ErrorMessage(int error)
{
  switch (error)
  {
    case 1:
    std::cout << "    * Your password must be at least 6 characters long\n";
    break;
    case 2:
    std::cout << "    * Your password does not contain at least one uppercase and one lowercase letter\n";
    break;
  }
 
}
