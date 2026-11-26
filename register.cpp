#include <iostream>
#include <limits>
#include "ewaste.hpp"
using namespace std;


// Purpose: Register a new E-Waste item.

void registerEWaste(vector<EWasteRecord>& records,
                    const string& filename)
{
    EWasteRecord record;

    cout << "\n===== REGISTER E-WASTE =====" << endl;

    // Obtain ID
    record.id = getNonEmptyInput("Enter ID: ");

    // Check for duplicate ID
    if (searchRecordByID(records, record.id) != -1)
    {
        cout << "ID already exists!" << endl;
        return;
    }

    // Obtain item name
    record.itemName = getNonEmptyInput("Enter item name: ");

    // Obtain weight
    cout << "Enter weight (kg): ";

    if (!(cin >> record.weight) || record.weight <= 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid weight!" << endl;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Set initial status
    record.status = "Not Recycled";

    // Add new record
    records.push_back(record);

    // Save records
    if (saveRecords(records, filename))
    {
        cout << "E-Waste registered successfully!" << endl;
    }
    else
    {
        records.pop_back();
        cout << "Failed to save record!" << endl;
    }
}