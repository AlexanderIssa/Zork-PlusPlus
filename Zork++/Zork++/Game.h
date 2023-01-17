#pragma once
#include "World.h";
#include "Player.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

    class Game
    {
    public:
        Game() = default;

        void from_json(const json& j, Game& g) {
            //j.at("World").get_to(g.world);
            j.at("Player").get_to(g.player.Name);
        }

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
    }

