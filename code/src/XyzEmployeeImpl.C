#include "XyzEmployeeImpl.H"


XyzEmployeeImpl::XyzEmployeeImpl(string EmpNameParm, string EmpIdParm, int EmpStatusParm, int EmpTypeParm, int EmpGenderParm, string DobParm, string DojParm): 
    mEmployeeName(EmpNameParm), mEmployeeId(EmpIdParm), mEmployeeStatus(EmpStatusParm), mEmployeeType(EmpTypeParm), mGender(EmpGenderParm), mDateOfBirth(DobParm), mDateOfJoining(DojParm)         
{

}

void XyzEmployeeImpl::setEmployeeBasicDetails(EmpDetails* EmpDetailsParm)
{
    mEmployeeName       = EmpDetailsParm->mEmpName;
    mDateOfBirth        = EmpDetailsParm->mDob;
    mDateOfJoining      = EmpDetailsParm->mDoj;
    mGender             = EmpDetailsParm->mGender;
    mEmployeeStatus     = EmpDetailsParm->mEmpStatus;
    mEmployeeType       = EmpDetailsParm->mEmpType; 
    mEmployeeId         = EmpDetailsParm->mEmpId;
}

void XyzEmployeeImpl::setLeaveDetails(int LeavesAvailedParm)
{
    
}

InternDetails XyzEmployeeImpl::getInternSpecificDetails(void)
{
    InternDetails sDetails;
    return sDetails;
}

ExternalAgency XyzEmployeeImpl::getExtAgency(void)
{
    ExternalAgency sAgency = AGENCY_UNDEFINED;
    return sAgency;
}

string XyzEmployeeImpl::getEmployeeId(void)
{
    return mEmployeeId;
}

char XyzEmployeeImpl::getEmployeeGender(void)
{
    return mGender;
}

void XyzEmployeeImpl::setEmployeeStatus(int EmployeeStatusParm)
{
    mEmployeeStatus = EmployeeStatusParm;
}

uint8_t XyzEmployeeImpl::getEmployeeStatus(void)
{
    return mEmployeeStatus;
}

string XyzEmployeeImpl::getEmployeeName(void)
{
    return mEmployeeName;
}

uint8_t XyzEmployeeImpl::getEmployeeType(void)
{
    return mEmployeeType;
}

void XyzEmployeeImpl::printEmpSpecificHeader(void)
{

}

void XyzEmployeeImpl::printEmpSpecificDetails(void)
{
    string sEmpStatus;
    switch(mEmployeeStatus)
    {
        case ACTIVE:
        {
            sEmpStatus = "ACTIVE";
            break;
        }
        case INACTIVE:
        {
            sEmpStatus = "INACTIVE";
            break;
        }
        case RESIGNED:
        {
            sEmpStatus = "RESIGNED";
            break;
        }
        default:
        {
            break;
        }
    }

    string sGender;
    if(mGender == 1)
    {
        sGender = "MALE";
    }
    else
    {
        sGender = "FEMALE";
    }    

    string sEmpType;
    switch(mEmployeeType)
    {
        case FULL_TIME:
        {
            sEmpType = "FULL_TIME";
            break;
        }
        case CONTRACT:
        {
            sEmpType = "CONTRACT";
            break;
        }
        case INTERN:
        {
            sEmpType = "INTERN";
            break;
        }
    }

    cout << left
         << "| " << setw(SpaceEnum::EmployeeName) << mEmployeeName
         << "| " << setw(SpaceEnum::EmployeeID) << mEmployeeId
         << "| " << setw(SpaceEnum::Type) << sEmpType
         << "| " << setw(SpaceEnum::Status) << sEmpStatus
         << "| " << setw(SpaceEnum::Gender) << sGender
         << "| " << setw(SpaceEnum::Date) << mDateOfBirth
         << "| " << setw(SpaceEnum::Date) << mDateOfBirth
         << "| " << setw(SpaceEnum::Date) << mDateOfBirth;
}

string XyzEmployeeImpl::getEmployeeLeavesAvailed(void)
{
    return "NA";
}

string XyzEmployeeImpl::getEmployeeLeavesLeft(void)
{
    return "NA";
}

void XyzEmployeeImpl::printParticularEmployeeSummary(void)
{
    cout << "Employee Details :" << endl;
    string sEmpStatus;
    switch(mEmployeeStatus)
    {
        case ACTIVE:
        {
            sEmpStatus = "ACTIVE";
            break;
        }
        case INACTIVE:
        {
            sEmpStatus = "INACTIVE";
            break;
        }
        case RESIGNED:
        {
            sEmpStatus = "RESIGNED";
            break;
        }
        default:
        {
            break;
        }
    }

    string sGender;
    if(mGender == 1)
    {
        sGender = "MALE";
    }
    else
    {
        sGender = "FEMALE";
    }    

    string sEmpType;
    switch(mEmployeeType)
    {
        case FULL_TIME:
        {
            sEmpType = "FULL_TIME";
            break;
        }
        case CONTRACT:
        {
            sEmpType = "CONTRACT";
            break;
        }
        case INTERN:
        {
            sEmpType = "INTERN";
            break;
        }
    }

    cout <<  " Employee Name   : " << mEmployeeName << endl;
    cout <<  " Employee Id     : " << mEmployeeId << endl;
    cout <<  " Employee Type   : " << sEmpType << endl;
    cout <<  " Employee Status : " << sEmpStatus << endl;
    cout <<  " Employee Gender : " << sGender << endl;
    cout <<  " Date of Birth   : " << mDateOfBirth << endl;
    cout <<  " Date of Joining : " << mDateOfBirth << endl;   

}

void XyzEmployeeImpl::addLeavestoFullTimeEmp(int LeavesLeftParm)
{

}

void XyzEmployeeImpl::printResignedEmployeeSummaryHeader(void)
{
    cout << setfill('-') << setw(242) << "-" << endl;
    cout << left
         << "| Employee Name     "
         << "| ID        "
         << "| Type             "
         << "| Status         "
         << "| Gender      "
         << "| Date of Birth       "
         << "| Date of Joining    "
         << "| Date of Leaving    |" << endl;
    cout << setfill('-') << setw(242) << "-" << endl;
    cout << setfill(' ') << setw(242) << " " << endl;          
}

void XyzEmployeeImpl::prinResignedEmployeeSummary(void)
{
    string sGender;
    if(mGender == 1)
    {
        sGender = "MALE";
    }
    else
    {
        sGender = "FEMALE";
    }

    cout << left
         << "| " << setw(18) << mEmployeeName
         << "| " << setw(10) << mEmployeeId
         << "| " << setw(15) << "RESIGNED"
         << "| " << setw(12) << sGender
         << "| " << setw(20) << mDateOfBirth 
         << "| " << setw(19) << mDateOfBirth
         << "| " << setw(19) << mDateOfBirth
         << "|" << endl;

    cout << setfill(' ') << setw(187) << " " << endl;
}

void XyzEmployeeImpl::printEmployeeSummaryHeader(void)
{
    cout << setfill('-') << setw(242) << "-" << endl;
    cout << left
         << "| Employee Name     "
         << "| ID        "
         << "| Type             "
         << "| Status         "
         << "| Gender      "
         << "| Date of Birth       "
         << "| Date of Joining    "
         << "| Date of Leaving    "
         << "| Leaves Availed      "
         << "| Leaves Left     " 
         << "| Agency          " 
         << "| Hiring College  "
         << "| Hiring Branch    |"<< endl;
    cout << setfill('-') << setw(242) << "-" << endl;
    cout << setfill(' ') << setw(242) << " " << endl;   
}


void XyzEmployeeImpl::printEmployeeSummary(void)
{
    string sEmpStatus;
    switch(mEmployeeStatus)
    {
        case ACTIVE:
        {
            sEmpStatus = "ACTIVE";
            break;
        }
        case INACTIVE:
        {
            sEmpStatus = "INACTIVE";
            break;
        }
        case RESIGNED:
        {
            sEmpStatus = "RESIGNED";
            break;
        }
        default:
        {
            break;
        }
    }

    string sGender;
    if(mGender == 1)
    {
        sGender = "MALE";
    }
    else
    {
        sGender = "FEMALE";
    }


    ExternalAgency mExtAgency = getExtAgency();
    string sAgency;
    switch(mExtAgency)
    {
        case AVENGERS:
        {
            sAgency = "AVENGERS";
            break;
        }
        case JUSTICE_LEAUGE:
        {
            sAgency = "JUSTICE_LEAUGE";
            break;
        }
        case X_MEN:
        {
            sAgency = "X_MEN";
            break;
        }
        default:
        {
            sAgency = "NA";
            break;
        }
    }       

    InternDetails sInternDetails  = getInternSpecificDetails();
    string sHiringCollege;
    switch(sInternDetails.mHiringCollege)
    {
        case IIT_DELHI:
        {
            sHiringCollege = "IIT_DELHI";
            break;
        }
        case IIT_MUMBAI:
        {
            sHiringCollege = "IIT_MUMBAI";
            break;
        }
        case IIT_HYDERABAD:
        {
            sHiringCollege = "IIT_HYDERABAD";
            break;
        }
        case IIT_KANPUR:
        {
            sHiringCollege = "IIT_KANPUR";
            break;
        }
        case NIT_WARANGAL:
        {
            sHiringCollege = "NIT_WARANGAL";
            break;
        }
        case NIT_TIRUCHI:
        {
            sHiringCollege = "NIT_TIRUCHI";
            break;
        }
       case IIIT_HYDERABAD:
        {
            sHiringCollege = "IIIT_HYDERABAD";
            break;
        }     
        default:
        {
            sHiringCollege = "NA";
            break;
        }
    }


    string sHiringBranch;
    switch(sInternDetails.mHiringBranch)
    {
        case CSE:
        {
            sHiringBranch = "CSE";
            break;
        }
        case CSIT:
        {
            sHiringBranch = "CSIT";
            break;
        }
        case ECE:
        {
            sHiringBranch = "ECE";
            break;
        }
        default:
        {
            sHiringBranch = "NA";
            break;
        }
    }

    string sEmpType;
    switch(mEmployeeType)
    {
        case FULL_TIME:
        {
            sEmpType = "FULL_TIME";
            break;
        }
        case CONTRACT:
        {
            sEmpType = "CONTRACT";
            break;
        }
        case INTERN:
        {
            sEmpType = "INTERN";
            break;
        }
    }

    string sLeavesAvailed = getEmployeeLeavesAvailed();
    string sLeavesLeft = getEmployeeLeavesLeft();
    cout << left
         << "| " << setw(SpaceEnum::EmployeeName) << mEmployeeName
         << "| " << setw(SpaceEnum::EmployeeID) << mEmployeeId
         << "| " << setw(SpaceEnum::Type) << sEmpType
         << "| " << setw(SpaceEnum::Status) << sEmpStatus
         << "| " << setw(SpaceEnum::Gender) << sGender
         << "| " << setw(SpaceEnum::Date) << mDateOfBirth
         << "| " << setw(SpaceEnum::Date) << mDateOfBirth
         << "| " << setw(SpaceEnum::Date) << mDateOfBirth
         << "| " << setw(SpaceEnum::LeavesAvailed) << sLeavesAvailed
         << "| " << setw(SpaceEnum::LeavesAvailed) << sLeavesLeft
         << "| " << setw(SpaceEnum::Agency) << sAgency
         << "| " << setw(SpaceEnum::College) << sHiringCollege
         << "| " << setw(SpaceEnum::Branch) << sHiringBranch
         << "|" << endl;
    
    cout << setfill(' ') << setw(187) << " " << endl;    
}