#pragma once

class Character
{
public:
	Character() : Character(0, 0, 0, 0, 0) {}
	Character(int id, int hp, int atk, int def, int avoid);
	virtual ~Character();

public:
	int GetID() { return id; }
	int GetHP() { return hp; }
	int GetATK() { return atk; }
	int GetDEF() { return def; }
	int GetAVOID() { return avoid; }
	void SetHP(int hp) { this->hp = hp; }
	void SetATK(int atk) { this->atk = atk; }
	void SetDEF(int def) { this->def = def; }
	void SetAVOID(int avoid) { this->avoid = avoid; }

private:
	//	추가 해야할 것 : defense, 
	const int id;
	int hp;
	int atk;
	int def;
	int avoid;
};