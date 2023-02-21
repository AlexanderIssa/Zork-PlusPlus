#include "Player.h"

namespace Zork
{
	// When deserializing a JSON, when it hits "Player" set it to the Name
	void from_json(const json& j, Player& p) {
		//j.at("Player").get_to(p.Name);
	};

	//void to_json(json& j, const Player& p) {
	//	//j = json{ {"Player", p.Name} };
	//};

	Player::Player(World world, Room startingLocation):_world(world), _currentRoom(startingLocation), CurrentRoom(_currentRoom) // constructor with 2 params
	{
	}

};
