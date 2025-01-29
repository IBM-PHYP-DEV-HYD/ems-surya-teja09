#ifndef XYZEMPLOYEEIF_H
#define XYZEMPLOYEEIF_H

#include "Utilis.H"
#include "EmsPrintRecord.H"

class XyzEmployeeIF
{
public:
    
    EmsPrintRecord mEmsPrint;

    virtual void setLeaveDetails(int leavesAvailedParm) = 0;
    virtual InternDetails getInternSpecificDetails(void) = 0;
    virtual Ems::ExternalAgency getExtAgency(void) = 0;
    virtual string getEmployeeId(void) = 0;
    virtual void setEmployeeBasicDetails(EmpDetails* empDetailsParm) = 0;
    virtual char getEmployeeGender(void) = 0;
    virtual int getEmployeeStatus(void) = 0;
    virtual int getEmployeeType(void) = 0;
    virtual string getEmployeeLeavesAvailed(void) = 0;
    virtual string getEmployeeLeavesLeft(void) = 0;
    virtual void addLeavestoFullTimeEmp(int leavesLeftParm) = 0;
    virtual void printEmpSpecificHeader(void) = 0;
    virtual void printEmpSpecificDetails(EmsPrintRecord &emsPrintParm) = 0;
    virtual void printEmployeeSummary(EmsPrintRecord &emsPrintParm) = 0;
    virtual void printEmployeeSummaryHeader(void) = 0;
    virtual void printResignedEmployeeSummaryHeader(void) = 0;
    virtual void printParticularEmployeeSummary(void) = 0;
    virtual void prinResignedEmployeeSummary(void) = 0;
    virtual string getEmployeeName(void) = 0; 
    virtual void setEmployeeStatus(int employeeStatusParm) = 0;
    virtual string getDateOfBirth() = 0;
    virtual int getGender() = 0;
    virtual string getDateOfJoining() = 0;
    virtual string getDateOfLeaving() = 0;
    ~XyzEmployeeIF();
};

#endif

