#pragma once
#include "Room.h";
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace Zork
{
	class Neighbors
	{
	public:
		static map<Directions::DirectionsEnum, Room> neighborsMap;
		map<string, Room> NeighborNames;
		//NLOHMANN_DEFINE_TYPE_INTRUSIVE(Neighbors, North, South, West, East);


		
	private:

		Room North;
		Room South;
		Room East;
		Room West;

	};
	//void from_json(const json& j, Neighbors& n);
	//void to_json(json& j, const Neighbors& n);
}


