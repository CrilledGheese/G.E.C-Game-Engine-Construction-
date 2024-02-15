#pragma once
#include <vector>
#include <HAPI_lib.h>
using namespace HAPISPACE;

class Entity;
class Graphics;

class Game
{
private:
	Graphics* m_graphics{ nullptr };
	std::vector<Entity*> entityVec;

	void levelLoad();
public:
	~Game();

	void Run();
};