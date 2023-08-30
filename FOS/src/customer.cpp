#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <sstream>
#include "../include/customer.h"
#include "../include/admin.h"

using namespace std;

// Function to validate if a string contains only alphabetic characters
bool Customer::isAlpha(const string &str)
{
    return all_of(str.begin(), str.end(), ::isalpha);
}

// Function to validate if an email is in a valid format
bool isValidEmail(const std::string &email)
{
    regex emailPattern(R"(\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,}\b)");
    return regex_match(email, emailPattern);
}

// Handles the login page for customers
void Customer::loginPage()
{
    try
    {
        cout << "\n-------------------------------------------------" << endl;
        cout << "\t\tLogin Page" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "\tEnter 1 -> To Register Yourself" << endl;
        cout << "\tEnter 2 -> To Login" << endl;
        cout << "-------------------------------------------------" << endl;

        int choice;
        cout << "\nEnter your choice : ";
        cin >> choice;

        // Input validation for choice
        while (cin.fail() || choice < 1 || choice > 2)
        {
            cin.clear();
            cin.ignore(512, '\n');
            cout << "\nInvalid input. Please enter a number between 1 and 2: ";
            cin >> choice;
        }

        switch (choice)
        {
        case 1:
            customerRegistartion();
            break;
        case 2:
            customerLogin();
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

// Handles the customer registration process
void Customer::customerRegistartion()
{
    string userPassword, userEmail;
    int count = 0;

    // Get user's name
    cout << "\nEnter your name : ";
    while (!(cin >> name) || !isAlpha(name))
    {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Invalid input. Please enter a valid name: ";
    }

    // Get user's email address
    cout << "Enter your email address: ";
    while (!(cin >> email) || !isValidEmail(email))
    {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Invalid input. Please enter a valid email address: ";
    }

    // Get user's password
    cout << "Enter password : ";
    cin >> password;

    // Check if the user already exists
    ifstream input("/Users/KI20449224/Downloads/FOS/data/customer_registration.csv");

    // Loop through each line in the file
    while (input >> userEmail >> userPassword)
    {
        // Check if the entered email or password already exists
        if (userEmail == email || userPassword == password)
        {
            count = 1;
            break;
        }
    }

    if (count == 1)
    {
        cout << "\nUser already exist. Please register with another details."
             << endl;
        loginPage(); // Go back to the login page
    }

    // Open the file for appending registration data
    ofstream f1("/Users/KI20449224/Downloads/FOS/data/customer_registration.csv", ios::app);

    // Write the user's email and password to the file
    f1 << email << " " << password << endl;

    cout << "\nYour registration has been done successfully" << endl;
    loginPage();    // Go back to the login page
}

// Handles the customer login process
void Customer::customerLogin()
{
    string userPassword, userEmail;
    int count = 0;

    // Get user's email address
    cout << "\nEnter your email address : ";
    cin >> email;

    // Get user's password
    cout << "Enter your password : ";
    cin >> password;

    // Read customer registration data from the file
    ifstream input("/Users/KI20449224/Downloads/FOS/data/customer_registration.csv");

    // Loop through each line in the file
    while (input >> userEmail >> userPassword)
    {
        // Check if the entered email and password match
        if (userEmail == email && userPassword == password)
        {
            count = 1;
            break;
        }
    }

    input.close();

    // If login is successful, proceed to the customer dashboard
    if (count == 1)
    {
        cout << "\nLogin Successfull. Thanks for logging in."
             << endl;
        customerDashboard(); // Go to the customer dashboard
    }
    else
    {
        // If login fails, prompt the user to try again or register
        cout << "\n!!!Login Error!!!" << endl;
        cout << "Enter your details again or Register yourself first.\n"
             << endl;
        loginPage(); // Go back to the login page
    }
}

// Displays the customer dashboard with available options
void Customer::customerDashboard()
{
    try
    {
        // Display the dashboard menu
        cout << "\nHere's your Dashboard \nPlease enter your choice to perform particular tasks" << endl;
        cout << "\n--------------------------------------------------------" << endl;
        cout << "\tEnter 1 -> To View Food Items" << endl;
        cout << "\tEnter 2 -> To Order Food Items" << endl;
        cout << "\tEnter 3 -> To Quit From This Session" << endl;
        cout << "--------------------------------------------------------" << endl;

        int choice;
        cout << "\n\nPlease enter your choice : ";
        cin >> choice;

        // Input validation for choice
        while (cin.fail() || choice < 1 || choice > 3)
        {
            cin.clear();
            cin.ignore(512, '\n');
            cout << "\nInvalid input. Please enter a number between 1 and 3: ";
            cin >> choice;
        }

        switch (choice)
        {
        case 1:
            viewFoodItems(); // Go to the function to view food items
            break;
        case 2:
            orderFoodItems(); // Go to the function to order food items
            break;
        case 3:
            cout << "Thank you, will see you soon." << endl;
            exit(1); // Exit the program

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

// Displays the available food items and handles user's decision to order or not
void Customer::viewFoodItems()
{
    // Display the available food items
    showFoodItems();

    string opt;

    // Prompt the user whether they want to order food items
    cout << "\nDo you want to order food items (yes/no) : ";
    cin >> opt;

    // Input validation for opt
    while (true)
    {
        // Convert choice to lowercase for case-insensitive comparison
        transform(opt.begin(), opt.end(), opt.begin(), ::tolower);

        // If user chooses to order, proceed to ordering food items
        if (opt == "yes")
        {
            orderFoodItems();
            break;
        }
        else if (opt == "no")
        {
            customerDashboard();
            break;
        }
        else
        {
            cout << "Invalid input. Please enter 'yes' or 'no': ";
            cin >> opt;
        }
    }
}

// Handles the process of ordering food items
void Customer::orderFoodItems()
{
    try
    {
        // Open the food items CSV file for reading
        ifstream inputFile("/Users/KI20449224/Downloads/FOS/data/food_items.csv");

        // Check if the file is successfully opened
        if (!inputFile.is_open())
        {
            throw runtime_error("Error opening file: food_items.csv");
        }

        string line;

        // Read each line from the CSV file
        while (getline(inputFile, line))
        {
            stringstream ss(line);
            string temp;

            // Parse the CSV line into individual data elements
            getline(ss, temp, ',');
            foodCodes.push_back(stoi(temp));

            getline(ss, temp, ',');
            foodNames.push_back(temp);

            getline(ss, temp, ',');
            foodPrices.push_back(stoi(temp));

            getline(ss, temp, ',');
            maxQuantities.push_back(stoi(temp));

            getline(ss, temp, ',');
            availabilities.push_back(temp == "yes" ? true : false);
        }

        inputFile.close();

        // Display the available food items
        showFoodItems();

        cout << "\n\nSelect the food item by entering its code: ";
        int selectedCode;

        // Input validation for selectedCode
        while (!(cin >> selectedCode) || cin.peek() != '\n' || selectedCode <= 0)
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalid input. Please enter a valid positive foodCode: ";
        }

        // Check if the selected code is valid
        bool validCode = false;
        int selectedIndex = 0;
        for (int i = 0; i < foodCodes.size(); ++i)
        {
            if (foodCodes[i] == selectedCode)
            {
                validCode = true;
                selectedIndex = i;
                break;
            }
        }

        if (!validCode)
        {
            cout << "Invalid food code. Please select a valid food item."
                 << endl;
            orderFoodItems();
        }

        // Input quantity for the selected food item
        cout << "\nEnter the quantity to order (up to " << maxQuantities[selectedIndex] << "): ";
        int quantity;

        // Input validation for quantity
        while (!(cin >> quantity) || cin.peek() != '\n' || quantity < 1 || quantity > maxQuantities[selectedIndex])
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalid input. Please enter a valid quantity: ";
        }

        // Calculate the total price
        int totalPrice = foodPrices[selectedIndex] * quantity;

        // Display order details and confirmation
        cout << "\nYour order: " << foodNames[selectedIndex] << " x " << quantity << endl;
        cout << "Total Price: $" << totalPrice << endl;
        cout << "Your order has been processed, it will be delived in 30 minutes." << endl;

        string opt;

        // Ask if the user wants to order another food item
        cout << "\nDo you want to order another food item (yes/no) : ";
        cin >> opt;

        // Input validation for opt
        while (true)
        {
            // Convert choice to lowercase for case-insensitive comparison
            transform(opt.begin(), opt.end(), opt.begin(), ::tolower);

            if (opt == "yes")
            {
                orderFoodItems();
                break;
            }
            else if (opt == "no")
            {
                customerDashboard();
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