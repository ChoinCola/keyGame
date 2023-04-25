#include "head.h"

int main()
{
	Game_bord bord;
	Player user;

	int FPS_count = 0;
	bord.REMake_bord();
	bord.REMake_Time();

	while (true) {
		bord.Input_key(user.input_key());
		system("cls");
		bord.PrintAll();
		FPS_count++;

		if (FPS_count == 10) {
			bord.Count_down();
			FPS_count = 0;
		}
		if (bord.time_chack() || bord.Now_bord_chack()) {
			bool countzero = bord.time_chack();
			bord.REMake_bord();
			bord.REMake_Time();

			if(countzero)
				bord.Life_damage();
		}
		Sleep(10);
	}
	return 0;
}