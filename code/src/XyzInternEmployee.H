#ifndef XYZINTERNEMPLOYEE_H
#define XYZINTERNEMPLOYEE_H

#include "Utilis.H"
#include "XyzEmployeeImpl.H"
#include "iomanip"

class XyzInternEmployee : public XyzEmployeeImpl
{
private:
    HiringFromColleges mHiringCollege;
    HiringFromBranches mHiringBranch; 

public:
    void setInternSpecificDetails(InternDetails InternDetailsParm);
    InternDetails getInternSpecificDetails(void);
    ExternalAgency getExtAgency(void);
    string getEmployeeLeavesAvaialed(void);
    string getEmployeeLeavesLeft(void);
    void printEmpSpecificHeader(void);
    void printEmpSpecifiDetails(void);
};

#endif