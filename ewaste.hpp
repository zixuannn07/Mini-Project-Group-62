#ifndef EWASTE_HPP
#define EWASTE_HPP
#include "ewaste.h"

// Programmer: Tan Ee Joe
// Purpose: Declare the function for registering
// new E-Waste records.
void registerEWaste(vector<EWasteRecord>& records,
                    const string& filename);

                    
// Programmer: Tan Ee Joe
// Purpose: Declare the function for displaying
// all registered E-Waste records.
void viewRecords(const vector<EWasteRecord>& records);

#endif
