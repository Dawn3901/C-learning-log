#include<iostream>
//memcpy(被粘贴的，被复制的，复制粘贴的大小)
class String
{
private:
	char* m_Buffer;
	unsigned int m_Size;
public:
	String(const char* string)
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size+1];//+1是给 0 结束符留位置
		memcpy(m_Buffer, string, m_Size);
		m_Buffer[m_Size] = 0;
	}

	//c++内置的拷贝类似这样，是一种浅拷贝，这种拷贝不会多开内存，delete的时候会报错
	/*String(const String& other)
		:m_Buffer(other.m_Buffer), m_Size(other.m_Size) {};*/

	//copy 构造函数
	String(const String& other)
		:m_Size(other.m_Size)
	{
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1); //大多情况下这里 +1 就可以把 0 也copy了
		std::cout << "Copied!" << std::endl;
	}//这样写，String在用作函数参数的时候也会调用，增大内存负载，引用可以避免(删去line43的&验证)

	//添加友元使得友元函数可以直接调用类内成员
	friend std::ostream& operator<<(std::ostream& stream, const String& string);
	char& operator[](const int index)
	{
		return m_Buffer[index];
	}
	~String() { delete[] m_Buffer; }
};

std::ostream& operator<<(std::ostream& stream, const String& string) {
	stream << string.m_Buffer;
	return stream;
}

void PrintString(const String& string) {
	std::cout << string << std::endl;
}

int main()
{
	String string("Dawn");
	std::cout << string << std::endl;
	std::cout << string[1] << std::endl;
	string[0] = 'd';
	std::cout << string << std::endl;

	String s = string;
	s[1] = 'o';
	PrintString(string);
	PrintString(s);

	return 0;
}
