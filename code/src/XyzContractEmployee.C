#include "XyzContractEmployee.H"

XyzContractEmployee::XyzContractEmployee(string EmpNameParm, string EmpIdParm, int EmpStatusParm, int EmpTypeParm, int EmpGenderParm, string DobParm, string DojParm):
                     XyzEmployeeImpl(EmpNameParm, EmpIdParm, EmpStatusParm, EmpTypeParm, EmpGenderParm, DobParm, DojParm) 
{
    mExtAgency = getRandomizedEmployeeAgency();   
}

ExternalAgency XyzContractEmployee::getExtAgency(void)
{
    return (ExternalAgency)mExtAgency;
}

InternDetails XyzContractEmployee::getInternSpecificDetails(void)
{
    InternDetails sInternDetailsParm;
    sInternDetailsParm.mHiringCollege = COLLEGE_UNDEFINED;
    sInternDetailsParm.mHiringBranch = UNDEFINED_BRANCH;   

    return sInternDetailsParm;
}

string XyzContractEmployee::getEmployeeLeavesAvailed(void)
{
    return "NA";
}

string XyzContractEmployee::getEmployeeLeavesLeft(void)
{
    return "NA";
}

void XyzContractEmployee::printParticularEmployeeSummary(void)
{
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
            break;
        }
    }

    XyzEmployeeImpl::printParticularEmployeeSummary();
    cout <<  " External Agency : " << sAgency << endl;
}

void XyzContractEmployee::printEmpSpecificHeader(void)
{
    cout << setfill('-') << setw(165) << "-" << endl;
    cout << left
         << "| Employee Name     "
         << "| ID        "
         << "| Type             "
         << "| Status         "
         << "| Gender      "
         << "| Date of Birth       "
         << "| Date of Joining    "
         << "| Date of Leaving    "
         << "| Agency          |" << endl;
    cout << setfill('-') << setw(165) << "-" << endl;
    cout << setfill(' ') << setw(165) << " " << endl;
}


void XyzContractEmployee::printEmpSpecificDetails(void)
{
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
            break;
        }
    }    

    XyzEmployeeImpl::printEmpSpecificDetails();
    cout << "| " << setw(SpaceEnum::Agency) << sAgency
         << "|" << endl;

    cout << setfill(' ') << setw(160) << " " << endl;
}