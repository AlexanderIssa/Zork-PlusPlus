#include "Room.h"

namespace Zork
{
	Directions::DirectionsEnum Room::ToDirection(string key)
	{
		Directions::DirectionsEnum directionP = Directions::DirectionsEnum::Unknown;
		static unordered_map<string, Directions::DirectionsEnum> directionsMap = { {"North", Directions::DirectionsEnum::North}, {"South", Directions::DirectionsEnum::South}, {"East", Directions::DirectionsEnum::East}, {"West", Directions::DirectionsEnum::West}};
		auto it = directionsMap.find(key); // use commandString as a key in the commandsMap and set "it" as the value returned
		if (it != directionsMap.end()) {
			// if "it" is not at the end of the map then set passed command as the stored value
			directionP = it->second;
		}
		else { directionP = Directions::DirectionsEnum::Unknown; }

		return directionP;
	}

	Room Room::ToRoom(string key, vector<Room> rv)
	{
		Room roomToSend;
		for (auto room : rv)
		{
			if (room.Name == key)
			{
				roomToSend = room;
			}
		}
		return roomToSend;
	}

	//// When being deserialized, assign certain data from the JSON file into specific variables within the Room class
	void from_json(const json& j, Room& r)
	{
		Directions::DirectionsEnum directionKey;
		j.at("Name").get_to(r.Name);
		j.at("Description").get_to(r.Description);
		j.at("/NeighborNames"_json_pointer).get_to(r.NeighborNames);
		//UpdateNeighbors();
		/*for (auto const& pair : r.NeighborNames) {
			cout << "{" << pair.first << ": " << pair.second << "}\n";
			directionKey = ToDirection(pair.first);

			Neighbors.insert(directionKey, );

		}*/
	};

	//void to_json(json& j, const Room& r)
	//{
	//	j = json{ {"Name", r.Name} };
	//	j = json{ {"Description", r.Description} };
	//};

};