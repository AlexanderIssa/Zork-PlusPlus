#pragma once
#include "World.h";
#include "Item.h";
#include "Room.h";
#include <nlohmann/json.hpp>
#include <iostream>
#include <string>

using json = nlohmann::json;

namespace Zork
{
	class Player
	{
	public:
		Room CurrentRoom;
		static World pWorld;
		string Name;
		int Moves;
		int Score;
		float Health;
		list<Item> _inventory;

		Player() = default;
		/*Player(World world, Room startingLocation)
		{
			_world = world;
			_currentRoom = startingLocation;
			CurrentRoom = _currentRoom;
		}*/

		void setPlayerInfo(World world, Room startingLocation)
		{
			_world = world;
			_currentRoom = startingLocation;
		}

	private:
		World _world;
		Room _currentRoom;
	};

	void from_json(const json& j, Player& p);
	void to_json(json& j, const Player& p);
};


