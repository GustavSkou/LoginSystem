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

void SignUp(string username, string password){

    string* prtUsername = &username;
    string* prtPassword = &password;

    user newUser(prtUsername, prtPassword);

    ofstream userFile(path + *newUser.username + ".txt");

    userFile<< "username ; " + *newUser.username << "\n" 
            << "password ; " + *newUser.password;

    userFile.close();
}

void SignIn(string username, string password) {

    string userData1;
    string userData2;

    string* prtUsername = &username;
    string* prtPassword = &password;

    user existingUser(prtUsername, prtPassword);

    ifstream existingUserFile(path + *existingUser.username + ".txt");

    getline(existingUserFile, userData1);
    getline(existingUserFile, userData2);

    cout << userData1 << "\n" << userData2;
    
    existingUserFile.close();
}

int main () {
    int input = 0;
    string username;
    string password;

    cout<< "Sign in (1)\n" 
        << "Sign up (2)\n";
    
    do {
        cin >> input;

        switch (input) {
        case 1:                                             //Sign in
            
            cout<< "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" 
                << "Sign in" << "\n";

            cout<< "Enter username : ";
            cin >> username;

            cout<< "Enter password : ";
            cin >> password;

            SignIn(username, password);
            
            break;
        
        case 2:                                             //Sign up

            cout<< "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" 
                << "Sign up" << "\n";

            cout << "Create username : ";
            cin >> username;

            cout << "Create password : ";
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