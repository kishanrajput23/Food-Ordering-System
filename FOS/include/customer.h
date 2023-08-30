#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "/Users/KI20449224/Downloads/FOS/include/admin.h"
using namespace std;

class Customer : public Admin 
{
    string name;
    string email;
    string password;

    vector<int> foodCodes;
    vector<string> foodNames;
    vector<int> foodPrices;
    vector<int> maxQuantities;
    vector<bool> availabilities;

public:
    // Handles the customer's login page
    void loginPage();

    // Handles customer registration process
    void customerRegistartion();

    // Handles the process of customer login
    void customerLogin();
    
    // Displays the customer dashboard with various functionalities
    void customerDashboard();
    
    // Allows the customer to place orders for food items
    void orderFoodItems();

    // Displays the available food items for customers to view
    void viewFoodItems();

    // Checks whether a given string consists of alphabetic characters only
    bool isAlpha(const string &str);
};

#endif // CUSTOMER_H