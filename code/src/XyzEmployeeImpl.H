#ifndef XYZEMPLOYEEIMPL_H
#define XYZEMPLOYEEIMPL_H

#include "iostream"
#include "string.h"
#include "Utilis.H"
#include "XyzEmployeeIF.H"

using namespace std;

class XyzEmployeeImpl : public XyzEmployeeIF
{
public:
    string mEmployeeName;
    string mEmployeeId;
    int mEmployeeStatus;
    int mEmployeeType;
    int mGender;
    string mDateOfBirth;
    string mDateOfJoining;
    string mDateOfLeaving; 

public:
    //XyzEmployeeImpl(string EmpNameParm, string EmpIdParm, uint8_t EmpStatusParm, uint8_t EmpTypeParm, char EmpGenderParm, string DobParm, string DojParm);
    void setLeaveDetails(int LeavesAvailedParm); 
    void setInternSpecificDetails(InternDetails InternDetailsParm);
    void setExtAgency(int ExtAgencyParm);
    InternDetails getInternSpecificDetails(void);
    ExternalAgency getExtAgency(void);
    string getEmployeeId(void);
    void setEmployeeBasicDetails(EmpDetails* EmpDetailsParm);
    char getEmployeeGender(void);
    uint8_t getEmployeeStatus(void);
    uint8_t getEmployeeType(void);
    void printEmpSpecificHeader(void);
    void printEmpSpecifiDetails(void);
};

#endif