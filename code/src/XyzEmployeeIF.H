#ifndef XYZEMPLOYEEIF_H
#define XYZEMPLOYEEIF_H

#include "Utilis.H"

class XyzEmployeeIF
{
public:
    
    virtual void setLeaveDetails(uint8_t LeavesAvailedParm) = 0;
    virtual void setInternSpecificDetails(InternDetails InternDetailsParm) = 0;
    virtual void setExtAgency(ExternalAgency ExtAgencyParm) = 0;
    virtual void getLeaveDetails(void) = 0;
    virtual InternDetails getInternSpecificDetails(void) = 0;
    virtual ExternalAgency getExtAgency(void) = 0;
    virtual void getEmployeeBasicDetails(void) = 0;
    virtual void setEmployeeBasicDetails(EmpDetails* EmpDetailsPar) = 0;

    ~XyzEmployeeIF();
};

#endif

