#ifndef UTILIS_H
#define UTILIS_H

#include <iostream>
#include <random>
using namespace std;

namespace Ems
{
    enum EmployeeStatus
    {
        STATUS_UNDEFINED   = 0,
        ACTIVE             = 1,
        INACTIVE           = 2,
        RESIGNED           = 3
    };

    enum EmployeeType
    {
        TYPE_UNDEFINED     = 0,
        FULL_TIME          = 1,
        CONTRACT           = 2,
        INTERN             = 3
    };

    enum ExternalAgency
    {
        AVENGERS                   = 0,
        JUSTICE_LEAUGE             = 1,
        X_MEN                      = 2,
        AGENCY_UNDEFINED           = 3,
    };

    enum HiringFromColleges
    {
        IIT_DELHI                  = 0,
        IIT_MUMBAI                 = 1,
        IIT_HYDERABAD              = 2,
        IIT_KANPUR                 = 3,
        NIT_WARANGAL               = 4,
        NIT_TIRUCHI                = 5,
        IIIT_HYDERABAD             = 6,
        COLLEGE_UNDEFINED          = 7
    };

    enum HiringFromBranches
    {
        CSE               = 0,
        CSIT              = 1,
        ECE               = 2,
        UNDEFINED_BRANCH  = 3
    };

    enum EmployeeGender
    {
        MALE              = 1,
        FEMALE            = 2,
        NA                = 3
    };

    enum Misc
    {
        ADD_LEAVES         = 1,
        CONVERT_EMP        = 2,
        EMP_ID_SEARCH      = 3,
        EMP_NAME_SEARCH    = 4
    };

    enum MainMenu
    {
        ADD_EMPLOYEE       = 1,
        REMOVE_EMPLOYEE    = 2,
        PRINT_EMPLOYEE     = 3,
        OTHERS             = 4,
        EXIT               = -1
    };

    enum PrintMenu
    {
        TYPE             = 1,
        GENDER           = 2,
        STATUS           = 3,
        SUMMARY          = 4,
        RESIGNED_EMP     = 5
    };

    enum AddEmployee
    {
        RANDOM            = 1,
        USER_DEFINED      = 2
    };

    enum SpaceEnum {
        EmployeeName    = 18,
        EmployeeID      = 10,
        Gender          = 12,
        Date            = 20,
        Type            = 17,
        Status          = 15,
        LeavesAvailed   = 20,
        LeavesLeft      = 16,
        College         = 16,
        Branch          = 17,
        Agency          = 16,
        Total           = 222

    };
}

#pragma once
struct EmpDetails
{
    string mEmpName;
    string mDob;
    string mDoj;
    string mDol;
    int mGender;
    int mEmpStatus;
    string mEmpId;
    int mEmpType;
    int mLeavesAvailed;
    int mLeavesLeft;
    int mExtAgency;
    Ems::HiringFromColleges mHiringCollege;
    Ems::HiringFromBranches mHiringBranch;
};

#pragma once
struct InternDetails
{
    Ems::HiringFromColleges mHiringCollege;
    Ems::HiringFromBranches mHiringBranch; 
};

int getRandomNumber(int startNumParm, int endNumParm);
void getRandomizedEmpBasicDetails(EmpDetails* empDetailsParm);
int getRandomizedEmployeeAgency(void);
string getFullTimeEmpId(void);
void getRandomizedInternDetails(InternDetails *internDetailsParm);
void printmainmenu(void);
void printEmployeeOption(void);
void printemployeetypemenu(void);
void printEmployeedetailsMenu(void);
void printEmployeeOtherdetailsMenu(void);
void printDeletemenu(void);
string getAgencyFromEnum(int extAgencyParm);
string getHiringCollegeFromEnum(int hiringCollegeParm);
string getHiringBranchFromEnum(int hiringBranchParm);
string getEmpStatusFromEnum(int empStatusParm);
string getGenderFromEnum(int genderParm);
string getTypeFromEnum(int employeeTypeParm);
string getRandomizedDol(void);

#endif