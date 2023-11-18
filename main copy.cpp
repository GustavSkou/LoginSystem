#include <iostream> 
#include <vector>
#include <fstream>
using namespace std;

string path = "C:\\Users\\gusta\\projects\\helloworld\\LoginSystem\\AllUserData\\";

class user {
    public:
        string* username;
        string* password;

        user(string* x, string* y){
            username = x;
            password = y;
        }
};

SignIn(string username, string password) {

    user signInUser(&username, &password);
    
    ifstream existingUserFile(path + *signInUser.username + ".txt");

    if (!existingUserFile.is_open()) {
        
        return false;
    }
    else {

        string* openUser = new string[2];
        string readUserData;

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

void SignUp(string username, string password){

    user newUser(&username, &password);

    ofstream userFile(path + *newUser.username + ".txt");

    userFile<< "username;" + *newUser.username << "\n" 
            << "password;" + *newUser.password;

    userFile.close();
}

int main () {
    int input = 0;
    string username;
    string password;
    bool verify = false;

    cout<< "Sign in (1)\n" 
        << "Sign up (2)\n";
    
    do {
        cin >> input;

        switch (input) {

            case 1: //Sign in
                
                cout<< "Sign in" << "\n";

                cout<< "Enter username : ";
                cin >> username;

                cout<< "Enter password : ";
                cin >> password;

                verify = SignIn(username, password);
                
                switch (verify) {
                
                case true:
                    cout << "Signing in :-)";
                    break;
                
                case false:
                    cout << "Wrong username or password!";
                    break;
                }
                
                break;
            
            case 2: //Sign up

                cout<< "Sign up" << "\n";

                cout<< "Create username : ";
                cin >> username;

                cout<< "Create password : ";
                cin >> password;

                SignUp(username, password);

                break;

            default:                                            //error

                cout << "try again\n";
                break;
        }
    }
    while((input != 1) && (input != 2));

    return 0;
}