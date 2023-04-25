#include "Game_bord.h"
#include "head.h"

auto Game_bord::Input_key(const int input) -> bool
{
	if (input == bord[now_bord]) {
		bord[now_bord] = 0;
		now_bord++;
		return 1;
	}
	return 0;
}
auto Game_bord::PrintAll() -> void
{
	std::cout << "현재 라이프 : " << life << std::endl;
	for (int i = 0; i < time_max; i++) {
		if (time_out[i] == true)
			std::cout << "●";
		else
			std::cout << "＃";
	}
	printf("\n");
	for (int i = 0; i < now_max_bord; i++) {
		switch (bord[i])
		{
		case 0:
			printf("○");
			break;
		case 1:
			printf("←");
			break;
		case 2:
			printf("→");
			break;
		case 3:
			printf("↑");
			break;
		case 4:
			printf("↓");
			break;
		}
		printf(" ");
	}
}


auto Game_bord::REMake_bord() -> void
{
	bord.clear();
	std::random_device rd; // 시드 값으로 사용할 랜덤 장치
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(1, 4); // 1부터 4까지의 균등 분포
	std::uniform_int_distribution<int> bord_max(6, max_bord); // 무작위 키 숫자 6개에서 맥스까지

	now_max_bord = bord_max(gen);
	now_bord = 0;
	for (int i = 0; i < now_max_bord; i++) {
		bord.push_back(dist(gen));
	}
}

auto Game_bord::REMake_Time() -> void
{
	time_out.clear();
	time_out.resize(TIME_SET);
	time_out.assign(TIME_SET, true);
	time_now = TIME_SET - 1;
} 

auto Game_bord::Count_down() -> void
{
	time_out[time_now] = false;
	time_now--;
}
auto Game_bord::time_chack() -> bool
{
	return time_now == -1;
}

auto Game_bord::Life_damage() -> void
{
	life--;
	if (life <= 0) {
		printf("\n게임 종료!\n");
		exit(0);
	}
}

auto Game_bord::Now_bord_chack() -> bool 
{
	return now_bord == now_max_bord ;
}