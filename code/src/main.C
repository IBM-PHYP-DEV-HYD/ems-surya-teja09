#include "Edll.H"
#include "XyzEmployeeManager.H"

int Loopcount = 0;

int main()
{
    XyzEmployeeManager XyzEmpMgr;
    int sMainchoice = 0, sInput = 0;
    
    while(1)
    {
        #if 0
        XyzEmpMgr.addEmployee();
        ++Loopcount;
        
        if(Loopcount % 5 == 0)
            XyzEmpMgr.printEmployeeSummary();
        

        
        if(Loopcount % 10 == 0)
        {
            cout << "Printing male employees " << endl;
            XyzEmpMgr.printEmployeesByGender(2);
        }
        #endif
        printmainmenu();
        cin >> sMainchoice;

        switch(sMainchoice)
        {
            case 1: 
            {
                printEmployeeOption();
                cin >> sInput;
                XyzEmpMgr.addEmployee();
            }
            break;

            case 2:
            {
                printDeletemenu();
                cin>>sInput;
                XyzEmpMgr.removeEmployee("Test");
            }
            break;

            case 3:
            {
                printEmployeedetailsMenu();
                cin>>sInput;
                XyzEmpMgr.printEmployeeSummary();
                
            }
            break;

            case 4:
            {
                printEmployeeOtherdetailsMenu();
                cin>>sInput;
                //XyzEmpMgr.otherdetails(sInput);
                
            }
            break;

            default: 
            {

            }
            break;
        }
    }

    return 0;
}