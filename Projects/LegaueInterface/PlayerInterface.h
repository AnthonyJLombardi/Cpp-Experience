#ifndef _PLAYER_INTERFACE_H_
#define _PLAYER_INTERFACE_H_

#include "Player.h"
#include <limits>

#ifndef _CLEAR_
#define _CLEAR_
const char clear_command[] = "cls"; // for Windows
//const char clear_command[] = "clear"; // for Linux and possibly Mac's
#endif 

class PlayerInterface 
{

public:
	Player run();
	PlayerInterface(int y) : player_(), season_year_(y) {}
	PlayerInterface(const Player & p, int y) : player_(p), season_year_(y) {}

private:
	Player player_;
	int season_year_;
	std::string error_message_;
	
	void display_();
    void execute_command_(int command, bool & done, bool & save);
};

#endif
