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
		static map<Directions::DirectionsEnum, Room> Neighbors;
		map<string, Room> NeighborNames;
		Room() = default;

	private:
		//map<string, Room> NeighborNames;
	};

	void from_json(const json& j, Room& r);
	void to_json(json& j, const Room& r);

	//	// When being deserialized, assign certain data from the JSON file into specific variables within the Room class
	//void from_json(const json& j, Room& r)
	//{
	//	j.at("Name").get_to(r.Name);
	//	j.at("Description").get_to(r.Description);
	//	//j.at("NeighborNames").get_to(r.NeighborNames);
	//};

	//void to_json(json& j, const Room& r)
	//{
	//	j = json{ {"Name", r.Name} };
	//	j = json{ {"Description", r.Description} };
	//};
};
