#include<iostream>
#include<math.h>
using namespace std;

class Loan
{
public:
	double monthlyInterestRate;
	int numbersOfYears;
	double monthlyPayment;
	double totalPayment;
	double loanAmount;

	Loan(int& years,double& interest,double& lA) {

		numbersOfYears = years;
		monthlyInterestRate = interest / 1200;
		loanAmount = lA;
		double tmp1 = 1.0 / pow((1.0 + monthlyInterestRate), 12 * numbersOfYears);
		double tmp2 = loanAmount * monthlyInterestRate;
		monthlyPayment = tmp2 / (1.0 - tmp1);
		totalPayment = static_cast<double>(monthlyPayment * 12 * numbersOfYears);
	}
	void log_monthlyPayment()
	{
		cout << monthlyPayment << endl;
	}
	void log_totalPayment() {
		cout << totalPayment << endl;
	}
};

int main()
{
	cout << "这是一个贷款利息计算器" << endl;
	int Years;
	double Interest, LoanAmount;
	cout << "请输入您的贷款年限：" << endl;
	cin >> Years;
	cout << "请输入年利率：(单位%)" << endl;
	cin >> Interest;
	cout << "请输入您的贷款总额：" << endl;
	cin >> LoanAmount;
	Loan your_loan(Years, Interest, LoanAmount);
	cout << "您的月还款额为：";
	your_loan.log_monthlyPayment();
	cout << "您的还款总额为：";
	your_loan.log_totalPayment();
	return 0;
}
