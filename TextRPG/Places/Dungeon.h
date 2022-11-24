#pragma once

enum class FightAct
{
	Attack = 1,
	Escape,
	Potion,
	Makgora
};

enum class Attack
{
	Normal = 1,
	Skill
};

enum class Potion
{
	HpPotion = 1,
	ManaPotion,
	ReviveStone,
	End
};

class Dungeon
{
public:
	Dungeon(Player* player);
	~Dungeon();

private: // 던전 층, 게임 턴, player 관련 정보
	int turn;
};

