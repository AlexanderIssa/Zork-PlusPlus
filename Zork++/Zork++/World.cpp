#include "Player.h"
#include "World.h"
#include "Item.h"
#include "Room.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace Zork
{
	void from_json(const json& j, World& w) {
		//j.at("world").get_to(w);
		j.at("Player").get_to(w.player.Name);
		j.at("Rooms").get_to(w.Rooms);
	};

	void to_json(json& j, const World& w) {
		j = json{ {"World", w} };
		//j = json{ {"Rooms", w._roomsByName} };
	};
};