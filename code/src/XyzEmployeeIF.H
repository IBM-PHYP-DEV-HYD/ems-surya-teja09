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
    virtual string getEmployeeId(void) = 0;
    virtual void setEmployeeBasicDetails(EmpDetails* EmpDetailsParm) = 0;
    virtual string getEmployeeId(void) = 0;
    virtual char getEmployeeGender(void) = 0;
    virtual uint8_t getEmployeeStatus(void) = 0;
    virtual uint8_t getEmployeeType(void) = 0;

    ~XyzEmployeeIF();
};

#endif

