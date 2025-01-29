#ifndef XYZFULLTIMEEMPLOYEE_H
#define XYZFULLTIMEEMPLOYEE_H

#include "iostream"
#include <iomanip>
#include "XyzEmployeeImpl.H"
#include "EmsPrintRecord.H"

using namespace std;

class XyzFullTimeEmployee : public XyzEmployeeImpl
{
protected:
    int mLeavesAvailed;
    int mLevesLeft;

public:
    XyzFullTimeEmployee(string empNameParm, 
                        string empIdParm, 
                        int empStatusParm, 
                        int empTypeParm, 
                        int empGenderParm, 
                        string dobParm, 
                        string dojParm, 
                        string dolParm,
                        int leavesAvailedParm,
                        int leavesLeftParm);
    void setLeaveDetails(int leavesAvailedParm);
    Ems::ExternalAgency getExtAgency(void);
    InternDetails getInternSpecificDetails(void);
    string getEmployeeLeavesAvailed(void);
    string getEmployeeLeavesLeft(void);
    void printEmpSpecificHeader(void);
    void printEmpSpecificDetails(EmsPrintRecord &emsPrintParm);
    void printParticularEmployeeSummary(void);
    void addLeavestoFullTimeEmp(int leavesLeftParm);
};

#endif