#ifndef _SYSTEM_H
#define _SYSTEM_H

#include "UObject.h"

//Emumeration
enum SystemType {
	
	Sys_Window,
	Sys_Game,
	Sys_Input,
	Sys_Graphics,
	Sys_GameTimer
};

//Structs
struct SystemData {

};

class System : public UObject {

public:
	System();
	virtual ~System();

	SystemType GetType() { return n_SystemType; }

protected:

	SystemType n_SystemType;
};

#endif
