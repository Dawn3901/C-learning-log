#include<iostream>
using namespace std;

class Player {
public://Public下的在其它地方也能使用,struct的话默认public,class默认private
	int x, y;
	int speed;
	int hp;
	//函数扔在class里面好使
	void underAttack(int damage) {
		hp -= damage;
	}
	void log_position() {
		cout << "Now your position is (" << x << "," << y << ")"<<endl;
	}
	void log_health() {
		cout << "Now your HP is " <<hp<< endl;
	}
};
//class的函数两种写法,上一种更好,调用方式不同
void move(Player& player, int time) {
	player.x += player.speed * time;
	player.y += player.speed * time;
}


int main()
{
	Player dawn{0,0,5,100};
	cout << "Your initial position is (" << dawn.x << "," << dawn.y <<")" << endl;
	cout << "Your max-heath is " << dawn.hp << endl;
	move(dawn, 2);
	dawn.underAttack(30);
	dawn.log_health();
	dawn.log_position();
	system("pause");
	return 0;
}