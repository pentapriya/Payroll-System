#include<iostream>
using namespace std;

class salary{
    public:

    double get_basic(double annual_ctc){
        double monthly_ctc=annual_ctc/12;
        return (monthly_ctc*47)/100;
    }

    double get_DA(double Basic){
        return (Basic*20)/100;
    }

    double get_HRA(double Basic,double DA){
        return ((Basic+DA)*50)/100;
    }

    double get_Advance_statutory_bonus(double Basic,double DA){
        return ((Basic+DA)*15)/100;
    }

    double get_personal_allowance(double Basic,double DA){
        return ((Basic+DA)*5)/100;
    }

    double get_Remote_working_Allowance(double Basic,double DA){
        return ((Basic+DA)*5)/100;
    }

    double get_extra_work_hrs(double extra_work_hrs){
        return extra_work_hrs*110*1.5;
    }

    double get_Gross_Salary(double Basic,double HRA,double incentive,double Advance_statutory_bonus,double Remote_working_Allowance,double personal_allowance,double Extra_work_hrs){
        return (Basic+HRA+incentive+Advance_statutory_bonus+Remote_working_Allowance+personal_allowance+Extra_work_hrs);
    }

    double get_ESI(double Gross_Salary){
        return (Gross_Salary<21000)?(0.25*Gross_Salary):0;
    }

    double get_PF(double Basic,double DA){
        return ((Basic+DA)*12)/100;
    }

    double get_LOP(double Number_Of_Days_paid,double Number_of_days_present,double paid_leaves){
        double total_days=Number_of_days_present+paid_leaves+8;
        double LOP=Number_Of_Days_paid-total_days;
        return (LOP*990);
    }

    double get_Gross_deducted_salary(double ESI,double PF,double PT,double LOP){
        return ESI+PF+PT+LOP;
    }

    double get_Net_Salary(double Gross_Salary,double Gross_deducted_salary){
        return Gross_Salary-Gross_deducted_salary;
    }
};