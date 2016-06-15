#include "Engine.h"

//Additional include files
#include "System.h"
#include "Game.h"

#ifndef _DELETEMACRO_H
	#include "deletemacros.h"
#endif
#ifndef _STRING_H
	#include "string.h"
#endif

EngineState Engine::n_EngineState = EngineState::Invalid;

Engine::Engine() {

	n_EngineState = EngineState::Constructing;
}


Engine::~Engine() {

	n_EngineState = EngineState::Destroying;
}

int Engine::RunLoop() {

	Context context;

	if (!this->Initialize())
		return 0;

	srand(GetTickCount());

	MSG msg = {};

	n_EngineState = EngineState::Runnig;

	while (msg.message != WM_QUIT && n_EngineState == EngineState::Runnig) {

		//CheckResize();

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		this->Update(context);
		this->Draw(context);
	}

	//Logger::Log("Ending program");
	//Logger::WriteLogFile();

	if (!this->ShutDown())
		return 0;

	return msg.wParam;
}

int Engine::Initialize() {

	n_EngineState = EngineState::Initializing;

	Game* game = CreateGame();

	if (!game)
		return false;

	//Add some systems


	return true;
}

int Engine::Draw(const Context& context) {
	
	return true;
}
int Engine::Update(const Context& context) {

	return true;
}
int Engine::ShutDown() {

	n_EngineState = EngineState::ShuttingDown;

	for (std::pair<SystemType, System*> psys : n_mapSystems) {

		//if (!psys.second->ShutDown()) {

			//Logger::Log("Faild to shutdown system " + psys->GetSystemType());
			//continue;
		//}

		SafeDelete(psys.second);
	}

	return true;
}

int Engine::AddSystem(System* psys) {

	auto element = n_mapSystems.insert(std::make_pair(psys->GetType(), psys));
	if (element.second)
		return true;

	return false;
}

Game* Engine::CreateGame() {

	if (!AddSystem(new Game(GameData())))
		return nullptr;

	Game* game = GetSystem<Game>(SystemType::Sys_Game);

	if (!game)
		return nullptr;

	//if (!game->Initialize())
	//	return nullptr;

	return game;
}