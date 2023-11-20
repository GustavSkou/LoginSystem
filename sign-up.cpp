#include <fstream>
#include "username-checker.cpp"

bool SignUp(std::string username, std::string password){

    if (!isUsernameInUse(&username)) {

        user newUser(&username, &password);

        std::ofstream userFile(path + *newUser.username + ".txt");

        userFile<< "username;" + *newUser.username << "\n" 
                << "password;" + *newUser.password;

        userFile.close();

        return true;
    }
    else {
        
        return false;
    }
}