#include "Player.h"

namespace Zork
{
	// When deserializing a JSON, when it hits "Player" set it to the Name
	void from_json(const json& j, Player& p) {
		//j.at("StartingLocation").get_to(CurrentRoom);
	};

	//void to_json(json& j, const Player& p) {
	//	//j = json{ {"Player", p.Name} };
	//};

	Player::Player(World world, Room startingLocation):_world(world), _currentRoom(startingLocation), CurrentRoom(_currentRoom) // constructor with 2 params
	{
	}

    void Player::Move(Directions::DirectionsEnum direction)
    {
		//CurrentRoom = CurrentRoom.Neighbors.find(direction);
		for (auto it : CurrentRoom.Neighbors)
		{
			cout << it.first << ":" << it.second.Name << "\n";
		}

        auto nextRoom = CurrentRoom.Neighbors.find(direction);

		if (nextRoom == CurrentRoom.Neighbors.end())
		{
			// There is no room for that direction
			cout << "The path is blocked!\n";
		}
		else
		{
			cout << nextRoom->first << " " << nextRoom->second.Name << "\n";
			// found the appropriate room but settin cr to second isnt the same as setting it to the room with the same name in the world
			// after setting _cr and CR to nextroom->second, seems like neighbors dont exist for nextroom->second? so stuck when move once
			_currentRoom = nextRoom->second;
			CurrentRoom = _currentRoom;
		}
        
    }

};
