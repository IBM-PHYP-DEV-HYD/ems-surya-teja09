#include "EmsPrintRecord.H"

void EmsPrintRecord::printAll()
{
    cout << "| "<< left << setw(MAX_NAME_LEN) << setfill(' ') << mEmpName;
    cout << "| "<< left << setw(MAX_ID_LEN+7) << setfill(' ') << mEmpid;
    cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   << getTypeFromEnum(mEmpType);
    cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   << getEmpStatusFromEnum(mEmpStatus);
    cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   << getGenderFromEnum(mEmpGender);
    cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   << mEmpDob;
    cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   << mEmpDoj;
    cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   << mEmpDol;
    if(mPrintAllVar == true)
    {
        cout << "| "<< left << setw(MAX_ID_LEN+7) << setfill(' ') << mEmpNol;
        cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   << getAgencyFromEnum(mEmpAgency);
        cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   << getHiringCollegeFromEnum(mEmpCollege);
        cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   << getHiringBranchFromEnum(mEmpBranch);
    }
    else
    {
        if(mEmpType == FULL_TIME)
        {
            cout << "| "<< left << setw(MAX_ID_LEN+7) << setfill(' ') << mEmpNol;
        }
        else if(mEmpType == CONTRACT)
        {
            cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   << getAgencyFromEnum(mEmpAgency);
        }
        else if(mEmpType == INTERN)
        {
            cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   << getHiringCollegeFromEnum(mEmpCollege);
            cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   << getHiringBranchFromEnum(mEmpBranch);
        }
    }
    cout<<endl;
}