#include <iostream>
#include "/Users/KI20449224/Downloads/FOS/include/admin.h"
#include "/Users/KI20449224/Downloads/FOS/include/customer.h"

using namespace std;

int main()
{
    Admin ad;
    Customer cst;
    int choice;

    // Display the welcome message and options
    cout << "\n\n--------------------------------------------------------------------" << endl;
    cout << "                      Food Ordering System                        " << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "\t\tWelcome To Home Page" << endl;
    cout << "\t\tPress 1 --> Admin Login" << endl;
    cout << "\t\tPress 2 --> Customer Login" << endl;
    cout << "\t\tPress 3 --> Exit" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "\nPlease Enter Your Choice : ";

    try
    {
        // Input validation for choice
        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(512, '\n');
            cout << "\nPlease enter a number!!" << endl;
            cout << "\nPlease Enter Your Choice : ";
        }

        // Based on the selected choice, perform the corresponding action
        switch (choice)
        {
        case 1:
            ad.adminLogin();        // Call the admin login function
            break;
        case 2:
            cst.loginPage();        // Call the customer login function
            break;
        case 3:
            cout << "See you again." << endl;
            break;
        default:
            cout << "\nPlease select from the options given above" << endl;
            main();     // If choice is invalid, show options again
        }
    }
    catch (const std::exception &ex)
    {
        cerr << "Exception caught: " << ex.what() << endl;
    }
    return 0;
}
