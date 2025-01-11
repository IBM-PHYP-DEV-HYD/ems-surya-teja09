#include "Edll.H"
#include "XyzEmployeeManager.H"

int main()
{
    XyzEmployeeManager XyzEmpMgr;
    int sMainchoice = 0;
    
    while(1)
    {
        printmainmenu();
        cin >> sMainchoice;

        switch(sMainchoice)
        {
            case ADD_EMPLOYEE: 
            {
                printEmployeeOption();
                XyzEmpMgr.addEmployee();
                break;
            }
            case REMOVE_EMPLOYEE:
            {
                XyzEmpMgr.removeEmployee();
                break;
            }
            case PRINT_EMPLOYEE:
            {
                printEmployeedetailsMenu();
                XyzEmpMgr.printEmployeeDetails();
                break;
            }
            case OTHERS:
            {
                printEmployeeOtherdetailsMenu(); 
                //Needs to be implmented      
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