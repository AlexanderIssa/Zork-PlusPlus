#pragma once
#include "Item.h";
#include "Room.h";
//#include "Player.h"; this causes identifier errors "circular identification"
#include <nlohmann/json.hpp>
#include<map>
#include<string>
#include<vector>

using json = nlohmann::json;

namespace Zork
{
	class World
	{
	public:
		vector<Room> Rooms;
		vector<Item> Items;

		Room StartingRoom;

		// map is equivalent to dictionary in C#
		map<string, Room>_roomsByName;
		map<string, Item>_itemsByName;

		World() = default;
		World(vector<Room> rooms, vector<Item> items);
	};

	void to_json(json& j, const World& w);
	void from_json(const json& j, World& w);
};