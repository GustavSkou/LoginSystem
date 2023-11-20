#include <fstream>

bool isUsernameInUse(std::string* username) {

    std::ifstream isInUse(path + *username + ".txt");

    if (isInUse.is_open()) {
        return true;
    }
    else {
        return false;
    }
}