#ifndef EWASTE_HPP
#define EWASTE_HPP

#include "ewaste.h"

void registerEWaste(vector<EWasteRecord>& records,
                    const string& filename);

void viewRecords(const vector<EWasteRecord>& records);

#endif