#pragma once
#include "Item.h";
#include "Room.h";
#include <nlohmann/json.hpp>
#include <iostream>
#include <iterator>
#include <list>
#include <string>

//using namespace std;
using json = nlohmann::json;

namespace Zork
{
	class Player
	{
	public:
		Room CurrentRoom;
		string Name;
		int Moves;
		int Score;
		float Health;
		list<Item> _inventory;
	};

	void from_json(const json& j, Player& g);
	void to_json(json& j, const Player& g);
};


