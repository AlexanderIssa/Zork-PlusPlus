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

        Game(Player player)
        {

        }

        string test;

        World world;
        Player player;



        //Game(World world, string startingLocation, int playerHealth)
        //{
        //    //World = world;
        //    //Player = new Player(World, startingLocation, playerHealth);
        //}
    };

    //void from_json(const json& j, Game& g) {
    //    //j.at("World").get_to(g.world);
    //    j.at("Player").get_to(g.player.Name);
    //};

    //void to_json(json& j, const Game& g) {
    //    j = json{ {"Player", g.player.Name} };
    //};

};


