#include "Game.h";
#include <iostream>
#include <fstream>

using namespace std;

    int main()
    {

        //To create a json object by reading a JSON file:
        ifstream gameFile("Game.json");
        json data = json::parse(gameFile);

        // Convert json data into a Game type var called game
        Zork::Game jgame = data.get<Zork::Game>();
        Zork::Game game(jgame.world, jgame.startingLocation);

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
            game.ProcessInput(game.inputString);
        }

        cout << "Thank you for playing!";
        return 0;
    };