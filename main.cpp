#include <iostream> 

#include "user.cpp"
#include "sign-in.cpp"
#include "sign-up.cpp"

using namespace std;

int main () {
    int input = 0;
    string username;
    string password;
    
    cout<< "Sign in (1)\n" 
        << "Sign up (2)\n";
    
    do {
        cin >> input;

        switch (input) {

            case 1: //Sign in
                {
                    bool signFail;
                    bool verify;
                    bool* signFailPtr = &signFail;

                    cout<< "Sign in" << "\n";

                    do {
                        cout<< "Enter username : ";
                        cin >> username;

                        cout<< "Enter password : ";
                        cin >> password;

                        verify = SignIn(username, password);
                        
                        switch (verify) {
                        
                            case true:
                                cout << "Signing in " << username;
                                *signFailPtr = false;
                                break;
                            
                            case false:
                                cout << "Wrong username or password! \n Try again \n ";
                                *signFailPtr = true;
                                break;
                        }
                    }
                    while(*signFailPtr);
                }

                break;

            case 2: //Sign up
                {
                    bool signUpSuccess = false;

                    cout<< "Sign up" << "\n";

                    cout<< "Create username : ";
                    cin >> username;

                    cout<< "Create password : ";
                    cin >> password;

                    signUpSuccess = SignUp(username, password);

                    do {
                        switch (signUpSuccess)
                        {
                        case true:
                            break;    
                        
                        case false:
                            cout<< "Username already in use" << "\n" << "Try again" << "\n";

                            cout<< "Create username : ";
                            cin >> username;

                            cout<< "Create password : ";
                            cin >> password;

                            signUpSuccess = SignUp(username, password);

                            break;
                        }
                    }
                    while (!signUpSuccess);

                    cout << "User " << username << " was created";
                }
                break;

            default:                                            //error

                cout << "try again\n";
                break;
        }
    }
    while((input != 1) && (input != 2));

    return 0;
}