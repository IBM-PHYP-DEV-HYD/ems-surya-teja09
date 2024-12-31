#ifndef XYZFULLTIMEEMPLOYEE_H
#define XYZFULLTIMEEMPLOYEE_H

#include "iostream"
#include <iomanip>
#include "XyzEmployeeImpl.H"

using namespace std;

class XyzFullTimeEmployee : public XyzEmployeeImpl
{
public:
    int mLeavesAvailed;
    int mLevesLeft;

public:

    void setLeaveDetails(int LeavesAvailedParm);
    ExternalAgency getExtAgency(void);
    InternDetails getInternSpecificDetails(void);
    string getEmployeeLeavesAvaialed(void);
    string getEmployeeLeavesLeft(void);
    void printEmpSpecificHeader(void);
    void printEmpSpecifiDetails(void);
    void printParticularEmployeeSummary(void);
};

#endif