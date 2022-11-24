#include "stdafx.h"
#include "Character.h"

Character::Character(int id, int hp, int atk, int def, int avoid)
	: id(id)
	, hp(hp)
	, atk(atk)
	, def(def)
	, avoid(avoid)
{
}

Character::~Character()
{
}