#include "Game.h"

using namespace std;

namespace Zork
{

    int Game::compare_case_insensitive(string s1, string s2) {
        //convert s1 and s2 into lower case strings
        transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
        transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
        if (s1.compare(s2) == 0)
            return 1; //The strings are same
        return 0; //not matched
    }

    // function to convert an entire string to lowercase 
    string Game::LowercaseString(string s)
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        return s;
    }

    void from_json(const json& j, Game& g) {
        j.at("World").get_to(g.world);
        j.at("StartingLocation").get_to(g.startingLocation);
        //for (auto room : g.world.Rooms)
        //{
        //    //room.UpdateNeighbors(g.world.Rooms);
        //    if (room.Name == j.at("StartingLocation"))
        //    {
        //        g.player.CurrentRoom = room;
        //    }
        //}
        // psuedo code, somehow check to see if starting room is null or empty, if it is then starting location is bad
        /*if (g.world.StartingRoom == null/empty)
        {
            cout << "Invalid starting location!\n";
            Application.Quit();
        }*/
        //for (auto room : g.world.Rooms)
        //{
        //    if (room.Name == j.at("North"))
        //    {
        //        g.world.Rooms.neighbor.north = room;
        //    }
        //}
    };

    //void to_json(json& j, const Game& g) {
    //    j = json{ {"World", g.world} };
    //    j = json{ {"StartingLocation"}, g.player.CurrentRoom };
    //};

    void Game::ToCommand(string commandString)
    {
        //map<string, Commands::commands> commandsMap;
        //commandsMap["quit"] = Commands::commands::Q;

        commandString = LowercaseString(commandString);

        static unordered_map<string, Commands::commandsEnum> const commandsMap = { {"quit", Commands::commandsEnum::Quit}, {"q", Commands::commandsEnum::Quit}, {"look", Commands::commandsEnum::Look}, {"l", Commands::commandsEnum::Look}, {"north", Commands::commandsEnum::North}, {"south", Commands::commandsEnum::South}, {"east", Commands::commandsEnum::East}, {"west", Commands::commandsEnum::West} };
        auto it = commandsMap.find(commandString); // use commandString as a key in the commandsMap and set "it" as the value returned
        if (it != commandsMap.end()) {
            // if "it" is not at the end of the map then set passed command as the stored value
            command = it->second;
        }
        else { command = Commands::commandsEnum::Unknown; }
    };

    Directions::DirectionsEnum Game::CommandToDirection(Commands::commandsEnum commandPass)
    {
        Directions::DirectionsEnum directionP = Directions::DirectionsEnum::Unknown;
        static unordered_map<Commands::commandsEnum, Directions::DirectionsEnum> directionsMap = { {Commands::commandsEnum::North, Directions::DirectionsEnum::North}, {Commands::commandsEnum::South, Directions::DirectionsEnum::South}, {Commands::commandsEnum::East, Directions::DirectionsEnum::East}, {Commands::commandsEnum::West, Directions::DirectionsEnum::West} };
        auto it = directionsMap.find(commandPass); // use commandString as a key in the commandsMap and set "it" as the value returned
        if (it != directionsMap.end()) {
            // if "it" is not at the end of the map then set passed command as the stored value
            directionP = it->second;
        }
        else { directionP = Directions::DirectionsEnum::Unknown; }

        return directionP;
    };

    void Game::Run()
    {
        IsRunning = true;

        cout << "Current Room Info: " << player.CurrentRoom.Name << "\n" << player.CurrentRoom.Description << "\n";
    };

    void Game::ProcessInput(string inputString)
    {
        ToCommand(inputString);
        switch (command)
        {
        case Zork::Commands::commandsEnum::Quit:
            IsRunning = false;
            break;

        case Zork::Commands::commandsEnum::Look:
            cout << player.CurrentRoom.Description << "\n";
            for (auto const& pair : player.CurrentRoom.Neighbors) {
                cout << "{" << pair.first << ": " << pair.second.Name << "}\n";
            }
            break;

        case Zork::Commands::commandsEnum::North:
        case Zork::Commands::commandsEnum::South:
        case Zork::Commands::commandsEnum::East:
        case Zork::Commands::commandsEnum::West:
            direction = CommandToDirection(command);
            player.Move(direction);
            break;

        case Zork::Commands::commandsEnum::Take:
            break;

        case Zork::Commands::commandsEnum::Drop:
            break;

        case Zork::Commands::commandsEnum::Inventory:
            break;

        case Zork::Commands::commandsEnum::Score:
            break;

        case Zork::Commands::commandsEnum::Reward:
            break;

        case Zork::Commands::commandsEnum::Attack:
            break;

        case Zork::Commands::commandsEnum::Health:
            break;

        case Zork::Commands::commandsEnum::Damage:
            break;

        case Zork::Commands::commandsEnum::Use:
            break;

        case Zork::Commands::commandsEnum::Unknown:
            cout << "Unknown Command." << "\n";
            break;

        default:
            break;
        }
        cout << "Current Room: " << player.CurrentRoom.Name << "\n";

    };
}
