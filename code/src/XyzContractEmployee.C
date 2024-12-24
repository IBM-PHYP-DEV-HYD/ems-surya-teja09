#include "XyzContractEmployee.H"


void XyzContractEmployee::setExtAgency(ExternalAgency ExtAgencyParm)
{
    mExtAgency = ExtAgencyParm;
}

ExternalAgency XyzContractEmployee::getExtAgency(void)
{
    return mExtAgency;
}

void XyzContractEmployee::printEmpSpecificHeader(void)
{
    cout << setfill('-') << setw(160) << "-" << endl;
    cout << left
         << "| Employee Name     "
         << "| ID        "
         << "| Type             "
         << "| Status         "
         << "| Gender      "
         << "| Date of Birth       "
         << "| Date of Joining    "
         << "| Date of Leaving    "
         << "| Agency     |" << endl;
    cout << setfill('-') << setw(160) << "-" << endl;
    cout << setfill(' ') << setw(160) << " " << endl;
}


void XyzContractEmployee::printEmpSpecifiDetails(void)
{
    cout << left
         << "| " << setw(18) << mEmployeeName
         << "| " << setw(10) << mEmployeeId
         << "| " << setw(18) << mEmployeeType
         << "| " << setw(16) << mEmployeeStatus
         << "| " << setw(13) << mGender
         << "| " << setw(20) << mDateOfBirth
         << "| " << setw(19) << mDateOfBirth
         << "| " << setw(19) << mDateOfBirth
         << "| " << setw(11) << mExtAgency
         << "|" << endl;
         
    cout << setfill(' ') << setw(160) << " " << endl;
}