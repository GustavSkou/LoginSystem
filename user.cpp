#include <string>

std::string path = "C:\\Users\\gusta\\projectsCPP\\LoginSystem\\AllUserData\\";

class user {
    public:
        std::string* username;
        std::string* password;

        user(std::string* x, std::string* y){
            username = x;
            password = y;
        }
};
