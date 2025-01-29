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
    XyzContractEmployee(string empNameParm, 
                        string empIdParm, 
                        int empStatusParm, 
                        int empTypeParm, 
                        int empGenderParm, 
                        string dobParm, 
                        string dojParm, 
                        string dolParm,
                        int extAgencyParm);
    Ems::ExternalAgency getExtAgency(void);
    InternDetails getInternSpecificDetails(void);
    string getEmployeeLeavesAvailed(void);
    string getEmployeeLeavesLeft(void);
    void printEmpSpecificHeader(void);
    void printEmpSpecificDetails(EmsPrintRecord &emsPrintParm);
    void printParticularEmployeeSummary(void);
};

#endif