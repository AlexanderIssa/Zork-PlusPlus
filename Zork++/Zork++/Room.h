#pragma once
#include "Directions.h";
//#include "World.h";
#include <iostream>;
#include <nlohmann/json.hpp>

using json = nlohmann::json;

using namespace std;

namespace Zork
{
	class Room
	{
	public:
		string Name;
		string Description;
		map<Directions::DirectionsEnum, Room> Neighbors;
		//map<Directions::DirectionsEnum, string> NeighborNames;
		map<string, string> NeighborNames;

		//NLOHMANN_DEFINE_TYPE_INTRUSIVE(Room, Name, Description, Neighbors);
		//json j_list_of_pairs = json::array({ {"one", 1}, {"two", 2} });
		//Room() = default;
		Directions::DirectionsEnum ToDirection(string key);
		Room ToRoom(string key, vector<Room> rv);

		void UpdateNeighbors(map<string, Room> RoomsByName) //  //Zork::World world
		{
			for(auto neighborName : NeighborNames)
			{
				//_neighbors.insert(neighborName.first, world.RoomsByName[neighborName.second]);
				//_neighbors[neighborName.first] = RoomsByName[neighborName.second];

				directionKey = ToDirection(neighborName.first);
				_neighbors[directionKey] = RoomsByName[neighborName.second];
			}

			//NeighborNames = null;
			Neighbors = _neighbors;
			//cout << Name << ":\n";
			//for(auto neighborName : NeighborNames)
			//{
			//	cout << "{" << neighborName.first << ": " << neighborName.second << "}\n";
			//	//_neighbors.insert(neighborName.first, world.RoomsByName[neighborName.second]);
			//	directionKey = ToDirection(neighborName.first);
			//	_neighbors[directionKey] = RoomsByName[neighborName.second];
			//	//cout << "RoomsByName Room: " << RoomsByName[neighborName.second].Name << "\n";
			//}

			//Neighbors = _neighbors;

			for (auto neighbor: Neighbors)
			{
				cout << neighbor.first << " " << neighbor.second.Name << "\n";
			}


				//for (auto pair : NeighborNames) {
				//	cout << "{" << pair.first << ": " << pair.second << "}\n";
				//	directionKey = ToDirection(pair.first);

				//	Neighbors[directionKey] = ToRoom(pair.second, rv);
				//}
		};

		void UpdateNeighbors2(map<string, Room> RoomsByName, vector<Room> wRooms) //  //Zork::World world
		{
			for (auto neighborName : NeighborNames)
			{
				directionKey = ToDirection(neighborName.first);
				//_neighbors[directionKey] = RoomsByName[neighborName.second];
				_neighbors[directionKey] = wRooms[2]; // the neighbor's neighbor does not exist


			}

			//NeighborNames = null;
			Neighbors = _neighbors;

			for (auto neighbor : Neighbors)
			{
				cout << neighbor.first << " " << neighbor.second.Name << "\n";
			}
		};

		Room()
		{
		}

	private:
		//map<string, Room> NeighborNames;
		Directions::DirectionsEnum directionKey;
		map<Directions::DirectionsEnum, Room> _neighbors;
	};

	void from_json(const json& j, Room& r);
	//void to_json(json& j, const Room& r);
};
