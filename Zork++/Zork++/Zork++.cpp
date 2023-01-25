// Zork++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>
#include <string>
#include "Game.h";
#include "Item.h";
#include "Room.h";
#include "World.h";
#include "Player.h";

using namespace std;
using json = nlohmann::json;

    int main()
    {

        //To create a json object by reading a JSON file:
        ifstream gameFile("Game.json");
        json data = json::parse(gameFile);

        //Zork::Game game;

        // Convert json data into a Game type var called game
        Zork::Game jgame = data.get<Zork::Game>();
        //Zork::Game game(jgame.world, jgame.player);
        Zork::Game game(jgame.player, jgame.world, jgame.player.CurrentRoom);
        //game.setWorld(jgame.world);
        //game.setPlayer(jgame.player);
        ////List of Rooms in the world
        //for (Zork::Room i : game.world.Rooms)
        //{
        //    cout << i.Name << "\n";
        //    cout << i.Description << "\n";
        //}

        game.Run();
        while (game.IsRunning)
        {
            cout << "> ";
            cin >> game.inputString;
            game.RunProgram(game.inputString);
        }

        cout << "Thank you for playing!";
        return 0;
    };