#ifndef XYZINTERNEMPLOYEE_H
#define XYZINTERNEMPLOYEE_H

#include "Utilis.H"
#include "XyzEmployeeImpl.H"
#include "iomanip"

class XyzInternEmployee : public XyzEmployeeImpl
{
protected:
    Ems::HiringFromColleges mHiringCollege;
    Ems::HiringFromBranches mHiringBranch; 

public:
    XyzInternEmployee(string EmpNameParm, string EmpIdParm, int EmpStatusParm, int EmpTypeParm, int EmpGenderParm, string DobParm, string DojParm);
    InternDetails getInternSpecificDetails(void);
    Ems::ExternalAgency getExtAgency(void);
    string getEmployeeLeavesAvailed(void);
    string getEmployeeLeavesLeft(void);
    void printEmpSpecificHeader(void);
    void printEmpSpecificDetails(void);
    void printParticularEmployeeSummary(void);
};

#endif