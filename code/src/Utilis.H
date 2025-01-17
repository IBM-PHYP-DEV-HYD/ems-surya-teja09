#ifndef UTILIS_H
#define UTILIS_H

#include <iostream>
#include <random>
using namespace std;

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

#pragma once
struct InternDetails
{
    HiringFromColleges mHiringCollege;
    HiringFromBranches mHiringBranch; 
};

#pragma once
struct EmpDetails
{
    string mEmpName;
    string mDob;
    string mDoj;
    int mGender;
    uint8_t mEmpStatus;
    string mEmpId;
    int mEmpType;
};

enum MAIN_MENU
{
    ADD_EMPLOYEE       = 1,
    REMOVE_EMPLOYEE    = 2,
    PRINT_EMPLOYEE     = 3,
    OTHERS             = 4,
    EXIT               = -1

};

enum ADD_EMPLOYEE
{
    RANDOM            = 1,
    USER_DEFINED      = 2
};

enum PRINT_OPTIONS
{
    TYPE             = 1,
    GENDER           = 2,
    STATUS           = 3,
    SUMMARY          = 4
};

namespace SpaceEnum {
    constexpr int EmployeeName = 18;
    constexpr int EmployeeID = 10;
    constexpr int Gender = 12;
    constexpr int Date = 20;
    constexpr int Type = 17;
    constexpr int Status = 15;
    constexpr int LeavesAvailed = 20;
    constexpr int LeavesLeft = 16;
    constexpr int College = 16;
    constexpr int Branch = 17;
    constexpr int Agency = 16;
    constexpr int Total = 222;

}

int getRandomNumber(int startNumParm, int endNumParm);
void getRandomizedEmpBasicDetails(EmpDetails* EmpDetailsParm, uint32_t mEmpIdSeriesNumParm);
int getRandomizedEmployeeAgency(void);
void getRandomizedInternDetails(InternDetails *InternDetailsParm);
void printmainmenu(void);
void printEmployeeOption(void);
void printemployeetypemenu(void);
void printEmployeedetailsMenu(void);
void printEmployeeOtherdetailsMenu(void);
void printDeletemenu(void);

#endif