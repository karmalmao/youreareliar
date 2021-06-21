
#include "EntityDisplayApp.h"

#include "raylib.h"
#include "FixWindows.h"

EntityDisplayApp::EntityDisplayApp(int screenWidth, int screenHeight) :
	Application(screenWidth, screenHeight, "Display App")
{

}
EntityDisplayApp::~EntityDisplayApp()

{

}

void EntityDisplayApp::Startup()
{
	m_fileHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, m_sharedPath);
	m_data = (Entity*)MapViewOfFile(m_fileHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(Entity) * ENTITY_COUNT);
}

void EntityDisplayApp::Shutdown()
{
	UnmapViewOfFile(m_data);

	CloseHandle(m_fileHandle);
}

void EntityDisplayApp::Update(float deltaTime)
{
	Startup();

	m_entities.clear();
	if (m_data != nullptr)
	{
		for (int i = 0; i < ENTITY_COUNT; i++)
		{
			m_entities.push_back(m_data[i]);
		}
	}
	//todo clear m_entities
	//TODO: read m_data and update m_entities 


	Shutdown();
}

void EntityDisplayApp::Draw()
{
	BeginDrawing();

	ClearBackground(RAYWHITE);

	if (m_fileHandle != nullptr)
	{
		// draw entities
		for (auto& entity : m_entities)
		{

			DrawRectanglePro(
				Rectangle{ entity.x, entity.y, entity.size, entity.size }, // rectangle
				Vector2{ entity.size / 2, entity.size / 2 }, // origin
				entity.rotation,
				Color{ entity.r, entity.g, entity.b, 255 });
		}
	}
	else
	{
		DrawText("whats something funny i can type here hahahahahahahahahahahahah", 250, 250, 32, LIGHTGRAY);
		DrawText("also open editor", 250, 215, 32, LIGHTGRAY);
	}

	// output some text, uses the last used colour
	DrawText("Press ESC to quit", 630, 15, 12, LIGHTGRAY);

	EndDrawing();
}