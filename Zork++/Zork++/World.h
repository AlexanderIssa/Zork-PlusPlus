#pragma once
#include "Item.h";
#include "Room.h";
#include<map>
#include<string>
#include<vector>

class World
{
	public:
		//Room Rooms[]
		//Item Items[];

		vector<Room> Rooms;
		vector<Item> Items;

		// map is equivalent to dictionary in C#
		map<string, Room>_roomsByName;
		map<string, Item>_itemsByName;

		World() = default;
		World (vector<Room> rooms, vector<Item> items)
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