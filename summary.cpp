#include "ewaste.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Programmer: Gan Ee Hom
// Purpose: Generate a report showing recycling percentage
// and overall recycling statistics.

void generateRecyclingReport(const vector<EWasteRecord>& records)
{
    double totalWeight = calculateTotalWeight(records);
    double recycledWeight = calculateRecycledWeight(records);
    double percentage = 0.0;

    int recycledCount = 0;
    int notRecycledCount = 0;

    for (size_t i = 0; i < records.size(); i++)
    {
        if (records[i].status == "Recycled")
        {
            recycledWeight += records[i].weight;
            recycledCount++;
        }
        else if (records[i].status == "Not Recycled")
        {
            notRecycledCount++;
        }
    }

    if (totalWeight > 0)
    {
        percentage = (recycledWeight / totalWeight) * 100;
    }

    cout << "\n========== RECYCLING REPORT ==========\n";

    cout << fixed << setprecision(2);

    cout << "Total Registered Records: "<< records.size() << endl;

    cout << "Total Collected Weight: "<< totalWeight << " kg" << endl;

    cout << "Total Recycled Weight: "<< recycledWeight << " kg" << endl;

    cout << "Recycling Percentage: "<< percentage << "%" << endl;

    cout << "\n========== RECYCLING STATISTICS ==========\n";

    cout << "Recycled Items: "<< recycledCount << endl;

    cout << "Not Recycled Items: "<< notRecycledCount << endl;

    cout << "=========================================\n";
}