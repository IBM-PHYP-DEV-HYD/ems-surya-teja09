#include "EmsPrintRecord.H"

void EmsPrintRecord::printAll()
{
    cout << "| "<< left << setw(MAX_NAME_LEN) << setfill(' ') << mEmpName;
    cout << "| "<< left << setw(MAX_ID_LEN) << setfill(' ')   << mEmpid;
    cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   << mEmpType;
    cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   << mEmpStatus;
    cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   << mEmpGender;
    cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   << mEmpDob;
    cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   << mEmpDoj;
    cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   << mEmpDol;
    if(mPrintAllVar == true)
    {
        cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   << mEmpNola;
        cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   << mEmpNol;    
        cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   << mEmpAgency;
        cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   << mEmpCollege;
        cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   << mEmpBranch;
    }
    else
    {
        if(mEmpType == "FULL_TIME")
        {
            cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   << mEmpNola;
            cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')  << mEmpNol;
        }
        else if(mEmpType == "CONTRACT")
        {
            cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')  << mEmpAgency;
        }
        else if(mEmpType == "INTERN")
        {
            cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')  << mEmpCollege;
            cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')  << mEmpBranch;
        }
    }
    cout<<endl;
}
