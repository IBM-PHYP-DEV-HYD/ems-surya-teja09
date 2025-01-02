#include "Edll.H"
#include "XyzEmployeeManager.H"

int main()
{
    XyzEmployeeManager XyzEmpMgr;
    int sMainchoice = 0, sInput = 0;
    
    while(1)
    {
        printmainmenu();
        cin >> sMainchoice;

        switch(sMainchoice)
        {
            case 1: 
            {
                printEmployeeOption();
                cin >> sInput;
                XyzEmpMgr.addEmployee();
                break;
            }
            case 2:
            {
                XyzEmpMgr.removeEmployee();
                break;
            }
            case 3:
            {
                XyzEmpMgr.printEmployeeDetails();
                break;
            }
            case 4:
            {
                printEmployeeOtherdetailsMenu();       
                break; 
            }
            default: 
            {
                //Do Nothing
                break;
            }
        }
    }
    return 0;
}