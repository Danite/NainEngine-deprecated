#ifndef _IOSTREAM_H
#define _IOSTREAM_H

//C runtime header files.
#ifndef _IOSTREAM_
	#include <iostream>
#endif


#ifdef UNICODE
	#define tcout wcout
	#define tcin wcin
#else
	#define tcout cout
	#define tcin cin
#endif

#endif
