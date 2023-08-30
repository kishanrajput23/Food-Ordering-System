#ifndef ADMIN_H
#define ADMIN_H

using namespace std;

class Admin
{
    int foodCode;
    string foodName;
    int foodPrice;
    int noOfFoodItems;
    string availability;

public:

    // handles admin login credentials
    void adminLogin();
    
    // Displays the admin dashboard with various functionalities
    void adminDashboard();
    
    // Allows the admin to add new food items to the system
    void addFoodItems();
    
    // Allows the admin to update existing food item details
    void updateFoodItems();
    
    // Allows the admin to delete food items from the system
    void deleteFoodItems();

    // Displays a list of all available food items to the admin
    void showFoodItems();

    // Checks whether a given string consists of alphabetic characters only
    bool isAlpha(const string &str);

};

#endif // ADMIN_H