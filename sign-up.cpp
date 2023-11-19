#include <fstream>

void SignUp(std::string username, std::string password){

    user newUser(&username, &password);

    std::ofstream userFile(path + *newUser.username + ".txt");

    userFile<< "username;" + *newUser.username << "\n" 
            << "password;" + *newUser.password;

    userFile.close();
}