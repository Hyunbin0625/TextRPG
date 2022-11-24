#pragma once

class Monster : public Character
{
public:
	Monster(int id, int hp, int atk, int def, int avoid) : Character(id, hp, atk, def, avoid) {}

public:
	void MonsterAttack(Player* player);
};