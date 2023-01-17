#pragma once
#include "Item.h";
#include "Room.h";
#include<map>
#include<string>

class World
{
	public:
			
		Room Rooms[];
		Item Items[];
		map<string, Room>_roomsByName;

		int test()
		{
			for each (Room room in rooms)
			{

			}
			_roomsByName[room.name] = room;
			return 0;
		}
};