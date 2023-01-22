#pragma once
#include "Item.h";
#include "Room.h";
#include "Player.h";
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
		//Room Rooms[]
		//Item Items[];

		vector<Room> Rooms;
		vector<Item> Items;
		Player player;
		// map is equivalent to dictionary in C#
		map<string, Room>_roomsByName;
		map<string, Item>_itemsByName;

		World() = default;
		World(vector<Room> rooms, vector<Item> items)
		{
			Rooms = rooms;
			Items = items;

			// this is basically for each from C# "for (data_type  variable_name : container_type)"
			for (auto room : rooms)
			{
				_roomsByName[room.Name] = room;

			}

			for (auto item : items)
			{
				_itemsByName[item.Name] = item;
			}
		}
	};

	void to_json(json& j, const World& w);
	void from_json(const json& j, World& w);
};