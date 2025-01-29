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
    XyzInternEmployee(string empNameParm, 
                      string empIdParm, 
                      int empStatusParm, 
                      int empTypeParm, 
                      int empGenderParm, 
                      string dobParm, 
                      string dojParm, 
                      string dolParm,
                      Ems::HiringFromColleges hiringCollegeParm,
                      Ems::HiringFromBranches hiringBranchParm);
    InternDetails getInternSpecificDetails(void);
    Ems::ExternalAgency getExtAgency(void);
    string getEmployeeLeavesAvailed(void);
    string getEmployeeLeavesLeft(void);
    void printEmpSpecificHeader(void);
    void printEmpSpecificDetails(EmsPrintRecord &emsPrintParm);
    void printParticularEmployeeSummary(void);
};

#endif