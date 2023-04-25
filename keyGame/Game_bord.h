#pragma once
#include "head.h"

class Game_bord
{

	int life = MAX_LIFE;
	int max_bord = BORD_MAX_SIZE;
	int now_bord = 0;
	int now_max_bord;

	std::vector<bool> time_out;
	int time_max = TIME_SET;
	int time_now;
	std::vector<int> bord;

public:

	auto REMake_bord() -> void;
	auto Input_key(const int input) -> bool;
	auto PrintAll() -> void;
	auto REMake_Time() -> void;
	auto Count_down() -> void;
	auto time_chack() -> bool;
	auto Now_bord_chack() -> bool;
	auto Life_damage() -> void;
};

