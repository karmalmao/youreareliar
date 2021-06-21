#pragma once
#include <vector>
#include "Application.h"
#include "Entity.h"
#include "raygui.h"
#include "FixWindows.h"

class EntityDisplayApp : public Application
{
public:

	EntityDisplayApp(int screenWidth, int screenHeight);
	virtual ~EntityDisplayApp();

	virtual void Startup();
	virtual void Shutdown();

	HANDLE m_fileHandle;

	Entity* m_data;

	virtual void Update(float deltaTime);
	virtual void Draw();

protected:

	// an array of an unknown number of entities
	std::vector<Entity> m_entities;
};

