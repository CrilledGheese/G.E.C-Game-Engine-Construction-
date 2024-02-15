#include "Game.h"
#include "Enemy.h"
#include "Player.h"
#include "Graphics.h"
#include "Entity.h"

void Game::levelLoad()
{
	HAPI.SetShowFPS(true);
	//load sprites through graphics
	//create world entities, tell them which sprites to use
	m_graphics->CreateSprite("Data/DisplayPhoto.tga", "Player");

	Player* newPlayer = new Player();
	entityVec.push_back(newPlayer);

	Enemy* newEnemy = new Enemy();
	entityVec.push_back(newEnemy);
}

void Game::Run()
{
	m_graphics = new Graphics();
	if (!m_graphics->Initialise(1024, 768))
	{
		delete m_graphics;
		return;
	}

	levelLoad();

	while (HAPI.Update())
	{
		m_graphics->clearScreen();

		for (Entity* entity : entityVec)
		{
			entity->Update();
		}

		for (Entity* entity : entityVec)
		{
			entity->Render(m_graphics);
		}
	}
}

Game::~Game()
{
	for (auto& p : entityVec)
		delete p;

	delete m_graphics;
}