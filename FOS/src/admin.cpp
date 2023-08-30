#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/admin.h"

using namespace std;

int loginCount = 0;

// Function to validate if a string contains only alphabetic characters
bool Admin::isAlpha(const string &str)
{
    return all_of(str.begin(), str.end(), ::isalpha);
}

// Handles the admin login process
void Admin ::adminLogin()
{
    // Admin credentials for authentication
    string userId = "admin";
    string password = "12345";
    string id, pass;

    // Display login page header
    cout << "\n\n------------------------------------------" << endl;
    cout << "         Welcome To The Login Page         " << endl;
    cout << "------------------------------------------" << endl;
    cout << "\n\nPlease Enter Your Username & Password For Authentication" << endl;

    try
    {
        cout << "\nEnter Your Username : ";
        cin >> id;

        cout << "\nEnter Your Password : ";
        cin >> pass;

        // Loop for multiple login attempts
        while (id != userId || pass != password)
        {
            cout << "\n!!!Login Error!!!" << endl;
            cout << "Please check your username or password again\n"
                 << endl;

            loginCount++;

            // Check if the number of login attempts exceeded the limit
            if (loginCount == 3)
            {
                cout << "ACCESS DENIED" << endl;
                cout << "You have reached your limit." << endl;
                exit(1);    // Exit the program
            }

            cout << "\nEnter Your Username : ";
            cin >> id;

            cout << "\nEnter Your Password : ";
            cin >> pass;
        }
    }

    catch (exception &ex)
    {
        cerr << "Exception caught: " << ex.what() << endl;
    }

    // Successful login message
    cout << "\nCongratulations " << userId << endl;
    cout << "Your login as an administrator is successfull.\n"
         << endl;
    adminDashboard();       // Call the admin dashboard function
}

// Display the admin dashboard with available options
void Admin ::adminDashboard()
{
    try
    {
        // Display the dashboard menu for admin
        cout << "\nHere's your Dashboard \nPlease enter your choice to perform particular tasks" << endl;
        cout << "\n\n--------------------------------------------------------" << endl;
        cout << "\tEnter 1 -> To Add Food Items" << endl;
        cout << "\tEnter 2 -> To Update Food Items" << endl;
        cout << "\tEnter 3 -> To Delete Food Items" << endl;
        cout << "\tEnter 4 -> To Quit From This Session" << endl;
        cout << "--------------------------------------------------------" << endl;

        int choice;
        cout << "\n\nPlease enter your choice : ";
        cin >> choice;

        while (cin.fail() || choice < 1 || choice > 4)
        {
            cin.clear();
            cin.ignore(512, '\n');
            cout << "\nInvalid input. Please enter a number between 1 and 4: ";
            cin >> choice;
        }

        switch (choice)
        {
        case 1:
            // Call the function to add new food items
            addFoodItems();     
            break;
        case 2:
            // Call the function to update existing food items
            updateFoodItems();      
            break;
        case 3:
            // Call the function to delete food items
            deleteFoodItems();
            break;
        case 4:
            cout << "Thank you, will see you soon." << endl;
            break;

        default:
            cout << "Please choose valid Option" << endl;
            break;
        }
    }
    catch (exception &ex)
    {
        cerr << "Exception caught: " << ex.what() << endl;
    }
}

// Add new food items to the list
void Admin::addFoodItems()
{
    try // exception handling if it might occur during execution of the program
    {
        cout << "Enter the food's required information below" << endl;

        cout << "Enter food code: ";
        while (!(cin >> foodCode) || cin.peek() != '\n' || foodCode <= 0)
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalid input. Please enter a valid positive foodCode: ";
        }

        cout << "Enter food name: ";
        while (!(cin>>foodName) || !isAlpha(foodName))
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalid input. Please enter a valid food name: ";
            getline(cin, foodName);
        }

        foodName[0] = toupper(foodName[0]);

        cout << "Enter food price($): ";
        while (!(cin >> foodPrice) || cin.peek() != '\n' || foodPrice <= 0)
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalid input. Please enter a valid positive price: ";
        }

        cout << "Enter the maximum number of food items one can order: ";
        while (!(cin >> noOfFoodItems) || cin.peek() != '\n' || noOfFoodItems <= 0)
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalid input. Please enter a valid positive number: ";
        }

        cout << "Is this food item available type(yes/no): ";
        cin >> availability;

        while (true)
        {
            // Convert choice to lowercase for case-insensitive comparison
            transform(availability.begin(), availability.end(), availability.begin(), ::tolower);

            if (availability == "yes" || availability == "no")
            {
                break;
                ;
            }
            else
            {
                cout << "Invalid input. Please enter 'yes' or 'no' (only): ";
                cin >> availability;
            }
        }

        ofstream f1("/Users/KI20449224/Downloads/FOS/data/food_items.csv", ios::app);

        f1 << foodCode << ", " << foodName << ", " << foodPrice << ", " << noOfFoodItems << ", " << availability << endl;

        cout << "\nFood items has been added successfully."
             << endl;

        string opt;

        cout << "\nDo you want to add another food item (yes/no) : ";
        cin >> opt;

        // Input validation for opt
        while (true)
        {
            // Convert choice to lowercase for case-insensitive comparison
            transform(opt.begin(), opt.end(), opt.begin(), ::tolower);

            if (opt == "yes")
            {
                addFoodItems();
                break;
            }
            else if (opt == "no")
            {
                adminDashboard();
                break;
            }
            else
            {
                cout << "Invalid input. Please enter 'yes' or 'no': ";
                cin >> opt;
            }
        }
    }
    catch (exception &ex)
    {
        cerr << "Exception caught: " << ex.what() << endl;
    }
}

// Update the details of a food item based on its code
void Admin::updateFoodItems()
{
    int foodNo;
    cout << "Enter the food code number update food item details: ";

    // Input validation for food code number
    while (!(cin >> foodNo) || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Invalid input. Please enter a valid food code number: ";
    }
    cin.ignore(256, '\n');

    ifstream inputFile("/Users/KI20449224/Downloads/FOS/data/food_items.csv");
    ofstream tempFile("/Users/KI20449224/Downloads/FOS/data/temp.csv");

    bool found = false;
    string line;

    while (getline(inputFile, line))
    {
        stringstream ss(line);
        string column;
        int code;

        getline(ss, column, ',');
        code = stoi(column); // Convert the string to integer

        if (code == foodNo)
        {
            found = true;

            cout << "Food found with food code number " << foodNo << ". Please enter updated data:" << endl;
            cout << "Enter food name: ";
            while (!(getline(cin, foodName)) || !isAlpha(foodName))
            {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Invalid input. Please enter a valid food name: ";
            }

            foodName[0] = toupper(foodName[0]);

            cout << "Enter food price($): ";
            while (!(cin >> foodPrice) || cin.peek() != '\n' || foodPrice <= 0)
            {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Invalid input. Please enter a valid positive price: ";
            }

            cout << "Enter the maximum number of food items one can order: ";
            while (!(cin >> noOfFoodItems) || cin.peek() != '\n' || noOfFoodItems <= 0)
            {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Invalid input. Please enter a valid positive number: ";
            }

            cout << "Is this food item available type(yes/no): ";
            cin >> availability;

            while (true)
            {
                // Convert choice to lowercase for case-insensitive comparison
                transform(availability.begin(), availability.end(), availability.begin(), ::tolower);

                if (availability == "yes" || availability == "no")
                {
                    break;
                }
                else
                {
                    cout << "Invalid input. Please enter 'yes' or 'no' (only): ";
                    cin >> availability;
                }
            }
            // Write the updated data to temp file
            tempFile << code << ", " << foodName << ", " << foodPrice << ", " << noOfFoodItems << ", " << availability << endl;
        }
        else
        {
            // Write the original data to temp file
            tempFile << line << endl;
        }
    }

    inputFile.close();
    tempFile.close();

    if (!found)
    {
        cout << "Food item with food code number " << foodNo << " not found." << endl;
    }
    else
    {
        // Rename the temp file to replace the original file
        remove("/Users/KI20449224/Downloads/FOS/data/food_items.csv");
        rename("/Users/KI20449224/Downloads/FOS/data/temp.csv", "/Users/KI20449224/Downloads/FOS/data/food_items.csv");
        cout << "Food item updated successfully." << endl;
    }

    string opt;
    cout << "\nDo you want to update another food item details (yes/no) : ";
    cin >> opt;

    // Input validation for opt
    while (true)
    {
        // Convert choice to lowercase for case-insensitive comparison
        transform(opt.begin(), opt.end(), opt.begin(), ::tolower);

        if (opt == "yes")
        {
            updateFoodItems();
            break;
        }
        else if (opt == "no")
        {
            adminDashboard();
            break;
        }
        else
        {
            cout << "Invalid input. Please enter 'yes' or 'no': ";
            cin >> opt;
        }
    }
}

// Delete a food item from the list based on its code
void Admin::deleteFoodItems()
{
    try
    {
        int foodNo;
        cout << "Enter the food code number to delete food item: ";

        // Input validation for food code number
        while (!(cin >> foodNo) || cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalid input. Please enter a valid food code number: ";
        }
        cin.ignore(256, '\n');

        ifstream inputFile("/Users/KI20449224/Downloads/FOS/data/food_items.csv");
        ofstream tempFile("/Users/KI20449224/Downloads/FOS/data/temp.csv");

        bool found = false;
        string line;

        // Iterate through each line of the input file
        while (getline(inputFile, line))
        {
            stringstream ss(line);
            string column;
            int admno;

            getline(ss, column, ',');
            admno = stoi(column); // Convert the string to integer

            if (admno == foodNo)
            {
                found = true;
                cout << "Food item with food code number " << foodNo << " has been deleted." << endl;
            }
            else
            {
                // Write the original data to temp file
                tempFile << line << endl;
            }
        }

        inputFile.close();
        tempFile.close();

        if (!found)
        {
            cout << "Food item with food code number " << foodNo << " not found." << endl;
        }
        else
        {
            // Rename the temp file to replace the original file
            remove("/Users/KI20449224/Downloads/FOS/data/food_items.csv");
            rename("/Users/KI20449224/Downloads/FOS/data/temp.csv", "/Users/KI20449224/Downloads/FOS/data/food_items.csv");
            cout << "Food item data deleted successfully." << endl;
        }

        string choice;

        cout << "Do you want to continue with the session (yes/no)";
        cin >> choice;

        // Input validation for choice
        while (true)
        {
            // Convert choice to lowercase for case-insensitive comparison
            transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

            if (choice == "yes")
            {
                adminDashboard();
                break;
            }
            else if (choice == "no")
            {
                cout << "See you again" << endl;
                break;
            }
            else
            {
                cout << "Invalid input. Please enter 'yes' or 'no': ";
                cin >> choice;
            }
        }
    }
    catch (exception &ex)
    {
        // Display any caught exceptions
        cerr << "Exception caught: " << ex.what() << endl;
    }
}

// Display the list of available food items
void Admin::showFoodItems()
{
    try // Handle any potential exceptions that might occur during execution
    {
        ifstream file("/Users/KI20449224/Downloads/FOS/data/food_items.csv");
        if (!file.is_open())
        {
            throw runtime_error("Error opening file: food_items.csv");
        }

        cout << "\nBelow are the list of food items : " << endl;

        // Display header with appropriate column formatting
        cout << setw(31) << "Food Code(#)" << setw(21) << "Food Name" << setw(29) << "Food Price($)" << setw(29) << "Max Quantity To Order" << setw(20) << "Availability" << endl;

        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string column;

            while (getline(ss, column, ','))
            {
                // Remove commas from each column
                column.erase(remove(column.begin(), column.end(), ','), column.end());

                cout << setw(25) << column; // Set width of 25 characters
            }
            cout << endl;
        }
        file.close();
    }
    catch (exception &ex)
    {
        cerr << "Exception caught: " << ex.what() << endl;
    }
}