#include "Player.h"
#include "head.h"

auto Player::input_key() -> int
{
    if (GetAsyncKeyState(VK_LEFT))
        return 1;
    else if (GetAsyncKeyState(VK_RIGHT))
        return 2;
    else if (GetAsyncKeyState(VK_UP))
        return 3;
    else if (GetAsyncKeyState(VK_DOWN))
        return 4;
}