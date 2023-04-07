#include "World.h"

namespace Zork
{
	// When deserializing a JSON, when it hits certain strings assign that data to certain types within the World class
	void from_json(const json& j, World& w) {
		j.at("Rooms").get_to(w.Rooms);
		//for (auto room : w.Rooms)
		//{
		//	room.UpdateNeighbors();
		//}
	};

	//void to_json(json& j, const World& w) {
	//	j = json{ {"World", w} };
	//	j = json{ {"Rooms", w.Rooms} };
	//};

	void World::setRooms()
	{
		// this is basically for each from C# "for (data_type  variable_name : container_type)"
		for (auto room : Rooms)
		{
			_roomsByName[room.Name] = room;

		}

		RoomsByName = _roomsByName;
		//cout << "RoomsByName: \n";
		//for (auto room2 : RoomsByName)
		//{
		//	cout << room2.first << " " << room2.second.Name << "\n";
		//}
	}

	void World::UpdateRoomNeighbors()
	{
		for (int i = 0; i < Rooms.size(); i++)
		{
			Rooms[i].UpdateNeighbors(RoomsByName);
		}
		// RoomsByName never gets neighbors yet we use that map to assign neighbors
		// In Zork C# RoomsByName somehow gets it's rooms to also start updating and gives them neighbors
		// it seems that all rooms in Rooms.cs in C# are connected in the world, I might be creating seperate instances of rooms here

		for (int i = 0; i < Rooms.size(); i++)
		{
			Rooms[i].UpdateNeighbors2(RoomsByName, Rooms);
		}

		// this function does not update the neighbors of THIS world's rooms, it only updates room var's neighbors, WHY?? 
		//for (Room room : this->Rooms)
		//{
		//	room.UpdateNeighbors(this->RoomsByName);
		//}
	}

	World::World(vector<Room> rooms)
	{
		Rooms = rooms;

		// this is basically for each from C# "for (data_type  variable_name : container_type)"
		for (auto room : Rooms)
		{
			_roomsByName[room.Name] = room;

		}
	}

	World::World(vector<Room> rooms, vector<Item> items)
	{
		Rooms = rooms;
		Items = items;

		// this is basically for each from C# "for (data_type  variable_name : container_type)"
		for (auto room : Rooms)
		{
			_roomsByName[room.Name] = room;

		}

		for (auto item : Items)
		{
			_itemsByName[item.Name] = item;
		}
	}
};