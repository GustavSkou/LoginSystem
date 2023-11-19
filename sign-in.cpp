#include <fstream>

bool SignIn(std::string username, std::string password) {

    user signInUser(&username, &password);
    
    std::ifstream existingUserFile(path + *signInUser.username + ".txt");

    if (!existingUserFile.is_open()) {
        
        return false;
    }
    else {

        std::string* openUser = new std::string[2];
        std::string readUserData;

        int n = 0;
        int* nPtr = &n;
        while (getline(existingUserFile, readUserData)) {
        
            int pos = readUserData.find(";") + 1;
            readUserData = readUserData.substr(pos);
            
            openUser[n] = readUserData;                     // array of pointers

            ++*nPtr;
        }
        existingUserFile.close();

        user existingUser(openUser, openUser + 1);          //laver objekt med pointerne som arrayen "openUser" indenholder

        if (*signInUser.password == *existingUser.password) {

            return true;
        }
        else {

            return false;
        }
    }
}