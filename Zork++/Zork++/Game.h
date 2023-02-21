#pragma once
#include <string>
#include <nlohmann/json.hpp>
#include <unordered_map>
#include <map>
#include <algorithm>
#include "World.h";
#include "Player.h"
#include "Commands.h"
#include "Item.h";
#include "Directions.h";
#include "Room.h";

using json = nlohmann::json;

namespace Zork
{

    class Game
    {
    public:
        World world;
        Player player;
        bool IsRunning;
        string inputString;
        Commands::commandsEnum command;
        Directions::DirectionsEnum direction;

        void setPlayer(World jworld, Room startingLocation)
        {
            player.setPlayerInfo(jworld, startingLocation);
        }

        Player getPlayer() { return player; } //inline function

        void setWorld(World jworld) { world = jworld; }
        World getWorld() { return world; }

        Game() = default;

        Game(World jworld, Room startingLocation)
        {
            world = jworld;
            setPlayer(world, startingLocation);
        }

        void Run();
        int compare_case_insensitive(string s1, string s2);
        string LowercaseString(string inputString);
        Directions::DirectionsEnum CommandToDirection(Commands::commandsEnum command);
        void ProcessInput(string inputString);
        void ToCommand(string commandString);

    };

    void from_json(const json& j, Game& g);
    //void to_json(json& j, const Game& g);
};


