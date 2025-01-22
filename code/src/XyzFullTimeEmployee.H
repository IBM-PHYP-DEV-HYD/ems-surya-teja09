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
    XyzFullTimeEmployee(string EmpNameParm, string EmpIdParm, int EmpStatusParm, int EmpTypeParm, int EmpGenderParm, string DobParm, string DojParm);
    void setLeaveDetails(int LeavesAvailedParm);
    ExternalAgency getExtAgency(void);
    InternDetails getInternSpecificDetails(void);
    string getEmployeeLeavesAvailed(void);
    string getEmployeeLeavesLeft(void);
    void printEmpSpecificHeader(void);
    void printEmpSpecificDetails(void);
    void printParticularEmployeeSummary(void);
    void addLeavestoFullTimeEmp(int LeavesLeftParm);
};

#endif