#pragma once
#include "Commands.h";
namespace Zork
{
	class Directions
	{
	public:
		enum directions
		{
			North = Commands::commands::North,
			South = Commands::commands::South,
			East = Commands::commands::East,
			West = Commands::commands::West
		};
	};
}


