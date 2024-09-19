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
	int daysOfmonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int year;
	int month;
	long long int days;
	int date;
	int hour;
	int minute;
	int second;
	int week;
	const string weeks[7] = { "Thursday","Friday","Satarday","Sunday","Monday","Tuesday","Wedesday" };
	const string Weeks[7] = { "星期四","星期五","星期六","星期日","星期一","星期二","星期三" };
	Date(time_t time) {
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
	
	void log_date() {
		cout << year << "年" << month << "月" << date << "日 " << hour << "点" << minute << "分" << second << "秒 " << Weeks[week] << endl;
	}
	void log_Date() {
		printf("%d/%d/%d %02d:%02d:%02d ", year, month, date, hour, minute, date);
		cout << weeks[week] << endl;
	}
};

int main()
{
	Date today(time(NULL));
	today.log_date();
	today.log_Date();
	return 0;
}
