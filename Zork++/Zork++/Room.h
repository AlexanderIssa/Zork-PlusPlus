#pragma once
#include "Directions.h";
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
		map<string, string> NeighborNames;

		//Neighbors neighbors;
		//NLOHMANN_DEFINE_TYPE_INTRUSIVE(Room, Name, Description, Neighbors);
		//json j_list_of_pairs = json::array({ {"one", 1}, {"two", 2} });
		//Room() = default;
		Directions::DirectionsEnum ToDirection(string key);
		Room ToRoom(string key, vector<Room> rv);
		void UpdateNeighbors(vector<Room> rv)
		{
			for (auto pair : NeighborNames) {
				cout << "{" << pair.first << ": " << pair.second << "}\n";
				directionKey = ToDirection(pair.first);
				Room room = ToRoom(pair.second, rv);
				Neighbors[directionKey] = room;
			}


		};

		Room()
		{
		}

	private:
		//map<string, Room> NeighborNames;
		Directions::DirectionsEnum directionKey;
	};

	void from_json(const json& j, Room& r);
	//void to_json(json& j, const Room& r);
};
