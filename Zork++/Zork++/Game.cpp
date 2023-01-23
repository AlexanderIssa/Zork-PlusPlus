#include "Game.h"
#include "Item.h";
#include "Room.h";
#include "Player.h";
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

namespace Zork
{
    void from_json(const json& j, Game& g) {
        //j.get_to(g);
        //j.at("Player").get_to(g.player.Name);
        j.at("World").get_to(g.world);
        //j.at("Player").get_to(g.world.player.Name);
    };

    void to_json(json& j, const Game& g) {
        //j = json{ {"Player", g.player.Name} };
        j = json{ {"World", g.world} };
    };

    void Game::ToCommand(string commandString)
    {
        //static unordered_map<string, Commands::commands> const table = { {"quit",Commands::commands::Quit} };
        //auto it = table.find(commandString);
        //if (it != table.end()) {
        //    return it->Commands::commands;
        //}
        //else { error() }

        //std::map<std::string, Commands::commands> xmap = boost::assign::map_list_of("A", A)("B", B)("C", C);

        //map<string, Commands::commands> commandsMap;
        //commandsMap["quit"] = Commands::commands::Q;


        //if (commandString == "quit")
        //{
        //    gCommand = Commands::commandsEnum::Q;
        //}
        //else
        //{
        //    gCommand = Commands::commandsEnum::Unknown;
        //}

        if (commandString.compare("quit") == 0)
        {
            command = gCommand::Quit;
        }
        else
        {
            command = gCommand::Unknown;
        }
    };

    void Game::Run(Game game)
    {
        IsRunning = true;
        game.world.player.CurrentRoom = game.world.Rooms[0];

        cout << "Player: " << game.world.player.Name << "\n" << "Current Room Info: " << game.world.player.CurrentRoom.Name << "\n" << game.world.player.CurrentRoom.Description << "\n";
    };

    void Game::RunProgram(string inputString)
    {
        //cout << inputString << "\n";

        ToCommand(inputString);
        switch (command)
        {
        case gCommand::Quit:
            IsRunning = false;
            break;

        case gCommand::Unknown:
            cout << "Unknown Command." << "\n";
            break;

        default:
            break;
        }
    };
}
