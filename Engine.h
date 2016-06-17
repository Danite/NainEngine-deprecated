#ifndef _ENGINE_H
#define _ENGINE_H

//C runtime header files
#ifndef _WINDOWS_
	#include <Windows.h>
#endif

#ifndef _MAP_
	#include <map>
#endif

#ifndef _CONTEXT_H
	#include "context.h"
#endif


//Forward declaration
enum SystemType;

class System;
class Game;

//Enumeration

enum EngineState {

	Invalid,
	Constructing,
	Initializing,
	Runnig,
	ShuttingDown,
	Destroying

};

class Engine
{
public:
	Engine();
	~Engine();

	int RunLoop();

	//void* operator new(size_t size);
	//void operator delete(void* pdelete);

	static EngineState GetEngineState() { return m_EngineState;  }

private:

	int Initialize();
	int Draw(Context& context);
	int Update(Context& context);
	int ShutDown();

	//Add the core system to the engine
	int AddSystem(System* psys);
	//Retrive the core system from the engine
	template<typename T>
	T* GetSystem(SystemType systype) {

		T* psys = static_cast<T*>(m_mapSystems[systype]);
		if (!psys) {
			
			//Logger::Log("System is not valid");
			return nullptr;
		}
		
		return psys;
	}

	//Create the game instance
	Game* CreateGame();

	std::map<SystemType, System*> m_mapSystems;
	static EngineState m_EngineState;
};

#endif