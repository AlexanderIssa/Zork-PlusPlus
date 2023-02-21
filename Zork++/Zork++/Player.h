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
		int Moves;
		int Score;
		float Health;
		list<Item> Inventory;

		Player() = default;
		Player(World world, Room startingLocation);


		void setPlayerInfo(World world, Room startingLocation)
		{
			_world = world;
			_currentRoom = startingLocation;
			CurrentRoom = _currentRoom;
		}

	private:
		World _world;
		Room _currentRoom;
		float _health;
		int _moves, _score;
		const list<Item> _inventory; // const = readonly in C#

	};

	void from_json(const json& j, Player& p);
	//void to_json(json& j, const Player& p);
};


