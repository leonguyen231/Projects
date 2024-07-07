#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Class to represent a Pokemon
class Pokemon {
private:
    string name;
    string type;
    int baseAttack;
    int baseDefense;
    int baseSpeed;
    int baseHP;

public:
    // Constructor to initialize Pokemon attributes
    Pokemon(string name, string type, int attack, int defense, int speed, int hp) {
        this->name = name;
        this->type = type;
        this->baseAttack = attack;
        this->baseDefense = defense;
        this->baseSpeed = speed;
        this->baseHP = hp;
    }

    // Method to display Pokemon information
    void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Type: " << type << endl;
        cout << "Base Attack: " << baseAttack << endl;
        cout << "Base Defense: " << baseDefense << endl;
        cout << "Base Speed: " << baseSpeed << endl;
        cout << "Base HP: " << baseHP << endl;
        cout << "------------------------" << endl;
    }

    // Getter function for name (optional)
    string getName() const { return name; }
};

// Function to search for a Pokemon by name
void searchPokemon(const vector<Pokemon>& pokemonList, const string& searchName) {
    bool found = false;

    for (const Pokemon& pokemon : pokemonList) {
        if (pokemon.getName() == searchName) {
            pokemon.displayInfo();
            found = true;
            break;  // Stop searching once found
        }
    }

    if (!found) {
        cout << "Pokemon not found." << endl;
    }
}

// Function to display entire Pokedex
void displayPokedex(const vector<Pokemon>& pokemonList) {
    cout << "------------------------" << endl;
    cout << "POKEDEX" << endl;
    cout << "------------------------" << endl;
    for (const Pokemon& pokemon : pokemonList) {
        pokemon.displayInfo();
    }
}

// Function to display menu and handle user input
void displayMenu(const vector<Pokemon>& pokemonList) {
    while (true) {
        cout << "Pokedex Menu:" << endl;
        cout << "1. Search for a Pokemon" << endl;
        cout << "2. Show entire Pokedex" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice (1-3): ";
        
        int choice;
        cin >> choice;
        cin.ignore();  // Clear newline character from input buffer
        
        switch (choice) {
            case 1: {
                string searchName;
                cout << "Enter the name of the Pokemon you want to search for: ";
                getline(cin, searchName);  // Read entire line to handle names with spaces
                searchPokemon(pokemonList, searchName);
                break;
            }
            case 2:
                displayPokedex(pokemonList);
                break;
            case 3:
                cout << "Exiting Pokedex. Goodbye!" << endl;
                return;
            default:
                cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
        }
        
        cout << endl;  // Add newline for clarity
    }
}

int main() {
    // Vector to store all Generation 1 Pokemon
    vector<Pokemon> gen1Pokemon;

    // Creating each Pokemon and adding it to the vector
    gen1Pokemon.push_back(Pokemon("Bulbasaur", "Grass/Poison", 49, 49, 45, 45));
    gen1Pokemon.push_back(Pokemon("Ivysaur", "Grass/Poison", 62, 63, 60, 60));
    gen1Pokemon.push_back(Pokemon("Venusaur", "Grass/Poison", 82, 83, 80, 80));
    gen1Pokemon.push_back(Pokemon("Charmander", "Fire", 52, 43, 65, 39));
    gen1Pokemon.push_back(Pokemon("Charmeleon", "Fire", 64, 58, 80, 58));
    gen1Pokemon.push_back(Pokemon("Charizard", "Fire/Flying", 84, 78, 100, 78));
    gen1Pokemon.push_back(Pokemon("Squirtle", "Water", 48, 65, 43, 44));
    gen1Pokemon.push_back(Pokemon("Wartortle", "Water", 63, 80, 58, 59));
    gen1Pokemon.push_back(Pokemon("Blastoise", "Water", 83, 100, 78, 79));
    gen1Pokemon.push_back(Pokemon("Caterpie", "Bug", 30, 35, 45, 45));
    gen1Pokemon.push_back(Pokemon("Metapod", "Bug", 20, 55, 30, 50));
    gen1Pokemon.push_back(Pokemon("Butterfree", "Bug/Flying", 45, 50, 70, 60));
    gen1Pokemon.push_back(Pokemon("Weedle", "Bug/Poison", 35, 30, 50, 40));
    gen1Pokemon.push_back(Pokemon("Kakuna", "Bug/Poison", 25, 50, 35, 45));
    gen1Pokemon.push_back(Pokemon("Beedrill", "Bug/Poison", 80, 40, 75, 65));
    gen1Pokemon.push_back(Pokemon("Pidgey", "Normal/Flying", 45, 40, 56, 40));
    gen1Pokemon.push_back(Pokemon("Pidgeotto", "Normal/Flying", 60, 55, 71, 63));
    gen1Pokemon.push_back(Pokemon("Pidgeot", "Normal/Flying", 80, 75, 91, 83));
    gen1Pokemon.push_back(Pokemon("Rattata", "Normal", 56, 35, 72, 30));
    gen1Pokemon.push_back(Pokemon("Raticate", "Normal", 81, 60, 97, 55));
    gen1Pokemon.push_back(Pokemon("Spearow", "Normal/Flying", 60, 30, 70, 40));
    gen1Pokemon.push_back(Pokemon("Fearow", "Normal/Flying", 90, 65, 100, 65));
    gen1Pokemon.push_back(Pokemon("Ekans", "Poison", 60, 44, 55, 35));
    gen1Pokemon.push_back(Pokemon("Arbok", "Poison", 85, 69, 80, 60));
    gen1Pokemon.push_back(Pokemon("Pikachu", "Electric", 55, 40, 90, 35));
    gen1Pokemon.push_back(Pokemon("Raichu", "Electric", 90, 55, 110, 60));
    gen1Pokemon.push_back(Pokemon("Sandshrew", "Ground", 75, 85, 40, 50));
    gen1Pokemon.push_back(Pokemon("Sandslash", "Ground", 100, 110, 65, 75));
    gen1Pokemon.push_back(Pokemon("Nidoran♀", "Poison", 47, 52, 41, 55));
    gen1Pokemon.push_back(Pokemon("Nidorina", "Poison", 62, 67, 56, 70));
    gen1Pokemon.push_back(Pokemon("Nidoqueen", "Poison/Ground", 92, 87, 76, 90));
    gen1Pokemon.push_back(Pokemon("Nidoran♂", "Poison", 57, 40, 50, 46));
    gen1Pokemon.push_back(Pokemon("Nidorino", "Poison", 72, 57, 65, 61));
    gen1Pokemon.push_back(Pokemon("Nidoking", "Poison/Ground", 102, 77, 85, 81));
    gen1Pokemon.push_back(Pokemon("Clefairy", "Fairy", 45, 48, 35, 70));
    gen1Pokemon.push_back(Pokemon("Clefable", "Fairy", 70, 73, 60, 95));
    gen1Pokemon.push_back(Pokemon("Vulpix", "Fire", 41, 40, 65, 38));
    gen1Pokemon.push_back(Pokemon("Ninetales", "Fire", 76, 75, 100, 73));
    gen1Pokemon.push_back(Pokemon("Jigglypuff", "Normal/Fairy", 45, 20, 20, 115));
    gen1Pokemon.push_back(Pokemon("Wigglytuff", "Normal/Fairy", 70, 45, 45, 140));
    gen1Pokemon.push_back(Pokemon("Zubat", "Poison/Flying", 45, 35, 55, 40));
    gen1Pokemon.push_back(Pokemon("Golbat", "Poison/Flying", 80, 70, 90, 75));
    gen1Pokemon.push_back(Pokemon("Oddish", "Grass/Poison", 50, 55, 30, 45));
    gen1Pokemon.push_back(Pokemon("Gloom", "Grass/Poison", 65, 70, 40, 60));
    gen1Pokemon.push_back(Pokemon("Vileplume", "Grass/Poison", 80, 85, 50, 75));
    gen1Pokemon.push_back(Pokemon("Paras", "Bug/Grass", 70, 55, 25, 35));
    gen1Pokemon.push_back(Pokemon("Parasect", "Bug/Grass", 95, 80, 30, 60));
    gen1Pokemon.push_back(Pokemon("Venonat", "Bug/Poison", 55, 50, 45, 60));
    gen1Pokemon.push_back(Pokemon("Venomoth", "Bug/Poison", 65, 60, 90, 70));
    gen1Pokemon.push_back(Pokemon("Diglett", "Ground", 55, 25, 95, 10));
    gen1Pokemon.push_back(Pokemon("Dugtrio", "Ground", 80, 50, 120, 35));
    gen1Pokemon.push_back(Pokemon("Meowth", "Normal", 45, 35, 90, 40));
    gen1Pokemon.push_back(Pokemon("Persian", "Normal", 70, 60, 115, 65));
    gen1Pokemon.push_back(Pokemon("Psyduck", "Water", 52, 48, 55, 50));
    gen1Pokemon.push_back(Pokemon("Golduck", "Water", 82, 78, 85, 80));
    gen1Pokemon.push_back(Pokemon("Mankey", "Fighting", 80, 35, 70, 40));
    gen1Pokemon.push_back(Pokemon("Primeape", "Fighting", 105, 60, 95, 65));
    gen1Pokemon.push_back(Pokemon("Growlithe", "Fire", 70, 45, 60, 55));
    gen1Pokemon.push_back(Pokemon("Arcanine", "Fire", 110, 80, 95, 90));
    gen1Pokemon.push_back(Pokemon("Poliwag", "Water", 50, 40, 90, 40));
    gen1Pokemon.push_back(Pokemon("Poliwhirl", "Water", 65, 65, 90, 65));
    gen1Pokemon.push_back(Pokemon("Poliwrath", "Water/Fighting", 95, 95, 70, 90));
    gen1Pokemon.push_back(Pokemon("Abra", "Psychic", 20, 15, 90, 25));
    gen1Pokemon.push_back(Pokemon("Kadabra", "Psychic", 35, 30, 105, 40));
    gen1Pokemon.push_back(Pokemon("Alakazam", "Psychic", 50, 45, 120, 55));
    gen1Pokemon.push_back(Pokemon("Machop", "Fighting", 80, 50, 35, 70));
    gen1Pokemon.push_back(Pokemon("Machoke", "Fighting", 100, 70, 45, 80));
    gen1Pokemon.push_back(Pokemon("Machamp", "Fighting", 130, 80, 55, 90));
    gen1Pokemon.push_back(Pokemon("Bellsprout", "Grass/Poison", 75, 35, 40, 50));
    gen1Pokemon.push_back(Pokemon("Weepinbell", "Grass/Poison", 90, 50, 55, 65));
    gen1Pokemon.push_back(Pokemon("Victreebel", "Grass/Poison", 105, 65, 70, 80));
    gen1Pokemon.push_back(Pokemon("Tentacool", "Water/Poison", 40, 35, 70, 40));
    gen1Pokemon.push_back(Pokemon("Tentacruel", "Water/Poison", 70, 65, 100, 80));
    gen1Pokemon.push_back(Pokemon("Geodude", "Rock/Ground", 80, 100, 20, 40));
    gen1Pokemon.push_back(Pokemon("Graveler", "Rock/Ground", 95, 115, 35, 55));
    gen1Pokemon.push_back(Pokemon("Golem", "Rock/Ground", 120, 130, 45, 80));
    gen1Pokemon.push_back(Pokemon("Ponyta", "Fire", 85, 55, 90, 50));
    gen1Pokemon.push_back(Pokemon("Rapidash", "Fire", 100, 70, 105, 65));
    gen1Pokemon.push_back(Pokemon("Slowpoke", "Water/Psychic", 65, 65, 15, 90));
    gen1Pokemon.push_back(Pokemon("Slowbro", "Water/Psychic", 75, 110, 30, 95));
    gen1Pokemon.push_back(Pokemon("Magnemite", "Electric/Steel", 35, 70, 45, 25));
    gen1Pokemon.push_back(Pokemon("Magneton", "Electric/Steel", 60, 95, 70, 50));
    gen1Pokemon.push_back(Pokemon("Farfetch'd", "Normal/Flying", 65, 55, 60, 52));
    gen1Pokemon.push_back(Pokemon("Doduo", "Normal/Flying", 85, 45, 75, 35));
    gen1Pokemon.push_back(Pokemon("Dodrio", "Normal/Flying", 110, 70, 100, 60));
    gen1Pokemon.push_back(Pokemon("Seel", "Water", 45, 55, 45, 65));
    gen1Pokemon.push_back(Pokemon("Dewgong", "Water/Ice", 70, 80, 70, 90));
    gen1Pokemon.push_back(Pokemon("Grimer", "Poison", 80, 50, 25, 80));
    gen1Pokemon.push_back(Pokemon("Muk", "Poison", 105, 75, 50, 105));
    gen1Pokemon.push_back(Pokemon("Shellder", "Water", 65, 100, 40, 30));
    gen1Pokemon.push_back(Pokemon("Cloyster", "Water/Ice", 95, 180, 70, 50));
    gen1Pokemon.push_back(Pokemon("Gastly", "Ghost/Poison", 35, 30, 80, 30));
    gen1Pokemon.push_back(Pokemon("Haunter", "Ghost/Poison", 50, 45, 95, 45));
    gen1Pokemon.push_back(Pokemon("Gengar", "Ghost/Poison", 65, 60, 110, 60));
    gen1Pokemon.push_back(Pokemon("Onix", "Rock/Ground", 45, 160, 70, 35));
    gen1Pokemon.push_back(Pokemon("Drowzee", "Psychic", 48, 45, 42, 60));
    gen1Pokemon.push_back(Pokemon("Hypno", "Psychic", 73, 70, 67, 85));
    gen1Pokemon.push_back(Pokemon("Krabby", "Water", 105, 90, 50, 30));
    gen1Pokemon.push_back(Pokemon("Kingler", "Water", 130, 115, 75, 55));
    gen1Pokemon.push_back(Pokemon("Voltorb", "Electric", 30, 50, 100, 40));
    gen1Pokemon.push_back(Pokemon("Electrode", "Electric", 50, 70, 140, 60));
    gen1Pokemon.push_back(Pokemon("Exeggcute", "Grass/Psychic", 40, 80, 40, 60));
    gen1Pokemon.push_back(Pokemon("Exeggutor", "Grass/Psychic", 95, 85, 55, 95));
    gen1Pokemon.push_back(Pokemon("Cubone", "Ground", 50, 95, 35, 50));
    gen1Pokemon.push_back(Pokemon("Marowak", "Ground", 80, 110, 45, 60));
    gen1Pokemon.push_back(Pokemon("Hitmonlee", "Fighting", 120, 53, 87, 50));
    gen1Pokemon.push_back(Pokemon("Hitmonchan", "Fighting", 105, 79, 76, 50));
    gen1Pokemon.push_back(Pokemon("Lickitung", "Normal", 55, 75, 30, 90));
    gen1Pokemon.push_back(Pokemon("Koffing", "Poison", 65, 95, 35, 40));
    gen1Pokemon.push_back(Pokemon("Weezing", "Poison", 90, 120, 60, 65));
    gen1Pokemon.push_back(Pokemon("Rhyhorn", "Ground/Rock", 85, 95, 25, 80));
    gen1Pokemon.push_back(Pokemon("Rhydon", "Ground/Rock", 130, 120, 40, 105));
    gen1Pokemon.push_back(Pokemon("Chansey", "Normal", 5, 5, 50, 250));
    gen1Pokemon.push_back(Pokemon("Tangela", "Grass", 55, 115, 60, 65));
    gen1Pokemon.push_back(Pokemon("Kangaskhan", "Normal", 95, 80, 90, 105));
    gen1Pokemon.push_back(Pokemon("Horsea", "Water", 40, 70, 60, 30));
    gen1Pokemon.push_back(Pokemon("Seadra", "Water", 65, 95, 85, 55));
    gen1Pokemon.push_back(Pokemon("Goldeen", "Water", 67, 60, 63, 45));
    gen1Pokemon.push_back(Pokemon("Seaking", "Water", 92, 65, 68, 80));
    gen1Pokemon.push_back(Pokemon("Staryu", "Water", 45, 55, 85, 30));
    gen1Pokemon.push_back(Pokemon("Starmie", "Water/Psychic", 75, 85, 115, 60));
    gen1Pokemon.push_back(Pokemon("Mr. Mime", "Psychic/Fairy", 45, 65, 90, 40));
    gen1Pokemon.push_back(Pokemon("Scyther", "Bug/Flying", 110, 80, 105, 70));
    gen1Pokemon.push_back(Pokemon("Jynx", "Ice/Psychic", 50, 35, 95, 65));
    gen1Pokemon.push_back(Pokemon("Electabuzz", "Electric", 83, 57, 105, 65));
    gen1Pokemon.push_back(Pokemon("Magmar", "Fire", 95, 57, 93, 65));
    gen1Pokemon.push_back(Pokemon("Pinsir", "Bug", 125, 100, 85, 65));
    gen1Pokemon.push_back(Pokemon("Tauros", "Normal", 100, 95, 110, 75));
    gen1Pokemon.push_back(Pokemon("Magikarp", "Water", 10, 55, 80, 20));
    gen1Pokemon.push_back(Pokemon("Gyarados", "Water/Flying", 125, 79, 81, 95));
    gen1Pokemon.push_back(Pokemon("Lapras", "Water/Ice", 85, 80, 60, 130));
    gen1Pokemon.push_back(Pokemon("Ditto", "Normal", 48, 48, 48, 48));
    gen1Pokemon.push_back(Pokemon("Eevee", "Normal", 55, 50, 55, 55));
    gen1Pokemon.push_back(Pokemon("Vaporeon", "Water", 65, 60, 65, 130));
    gen1Pokemon.push_back(Pokemon("Jolteon", "Electric", 65, 60, 130, 65));
    gen1Pokemon.push_back(Pokemon("Flareon", "Fire", 130, 60, 65, 65));
    gen1Pokemon.push_back(Pokemon("Porygon", "Normal", 60, 70, 40, 65));
    gen1Pokemon.push_back(Pokemon("Omanyte", "Rock/Water", 40, 100, 35, 35));
    gen1Pokemon.push_back(Pokemon("Omastar", "Rock/Water", 60, 125, 55, 70));
    gen1Pokemon.push_back(Pokemon("Kabuto", "Rock/Water", 80, 90, 55, 30));
    gen1Pokemon.push_back(Pokemon("Kabutops", "Rock/Water", 115, 105, 80, 60));
    gen1Pokemon.push_back(Pokemon("Aerodactyl", "Rock/Flying", 105, 65, 130, 80));
    gen1Pokemon.push_back(Pokemon("Snorlax", "Normal", 110, 65, 30, 160));
    gen1Pokemon.push_back(Pokemon("Articuno", "Ice/Flying", 85, 100, 85, 90));
    gen1Pokemon.push_back(Pokemon("Zapdos", "Electric/Flying", 90, 85, 100, 90));
    gen1Pokemon.push_back(Pokemon("Moltres", "Fire/Flying", 100, 90, 90, 90));
    gen1Pokemon.push_back(Pokemon("Dratini", "Dragon", 64, 45, 50, 41));
    gen1Pokemon.push_back(Pokemon("Dragonair", "Dragon", 84, 65, 70, 61));
    gen1Pokemon.push_back(Pokemon("Dragonite", "Dragon/Flying", 134, 95, 80, 91));
    gen1Pokemon.push_back(Pokemon("Mewtwo", "Psychic", 110, 90, 130, 106));
    gen1Pokemon.push_back(Pokemon("Mew", "Psychic", 100, 100, 100, 100));
    

    // Display menu and handle user input
    displayMenu(gen1Pokemon);

    return 0;
}
