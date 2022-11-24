#pragma once

struct PlayerDesc
{
	int id = 0;
	int hp = 0;
	int atk = 0;
	int def = 0;
	int avoid = 0;
	int maxHp = 0;
	int maxMana = 0;
	int maxExp = 0;
	int level = 0;
	int exp = 0;
	int mana = 0;
	int gold = 0;
	int dungeonFloor = 0;
	int weapon = 0;
	int armor = 0;
	int shoes = 0;
	int hpPotion = 0;
	int manaPotion = 0;
	int reviveStone = 0;
};

class Player : public Character
{
public:
	Player(PlayerDesc desc);

public:	// player ���� ����
	int GetPlayerLevel() { return level; }
	int GetPlayerExp() { return exp; }
	int GetPlayerMana() { return mana; }
	int GetPlayerMaxHp() { return maxHp; }
	int GetPlayerMaxMana() { return maxMana; }
	int GetPlayerMaxExp() { return maxExp; }
	int GetPlayerGold() { return gold; }
	int GetDungeonFloor() { return dungeonFloor; }
	
	void SetPlayerLevel(int playerLevel) { this->level = playerLevel; }
	void SetPlayerExp(int playerExp) { this->exp = playerExp; }
	void SetPlayerMana(int playerMana) { this->mana = playerMana; }
	void SetPlayerMaxHp(int playerMaxHp) { this->maxHp = playerMaxHp; }
	void SetPlayerMaxMana(int playerMaxMana) { this->maxMana = playerMaxMana; }
	void SetPlayerMaxExp(int playerMaxExp) { this->maxExp = playerMaxExp; }
	void SetPlayerGold(int playerGold) { this->gold = playerGold; }
	void SetDungeonFloor(int dungeonFloor) { this->dungeonFloor = dungeonFloor; }

public:	// ���尣 ����
	int GetPlayerWeapon() { return weapon; }
	int GetPlayerArmor() { return armor; }
	int GetPlayerShoes() { return shoes; }

	void SetPlayerWeapon(int playerWeapon) { this->weapon = playerWeapon; }
	void SetPlayerArmor(int playerArmor) { this->armor = playerArmor; }
	void SetPlayerShoes(int playerShoes) { this->shoes = playerShoes; }

public:	// ��ȭ�� ����
	int GetPlayerHpPotion() { return hpPotion; }
	int GetPlayerManaPotion() { return manaPotion; }
	int GetPlayerReviveStone() { return reviveStone; }

	void SetPlayerHpPotion(int playerHpPotion) { this->hpPotion = playerHpPotion; }
	void SetPlayerManaPotion(int playerManaPotion) { this->manaPotion = playerManaPotion; }
	void SetPlayerReviveStone(int playerReviveStone) { this->reviveStone = playerReviveStone; }

public:	// ������
	void PlayerLevelUp();
	void PlayerAttack(Character* Character);

public:
	void SkillBeginnerSword(Character* otherCharacter);

public:
	

private:
	// player ���� ���� ����
	int level;
	int exp;
	int mana;
	int maxHp;
	int maxMana;
	int maxExp;
	int gold;
	int dungeonFloor;

	// ���尣 ���� ����, ��ȭ ���� Ƚ�� ����
	int weapon;
	int armor;
	int shoes;

	// ��ȭ�� ���� ����, ���� ����
	int hpPotion;
	int manaPotion;
	int reviveStone;
	
};