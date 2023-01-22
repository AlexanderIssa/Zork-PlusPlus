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

//namespace Zork
//{
    int main()
    {

        //To create a json object by reading a JSON file:
        ifstream gameFile("Game.json");
        json data = json::parse(gameFile);

        //Zork::Game game;
        Zork::Player player;

        // figure out how to convert json data into a Game class data
        //game = data.get<Zork::Game>();
        player = data.get<Zork::Player>();

        cout << player.Name << "\n";

        cout << "Welcome to Zork! Insert you name below:\n";

        cin >> player.Name;

        Room TestRoom;
        TestRoom.Name = "Test Room";
        TestRoom.Description = "This is a Test Room";


        player.CurrentRoom = TestRoom;

        cout << "Player: " << player.Name << "\n" << "Current Room Info: " << player.CurrentRoom.Name << "\n" << player.CurrentRoom.Description << "\n";

        //game.Run();
        return 0;
    };
//};



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
