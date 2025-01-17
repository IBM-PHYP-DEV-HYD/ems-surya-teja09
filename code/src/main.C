#include "Edll.H"
#include "XyzEmployeeManager.H"

int main()
{
    XyzEmployeeManager sXyzEmpMgr;
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
                int sInput = 0;

                while(!(cin >> sInput))
                {
                    cout << "Enter valid choice: " << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');        
                }  
                sXyzEmpMgr.addEmployee(sInput);
                break;
            }
            case REMOVE_EMPLOYEE:
            {
                std::string sEmpId;
                cout << "Enter empid : " << endl;
                std::cin >> sEmpId;
                sXyzEmpMgr.removeEmployee(sEmpId);
                break;
            }
            case PRINT_EMPLOYEE:
            {
                printEmployeedetailsMenu();
                int sInput = 0;

                while(!(cin >> sInput))
                {
                    cout << "Enter valid choice: " << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');        
                }  
                sXyzEmpMgr.printEmployeeDetails(sInput);
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