#include "stdafx.h"
#include "Player.h"

Player::Player(PlayerDesc desc)
	: Character(desc.id, desc.hp, desc.atk, desc.def, desc.avoid)
	, mana(desc.mana)
	, level(desc.level)
	, exp(desc.exp)
	, maxHp(desc.maxHp)
	, maxMana(desc.maxMana)
	, maxExp(desc.maxExp)
	, gold(desc.gold)
	, dungeonFloor(desc.dungeonFloor)
	, weapon(desc.weapon)
	, armor(desc.armor)
	, shoes(desc.shoes)
	, hpPotion(desc.hpPotion)
	, manaPotion(desc.manaPotion)
	, reviveStone(desc.reviveStone)
{
}

void Player::PlayerLevelUp()
{
	level += 1;
	exp -= maxExp;
	maxExp = (level / 2) * 20;
	maxHp = level * 150;
	maxMana = level * 30;
}

void Player::PlayerAttack(Character* otherCharacter)
{
	if (otherCharacter->GetDEF() < (GetATK() + (GetPlayerWeapon() * 5)))
	{
		otherCharacter->SetHP(otherCharacter->GetHP() - ((GetATK() + (GetPlayerWeapon() * 5)) - otherCharacter->GetDEF()));
		cout << "===================== �÷��̾��� ���� =====================\n\n";
		cout << "�÷��̾�� " << GetATK() << "(+" << (GetPlayerWeapon() * 5) << ") �� �������� �����Ͽ���.\n";
		cout << "������ ���ʹ� " << otherCharacter->GetDEF() << "�� �������� ����Ͽ���.\n";
		cout << "�� ���� ������ : " << (GetATK() + (GetPlayerWeapon() * 5)) - otherCharacter->GetDEF() << "\n\n";
	}
	else
	{
		cout << "===================== �÷��̾��� ���� =====================\n\n";
		cout << "�÷��̾�� " << GetATK() << "(+" << (GetPlayerWeapon() * 5) << ") �� �������� �����Ͽ���.\n";
		cout << "������ ���ʹ� " << otherCharacter->GetDEF() << "�� �������� ����Ͽ���.\n";
		cout << "�� ���� ������ : 0\n\n";
	}

	if (otherCharacter->GetHP() < 1)
	{
		cout << "���� ������ ü�� : 0\n\n";
	}
	else
	{
		cout << "���� ������ ü�� : " << otherCharacter->GetHP() << "\n\n";
	}
}

void Player::SkillBeginnerSword(Character* otherCharacter)
{
	if (mana >= 15)
	{
		if (otherCharacter->GetDEF() < ((GetATK() * 2) + (GetPlayerWeapon() * 5)))
		{
			otherCharacter->SetHP(otherCharacter->GetHP() - ((GetATK() * 2) + (GetPlayerWeapon() * 5)) - otherCharacter->GetDEF());
			mana = mana - 15;

			cout << "===================== �÷��̾��� ���� =====================\n\n";
			cout << "�÷��̾�� ���� 15�� �Ҹ���, ��ų ���\n"; 
			cout << "�÷��̾�� " << GetATK() * 2 << "(+" << GetPlayerWeapon() * 5 << ") �� �������� �����Ͽ���.\n";
			cout << "������ ���ʹ� " << otherCharacter->GetDEF() << "�� �������� ����Ͽ���.\n";
			cout << "�� ���� ������ : " << (GetATK() * 2) - otherCharacter->GetDEF() << "\n\n";
		}
		else
		{
			mana = mana - 15;

			cout << "===================== �÷��̾��� ���� =====================\n\n";
			cout << "�÷��̾�� ���� 15�� �Ҹ���, ��ų ���\n";
			cout << "�÷��̾�� " << GetATK() * 2 << "(+" << GetPlayerWeapon() * 5 << ") �� �������� �����Ͽ���.\n";
			cout << "������ ���ʹ� " << otherCharacter->GetDEF() << "�� �������� ����Ͽ���.\n";
			cout << "�� ���� ������ : 0\n\n";
		}

		if (otherCharacter->GetHP() < 1)
		{
			cout << "���� ������ ü�� : 0\n\n";
		}
		else
		{
			cout << "���� ������ ü�� : " << otherCharacter->GetHP() << "\n\n";
		}
	}
	else
	{
		cout << "�÷��̾��� ������ �����մϴ�!\n\n";
	}

}