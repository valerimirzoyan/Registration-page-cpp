#include <iostream>
#include <fstream> // file stream
#include <sstream> // string stream
#include <string>

using namespace std;

int main ()
{

    int a, i = 0;
    string text, old, password1, password2, pass, name, password0, age, user, word, word1;
    string creds [2], cp [2];

    cout << "  Security System  " << endl << endl;
    cout << " 1. Register  " << endl;
    cout << " 2. Login  " << endl;
    cout << " 3. Change password  " << endl;
    cout << " 4. End Program  " << endl << endl;

    do
    {

        cout << " Enter your choice:- ";
        cin >> a;

        switch ( a )
        {

            case 1:
            {

                cout << "  Register  " << endl << endl;

                cout << "Pls enter username:-";
                cin >> name;

                cout << "Pls enter the password:-";
                cin >> password0;

                cout << " Pls enter your age:- ";
                cin >> age;

                ofstream of1;
                of1.open ( "file.txt" );

                if ( of1.is_open () )
                {

                    of1 << name << "\n";
                    of1 << password0;
                    cout << " Register successful " << endl;
                    
                }

                break;
            }

            case 2:
            {
                i = 0;

                cout << "  Login  " << endl << endl;

                ifstream of2;
                of2.open ( "file.txe" );

                cout << "Pls enter the username:-";
                cin >> user;

                cout << "Pls enter the password:-";
                cin >> pass;

                if ( of2.is_open () )
                {

                    while ( !of2.eof () )
                    {

                        while ( getline ( of2, text ) )
                        {

                            istringstream iss ( text );
                            iss >> word;
                            creds [ i ] = word;
                            i++ ;

                        }

                        if ( user == creds [ 0 ] && pass == creds [ 1 ] )
                        {

                            cout << " Log in successful " << endl << endl;

                            cout << " Details: " << endl;

                            cout << " Usernam: " + name << endl;
                            cout << " Password: " + pass << endl;
                            cout << " age: " + age << endl;

                        }

                        else
                        {

                            cout << " Incorrect Credentials " << endl;

                            cout << " Press 2 to Login " << endl;
                            cout << " Press 3 to change password " << endl;
                            
                            break;

                        }

                    }
                    
                }

                break;
            }

            case 3:
            {

                i = 0;

                cout << " Cange password " << endl;

                ifstream of0;
                of0.open ( "file.txe " );

                cout << " Enter the old password:- ";
                cin >> old;

                if( of0.is_open () )
                {

                    while( of0.eof () )
                    {

                        while ( getline ( of0, text ) )
                        {

                            istringstream iss ( text );
                            iss >> word;
                            cp [ i ] = word1;
                            i++ ;

                        }

                        if ( old == cp [ 1 ] ) 
                        {

                            of0.close ();

                            ofstream of1;
                            if ( of1.is_open() )
                            {

                                cout << " Enter your new password:-";
                                cin >> password1;
                                cout << " Enter your password again:-";
                                cin >> password2;

                                if ( password1 == password2 )
                                {

                                    of1 << cp [ 0 ] << "\n";
                                    of1 << password1;
                                    cout << "password changed successfully " << endl;

                                }

                                else
                                {
                                    of1 << cp [ 0 ] << "\n";
                                    of1 << old;
                                    cout << " Password don't match " << endl;

                                    break;

                                }

                            }

                        }

                        else
                        {
                            cout << " Please enter a valid password " << endl;

                            break;

                        }

                        break;

                    }

                    break;

                }

                break;

            }

            case 4:
            {

                cout << " Tnx! ";

                break;

            }

            default:

                cout << " Enter a valid choice ";

        }

    }

    while ( a != 4 );

    return 0;
    
}