// 0609.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <assert.h>
#include <memory>

//class Test 
//{
//public:
//	void Show()
//	{
//		std::cout << "Hello World!!" << std::endl;
//	}
//
//
//
//};
//
//void Func(Test* test)
//{
//	assert(test != nullptr);
//	test->Show();
//}
//
//int main()
//{
//
//	Func(new Test());
//	Func(nullptr);
//   
//
//}




class Weapon
{
public:

	void Use(){}


};

class Player
{
	std::shared_ptr<Weapon> weapon;
public:
	

		// lvalue (参照) を受け取るコンストラクタ（コピー）
		Player(const std::shared_ptr<Weapon>&weapon1) :weapon(weapon1) {
			std::cout << weapon.use_count() << std::endl;
			std::cout << weapon1.use_count() << std::endl;
		}

		// rvalue を受け取るコンストラクタ（ムーブ）
		Player(std::shared_ptr<Weapon> && weapon1) :weapon(std::move(weapon1)) {
			std::cout << weapon.use_count() << std::endl;
			std::cout << weapon1.use_count() << std::endl;
		}


	

	

};


class Sword : public Weapon
{

};




int main() 
{

	auto sword = std::make_shared<Sword>();

	Player p1(std::move(sword));



		
}
