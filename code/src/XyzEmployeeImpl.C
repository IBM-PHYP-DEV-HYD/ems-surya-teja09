#include "XyzEmployeeImpl.H"

/*

XyzEmployeeImpl::XyzEmployeeImpl(string EmpNameParm, string EmpIdParm, uint8_t EmpStatusParm, uint8_t EmpTypeParm, char EmpGenderParm, string DobParm, string DojParm):
          mEmployeeName(EmpNameParm),       
{

}*/

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

void XyzEmployeeImpl::setInternSpecificDetails(InternDetails InternDetailsParm)
{

}

void XyzEmployeeImpl::setExtAgency(int ExtAgencyParm)
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

uint8_t XyzEmployeeImpl::getEmployeeStatus(void)
{
    return mEmployeeStatus;
}

uint8_t XyzEmployeeImpl::getEmployeeType(void)
{
    return mEmployeeType;
}

void XyzEmployeeImpl::printEmpSpecificHeader(void)
{

}

void XyzEmployeeImpl::printEmpSpecifiDetails(void)
{

}

string XyzEmployeeImpl::getEmployeeLeavesAvaialed(void)
{
    return "NA";
}

string XyzEmployeeImpl::getEmployeeLeavesLeft(void)
{
    return "NA";
}

void XyzEmployeeImpl::printParticularEmployeeSummary(void)
{
    
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

    string sLeavesAvailed = getEmployeeLeavesAvaialed();
    string sLeavesLeft = getEmployeeLeavesLeft();
    cout << left
         << "| " << setw(18) << mEmployeeName
         << "| " << setw(10) << mEmployeeId
         << "| " << setw(17) << sEmpType
         << "| " << setw(15) << sEmpStatus
         << "| " << setw(12) << sGender
         << "| " << setw(20) << mDateOfBirth
         << "| " << setw(19) << mDateOfBirth
         << "| " << setw(19) << mDateOfBirth
         << "| " << setw(20) << sLeavesAvailed
         << "| " << setw(16) << sLeavesLeft
         << "| " << setw(16) << sAgency
         << "| " << setw(16) << sHiringCollege
         << "| " << setw(17) << sHiringBranch
         << "|" << endl;
    
    cout << setfill(' ') << setw(187) << " " << endl;    
}