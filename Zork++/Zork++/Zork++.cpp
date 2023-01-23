// Zork++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>
#include <string>
#include "Game.h";
#include "Item.h";
#include "Room.h";
#include "Player.h";

using namespace std;
using json = nlohmann::json;

    int main()
    {

        //To create a json object by reading a JSON file:
        ifstream gameFile("Game.json");
        json data = json::parse(gameFile);

        Zork::Game game;
        /*Zork::Player player;
        Zork::World world;*/

        // Convert json data into a Game type var called game
        game = data.get<Zork::Game>();

        // List of Rooms in the world
        //for (Zork::Room i : game.world.Rooms)
        //{
        //    cout << i.Name << "\n";
        //    cout << i.Description << "\n";
        //}

        game.Run(game);
        while (game.IsRunning)
        {
            cout << "> ";
            cin >> game.inputString;
            game.RunProgram(game.inputString);
        }

        cout << "Thank you for playing!";
        return 0;
    };