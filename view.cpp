
#include <iostream>
#include <iomanip>
#include "ewaste.hpp"

using namespace std;

// Purpose: Display all registered E-Waste records.

void viewRecords(const vector<EWasteRecord>& records)
{
    cout << "\n===== E-WASTE RECORDS =====" << endl;

    // Check whether records exist
    if (records.empty())
    {
        cout << "No records available!" << endl;
        return;
    }

    // Display table headings
    cout << left
         << setw(10) << "ID"
         << setw(25) << "Name"
         << setw(15) << "Weight(kg)"
         << setw(20) << "Recycling Status"
         << endl;

    // Display all records
    for (size_t i = 0; i < records.size(); i++)
    {
        cout << left
             << setw(10) << records[i].id
             << setw(25) << records[i].itemName
             << setw(15) << fixed << setprecision(2)
             << records[i].weight
             << setw(20) << records[i].status
             << endl;
    }

    cout << "\nTotal records: "
         << records.size() << endl;
}
