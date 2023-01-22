#pragma once
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
	};

	void from_json(const json& j, Room& r);
	void to_json(json& j, const Room& r);
};
