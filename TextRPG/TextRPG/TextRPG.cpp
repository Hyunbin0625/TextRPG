#include "stdafx.h"
#include "TextRPG.h"


TextRPG::TextRPG()
{
	PlayerDesc desc = { 0 };
	cout << "����� ���������� �ҷ����ڽ��ϱ�?\n";
	cout << "1. Yes\t2. No(�� ����)\n";
	cout << "���� : ";

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		PlayerSavedRetrieve(&desc);
	}
	else 
	{
		desc.level = 1;
		desc.hp = 150;
		desc.mana = 30;
		desc.atk = 20;
		desc.def = 5;
		desc.gold = 500;
		desc.dungeonFloor = 1;
		desc.maxHp = desc.level * 150;
		desc.maxMana = desc.level * 30;
		desc.maxExp = desc.level * 20;
		desc.avoid = desc.shoes * 2;
	}

	Player* player1 = new Player(desc);
	system("cls");
	Play(player1);
}

TextRPG::~TextRPG()
{
	SAFE_DELETE(motel);
	SAFE_DELETE(store);
	SAFE_DELETE(forge);
	SAFE_DELETE(dungeon);
	SAFE_DELETE(player);
}

void TextRPG::Play(Player* player)
{
	bool playing = 1;

	while (playing)
	{
		Act act;
		cout << "=======================\n";
		cout << "1. ����\n";			// ���� ���, ����ġ, ��
		cout << "2. ���尣\n";		// ����, ���� �� ��ȭ�� ����, ���ݷ� ����
		cout << "3. ��ȭ��\n";		// ü������, ��������, ��Ȱ�� ������ ����, ��� �Һ�
		cout << "4. ����\n";			// ?? ü�� �� ���� ȸ��
		cout << "5. ĳ���� ����\n";	// ĳ���� ���� Ȯ��
		cout << "6. ��ų ����\n";		// ��ų ���� Ȯ��
		cout << "7. ���� ����\n";		// ���� ������ ���Ϸ� ����
		cout << "8. ���� ������\n";	// ���� ����
		cout << "=======================\n";
		cout << "�ൿ ���� : ";
		scanf("%d", &act);

		switch (act)
		{
		case Act::Dungeon:	// switch������ �����̳� �Ҵ��� ��, �߰�ȣ�� ����ؾ��Ѵ�!!
		{
			system("cls");
			dungeon = new Dungeon(player);
			SAFE_DELETE(dungeon);
			break;
		}
		case Act::Forge:
		{
			system("cls");
			forge = new Forge(player);
			SAFE_DELETE(forge);
			break;
		}
		case Act::Store:
		{
			system("cls");
			store = new Store(player);
			SAFE_DELETE(store);
			break;
		}
		case Act::Motel:
		{
			system("cls");
			motel = new Motel(player);
			SAFE_DELETE(motel);
			break;
		}
		case Act::CharInfo:
		{
			system("cls");
			PlayerInfo(player);
			break;
		}
		case Act::SkillInfo:
		{
			system("cls");
			SkillInfo(player);
			break;
		}
		case Act::Save:
		{
			system("cls");
			cout << "�÷����� ���� ������ �����Ͻðڽ��ϱ�?\n";
			cout << "1. Yes\t2. No(������)\n";
			cout << "���� : ";
			int select = 0;
			cin >> select;
			if (select == 1)
			{
				Save(player);
				cout << "�÷����� ������ ����Ǿ����ϴ�.";
				Sleep(1000);
			}
			system("cls");
			break;
		}
		case Act::End:
		{
			system("cls");
			cout << "�������� ���� ������ ������ϴ�.\n";
			cout << "1. Yes 2. No\n";
			cout << "���� : ";
			int select = 0;
			cin >> select;
			if (select == 1)
			{
				playing = 0;
				break;
			}
			break;
		}
		default:
			break;
		}
	}
}

void TextRPG::PlayerInfo(Player* player)
{
	cout << "=================== ĳ���� ���� ===================\n";
	cout << " Id\t: " << player->GetID() << "\n";
	cout << " Hp\t: " << player->GetHP() << " / " << player->GetPlayerMaxHp() << "\n";
	cout << " Mana\t: " << player->GetPlayerMana() << " / " << player->GetPlayerMaxMana() << "\n";
	cout << " Atk\t: " << player->GetATK() << "\n";
	cout << " Def\t: " << player->GetDEF() << "\n";
	cout << " Avoid\t: " << player->GetAVOID() << "\n";
	cout << " Level\t: " << player->GetPlayerLevel() << "\n";
	cout << " Exp\t: " << player->GetPlayerExp() << " / " << player->GetPlayerMaxExp() << "\n";
	cout << " Gold\t: " << player->GetPlayerGold() << "\n";

	cout << "\n==================== ���� ���� ====================\n";
	cout << " DungeonFloor\t: " << player->GetDungeonFloor() << "��\n";
	// �������
	cout << "\n==================== ��� ���� ====================\n";
	cout << " Weapon\t: " << player->GetPlayerWeapon() << "��, �߰� ���ݷ� : +" << player->GetPlayerWeapon() * 5 << "\n";
	cout << " Armor\t: " << player->GetPlayerArmor() << "��, �߰� ���� : +" << player->GetPlayerArmor() * 5 << "\n";
	cout << " Shoes\t: " << player->GetPlayerShoes() << "��, �߰� ȸ�Ƿ� : +" << player->GetPlayerShoes() * 2 << "%\n";
	// ���� ����������
	cout << "\n=================== ������ ���� ===================\n";
	cout << " HpPotion\t: " << player->GetPlayerHpPotion() << "��\n";
	cout << " ManaPotion\t: " << player->GetPlayerManaPotion() << "��\n";
	cout << " ReviveStone\t: " << player->GetPlayerReviveStone() << "��\n";

	cout << "\n===================================================\n";
	cout << "\n������\n";
	system("pause");
	system("cls");
}

void TextRPG::SkillInfo(Player* player)
{
	// ��ų����
	cout << "\n==================== ��ų ���� ====================\n";
	cout << "1. �ʱް˼�\n";
	cout << "\t���ݷ� : " << player->GetATK() * 2 << "\n";
	cout << "\t���� �Ҹ� : " << 15 << "\n";

	cout << "\n===================================================\n";
	cout << "\n������\n";
	system("pause");
	system("cls");
}

void TextRPG::Save(Player* player)
{
	FILE* saveFile = fopen("SaveFile.txt", "w");
	// https://moozi.tistory.com/356
//	fprintf(saveFile, "%l ", player);


//	fprintf(saveFile, "%d ", player->GetID());
//	fprintf(saveFile, "%d ", player->GetHP());
//	fprintf(saveFile, "%d ", player->GetATK());
//	fprintf(saveFile, "%d ", player->GetDEF());
//	fprintf(saveFile, "%d ", player->GetAVOID());
//	fprintf(saveFile, "%d ", player->GetPlayerMaxHp());
//	fprintf(saveFile, "%d ", player->GetPlayerMaxMana());
//	fprintf(saveFile, "%d ", player->GetPlayerMaxExp());
//	fprintf(saveFile, "%d ", player->GetPlayerLevel());
//	fprintf(saveFile, "%d ", player->GetPlayerExp());
//	fprintf(saveFile, "%d ", player->GetPlayerMana());
//	fprintf(saveFile, "%d ", player->GetPlayerGold());
//	fprintf(saveFile, "%d ", player->GetDungeonFloor());
//	fprintf(saveFile, "%d ", player->GetPlayerWeapon());
//	fprintf(saveFile, "%d ", player->GetPlayerArmor());
//	fprintf(saveFile, "%d ", player->GetPlayerShoes());
//	fprintf(saveFile, "%d ", player->GetPlayerHpPotion());
//	fprintf(saveFile, "%d ", player->GetPlayerManaPotion());
//	fprintf(saveFile, "%d\n", player->GetPlayerReviveStone());

	fclose(saveFile);
}

void TextRPG::PlayerSavedRetrieve(PlayerDesc* desc)
{
	FILE* readFile = fopen("SaveFile.txt", "r");

	if (readFile != nullptr)
	{	
	//	fscanf(readFile, "%l ", &desc);

	//	fscanf(readFile, "%d ", &desc->id);
	//	fscanf(readFile, "%d ", &desc->hp);
	//	fscanf(readFile, "%d ", &desc->atk);
	//	fscanf(readFile, "%d ", &desc->def);
	//	fscanf(readFile, "%d ", &desc->avoid);
	//	fscanf(readFile, "%d ", &desc->maxHp);
	//	fscanf(readFile, "%d ", &desc->maxMana);
	//	fscanf(readFile, "%d ", &desc->maxExp);
	//	fscanf(readFile, "%d ", &desc->level);
	//	fscanf(readFile, "%d ", &desc->exp);
	//	fscanf(readFile, "%d ", &desc->mana);
	//	fscanf(readFile, "%d ", &desc->gold);
	//	fscanf(readFile, "%d ", &desc->dungeonFloor);
	//	fscanf(readFile, "%d ", &desc->weapon);
	//	fscanf(readFile, "%d ", &desc->armor);
	//	fscanf(readFile, "%d ", &desc->shoes);
	//	fscanf(readFile, "%d ", &desc->hpPotion);
	//	fscanf(readFile, "%d ", &desc->manaPotion);
	//	fscanf(readFile, "%d ", &desc->reviveStone);

		fclose(readFile);
	}
	else
	{
		printf("Read Stream Open Error!");	// ���� ���
		Sleep(1200);
	}
}
