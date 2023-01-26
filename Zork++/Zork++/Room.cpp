#include "Room.h"

namespace Zork
{
	// When being deserialized, assign certain data from the JSON file into specific variables within the Room class
	void from_json(const json& j, Room& r)
	{
		j.at("Name").get_to(r.Name);
		j.at("Description").get_to(r.Description);
	};

	void to_json(json& j, const Room& r)
	{
		j = json{ {"Name", r.Name} };
		j = json{ {"Description", r.Description} };
	};
};