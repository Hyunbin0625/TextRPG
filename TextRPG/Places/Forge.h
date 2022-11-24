#pragma once

enum class Reinforce
{
	Weapon = 1,
	Armor,
	Shoes,
	End
};

class Forge
{
public:
	Forge(Player* player);
	~Forge();

};