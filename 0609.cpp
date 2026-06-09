// 0609.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <assert.h>
#include <memory>
#include <stdexcept>

class Weapon
{
public:
	void Use() {}
};

class Player
{
	// 初期化保証: コンストラクタで必ず有効な shared_ptr を受け取り、メンバは const として保持する
	const std::shared_ptr<Weapon> weapon;

public:
	// 値渡しで受け取りコンストラクタ内でムーブするスタイル:
	// 呼び出し元は std::move() してムーブ渡しするか、コピーした shared_ptr を渡す
	// null を許容しない設計のため、null だったら例外を投げる（初期化保証）
	explicit Player(std::shared_ptr<Weapon> weapon1) : weapon(std::move(weapon1))
	{
		if (!weapon)
		{
			throw std::invalid_argument("weapon must not be null");
		}
	}

	void Attack()
	{
		// コンストラクタで non-null を保証しているため、null チェック不要
		weapon->Use();
	}
};

class Sword : public Weapon
{
};


int main()
{
	auto sword = std::make_shared<Sword>();

	// 所有権をムーブして Player を初期化（sword は空になる）
	Player p1(std::move(sword));

	// p1.Attack(); // 安全に呼べる（コンストラクタにより weapon は常に有効）
}
