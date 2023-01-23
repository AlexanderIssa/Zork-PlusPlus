#include "Player.h"
#include "World.h"
#include "Item.h"
#include "Room.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace Zork
{
	// When deserializing a JSON, when it hits "Player" set it to the Name
	void from_json(const json& j, Player& p) {
		j.at("Player").get_to(p.Name);
	};

	void to_json(json& j, const Player& p) {
		j = json{ {"Player", p.Name} };
	};
};
