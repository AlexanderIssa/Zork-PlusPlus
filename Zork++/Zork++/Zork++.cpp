// Zork++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Game.h";
#include "Item.h";
#include "Room.h";
#include "Player.h";
#include <nlohmann/json.hpp>
#include <fstream>


using namespace std;
using json = nlohmann::json;


    int main()
    {
        //const string defaultRoomsFilename = "Content\Game.json";
        //Game game = JsonConvert.DeserializeObject<Game>(File.ReadAllText(gameFilename));

        // json conversion example:
    //    struct person {
    //        std::string name;
    //        std::string address;
    //        int age;
    //    };

    //    person p = { "Ned Flanders", "744 Evergreen Terrace", 60 };

    //    json j;
    //    j["name"] = p.name;
    //    j["address"] = p.address;
    //    j["age"] = p.age;

    //    person p2{
    //j["name"].get<string>(),
    //j["address"].get<string>(),
    //j["age"].get<int>()
    //    };

    //    cout << p2.name;

        //To create a json object by reading a JSON file:
        ifstream gameFile("Game.json");
        json data = json::parse(gameFile);
        Game game;
        Game Game2;
        Game2 = Game::from_json(data, game);
        //data = (Game)data;
        //Game game;
        //json data2 = game;

        //// figure out how to convert json data into a Game class data
        //auto game = data.get<Zork::Game>();

        cout << "Welcome to Zork! Insert you name below:\n";

        Player player;
        cin >> player.Name;

        //list<int> _test = { 12, 5, 10, 9 };

        //    for (int x : _test)
        //    {
        //        cout << x << '\n';
        //    }

        Room TestRoom;
        TestRoom.Name = "Test Room";
        TestRoom.Description = "This is a Test Room";


        player.CurrentRoom = TestRoom;

        cout << "Player: " << player.Name << "\n" << "Current Room Info: " << player.CurrentRoom.Name << "\n" << player.CurrentRoom.Description << "\n";

        //game.Run();
    }
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
