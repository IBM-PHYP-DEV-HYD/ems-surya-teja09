#include "XyzInternEmployee.H"

void XyzInternEmployee::setInternSpecificDetails(InternDetails InternDetailsParm)
{
    mHiringCollege = InternDetailsParm.mHiringCollege;
    mHiringBranch = InternDetailsParm.mHiringBranch;
}

InternDetails XyzInternEmployee::getInternSpecificDetails(void)
{
    InternDetails sInternDetailsParm;
    sInternDetailsParm.mHiringCollege = mHiringCollege;
    sInternDetailsParm.mHiringBranch = mHiringBranch;   

    return sInternDetailsParm;
}


void XyzInternEmployee::printEmpSpecificHeader(void)
{
    cout << setfill('-') << setw(189) << "-" << endl;
    cout << left
         << "| Employee Name     "
         << "| ID        "
         << "| Type             "
         << "| Status         "
         << "| Gender      "
         << "| Date of Birth       "
         << "| Date of Joining    "
         << "| Date of Leaving    "
         << "| Hiring Branch      "
         << "| Hiring College     |" << endl;
    cout << setfill('-') << setw(189) << "-" << endl;
    cout << setfill(' ') << setw(189) << " " << endl;
}


void XyzInternEmployee::printEmpSpecifiDetails(void)
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
    if(mGender == 0)
    {
        sGender = "MALE";
    }
    else
    {
        sGender = "FEMALE";
    }

    string sHiringCollege;
    switch(mHiringCollege)
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
            break;
        }
    }

    string sHiringBranch;
    switch(mHiringBranch)
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
            break;
        }
    }

    cout << left
         << "| " << setw(18) << mEmployeeName
         << "| " << setw(10) << mEmployeeId
         << "| " << setw(17) << "INTERN"
         << "| " << setw(16) << sEmpStatus
         << "| " << setw(12) << sGender
         << "| " << setw(20) << mDateOfBirth
         << "| " << setw(19) << mDateOfBirth
         << "| " << setw(19) << mDateOfBirth
         << "| " << setw(19) << sHiringBranch
         << "| " << setw(19) << sHiringCollege
         << "|" << endl;

    cout << setfill(' ') << setw(189) << " " << endl;
}

