#include<iostream>
#include<time.h>

using namespace std;

bool Isleapyear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return true;
	else return false;
}

class Date
{
public:
	bool correctdate = true;
	int daysOfmonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int year;
	int month;
	int date;
	int hour;
	int minute;
	int second;
	int week;
	const string weeks[7] = { "Thursday","Friday","Satarday","Sunday","Monday","Tuesday","Wedesday" };
	const string Weeks[7] = { "星期四","星期五","星期六","星期日","星期一","星期二","星期三" };
	Date(time_t time) {
		long long int days;
		second = time % 60;
		minute = time % 3600 / 60;
		hour = time % 86400 / 3600 + 8;
		days = time / 86400 + 1;
		week = (days-1) % 7;
		year = 1970;
		while ((days > 365 && !Isleapyear(year)) || (days > 366 && Isleapyear(year)))
		{
			if (Isleapyear(year++)) days -= 366;
			else days -= 365;
		}
		if (Isleapyear(year)) daysOfmonth[2] = 29;
		month = 1;
		while (days > daysOfmonth[month]) {
			days -= daysOfmonth[month++];
		}
		date = static_cast<int>(days);
	}
	Date(int Year, int Month, int Day)
	{
		year = Year, month = Month, date = Day, hour = 0, minute = 0, second = 0;
		week = 0;
		if (year < 1970 || month < 1 || month>12 || date<1 || date>daysOfmonth[month])
		{
			correctdate = false;
			return;
		}
		for (int i = 1970; i < year; i++) {
			if (Isleapyear(i))
			{
				week += 366;
				week %= 7;
			}
			else {
				week += 365;
				week %= 7;
			}
		}
		if (Isleapyear(year)) daysOfmonth[2] = 29;
		for (int j = 1; j < month; j++)
		{
			week +=daysOfmonth[j];
			week %= 7;
		}
		week += Day;
		week %= 7;
	}

	void log_date() {
		cout << year << "年" << month << "月" << date << "日 " << hour << "点" << minute << "分" << second << "秒 " << Weeks[week] << endl;
	}
	void log_Date() {
		printf("%d/%d/%d %02d:%02d:%02d ", year, month, date, hour, minute, second);
		cout << weeks[week] << endl;
	}
	void log_week() {
		if (correctdate)
			cout << year << "." << month << "." << date << "是" << weeks[week - 1] << endl;
		else cout << "输入错误！" << endl;
	}

};

int main()
{
	Date today(time(NULL));
	today.log_date();
	today.log_Date();

	Date startdate(1970, 1, 1);
	startdate.log_week();

	Date tomorrow(2024, 9, 22);
	tomorrow.log_week();

	int y, m, d, ch;
	cout << "请输入日期:" << endl;
	cin >> y; 
	ch=getchar();
	cin >> m; 
	ch=getchar();
	cin >> d;
	Date somedate(y,m,d);
	somedate.log_week();

	return 0;
}
