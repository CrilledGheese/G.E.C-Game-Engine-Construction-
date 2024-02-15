#include "Player.h"
#include "HAPI_lib.h"

using namespace HAPISPACE;

void Player::Update()
{

	const HAPI_TControllerData& contData{ HAPI.GetControllerData(0) };
	const HAPI_TKeyboardData& keyBData{ HAPI.GetKeyboardData() };

	if (keyBData.scanCode['W'] || contData.digitalButtons[HK_DIGITAL_DPAD_UP]) {

		y--;
	}
	if (keyBData.scanCode['A'] || contData.digitalButtons[HK_DIGITAL_DPAD_LEFT]) {

		x--;

	}
	if (keyBData.scanCode['S'] || contData.digitalButtons[HK_DIGITAL_DPAD_DOWN]) {

		y++;

	}
	if (keyBData.scanCode['D'] || contData.digitalButtons[HK_DIGITAL_DPAD_RIGHT]) {

		x++;

	}

	if ((x <= 500 && y <= 300) && (x >= 300 && y >= 100))
	{
		HAPI.SetControllerRumble(0, 65535, 65535);
	}
	else
	{
		HAPI.SetControllerRumble(0, 0, 0);
	}
}

void Player::getSpriteName(std::string name)
{
	spriteName = name;
}