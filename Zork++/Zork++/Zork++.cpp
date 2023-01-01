// Zork++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Game.h";
#include "Item.h";
#include "Room.h";
#include "Player.h";
using namespace std;

int main()
{
    const string defaultRoomsFilename = "Content\Game.json";
    //Game game = JsonConvert.DeserializeObkect<Game.(File.ReadAllText(gameFilename));
    cout << "Welcome to Zork!\n";

    Room TestRoom;
    TestRoom.name = "Test Room";
    TestRoom.description = "This is a Test Room";

    Player Alex;
    Alex.CurrentRoom = TestRoom;

    //cout << TestRoom.name << " " << TestRoom.description<< "\n";
    cout << "Player: Alex\n" << "Current Room Info: " << Alex.CurrentRoom.name << "\n" << Alex.CurrentRoom.description << "\n";
    
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
