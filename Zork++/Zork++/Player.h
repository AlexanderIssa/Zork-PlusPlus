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


		void setPlayerInfo(World world, string startingLocation)
		{
			//cout << "STARTING LOCATION: " << startingLocation << "\n";
			_world = world;

			// for some reason room gets neighbors but the specific room in _world.Rooms never gets neighbors and CurrentRoom is the only room with neighbors at the end of this function
			for (auto room : _world.Rooms)
			{
				cout << room.Name << ": " << room.Description << "\n";
				room.UpdateNeighbors(_world.RoomsByName);

				if (room.Name == startingLocation)
				{
					_currentRoom = room;
				}
			}

			CurrentRoom = _currentRoom;
		}


		void Move(Directions::DirectionsEnum direction);

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


