#include "Player.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace Zork
{
	void from_json(const json& j, Player& g) {
		//j.at("World").get_to(g.world);
		j.at("Player").get_to(g.Name);
	};

	void to_json(json& j, const Player& g) {
		j = json{ {"Player", g.Name} };
	};
};
