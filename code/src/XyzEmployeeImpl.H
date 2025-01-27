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
    XyzEmployeeImpl(string EmpNameParm, string EmpIdParm, int EmpStatusParm, int EmpTypeParm, int EmpGenderParm, string DobParm, string DojParm);
    void setLeaveDetails(int LeavesAvailedParm); 
    InternDetails getInternSpecificDetails(void);
    void setEmployeeStatus(int EmployeeStatusParm);
    Ems::ExternalAgency getExtAgency(void);
    string getEmployeeId(void);
    void setEmployeeBasicDetails(EmpDetails* EmpDetailsParm);
    char getEmployeeGender(void);
    uint8_t getEmployeeStatus(void);
    uint8_t getEmployeeType(void);
    void printEmpSpecificHeader(void);
    void printEmpSpecificDetails(void);
    void printEmployeeSummary(void);
    string getEmployeeLeavesAvailed(void);
    string getEmployeeLeavesLeft(void);
    void printEmployeeSummaryHeader(void);
    void printParticularEmployeeSummary(void);
    void addLeavestoFullTimeEmp(int LeavesLeftParm);
    void printResignedEmployeeSummaryHeader(void);
    void prinResignedEmployeeSummary(void);
    string getEmployeeName(void);
    string getDateOfBirth();
    int getGender();
    string getDateOfJoining();
    string getDateOfLeaving();
};

#endif