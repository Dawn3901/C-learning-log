#include<iostream>
#include<time.h>

enum example {
	a = 5, b, c, d, e, z, x, y
};
enum week {
	Sun = 7, Mon = 1, Tue, Wed, Thu, Fri, Sat
};

class Date {
	int second = time(NULL) % 60;//time(NULL)返回现在的时间到1970.1.1.8:00(Beijing)的时间戳
	int minute = time(NULL) / 60 % 60;
	int hour = time(NULL) / 3600 % 24 +8;
public:
	void log_time() {
		printf("%02d:%02d:%02d\n", hour, minute, second);
	}
};

int main()
{
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << z << std::endl;
	std::cout << x << std::endl;
  
	int week = Fri;
	std::cout << "今天星期" << week << std::endl;
  
	Date today;
	today.log_time();
	return 0;
}
