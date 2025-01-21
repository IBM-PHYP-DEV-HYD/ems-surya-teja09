#ifndef EMSPRINTRECORD_H
#define EMSPRINTRECORD_H

#include "Utilis.H"
#include "string.h"
#include "iomanip"

using namespace std;

#define MAX_NAME_LEN      20
#define MAX_ID_LEN        10
#define MAX_EQ_LEN        18

class EmsPrintRecord
{
public:
    string mEmpName;
    string mEmpid;
    int mEmpGender;
    string mEmpDob; /* Date of Birth */
    int mEmpType;
    int mEmpStatus;
    string mEmpDoj; /* Date of Joining */
    string mEmpDol; /* Date of Leaving */
    string mEmpNol; /* Number of Leaves */
    int mEmpAgency;
    HiringFromColleges mEmpCollege;
    HiringFromBranches mEmpBranch;
    bool mPrintAllVar;
    void printAll();
};

#endif