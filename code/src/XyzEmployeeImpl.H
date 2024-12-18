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

    //static uint64_t mEmployeeIdSeriesNum;

public:
    
    void setLeaveDetails(uint8_t LeavesAvailedParm); 
    void setInternSpecificDetails(InternDetails InternDetailsParm);
    void setExtAgency(ExternalAgency ExtAgencyParm);
    void getLeaveDetails(void);
    InternDetails getInternSpecificDetails(void);
    ExternalAgency getExtAgency(void);
    void getEmployeeBasicDetails(void);
    void setEmployeeBasicDetails(EmpDetails* EmpDetailsPar);
};

#endif