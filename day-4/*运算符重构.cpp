#include<iostream>
#include<string>

using namespace std;

struct vector2 {
	float x, y;
	vector2(float x, float y)
		:x(x), y(y) {}

	vector2 add(const vector2& other) const
	{
		return vector2(x + other.x, y + other.y);
	}
	//加法重构
	vector2 operator+(const vector2& other) const {
		return add(other);
	}

	vector2 mutiply(const vector2& other) const
	{
		return vector2(x * other.x, y * other.y);
	}
	//乘法重构
	vector2 operator*(const vector2& other) const
	{
		return mutiply(other);
	}

	bool equals(const vector2& other) const
	{
		if (x == other.x && y == other.y) return true;
		else return false;
	}
	//== != 重构
	bool operator==(const vector2& other) const
	{
		return equals(other);
	}
	bool operator!=(const vector2& other) const
	{
		return !(*this == other);
	}

	void log()
	{
		cout << x << "," << y << endl;
	}

};
// <<重构
ostream& operator<<(ostream& stream, const vector2& other)
{
	stream << "(" << other.x << "," << other.y << ")";
	return stream;
}


int main()
{
	vector2 position(4.0f, 4.0f);
	vector2 speed(1.2f, 2.0f);
	vector2 powerup(1.0f, -1.5f);

	vector2 result2 = position.add(speed.mutiply(powerup));
	vector2 result1 = position + speed * powerup;

	result2.log();
	result1.log();
	cout << result2 << endl;

	if (result2 == result1) {
		cout << "Same answer!" << endl;
	}
	if (!(result1 != result2)) {
		cout << "否定重构成功？" << endl;
	}
	return 0;
}
