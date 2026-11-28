#include "ewaste.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Programmer: Gan Ee Hom
// Purpose: Generate an overview of all registered
// E-Waste records in the system.

void generateSummaryReport(const vector<EWasteRecord>& records)
{
    double totalWeight = calculateTotalWeight(records);

    cout << "\n========================================\n";
    cout << "       E-WASTE MANAGEMENT OVERVIEW\n";
    cout << "========================================\n";

    cout << fixed << setprecision(2);

    // Check whether records are available
    if (records.empty())
    {
        cout << "\nNo E-Waste records available.\n";
        cout << "Please register some records first.\n";

        cout << "\n========================================\n";
        return;
    }

    // Find the heaviest and lightest items
    double heaviestWeight = records[0].weight;
    double lightestWeight = records[0].weight;

    string heaviestItem = records[0].itemName;
    string lightestItem = records[0].itemName;

    for (size_t i = 1; i < records.size(); i++)
    {
        if (records[i].weight > heaviestWeight)
        {
            heaviestWeight = records[i].weight;
            heaviestItem = records[i].itemName;
        }

        if (records[i].weight < lightestWeight)
        {
            lightestWeight = records[i].weight;
            lightestItem = records[i].itemName;
        }
    }

    // Display management overview
    cout << "\n--- GENERAL INFORMATION ---\n";

    cout << "Total Registered Items: "<< records.size() << endl;

    cout << "Total E-Waste Weight: "<< totalWeight << " kg" << endl;

    cout << "\n--- WEIGHT ANALYSIS ---\n";

    cout << "Heaviest Item: " << heaviestItem << endl;

    cout << "Heaviest Item Weight: "<< heaviestWeight << " kg" << endl;

    cout << "Lightest Item: "<< lightestItem << endl;

    cout << "Lightest Item Weight: "<< lightestWeight << " kg" << endl;

    cout << "\n========================================\n";
    cout << "       END OF MANAGEMENT OVERVIEW\n";
    cout << "========================================\n";
}
