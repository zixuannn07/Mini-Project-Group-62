
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "ewaste.hpp"

using namespace std;


// Purpose: Obtain valid text input from the user.

string getNonEmptyInput(const string& prompt)
{
    string value;

    while (true)
    {
        cout << prompt;

        if (!getline(cin, value))
        {
            exit(0);
        }

        if (value.find_first_not_of(" \t\r\n") != string::npos
            && value.find('|') == string::npos)
        {
            return value;
        }

        cout << "Invalid input! Please try again." << endl;
    }
}



// Purpose: Obtain a valid menu choice.

int getMenuChoice(int minimum, int maximum)
{
    int choice;
    string input;
    char extra;

    while (true)
    {
        cout << "Enter your choice: ";

        if (!getline(cin, input))
        {
            exit(0);
        }

        stringstream stream(input);

        if (stream >> choice &&
            !(stream >> extra) &&
            choice >= minimum &&
            choice <= maximum)
        {
            return choice;
        }

        cout << "Invalid choice! Please try again." << endl;
    }
}


void runProgram(const string& filename)
{
    int choice;

    // Load existing records from the text file
    vector<EWasteRecord> records = loadRecords(filename);

    do
    {
        cout << "\n===== E-WASTE TRACK =====" << endl;

        cout << "1. Register E-Waste" << endl;
        cout << "2. View E-Waste Records" << endl;
        cout << "3. Search Records" << endl;
        cout << "4. Update Collection Status" << endl;
        cout << "5. Update Recycling Status" << endl;
        cout << "6. Delete Records" << endl;
        cout << "7. Calculate Total Registered Weight" << endl;
        cout << "8. Calculate Recycled Weight" << endl;
        cout << "9. Generate Recycling Report" << endl;
        cout << "10. Generate Report Summary" << endl;
        cout << "0. Exit Program" << endl;

        choice = getMenuChoice(0, 10);

        switch (choice)
        {
            case 1:
                registerEWaste(records, filename);
                break;

            case 2:
                viewRecords(records);
                break;

            case 3:
                cout << "Search Records" << endl;

                break;
            

            case 4:
                 cout << "Update Collection Status" << endl;
                
                break;

            case 5:
                updateRecyclingStatus(records, filename);
                break;

            case 6:
                deleteRecord(records, filename);
                break;

            case 7:
                displayTotalWeight(records);
                break;

            case 8:
                cout << "Calculate Recycled Weight" << endl;
                break;

            case 9:
                cout << "Generate Recycling Report" << endl;
                break;

            case 10:
                cout << "Generate Report Summary" << endl;
                break;

            case 0:
                cout << "Exiting program..." << endl;
                break;
        }

    } while (choice != 0);
}
