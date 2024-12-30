#include "Edll.H"
#include "XyzEmployeeManager.H"

int Loopcount = 0;

int main()
{
    XyzEmployeeManager XyzEmpMgr;
    
    while(1)
    {
        XyzEmpMgr.addEmployee();
        ++Loopcount;
        
        if(Loopcount % 5 == 0)
            XyzEmpMgr.printEmployeeSummary();
        

        
        if(Loopcount % 10 == 0)
        {
            cout << "Printing male employees " << endl;
            XyzEmpMgr.printEmployeesByGender(1);
        }
           
    }

    return 0;
}