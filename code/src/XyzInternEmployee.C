#include "XyzInternEmployee.H"

XyzInternEmployee::XyzInternEmployee(string EmpNameParm, string EmpIdParm, int EmpStatusParm, int EmpTypeParm, int EmpGenderParm, string DobParm, string DojParm):
                     XyzEmployeeImpl(EmpNameParm, EmpIdParm, EmpStatusParm, EmpTypeParm, EmpGenderParm, DobParm, DojParm) 
{
    InternDetails sInternDetails;
    getRandomizedInternDetails(&sInternDetails);
    mHiringCollege = sInternDetails.mHiringCollege;
    mHiringBranch = sInternDetails.mHiringBranch;   
}

InternDetails XyzInternEmployee::getInternSpecificDetails(void)
{
    InternDetails sInternDetailsParm;
    sInternDetailsParm.mHiringCollege = mHiringCollege;
    sInternDetailsParm.mHiringBranch = mHiringBranch;   

    return sInternDetailsParm;
}

ExternalAgency XyzInternEmployee::getExtAgency(void)
{
    return (ExternalAgency)AGENCY_UNDEFINED;
}

string XyzInternEmployee::getEmployeeLeavesAvaialed(void)
{
    return "NA";
}

string XyzInternEmployee::getEmployeeLeavesLeft(void)
{
    return "NA";
}

void XyzInternEmployee::printParticularEmployeeSummary(void)
{
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

    XyzEmployeeImpl::printParticularEmployeeSummary();
    cout <<  " Hiring College  : " << sHiringCollege << endl;  
    cout <<  " Hiring Branch   : " << sHiringBranch << endl;     
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

    XyzEmployeeImpl::printEmpSpecifiDetails();
    cout << "| " << setw(19) << sHiringBranch
        << "| " << setw(19) << sHiringCollege
        << "|" << endl;

    cout << setfill(' ') << setw(189) << " " << endl;
}

