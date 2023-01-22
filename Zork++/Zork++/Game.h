#pragma once
#include "World.h";
#include "Player.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace Zork
{

    class Game
    {
    public:
        Game() = default;

        World world;
        Player player;

        Game(Player player)
        {

        }


        //Game(World world, string startingLocation, int playerHealth)
        //{
        //    //World = world;
        //    //Player = new Player(World, startingLocation, playerHealth);
        //}
    };

    void Run();

    void from_json(const json& j, Game& g);
    void to_json(json& j, const Game& g);
};


