/*
	HAPI Start
	----------
	This solution contains an already set up HAPI project and this main file
	
	The directory structure and main files are:

	HAPI_Start - contains the Visual Studio solution file (.sln)
		HAPI_Start - contains the Visual Studio HAPI_APP project file (.vcxproj) and source code
			HAPI - the directory with all the HAPI library files
			Data - a place to put your data files with a few sample ones provided

	Additionally in the top directory there is a batch file for creating a redistributable Demo folder

	For help using HAPI please see the Reference folder in the HAPI sub-directory
*/

// Include the HAPI header to get access to all of HAPIs interfaces
#include <HAPI_lib.h>
#include "Graphics.h"
#include "Sprite.h"
#include "Game.h"

// HAPI itself is wrapped in the HAPISPACE namespace
using namespace HAPISPACE;

// Every HAPI program has a HAPI_Main as an entry point
// When this function exits the program will close down

void HAPI_Main()
{
	Game* GameSystem = new Game;
	GameSystem->Run();

	delete GameSystem;
	HAPI.SetShowFPS(true);
}














	//int width{ 1024 };
	//int height{ 768 };
	//HAPI_TColour c{ 100, 100, 255 };

	//BYTE* screen = HAPI.GetScreenPointer();

	//Graphics GraphicsClass;
	//if (!GraphicsClass.Initialise(width, height))
	//		return;

	////BYTE* Texture{ nullptr };
	////int tWidth;
	////int tHeight;

	////if (!HAPI.LoadTexture("Data/DisplayPhoto.tga", &Texture, tWidth, tHeight))
	////{
	////	HAPI.UserMessage("Data sucks", "Data sucks good");
	////	return;
	////}

	//if (!GraphicsClass.CreateSprite("Data/DisplayPhoto.tga", "Keith"))
	//{
	//	HAPI.UserMessage("Data sucks", "Data sucks good");
	//	return;
	//}

	//if (!GraphicsClass.CreateSprite("Data/alphaThing.tga", "Alph"))
	//{
	//	HAPI.UserMessage("Data sucks", "Data sucks good");
	//	return;
	//}

	//if (!GraphicsClass.CreateSprite("Data/keithlazer.png", "KeithL"))
	//{
	//	HAPI.UserMessage("Data sucks", "Data sucks good");
	//	return;
	//}

	//if (!GraphicsClass.CreateSprite("Data/playerSprite.tga", "Player"))
	//{
	//	HAPI.UserMessage("Data sucks", "Data sucks good");
	//	return;
	//}

	//int x{ 450 };
	//int y{ 260 };

	//while (HAPI.Update())
	//{
	//	GraphicsClass.clearScreen();
	//	GraphicsClass.DrawSprite("Alph", x, y);

	//	//for (int x = 0; x < 1000; x++)
	//	//{
	//	//	GraphicsClass.DrawSprite("Alph", rand() % width, rand() % height);
	//	//}

	//	GraphicsClass.DrawSprite("Keith", -100, 30);
	//	GraphicsClass.DrawSprite("KeithL", 700, 300);
	//	GraphicsClass.DrawSprite("Player", 250, -45);

	//	const HAPI_TControllerData& contData{ HAPI.GetControllerData(0) };
	//	const HAPI_TKeyboardData& keyData{ HAPI.GetKeyboardData() };

	//	if (contData.digitalButtons[HK_DIGITAL_DPAD_UP] || keyData.scanCode['W'])
	//	{
	//		y--;
	//	}

	//	if (contData.digitalButtons[HK_DIGITAL_DPAD_DOWN] || keyData.scanCode['S'])
	//	{
	//		y++;
	//	}

	//	if (contData.digitalButtons[HK_DIGITAL_DPAD_LEFT] || keyData.scanCode['A'])
	//	{
	//		x--;
	//	}

	//	if (contData.digitalButtons[HK_DIGITAL_DPAD_RIGHT] || keyData.scanCode['D'])
	//	{
	//		x++;
	//	}

	//	if ((x <= 500 && y <= 300) && (x >= 300 && y >= 100))
	//	{
	//		HAPI.SetControllerRumble(0, 65535, 65535);
	//	}
	//	else
	//	{
	//		HAPI.SetControllerRumble(0, 0, 0);
	//	}

	//	//if (contData.digitalButtons[HK_DIGITAL_LEFT_THUMB])
	//	//{
	//	//	GraphicsClass.DrawSprite("KeithL", x, y);
	//	//}
	//	//else
	//	//{
	//	//	GraphicsClass.DrawSprite("Keith", x, y);
	//	//}

	//	//for (int offset = 0; offset < 1024 * 768 * 4; offset += 4)
	//	//{
	//	//	c = HAPI_TColour(255, 200, 255);
	//	//	memcpy(screen + offset, &c, 1024);
	//	//}

	//	//memset(screen, 0, width * height * 4);

	//	//int screenOffset{ (x + y * width) * 4 };

	//	//int textOffset{ 0 };

	//	//for (int y = 0; y < tHeight; y++)
	//	//{
	//	//	for (int x = 0; x < tWidth; x++)
	//	//	{
	//	//		memcpy(screen + screenOffset, Texture + textOffset, 4);
	//	//		textOffset += 4;
	//	//		screenOffset += 4;
	//	//	}
	//	//	screenOffset += (width - tWidth) * 4;
	//	//}
	//}
