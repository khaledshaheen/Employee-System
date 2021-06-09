//Khaled Shaheen
//Project Done by: Khaled Shaheen
#include<iostream>
#include<fstream>
using namespace std;
#include<string>
//counter
int counter1=1000;
//employee class
class Employee
{
    //private class variables
    private:
        int employeeID; 
        string firstName;
        string lastName; 
        float workingHours; 
        float costPerHour;
        float deduction; 
        double annualSalary;
    //public class variables
    public:
    //constructor 
        Employee()
        {
            //increment counter
            counter1++;
            //so it will increment the Employee ID
            employeeID=counter1;
        }
        //getter function for employee ID
        int get_employeeID()
        {
            return employeeID;
        } 
        //getter function for first name
        string get_firstName()
        {
            return firstName;
        }
        //getter function for last name
        string get_lastName()
        {
            return lastName;
        }
        //getter function for working hours
        float get_workingHours()
        {
            return workingHours;
        }
        //getter function for cost per hour
        float get_costPerHour()
        {
            return costPerHour;
        }
        //getter function for deduction
        float get_deduction()
        {
            return deduction;
        }
        //getter function for annual salary
        double get_annualSalary()
        {
            //calculate annual salary
            annualSalary=(workingHours*costPerHour*52)-(52*deduction);
            //validiate salary
            //if Salary is less than 0 or equal return 0
            if(annualSalary<=0)
            {
                return 0.0;
            }
            //else return the salary
            else{
                return annualSalary;
            }
            
        }
        //setter function for the first name;
        void set_firstName(string name)
        {
            firstName=name;
        }
        //setter function for the last name;
        void set_lastName(string name2)
        {
            lastName=name2;
        }
        //setter function for working hours ;
        void set_workingHours()
        {
            float temphours;
            //ask for hours per week
            cout<<"How many hours a week is his/her work?";
            cin>>temphours;
            //validate hours per week
            //hours per week should be between 60 and 1
            while( temphours<0 ||temphours<1 || temphours>60)
            {
                cout<<"Please enter a number between 1-60"<<endl;
                cout<<"How many hours a week is his/her work?";
                cin>>temphours;
                
            }
            //set after validation
            workingHours=temphours;
            
        }
        //setter function for the cost per hour;
        void set_costPerHour()
        {
            float tempCost;
            //get wage per hour
            cout<<"How much per hour is his/her wage? ";
            cin>>tempCost;
            //validate cost per hour
            //cost per hour should be postive
            while(tempCost<0)
            {   
                cout<<"Please Enter a postive wage!"<<endl;
                cout<<"How much per hour is his/her wage? ";
                cin>>tempCost;
                
            }
            //set after validation
            costPerHour=tempCost;
        }
        //setter function for the deduction;
        void set_deduction()
        {
            float tempdec;
            //get deduction
            cout<<"How much total deduction? ";
            cin>>tempdec;
            //validate deduction
            while(tempdec<0)
            {   
                cout<<"Please enter a postive number"<<endl;
                cout<<"How much total deduction? ";
                cin>>tempdec;
                
            }
            //set after validation
            deduction=tempdec;
        }
        //functions to set working hours, wage and deduction from file
        //setter function for the working hours name;
        void set_fileWork(int w)
        {
            workingHours=w;
        }
        //setter function for the wage;
        void set_filewage(int wage)
        {
            costPerHour=wage;
        }
        //setter function for the deduction;
        void set_filededuction(int Deduction)
        {
            deduction=Deduction;
        }
        

};
//HRM CLASS
int counter=0;
class HRM
{
    //declare public functions and variables
    public:
        //declare employee array of 1000
        Employee E[1000]; 
        int actEmp;
        //function to add employee
        void addEmployee()
        {   
            char yn;
            bool cont=true;
            //loop until user wants to add user
            do
            {
                string name1,name2;
                //make the counter be the actemp so the actemp will increment after every iteration of add function
                actEmp=counter;
                //get first name of employee
                cout<<"Please enter the first name of an employee?";
                cin>>name1;
                E[actEmp].set_firstName(name1);
                   //get last name of employee
                cout<<"Please enter the last name of an employee?";
                cin>>name2;
                E[actEmp].set_lastName(name2);
                //get working hours
                E[actEmp].set_workingHours();
                //get cost per hour
                E[actEmp].set_costPerHour();
                //get deduction
                E[actEmp].set_deduction();
                //print the added employee information
                cout<<"The employee with the following information has been added to the system:"<<endl;
                cout<<endl;
                cout<<"Employee ID First Name     Last Name       Salary per year($)"<<endl;
                cout<<"----------- ----------     ----------      ------------------"<<endl;
                cout<<"  "<<E[actEmp].get_employeeID()<<"         "<<E[actEmp].get_firstName()<<"          "<<E[actEmp].get_lastName()<<"               "<<E[actEmp].get_annualSalary()<<endl;
                cout<<"Do you want to add another employee(y/n)?";
                cin>>yn;
                //if the user entered N or n stop the loop.
                if(yn=='n' || yn=='N')
                {
                    cont=false;
                }
                //increment the counter
                counter++;
                
                //if the number of employees reached 100 break and inform the user
                if (actEmp==100)
                {
                    cout<<"Reached 100 employes"<<endl;
                    break;
                }
            }while(cont);

            
        }
        //menu function
       void PrintMenu()
        {
            cout<<"*********MENU*********"<<endl;
            cout<<"1.Add New Employee"<<endl;
            cout<<"2.Delete an Employee"<<endl;
            cout<<"3.Update Employee information"<<endl;
            cout<<"4.Search for an employee"<<endl;
            cout<<"5.Quit"<<endl;
            cout<<"Please enter your choice 1..5:";
        }
        //function that adds the infromation for the file
        void AddfromFile(string fname,string lname,int week,int Wage,int deduc)
        {
             //make the counter be the actemp so the actemp will increment after every iteration of add function
            actEmp=counter;
            //set the information of the employee from the file
            E[actEmp].set_firstName(fname);
            E[actEmp].set_lastName(lname);
            E[actEmp].set_fileWork(week);
            E[actEmp].set_filewage(Wage);
            E[actEmp].set_filededuction(deduc);
             //increment the counter
            counter++;
        }
        //search function that returns the location of the searched employee
        int searchEmployee(int ID)
        {
            int location=-2; 
            bool cont=true;
            bool found=false;
            char yn;
           
             //loop through  the array of employees 
            for(int x=0;x<actEmp+1;x++)
            {
                //if the ID in the array equal to the ID the user wants to search then let location be the x
                if(E[x].get_employeeID()==ID)
                {
                    //if found. found should be true
                    found=true;
                    //let location the index where the employee is found in the array
                    location=x;

                }
            }
            //if not found inform the user
            if(!found)
            {
                cout<<"Sorry, there is no employee with this ID?"<<endl;
            }
            //return location
            //if found location is = the location
            //else location is = -2 which means not found
            return location;
        }
        //delete employee function
        void deleteEmployee()
        {
            int ID;
            char yn;
            bool cont=true;
            int name;
            //loop to repeat deleting untill the user doesn't want to delete
            do{
                //get employee ID
                cout<<"Please enter the employee ID?";
                cin>>ID;
                //call the search employee function to check if employee is found first of all
                name=searchEmployee(ID);
                //if the name!=-2 so countiue the deleting process
                if(name!=-2)
                {
                    //prompt and ask the user of he is sure he wants to delete the employee
                    cout<<"Do you really want to delete employee "<<E[name].get_firstName()+" "+E[name].get_lastName() <<" (y/n)?";
                    cin>>yn;
                    //if user wants to delete employee then do it
                    if(yn=='Y'|| yn=='y')
                    
                    {
                         //print that the employee is deleted
                        cout<<"The employee "<<E[name].get_firstName()+" "+E[name].get_lastName()<<" has been deleted."<<endl;
                	    
                        //loop through the array of employees
                        for(int x=name;x<actEmp;x++)
                        {    
                            //delete
                            //move the (index + 1). the one just after the required employee to be deleted  to the index of the requried deleted employee
                            E[x]=E[x+1];
                         
                            //and empty the index that was moved
                            
                        }
                        //decremeant the number of employees and counter
                        actEmp--;
                        counter--;
                        
                       
                        
                    
                    }
                }
                //else print the employee is not deleted if he is not found during the search
                else
                {
                    cout<<"The employee has NOT been deleted."<<endl;
                }
                    
                //ask the user if he wants to continue
                cout<<"Do you want to repeat delete by entering new employee ID (y/n)?";
                cin>>yn;
                if(yn=='n' || yn=='N')
                {
                    cont=false;
                }
                //loop while cont is true
            }while(cont);
        }
        //update employee function
        void updateEmployee()
        {
            int num;
            int ID;
            char yn,yn2;
            bool cont=true,cont2=true;
            int location;
            //loop to until the user don't want to update another employee 
            do
            {       
            //search for the employee
              cout<<"Please enter the employee ID?";
              cin>>ID;
               //call the search employee function to check if employee is found first of all
              location=searchEmployee(ID);
              cont2=true;
            //loop untill the user don't want to update any other field of the employee
            while(cont2){
                //if the name!=-2 so countiue the deleting process
              if(location!=-2)
              {
                  //prompt to user what he wants to change 
                  cout<<"Please enter the related number of field which you would like to update?"<<endl;
                  cout<<"(1. First name, 2. Family name, 3. Working hours per week, 4. Payment for one hour, 5. deduction)?";
                  cin>>num;
                  string FName,LName;
                
                  //switch case that change specfic information based on the user input
                  switch (num)
                  {
                  case 1:
                    //get employee name
                    cout<<"Please enter the new name for "<<E[location].get_firstName()<<": ";
                    cin>>FName;
                    E[location].set_firstName(FName);
                    break;
                  case 2:
                    //get family name
                    cout<<"Please enter a new family name for "<<E[location].get_lastName()<<": ";
                    cin>>LName;
                    E[location].set_lastName(LName);
                    break;
                  case 3:
                    //get working hours
                    cout<<"Please enter the new working hours per week"<<endl;
                    E[location].set_workingHours();
                    //recaluate salaray
                    E[location].get_annualSalary();
                    break;
                  case 4:
                    //get cost per hour
                    cout<<"Please enter the new payment per one hour"<<endl;
                    E[location].set_costPerHour();
                    //recaluate salaray
                    E[location].get_annualSalary();
                    break;
                  case 5:
                  //get deduction
                   cout<<"Please enter the new deduction"<<endl;
                   E[location].set_deduction();
                   //recaluate salaray
                   E[location].get_annualSalary();
                   break;
                  
                  default:
                    //default case if number is not 1,2,3,4
                    cout<<"Enter a choose from 1-5"<<endl;
                      break;
                  }
                  //ask the user if he wants to update any other field
                  cout<<"Do you want to update any other field (y/n)?";
                  cin>>yn2;
                  if(yn2=='n' || yn2=='N')
                  {
                      //if the user don't want to update any other field then tell the user that the previous employee is updated
                    cout<<"The information for Mr."<<E[location].get_firstName()<< " has been updated"<<endl;
                    //stop asking to update any other field for the employee
                    cont2=false;
                  }
                }
                //else if employee not found break
                else
                {
                    break;
                }
            }
            //ask if the user wants to update the information of an another employee
                cout<<"Do you want to repeat update by entering new employee ID (y/n)?";
               cin>>yn;
               //if the user don't want to update the information of another employee then stop the loop
               if(yn=='n' || yn=='N')
                {   
                    //make cont false to stop loop
                    cont=false;
                }
            
            
            
            } while (cont);
            
        }


};



//main function
int main()
{
    //declare object of HRM class
    HRM test;
    //declare variables
    string Firname,Lasname;
    double SalL;
    int id,weekh,wage,ded;
    ifstream fileRead;
    //open file to read employee information
    fileRead.open("employee.txt");
    //loop to the end of the file
    while(!fileRead.eof())
    {
        //read first name
        fileRead>>Firname;
        //read last name
        fileRead>>Lasname;
        //read working hour
        fileRead>>weekh;
        //read wage
        fileRead>>wage;
        //read deduction
        fileRead>>ded;
        //if end of file then break from the loop
        if(fileRead.eof())
        {
            break;
        }
        //pass the read items to the add function in the HRM class
        test.AddfromFile(Firname,Lasname,weekh,wage,ded);
    }
    //close file
    fileRead.close();
    
    bool cont=true;
    char yn;

    int num,ID;
    //loop the menu until the user quits
    do{
    //print menu
    test.PrintMenu();
    cin>>num;
    cout<<endl;
    
    switch (num)
    {
    //if num==1
    //add employee
    case 1:{
        test.addEmployee();
        break;
    //if num==2
    //delete employee
    }case 2:{
        test.deleteEmployee();
        break;
    //if num==3
    //update employee
    }case 3:{
        test.updateEmployee();
        break;
    //if num==4
    //search employee
    }case 4:{
        bool cont2=true;
        //loop if the user wants to do a new search
        do{
            //get employee ID
            cout<<"Please enter the employee ID?";
            cin>>ID;
            //search employee ID
            int num1=test.searchEmployee(ID);
            // if employee found then print the employee information 
            if(num1!=-2){
         
                cout<<"Employee ID First Name Last Name  Salary per year($)"<<endl;
                cout<<"----------- ---------- ---------- ----------------------"<<endl;
                cout<<"  "<<test.E[num1].get_employeeID()<<"          "<<test.E[num1].get_firstName()<<"         "<<test.E[num1].get_lastName()<<"        "<<test.E[num1].get_annualSalary()<<endl;
                
            }
            //ask if the user wants to do a new search
            cout<<"Do you want to do new search (y/n)?";
            cin>>yn;
            if(yn=='n' || yn=='N')
            {
                cont2=false;
            }
        }while(cont2);
        
        break;
    // if number ==5 then which is quit. So, print the information from the array to the file
    }case 5:{
        ofstream file;
         //open a new file for writing employee information
        file.open("employeenew.txt");
       //loop based on the length of the employee array
        for(int x=0;x<test.actEmp+1;x++)
        {
            //print the information of the employees in the array
            file<<test.E[x].get_employeeID()<<" ";
            file<<test.E[x].get_firstName()<<" ";
            file<<test.E[x].get_lastName()<<" ";
            file<<test.E[x].get_workingHours()<<" ";
            file<<test.E[x].get_costPerHour()<<" ";
            file<<test.E[x].get_deduction()<<" ";
            file<<test.E[x].get_annualSalary()<<endl;
        }
        //close file
        file.close();
        break;
    //default case if the user entered a number other than 1,2,3,4,5    
    }default:
    //if so then tell the user to enter a correct number
        cout<<"ENTER A NUMBER FROM 1-5"<<endl;
        break;
    }
    //loop until if the user haven't quitted the program
    }while(num!=5);
}
