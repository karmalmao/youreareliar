#pragma once

#include "Application.h"
#include "Entity.h"
#include <vector>
#include "raylib.h"
#include "FixWindows.h"

class EntityEditorApp : public Application
{
public:
	EntityEditorApp(int screenWidth, int screenHeight);
	virtual ~EntityEditorApp();

	void Startup();
	void Shutdown();

	HANDLE m_fileHandle;

	Entity* m_data;

	void Update(float deltaTime);
	void Draw();

protected:

	// define a block of entities that should be shared

	Entity m_entities[ENTITY_COUNT];
};