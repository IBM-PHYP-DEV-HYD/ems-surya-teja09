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
    void setExtAgency(int ExtAgencyParm);
    void printEmpSpecificHeader(void);
    void printEmpSpecifiDetails(void);
};

#endif