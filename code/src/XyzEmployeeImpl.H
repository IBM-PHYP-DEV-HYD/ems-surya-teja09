#ifndef XYZEMPLOYEEIMPL_H
#define XYZEMPLOYEEIMPL_H

#include "iostream"
#include "string.h"
#include "Utilis.H"
#include "iomanip"
#include "XyzEmployeeIF.H"

using namespace std;

class XyzEmployeeImpl : public XyzEmployeeIF
{
protected:
    string mEmployeeName;
    string mEmployeeId;
    int mEmployeeStatus;
    int mEmployeeType;
    int mGender;
    string mDateOfBirth;
    string mDateOfJoining;
    string mDateOfLeaving; 

public:
    XyzEmployeeImpl(string empNameParm, string empIdParm, int empStatusParm, int empTypeParm, int empGenderParm, string dobParm, string dojParm, string dolParm);
    void setLeaveDetails(int leavesAvailedParm); 
    InternDetails getInternSpecificDetails(void);
    void setEmployeeStatus(int employeeStatusParm);
    Ems::ExternalAgency getExtAgency(void);
    string getEmployeeId(void);
    void setEmployeeBasicDetails(EmpDetails* empDetailsParm);
    char getEmployeeGender(void);
    int getEmployeeStatus(void);
    int getEmployeeType(void);
    void printEmpSpecificHeader(void);
    void fillEmpSpecificDetails(EmsPrintRecord &emsPrintParm);
    void fillEmployeeSummary(EmsPrintRecord &emsPrintParm);
    string getEmployeeLeavesAvailed(void);
    string getEmployeeLeavesLeft(void);
    void printEmployeeSummaryHeader(void);
    void printParticularEmployeeSummary(void);
    void addLeavestoFullTimeEmp(int leavesLeftParm);
    void printResignedEmployeeSummaryHeader(void);
    void prinResignedEmployeeSummary(EmsPrintRecord &emsPrintParm);
    string getEmployeeName(void);
    string getDateOfBirth();
    int getGender();
    string getDateOfJoining();
    string getDateOfLeaving();
};

#endif