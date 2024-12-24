#ifndef XYZCONTRACTEMPLOYEE_H
#define XYZCONTRACTEMPLOYEE_H

#include "Utilis.H"
#include "XyzEmployeeImpl.H"
#include "iomanip"

class XyzContractEmployee : public XyzEmployeeImpl
{
protected:
    ExternalAgency mExtAgency;
public:
    void setExtAgency(ExternalAgency ExtAgencyParm);
    ExternalAgency getExtAgency(void);
    void printEmpSpecificHeader(void);
    void printEmpSpecifiDetails(void);
};

#endif