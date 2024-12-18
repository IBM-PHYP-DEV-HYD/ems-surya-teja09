#include "XyzFullTimeEmployee.H"

void XyzFullTimeEmployee::setLeaveDetails(uint8_t LeavesAvailedParm)
{
    uint8_t sLeavesAvailed = 0;

    cout << "Enter number of leaves availed between 0 - 22" << endl;
    while(!(cin >> sLeavesAvailed))
    {
        cout << "Enter valid choice: " << endl;
        cin.clear();
        cin.ignore(1000, '\n');        
    }

    mLeavesAvailed = sLeavesAvailed;
}



void XyzFullTimeEmployee::getLeaveDetails(void)
{

}
