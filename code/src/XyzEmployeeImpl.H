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
    uint8_t mEmployeeStatus;
    uint8_t mEmployeeType;
    char mGender;
    string mDateOfBirth;
    string mDateOfJoining;
    string mDateOfLeaving; 

public:
    //XyzEmployeeImpl(string EmpNameParm, string EmpIdParm, uint8_t EmpStatusParm, uint8_t EmpTypeParm, char EmpGenderParm, string DobParm, string DojParm);
    void setLeaveDetails(uint8_t LeavesAvailedParm); 
    void setInternSpecificDetails(InternDetails InternDetailsParm);
    void setExtAgency(ExternalAgency ExtAgencyParm);
    void getLeaveDetails(void);
    InternDetails getInternSpecificDetails(void);
    ExternalAgency getExtAgency(void);
    string getEmployeeId(void);
    void setEmployeeBasicDetails(EmpDetails* EmpDetailsParm);
    char getEmployeeGender(void);
    uint8_t getEmployeeStatus(void);
    uint8_t getEmployeeType(void);
};

#endif