#include "ewaste.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Programmer: Gan Ee Hom
// Purpose: Calculate the total weight of recycled E-Waste.

double calculateRecycledWeight(const vector<EWasteRecord>& records)
{
    double RecycledWeight = 0.0;

    for (size_t i = 0; i < records.size(); i++)
    {
        if (records[i].status == "Recycled")
        {
            RecycledWeight += records[i].weight;
        }
    }

    cout << fixed << setprecision(2);
    cout << "\n===== RECYCLED WEIGHT =====" << endl;
    cout << "Total Recycled Weight: " << RecycledWeight << " kg" << endl;
    return RecycledWeight;
}