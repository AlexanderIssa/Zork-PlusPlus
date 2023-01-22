#include "Room.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace Zork
{
	void from_json(const json& j, Room& r)
	{
		j.at("Name").get_to(r.Name);
		j.at("Description").get_to(r.Description);
	};

	void to_json(json& j, const Room& r)
	{

	};
};