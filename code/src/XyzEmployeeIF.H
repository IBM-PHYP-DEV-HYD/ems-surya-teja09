#ifndef XYZEMPLOYEEIF_H
#define XYZEMPLOYEEIF_H

#include "Utilis.H"

class XyzEmployeeIF
{
public:
    
    virtual void setLeaveDetails(int LeavesAvailedParm) = 0;
    virtual InternDetails getInternSpecificDetails(void) = 0;
    virtual ExternalAgency getExtAgency(void) = 0;
    virtual string getEmployeeId(void) = 0;
    virtual void setEmployeeBasicDetails(EmpDetails* EmpDetailsParm) = 0;
    virtual char getEmployeeGender(void) = 0;
    virtual uint8_t getEmployeeStatus(void) = 0;
    virtual uint8_t getEmployeeType(void) = 0;
    virtual string getEmployeeLeavesAvailed(void) = 0;
    virtual string getEmployeeLeavesLeft(void) = 0;
    virtual void addLeavestoFullTimeEmp(int LeavesLeftParm) = 0;
    virtual void printEmpSpecificHeader(void) = 0;
    virtual void printEmpSpecificDetails(void) = 0;
    virtual void printEmployeeSummary(void) = 0;
    virtual void printEmployeeSummaryHeader(void) = 0;
    virtual void printResignedEmployeeSummaryHeader(void) = 0;
    virtual void printParticularEmployeeSummary(void) = 0;
    virtual void prinResignedEmployeeSummary(void) = 0;
    virtual string getEmployeeName(void) = 0; 
    ~XyzEmployeeIF();
};

#endif

