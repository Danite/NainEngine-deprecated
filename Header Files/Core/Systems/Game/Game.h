#ifndef _GAME_H
#define _GAME_h

#include "System.h"


struct GameData : public SystemData {

};

class Game : public System {

public:
	Game(const GameData& data);
	virtual ~Game();
};

#endif
