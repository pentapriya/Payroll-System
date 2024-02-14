#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<fstream>
#include "final.h"


class Employee:public salary
{
public:
    int employeeID;
    string name;
    string Designation;
    string Date_Of_Joining;
    string PAN_Number, UAN_Number;
    double Number_Of_Days_paid;
    double Number_of_days_present,paid_leaves,week_offs;
    double Annual_CTC,Basic, HRA,DA;
    double Advance_statutory_bonus;
    double personal_allowance;
    double incentive,Remote_working_Allowance;
    double Extra_work_hours,extra_work_hours,Loss_of_pay;
    double Gross_Salary;
    double ESI,PF,PT;
    double Gross_deducted_salary;
    double Net_Salary;

    Employee() : employeeID(0), name(""), Designation(""), Date_Of_Joining(""),
                 PAN_Number(""), UAN_Number(""), Number_Of_Days_paid(30),
                 Number_of_days_present(0),paid_leaves(0),
                 Annual_CTC(0), Basic(0), DA(0), HRA(0), Advance_statutory_bonus(0),
                 personal_allowance(0), incentive(0), Remote_working_Allowance(0),
                 Extra_work_hours(0), Gross_Salary(0),
                 ESI(0), PF(0), PT(0),Loss_of_pay(0), Gross_deducted_salary(0), Net_Salary(0) {}

    Employee(int _employeeID, string _name, string _Designation, string _Date_Of_Joining, string _PAN_Number, string _UAN_Number,double _Number_of_days_present,double _paid_leaves, double _Annual_CTC,double _Extra_work_hours)
        : employeeID(_employeeID), name(_name), Designation(_Designation), Date_Of_Joining(_Date_Of_Joining),Extra_work_hours(_Extra_work_hours),
          PAN_Number(_PAN_Number), UAN_Number(_UAN_Number), Number_Of_Days_paid(30),Number_of_days_present(_Number_of_days_present),paid_leaves(_paid_leaves), Annual_CTC(_Annual_CTC),Basic(0),DA(0), HRA(0),Advance_statutory_bonus(0),personal_allowance(0),
          incentive(0),Remote_working_Allowance(0),Gross_Salary(0),ESI(0),PF(0),PT(0),Loss_of_pay(0),Gross_deducted_salary(0){}

    // Add employee data to Employee class
    void input_employee_data() {
        cout << "Enter Employee ID: ";
        cin >> employeeID;

        cout << "Enter Employee Name: ";
        cin.ignore(); 
        getline(cin, name);

        cout << "Enter Employee Designation: ";
        getline(cin, Designation);

        cout << "Enter Date of Joining (DD-MM-YYYY): ";
        cin >> Date_Of_Joining;

        cout << "Enter PAN Number: ";
        cin >> PAN_Number;

        cout << "Enter UAN Number: ";
        cin >> UAN_Number;

        cout<<"Enter Number of days present: ";
        cin>>Number_of_days_present;

        cout << "Enter Number of Paid_leaves: ";
        cin >> paid_leaves;

        cout << "Enter Annual CTC: ";
        cin >> Annual_CTC;

        cout << "Enter Extra Work Hours: ";
        cin >> Extra_work_hours;
    }

    //function for salary details of employee

    void salary_data(salary& sal){
        Basic=sal.get_basic(Annual_CTC);
        DA=sal.get_DA(Basic);
        HRA=sal.get_HRA(Basic,DA);
        Advance_statutory_bonus=get_Advance_statutory_bonus(Basic,DA);
        personal_allowance=get_personal_allowance(Basic,DA);
        Remote_working_Allowance=get_Remote_working_Allowance(Basic,DA);
        extra_work_hours=get_extra_work_hrs(Extra_work_hours);
        Gross_Salary=get_Gross_Salary(Basic,HRA,incentive,Advance_statutory_bonus,Remote_working_Allowance,personal_allowance,extra_work_hours);
        
        ESI=get_ESI(Gross_Salary);
        PF=get_PF(Basic,DA);
        PT=200;
        Loss_of_pay=get_LOP(Number_Of_Days_paid,Number_of_days_present,paid_leaves);
        Gross_deducted_salary=get_Gross_deducted_salary(ESI,PF,PT,Loss_of_pay);

        Net_Salary=get_Net_Salary(Gross_Salary,Gross_deducted_salary);
    }

    
};



class payroll
{
public:
    vector<Employee> emp;
    string data;

    void add_employee(const Employee &e,salary& sal)
    {
        Employee newEmployee = e;
        newEmployee.salary_data(sal);
        emp.push_back(newEmployee);
    }

    void generate_report()
    {
        ofstream file;
        file.open("payroll_report.txt", ios::app);
        if (!file)
        {
            cout << "error in opening file" << endl;
        }
        else
        {
            Employee &lastEmployee = emp.back();
                file <<endl<<endl<< "Payroll_Report of " <<lastEmployee.name<<'_'<<lastEmployee.employeeID<<':'<< endl<<endl
                     << "emp_name         :  " <<right<< setw(7)<< lastEmployee.name  << setw(40)<< "\t\temp_id       :  "<<setw(3) << lastEmployee.employeeID <<endl
                     << "emp_designation  : " <<right<< setw(11)<< lastEmployee.Designation <<right<< setw(42)<< "\temp_date_of_joining  : " << setw(5)<< lastEmployee.Date_Of_Joining<<endl
                     << "emp_PAN_Number   : " <<right<< setw(10)<< lastEmployee.PAN_Number <<right<<setw(43)<< "\temp_UAN_Number       : " << setw(10)<< lastEmployee.UAN_Number<<endl 
                     << "emp_Number_Of_Days_paid: "<< setw(3) << lastEmployee.Number_Of_Days_paid <<right<<setw(44)<< "\tAnnual_CTC      : " << setw(6)<<lastEmployee.Annual_CTC << endl<<endl
                     <<"Earnings"<<setw(65)<<"Deductions"<<endl<<endl
                     << "Basic  \t\t\t\t\t\t : "<<right<< setw(5)<< lastEmployee.Basic <<setw(40)<<"ESI\t:\t\t"<<lastEmployee.ESI<< endl
                     <<"DA      \t\t\t\t\t : "<<right<< setw(5)<<lastEmployee.DA<<setw(40)<<"PF\t:\t\t"<<lastEmployee.PF<<endl
                     << "HRA  \t\t\t\t\t\t : " <<right<< setw(5)<< lastEmployee.HRA<<setw(40)<<"PT\t:\t\t"<<lastEmployee.PT<<endl
                     <<"Advance_statutory_bonus\t\t : "<<right<< setw(5)<<lastEmployee.Advance_statutory_bonus<<setw(36)<<"\t\tLOP\t:\t\t "<<lastEmployee.Loss_of_pay<<endl
                     <<"personal_allowance  \t\t : "<<right<< setw(5)<<lastEmployee.personal_allowance<<endl
                     <<"Remote_working_Allowance  \t : "<<right<< setw(5)<<lastEmployee.Remote_working_Allowance<<endl
                     <<"extra_work_hours\t\t\t : "<<right<< setw(5)<<lastEmployee.extra_work_hours<<endl<<endl
                     <<"Gross_Earnings  \t\t : "<<right<< setw(5)<<lastEmployee.Gross_Salary<<setw(40)<<"Gross_Deductions\t:\t\t"<<lastEmployee.Gross_deducted_salary<< endl<<endl
                     <<"Net_Salary\t\t:\t\t"<<lastEmployee.Net_Salary<<endl<<endl<<endl<<endl;
            
        }

        file.close();
    }

    //function to search employee data from payroll_report.txt

    void search_employee(const string& search_query)
    {
        ifstream file("payroll_report.txt");
        if (!file)
        {
            cout << "Error opening payroll_report.txt" << endl;
            return;
        }

        string line;
        bool found = false;

        while (getline(file, line))
        {
            data=line;

            size_t foundName = line.find("emp_name");
            size_t foundID = line.find("emp_id");

            if (foundName != string::npos && line.find(search_query) != string::npos)
            {
                found = true;
                display_employee_details(file);
                break;
            }
            else if (foundID != string::npos && line.find(search_query) != string::npos)
            {
                found = true;
                display_employee_details(file);
                break;
            }
        }

        file.close();

        if (!found)
        {
            cout << "Employee with name or ID '" << search_query << "' not found." << endl;
        }
    }


    // function to display employee details from the file
    void display_employee_details(ifstream& file)
    {
        string line;
        cout<<data<<endl;
        while (getline(file, line) && line.find("Payroll_Report") == string::npos)
        {
            
            cout << line << endl;

        }
    }

   
    //To display all employee details from the text file

    void display_all_employees()
    {
        ifstream file("payroll_report.txt");
        if (!file)
        {
            cout << "Error opening payroll_report.txt" << endl;
            return;
        }

        string line;
        while (getline(file, line))
        {
            cout << line << endl;
        }

        file.close();
    }

    


};

int main()
{
    payroll pay;
    salary sal;
    int choice;
    char ch;
    Employee emp;  
    cout << setfill('-') << setw(55) << "-" << " Payroll System " << setw(45) << "-" << setfill(' ') << endl;
    
    do
    {
        cout<<"1.Add employee"<<endl<<"2.Display employee payroll details"<<endl<<"3.Search employe by name or ID"<<endl<<"4.exit"<<endl;
        cout << "Enter an option: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            char input;
            do
            {
                //Employee emp(23, "lakshmi priya", "Assoicate1", "20-09-2023", "GCYXD3456", "12312342312", 18,1, 400010,9);
                emp.input_employee_data();
                pay.add_employee(emp, sal);
                pay.generate_report();
                cout<<"do you want to add another employee details: "<<endl;
                cin>>input;
            }while(input=='y');
            break;
        }
            
        case 2:
        {
            pay.display_all_employees();
            break;
        }

        case 3:
        {
            string search_query;
            cout << "Enter employee name or ID to search: ";
            cin >> search_query;
            pay.search_employee(search_query);
        }
        break;
        case 4:exit(0);

        default:
            cout << "Enter a valid option" << endl;
        }
        cout << "Do you want to continue: " << endl;
        cin >> ch;
    } while (ch == 'y');

    return 0;
}
