#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, i = 0;
    string text, old, pass, password0, password1, password2, name, age, user, word, word1;
    string creds[2], cp[2];

    cout << "\n" << "     Security_System      " << endl;

    cout << "__________________________" << endl << endl;
    cout << "!    1.Register          !" << endl;
    cout << "!    2.Login             !" << endl;
    cout << "!    3.Change Password   !" << endl;
    cout << "!    4.End Program       !" << endl;
    cout << "__________________________" << endl << endl;

    do
    {
        cout << endl << endl;
        cout << "Enter your Choice: ";
        cin >> a;
        switch (a)
        {
        case 1:
        {
            cout << "____________________________" << endl << endl;
            cout << "!        Register          !" << endl;
            cout << "____________________________" << endl << endl;
            cout << "Please enter Username: ";
            cin >> name;
            cout << "Please enter Password: ";
            cin >> password0;
            cout << "Please enter Age: ";
            cin >> age;

            ofstream of1;
            of1.open("file.txt");
            if (of1.is_open())
                ;
            {
                of1 << name << "\n";
                of1 << password0;
                cout << "\n" << "Registration Successfull ! " << endl;
            }
            break;
        }

        case 2:
        {
            i = 0;
            cout << "____________________________" << endl << endl;
            cout << "!          Login           !" << endl;
            cout << "____________________________" << endl << endl;

            fstream of2;
            of2.open("file.text");
            cout << "Please enter Username: ";
            cin >> user;
            cout << "Please enter Password: ";
            cin >> pass;

            if (of2.is_open())
            {
                while (!of2.eof())
                {
                    while (getline(of2, text))
                    {
                        istringstream iss(text);
                        iss >> word;
                        creds[i] = word;
                        i++;
                    }
                    if (user == creds[0] && pass == creds[1])
                    {
                        cout << "\n" << "Login Successfull ! " << endl << endl;
                        cout << "Details: " << endl;
                        cout << "Username: " + name << endl;
                        cout << "Password: " + pass << endl;
                        cout << "Age: " + age << endl;
                    }
                    else
                    {
                        cout << endl << endl;
                        cout << "Incorrect Credentials ! " << endl;
                        cout << "!    1. Press 2 to Login     !" << endl;
                        cout << "!    2. Press 3 to Change Password       !" << endl;
                        break;
                    }
                }
            }
            break;
        }

        case 3:
        {
            i = 0;
            cout << "__________________________" << endl << endl;
            cout << "!    Change Password     !" << endl;
            cout << "__________________________" << endl << endl;

            fstream of0;
            of0.open("file.txt");
            cout << "Enter the Old Password: ";
            cin >> old;

            if (of0.is_open())
            {
                while (of0.eof())
                {
                    while (getline(of0, text))
                    {
                        istringstream iss(text);
                        iss >> word1;
                        cp[i] = word1;
                        i++;
                    }
                    if (old == cp[1])
                    {
                        of0.close();
                        ofstream of1;
                        if (of1.is_open())
                        {
                            cout << "Enter your new Password: ";
                            cin >> password1;
                            cout << "Enter your Password again: ";
                            cin >> password2;
                            if (password1 == password2)
                            {
                                of1 << cp[0] << "\n";
                                of1 << password1;
                                cout <<"\n"<<"Password changed successfully! "<<endl;
                            }
                            else
                            {
                                of1 << cp[0] << "\n";
                                of1 << old;
                                cout <<"\n"<<"Password do not Match! " << endl;
                            }
                        }
                    }
                    else
                    {
                        cout << "Please enter a Valid Password! " << endl;
                        break;
                    }
                }
            }
            break;
        }

        case 4:
        {
            cout << "_____________________________" << endl << endl;
            cout << "!      Thank You ()         !" << endl;
            cout << "_____________________________" << endl << endl;
            break;
        }
        default:
            cout << "\n" << "Enter a valid choice ! ";
        }
    }

    while (a != 4);
    return 0;
}
