#include "World.h"

namespace Zork
{
	// When deserializing a JSON, when it hits certain strings assign that data to certain types within the World class
	void from_json(const json& j, World& w) {
		j.at("Rooms").get_to(w.Rooms);
	};

	//void to_json(json& j, const World& w) {
	//	j = json{ {"World", w} };
	//	j = json{ {"Rooms", w.Rooms} };
	//};

	World::World(vector<Room> rooms, vector<Item> items)
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