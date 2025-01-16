#ifndef XYZCONTRACTEMPLOYEE_H
#define XYZCONTRACTEMPLOYEE_H

#include "Utilis.H"
#include "XyzEmployeeImpl.H"
#include "iomanip"

class XyzContractEmployee : public XyzEmployeeImpl
{
protected:
    int mExtAgency;
public:
    XyzContractEmployee(string EmpNameParm, string EmpIdParm, int EmpStatusParm, int EmpTypeParm, int EmpGenderParm, string DobParm, string DojParm);
    ExternalAgency getExtAgency(void);
    InternDetails getInternSpecificDetails(void);
    string getEmployeeLeavesAvailed(void);
    string getEmployeeLeavesLeft(void);
    void printEmpSpecificHeader(void);
    void printEmpSpecificDetails(void);
    void printParticularEmployeeSummary(void);
};

#endif