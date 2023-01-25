#pragma once
#include "World.h";
#include "Player.h"
#include "Commands.h"
#include <string>
#include <nlohmann/json.hpp>

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
        //Commands::commandsEnum gCommand = Commands::commandsEnum::Unknown;
        enum gCommand
        {
            Quit,
            Unknown,
            Look
        };
        gCommand command;

        void setPlayer(Player jplayer, World jworld, Room startingLocation)
        {
            player = jplayer;
            player.setPlayerInfo(jworld, startingLocation);
        }
        Player getPlayer()
        {
            return player;
        }

        void setWorld(World jworld)
        {
            world = jworld;
        }
        World getWorld()
        {
            return world;
        }

        Game() = default;

        Game(Player jplayer, World jworld, Room startingLocation)
        {
            world = jworld;
            setPlayer(jplayer, world, startingLocation);
        }

        void Run();
        int compare_case_insensitive(string s1, string s2);
        void RunProgram(string inputString);
        void ToCommand(string commandString);

    };

    void from_json(const json& j, Game& g);
    void to_json(json& j, const Game& g);
};


