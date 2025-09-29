#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    //Player Stats
    int playerHP = 400;
    int playerATK = 12;
    int playerDEF = 5;

    //Boss Stats
    int bossHP = 400;
    int bossATK = 21;
    int bossDEF = 20;

    //Items
    bool hasRapier = false;        // Divine Rapier - One-time use, deals 275 true damage (ignores DEF).
    bool hasNet = false;           // 90-Caliber Net - Free action, once. Skips the next boss attack.
    bool hasSunglasses = false;    // Sunglasses - Free action, once. Skips the next boss attack.
    bool hasAmulet = false;        // Schala's Amulet - If Jun's HP falls to 0 or less, the amulet shatters and restores him to 1 HP instead.
    bool hasRustbite = false;      // Rustbite - Permanently reduces Bjorne's DEF by 6.

    //Item Effect
    bool skipNextBossAttack = false;

    int choice;
    char choicechar;
    string pause;


    // Scene 0 — Introduction
    cout << "BLEACH: District 67 — A Text-Based Adventure" << endl
         << "Disclaimer: This is a fan-made educational project. Bleach is created by Tite Kubo." << endl
         << "All rights belong to their respective owners. For classroom use only." << endl
         << endl;

    cout << "You are Jun Arashi, a soul living in District 67 of Rukongai." << endl
         << "One night, a terrible presence descends — a rogue Hollow stalks the district." << endl
         << "You must prepare yourself for the coming battle." << endl
         << endl;

    cout << "Press Enter to continue..." << endl;
    getline(cin, pause);


    // Scene 1 — Prologue
    cout << "   <-------------------------------------------------------------------------->" << endl
         << endl
         << "   District 67, outskirts of Rukongai." << endl
         << endl
         << "   Jun stands in a dark alley as screams echo through the streets." << endl
         << "   The night sky trembles as a Hollow's roar shakes the rooftops." << endl
         << "   Jun clenches his fists — there is no running now." << endl;
    getline(cin, pause);


    // Scene 2 — The Saint (Hanae)
    cout << "   <-------------------------------------------------------------------------->" << endl
    	 << endl
    	 << "	Player Starting Status" << endl
		 << "   Player Status" << endl
         << "   Name: Jun Arashi" << endl
         << "   Race: Soul Reaper" << endl
         << "   HP: " << playerHP << endl
         << "   ATK: "  << playerATK << endl
         << "   DEF: " << playerDEF << endl
         << endl
         << "   <-------------------------------------------------------------------------->" << endl
         << endl
         << "   Hanae, the district's wandering saint, approaches you." << endl
         << endl
         << "   Hanae: \"You look pale, Jun. The night is cruel… let me bless you with light.\"" << endl
         << "   Choose:" << endl
         << "   [1] Safe - \"Just a little strength will do.\" (+4 ATK)" << endl
         << "   [2] Mid  -  \"I'll take whatever you can give.\" (+1 ATK, +1 DEF, +7 HP)" << endl
         << "   [3] Risky -  \"Give me everything you have!\" (+11 ATK, +3 DEF, -5 HP)" << endl
         << "   Your Choice: ";
    cin >> choice;
    cout << endl;

    switch (choice) {
        case 1:
            playerATK += 4;
            cout << "   You choose: \"Just a little strength will do.\" (+4 ATK)" << endl;
            break;
        case 2:
            playerATK += 1; playerDEF += 1; playerHP += 7;
            cout << "   You choose: \"I'll take whatever you can give.\" (+1 ATK, +1 DEF, +7 HP)" << endl;
            break;
        case 3:
            playerATK += 11; playerDEF += 3; playerHP -= 5;
            cout << "   You choose: \"Give me everything you have!\" (+11 ATK, +3 DEF, -5 HP)" << endl;
            break;
        default:
            cout << "   You choose: Not on the Option (No Stats Added.)";
            break;
    }

    //Player Status
    cout << "   Player Status" << endl
         << "   Name: Jun Arashi" << endl
         << "   Race: Soul Reaper" << endl
         << "   HP: " << playerHP << endl
         << "   ATK: "  << playerATK << endl
         << "   DEF: " << playerDEF << endl
         << endl;

    //Inventory
    if (hasRapier == true || hasNet == true || hasSunglasses == true || hasAmulet == true || hasRustbite == true) {cout << "   Items: " << endl;}
    if (hasRapier == true){cout << "   Divine Rapier [Active]" << endl;}
    if (hasNet == true){cout << "   90-Caliber Net [Active]" << endl;}
    if (hasSunglasses == true){cout << "   Sunglasses [Active]" << endl;}
    if (hasAmulet == true){cout << "   Schala's Amulet [Passive]" << endl;}
    if (hasRustbite == true){cout << "   Rustbite Charge [Active]" << endl;}
    cin.ignore();
    cin.get();
    if (playerHP <= 0) { if (hasAmulet) { hasAmulet = false; playerHP = 1; cout << endl << "	Schala's Amulet shatters and restores you to 1 HP!" << endl; } else { cout << endl << " You fall to the ground... Your journey ends here." << endl; return 0; } }
    

	// Scene 3 — The Tinkerer (Riku)
    cout << "   <-------------------------------------------------------------------------->" << endl
         << endl
         << "   Riku, the district's tinkerer, sits surrounded by scraps of strange metal." << endl
         << endl
         << "   Riku: \"You'll need more than fists against a Hollow. I can forge something quick.\"" << endl
         << "   Choose:" << endl
         << "   [1] Safe - \"Just give me something simple.\" (+4 ATK)" << endl
         << "   [2] Mid  - \"Make me sturdier.\" (+1 DEF, -2 HP)" << endl
         << "   [3] Risky - \"Push the limits!\" (+5 ATK, +3 DEF, -5 HP, gain Rustbite (-6 Boss DEF))" << endl
         << "   Your Choice: ";
    cin >> choice;
    cout << endl;
    switch (choice) {
        case 1:
            playerATK += 4;
            cout << "   You choose: \"Just give me something simple.\" (+4 ATK)" << endl;
            break;
        case 2:
            playerDEF += 1; playerHP -= 2;
            cout << "   You choose: \"Make me sturdier.\" (+1 DEF, -2 HP)" << endl;
            break;
        case 3:
            playerATK += 5; playerDEF += 3; playerHP -= 5;
            hasRustbite = true;
            bossDEF -= 6;
            cout << "   You choose: \"Push the limits!\" (+5 ATK, +3 DEF, -5 HP, gain Rustbite (-6 Boss DEF))" << endl
                 << "   You have gained an Item!" << endl
                 << "   You Obtained Rustbite Charge";
            break;
        default:
            cout << "   You choose: Not on the Option (No Stats Added.)" << endl;
            break;
    }
    //Player Status

    cout << "   Player Status" << endl
         << "   Name: Jun Arashi" << endl
         << "   Race: Soul Reaper" << endl
         << "   HP: " << playerHP << endl
         << "   ATK: "  << playerATK << endl
         << "   DEF: " << playerDEF << endl
         << endl;

    //Inventory
    if (hasRapier == true || hasNet == true || hasSunglasses == true || hasAmulet == true || hasRustbite == true) {cout << "   Items: " << endl;}
    if (hasRapier == true){cout << "   Divine Rapier [Active]" << endl;}
    if (hasNet == true){cout << "   90-Caliber Net [Active]" << endl;}
    if (hasSunglasses == true){cout << "   Sunglasses [Active]" << endl;}
    if (hasAmulet == true){cout << "   Schala's Amulet [Passive]" << endl;}
    if (hasRustbite == true){cout << "   Rustbite Charge [Active]" << endl;}
    cin.ignore();
    cin.get();
    if (playerHP <= 0) { if (hasAmulet) { hasAmulet = false; playerHP = 1; cout << endl << "	Schala's Amulet shatters and restores you to 1 HP!" << endl; } else { cout << endl << " You fall to the ground... Your journey ends here." << endl; return 0; } }


    // Scene 4 — Sister Midori (Shrine)
    cout << "   <-------------------------------------------------------------------------->" << endl
         << endl
         << "   You pass a ruined shrine. Sister Midori kneels in prayer." << endl
         << endl
         << "   Midori: \"Child… I can offer a charm. But the gods ask for something in return.\"" << endl
         << "   Choose:" << endl
         << "   [1] Safe - \"A small blessing, please.\" (+4 ATK)" << endl
         << "   [2] Mid  - \"I'll take the charm.\" (Gain Net, -2 HP)" << endl
         << "   [3] Risky - \"I want true power!\" (+9 ATK, -4 HP)" << endl
         << "   Your Choice: ";
    cin >> choice;
    cout << endl;
    switch (choice) {
        case 1:
            playerATK += 4;
            cout << "   You choose: \"A small blessing, please.\" (+4 ATK)" << endl;
            break;
        case 2:
            hasNet = true; playerHP -= 2;
            cout << "   You choose: \"I'll take the charm.\" (Gain Net, -2 HP)" << endl
                 << "   You have gained an Item!" << endl
                 << "   You Obtained 90-Caliber Net";
            break;
        case 3:
            playerATK += 9; playerHP -= 4;
            cout << "   You choose: \"I want true power!\" (+9 ATK, -4 HP)" << endl;
            break;
        default:
            cout << "   You choose: Not on the Option (No Stats Added.)" << endl;
            break;
    }
    //Player Status
    cout << "   Player Status" << endl
         << "   Name: Jun Arashi" << endl
         << "   Race: Soul Reaper" << endl
         << "   HP: " << playerHP << endl
         << "   ATK: "  << playerATK << endl
         << "   DEF: " << playerDEF << endl
         << endl;

    //Inventory
    if (hasRapier == true || hasNet == true || hasSunglasses == true || hasAmulet == true || hasRustbite == true) {cout << "   Items: " << endl;}
    if (hasRapier == true){cout << "   Divine Rapier [Active]" << endl;}
    if (hasNet == true){cout << "   90-Caliber Net [Active]" << endl;}
    if (hasSunglasses == true){cout << "   Sunglasses [Active]" << endl;}
    if (hasAmulet == true){cout << "   Schala's Amulet [Passive]" << endl;}
    if (hasRustbite == true){cout << "   Rustbite Charge [Active]" << endl;}
    cin.ignore();
    cin.get();
    if (playerHP <= 0) { if (hasAmulet) { hasAmulet = false; playerHP = 1; cout << endl << "	Schala's Amulet shatters and restores you to 1 HP!" << endl; } else { cout << endl << " You fall to the ground... Your journey ends here." << endl; return 0; } }


    // Scene 5 — Yumi the Smuggler
    cout << "   <-------------------------------------------------------------------------->" << endl
         << endl
         << "   A shadow in the corner alley beckons you. Yumi, the smuggler, grins." << endl
         << endl
         << "   Yumi: \"Dangerous times, dangerous goods. I can sell you power, if you're willing to pay the price.\"" << endl
         << "   Choose:" << endl
         << "   [1] Safe - \"Something reliable.\" (+11 ATK)" << endl
         << "   [2] Mid  - \"The Armlet of Mordiggan…\" (+15 ATK, -1 DEF, -2 HP)" << endl
         << "   [3] Risky - \"What's your strongest weapon?\" (Gain Divine Rapier, -10 HP, -3 DEF, -3 ATK)" << endl
         << "   Your Choice: ";
    cin >> choice;
    cout << endl;
    switch (choice) {
        case 1:
            playerATK += 11;
            cout << "   You choose: \"Something reliable.\" (+11 ATK)" << endl;
            break;
        case 2:
            playerATK += 15; playerDEF -= 1; playerHP -= 2;
            cout << "   You choose: \"The Armlet of Mordiggan…\" (+15 ATK, -1 DEF, -2 HP)" << endl;
            break;
        case 3:
            hasRapier = true; playerHP -= 10; playerDEF -= 3; playerATK -= 3;
            cout << "   You choose: \"What's your strongest weapon?\" (Gain Divine Rapier, -10 HP, -3 DEF, -3 ATK)" << endl
                 << "   You have gained an Item!" << endl
                 << "   You Obtained Divine Rapier";
            break;
        default:
            cout << "   You choose: Not on the Option (No Stats Added.)" << endl;
            break;
    }

    //Player Status
    cout << "   Player Status" << endl
         << "   Name: Jun Arashi" << endl
         << "   Race: Soul Reaper" << endl
         << "   HP: " << playerHP << endl
         << "   ATK: "  << playerATK << endl
         << "   DEF: " << playerDEF << endl
         << endl;

    //Inventory
    if (hasRapier == true || hasNet == true || hasSunglasses == true || hasAmulet == true || hasRustbite == true) {cout << "   Items: " << endl;}
    if (hasRapier == true){cout << "   Divine Rapier [Active]" << endl;}
    if (hasNet == true){cout << "   90-Caliber Net [Active]" << endl;}
    if (hasSunglasses == true){cout << "   Sunglasses [Active]" << endl;}
    if (hasAmulet == true){cout << "   Schala's Amulet [Passive]" << endl;}
    if (hasRustbite == true){cout << "   Rustbite Charge [Active]" << endl;}
    cin.ignore();
    cin.get();
    if (playerHP <= 0) { if (hasAmulet) { hasAmulet = false; playerHP = 1; cout << endl << "	Schala's Amulet shatters and restores you to 1 HP!" << endl; } else { cout << endl << " You fall to the ground... Your journey ends here." << endl; return 0; } }


    // Scene 6 — Kaji the Peddler
    cout << "   <-------------------------------------------------------------------------->" << endl
         << endl
         << "   An old peddler, Kaji, rattles his cart of bottles and charms." << endl
         << endl
         << "   Kaji: \"Spare change for power? Every blessing has a price.\"" << endl
         << "   Choose:" << endl
         << "   [1] Safe - \"A minor boost.\" (+4 ATK)" << endl
         << "   [2] Mid  - \"Something stronger.\" (+8 ATK, -2 HP)" << endl
         << "   [3] Risky - \"Everything you've got!\" (+15 ATK, -2 DEF, -5 HP)" << endl
         << "   Your Choice: ";
    cin >> choice;
    cout << endl;
    switch (choice) {
        case 1:
            playerATK += 4;
            cout << "   You choose: \"A minor boost.\" (+4 ATK)" << endl;
            break;
        case 2:
            playerATK += 8; playerHP -= 2;
            cout << "   You choose: \"Something stronger.\" (+8 ATK, -2 HP)" << endl;
            break;
        case 3:
            playerATK += 15; playerDEF -= 2; playerHP -= 5;
            cout << "   You choose: \"Everything you've got!\" (+15 ATK, -2 DEF, -5 HP)" << endl;
            break;
        default:
            cout << "   You choose: Not on the Option (No Stats Added.)" << endl;
            break;
    }

    //Player Status
    cout << "   Player Status" << endl
         << "   Name: Jun Arashi" << endl
         << "   Race: Soul Reaper" << endl
         << "   HP: " << playerHP << endl
         << "   ATK: "  << playerATK << endl
         << "   DEF: " << playerDEF << endl
         << endl;

    //Inventory
    if (hasRapier == true || hasNet == true || hasSunglasses == true || hasAmulet == true || hasRustbite == true) {cout << "   Items: " << endl;}
    if (hasRapier == true){cout << "   Divine Rapier [Active]" << endl;}
    if (hasNet == true){cout << "   90-Caliber Net [Active]" << endl;}
    if (hasSunglasses == true){cout << "   Sunglasses [Active]" << endl;}
    if (hasAmulet == true){cout << "   Schala's Amulet [Passive]" << endl;}
    if (hasRustbite == true){cout << "   Rustbite Charge [Active]" << endl;}
    cin.ignore();
    cin.get();
    if (playerHP <= 0) { if (hasAmulet) { hasAmulet = false; playerHP = 1; cout << endl << "	Schala's Amulet shatters and restores you to 1 HP!" << endl; } else { cout << endl << " You fall to the ground... Your journey ends here." << endl; return 0; } }


    // Scene 7 — Aiko the Child
    cout << "   <-------------------------------------------------------------------------->" << endl
         << endl
         << "   Aiko, a small child, tugs at your sleeve with pleading eyes." << endl
         << endl
         << "   Aiko: \"Please… help us. You're the only one who can stand against the Hollow.\"" << endl
         << "   Choose:" << endl
         << "   [1] Safe - \"I'll do my best.\" (+2 ATK)" << endl
         << "   [2] Mid  - \"I'll push myself harder.\" (+1 ATK, +1 DEF, -1 HP)" << endl
         << "   [3] Risky - \"I'll protect everyone at any cost!\" (+8 ATK, +3 DEF, -5 HP)" << endl
         << "   Your Choice: ";
    cin >> choice;
    cout << endl;
    switch (choice) {
        case 1:
            playerATK += 2;
            cout << "   You choose: \"I'll do my best.\" (+2 ATK)" << endl;
            break;
        case 2:
            playerATK += 1; playerDEF += 1; playerHP -= 1;
            cout << "   You choose: \"I'll push myself harder.\" (+1 ATK, +1 DEF, -1 HP)" << endl;
            break;
        case 3:
            playerATK += 8; playerDEF += 3; playerHP -= 5;
            cout << "   You choose: \"I'll protect everyone at any cost!\" (+8 ATK, +3 DEF, -5 HP)" << endl;
            break;
        default:
            cout << "   You choose: Not on the Option (No Stats Added.)" << endl;
            break;
    }

    //Player Status
    cout << "   Player Status" << endl
         << "   Name: Jun Arashi" << endl
         << "   Race: Soul Reaper" << endl
         << "   HP: " << playerHP << endl
         << "   ATK: "  << playerATK << endl
         << "   DEF: " << playerDEF << endl
         << endl;

    //Inventory
    if (hasRapier == true || hasNet == true || hasSunglasses == true || hasAmulet == true || hasRustbite == true) {cout << "   Items: " << endl;}
    if (hasRapier == true){cout << "   Divine Rapier [Active]" << endl;}
    if (hasNet == true){cout << "   90-Caliber Net [Active]" << endl;}
    if (hasSunglasses == true){cout << "   Sunglasses [Active]" << endl;}
    if (hasAmulet == true){cout << "   Schala's Amulet [Passive]" << endl;}
    if (hasRustbite == true){cout << "   Rustbite Charge [Active]" << endl;}
    cin.ignore();
    cin.get();
    if (playerHP <= 0) { if (hasAmulet) { hasAmulet = false; playerHP = 1; cout << endl << "	Schala's Amulet shatters and restores you to 1 HP!" << endl; } else { cout << endl << " You fall to the ground... Your journey ends here." << endl; return 0; } }


    // Scene 8 — Master Renga
    cout << "   <-------------------------------------------------------------------------->" << endl
         << endl
         << "   Your old mentor, Renga, leans on his cane and lowers his sunglasses." << endl
         << endl
         << "   Renga: \"Jun… take these. You'll need sharp eyes more than a sharp blade.\"" << endl
         << "   Choose:" << endl
         << "   [1] Safe - \"A steady path will do.\" (+5 ATK)" << endl
         << "   [2] Mid  - \"I'll endure the strain.\" (+7 ATK, -2 HP)" << endl
         << "   [3] Risky - \"I'll fight with your spirit!\" (Gain Sunglasses, +2 DEF, -5 HP)" << endl
         << "   Your Choice: ";
    cin >> choice;
    cout << endl;
    switch (choice) {
        case 1:
            playerATK += 5;
            cout << "   You choose: \"A steady path will do.\" (+5 ATK)" << endl;
            break;
        case 2:
            playerATK += 7; playerHP -= 2;
            cout << "   You choose: \"I'll endure the strain.\" (+7 ATK, -2 HP)" << endl;
            break;
        case 3:
            hasSunglasses = true; playerDEF += 2; playerHP -= 5;
            cout << "   You choose: \"I'll fight with your spirit!\" (Gain Sunglasses, +2 DEF, -5 HP)" << endl
                 << "   You have gained an Item!" << endl
                 << "   You Obtained Sunglasses";
            break;
        default:
            cout << "   You choose: Not on the Option (No Stats Added.)" << endl;
            break;
    }

    //Player Status
    cout << "   Player Status" << endl
         << "   Name: Jun Arashi" << endl
         << "   Race: Soul Reaper" << endl
         << "   HP: " << playerHP << endl
         << "   ATK: "  << playerATK << endl
         << "   DEF: " << playerDEF << endl
         << endl;

    //Inventory
    if (hasRapier == true || hasNet == true || hasSunglasses == true || hasAmulet == true || hasRustbite == true) {cout << "   Items: " << endl;}
    if (hasRapier == true){cout << "   Divine Rapier [Active]" << endl;}
    if (hasNet == true){cout << "   90-Caliber Net [Active]" << endl;}
    if (hasSunglasses == true){cout << "   Sunglasses [Active]" << endl;}
    if (hasAmulet == true){cout << "   Schala's Amulet [Passive]" << endl;}
    if (hasRustbite == true){cout << "   Rustbite Charge [Active]" << endl;}
    cin.ignore();
    cin.get();
    if (playerHP <= 0) { if (hasAmulet) { hasAmulet = false; playerHP = 1; cout << endl << "	Schala's Amulet shatters and restores you to 1 HP!" << endl; } else { cout << endl << " You fall to the ground... Your journey ends here." << endl; return 0; } }


    // Scene 9 — Mika the Charm-Seller
    cout << "   <-------------------------------------------------------------------------->" << endl
         << endl
         << "   Mika holds a tray of strange charms." << endl
         << endl
         << "   Mika: \"These trinkets are cursed and blessed alike. What will you take?\"" << endl
         << "   Choose:" << endl
         << "   [1] Safe - \"A small charm.\" (+2 ATK)" << endl
         << "   [2] Mid  - \"That one… it glows faintly.\" (Gain Schala's Amulet, -3 HP)" << endl
         << "   [3] Risky - \"I want the strongest one!\" (+11 ATK, +2 DEF, -7 HP)" << endl
         << "   Your Choice: ";
    cin >> choice;
    cout << endl;
    switch (choice) {
        case 1:
            playerATK += 2;
            cout << "   You choose: \"A small charm.\" (+2 ATK)" << endl;
            break;
        case 2:
            hasAmulet = true; playerHP -= 3;
            cout << "   You choose: \"That one… it glows faintly.\" (Gain Schala's Amulet, -3 HP)" << endl
                 << "   You have gained an Item!" << endl
                 << "   You Obtained Schala's Amulet";
            break;
        case 3:
            playerATK += 11; playerDEF += 2; playerHP -= 7;
            cout << "   You choose: \"I want the strongest one!\" (+11 ATK, +2 DEF, -7 HP)" << endl;
            break;
        default:
            cout << "   You choose: Not on the Option (No Stats Added.)" << endl;
            break;
    }

    //Player Status
    cout << "   Player Status" << endl
         << "   Name: Jun Arashi" << endl
         << "   Race: Soul Reaper" << endl
         << "   HP: " << playerHP << endl
         << "   ATK: "  << playerATK << endl
         << "   DEF: " << playerDEF << endl
         << endl;

    //Inventory
    if (hasRapier == true || hasNet == true || hasSunglasses == true || hasAmulet == true || hasRustbite == true) {cout << "   Items: " << endl;}
    if (hasRapier == true){cout << "   Divine Rapier [Active]" << endl;}
    if (hasNet == true){cout << "   90-Caliber Net [Active]" << endl;}
    if (hasSunglasses == true){cout << "   Sunglasses [Active]" << endl;}
    if (hasAmulet == true){cout << "   Schala's Amulet [Passive]" << endl;}
    if (hasRustbite == true){cout << "   Rustbite Charge [Active]" << endl;}
    cin.ignore();
    cin.get();
    if (playerHP <= 0) { if (hasAmulet) { hasAmulet = false; playerHP = 1; cout << endl << "	Schala's Amulet shatters and restores you to 1 HP!" << endl; } else { cout << endl << " You fall to the ground... Your journey ends here." << endl; return 0; } }


    // Scene 10 — Supply Cache
    cout << "   <-------------------------------------------------------------------------->" << endl
         << endl
         << "   You find a hidden cache of supplies — medicine, weapons, armor." << endl
         << "   Choose:" << endl
         << "   [1] Safe - \"Patch me up completely.\" (Set HP to 50)" << endl
         << "   [2] Mid  - \"I'll take the sharper blades.\" (+12 ATK, -3 HP)" << endl
         << "   [3] Risky - \"Load me with everything!\" (+23 ATK, +2 HP)" << endl
         << "   Your Choice: ";
    cin >> choice;
    cout << endl;
    switch (choice) {
        case 1:
            playerHP = 50;
            cout << "   You choose: \"Patch me up completely.\" (Set HP to 50)" << endl;
            break;
        case 2:
            playerATK += 12; playerHP -= 3;
            cout << "   You choose: \"I'll take the sharper blades.\" (+12 ATK, -3 HP)" << endl;
            break;
        case 3:
            playerATK += 23; playerHP += 2;
            cout << "   You choose: \"Load me with everything!\" (+23 ATK, +2 HP)" << endl;
            break;
        default:
            cout << "   You choose: Not on the Option (No Stats Added.)" << endl;
            break;
    }

    //Player Status
    cout << "   Player Status" << endl
         << "   Name: Jun Arashi" << endl
         << "   Race: Soul Reaper" << endl
         << "   HP: " << playerHP << endl
         << "   ATK: "  << playerATK << endl
         << "   DEF: " << playerDEF << endl
         << endl;
         
    //Inventory
    if (hasRapier == true || hasNet == true || hasSunglasses == true || hasAmulet == true || hasRustbite == true) {cout << "   Items: " << endl;}
    if (hasRapier == true){cout << "   Divine Rapier [Active]" << endl;}
    if (hasNet == true){cout << "   90-Caliber Net [Active]" << endl;}
    if (hasSunglasses == true){cout << "   Sunglasses [Active]" << endl;}
    if (hasAmulet == true){cout << "   Schala's Amulet [Passive]" << endl;}
    if (hasRustbite == true){cout << "   Rustbite Charge [Active]" << endl;}
    cin.ignore();
    cin.get();
    if (playerHP <= 0) { if (hasAmulet) { hasAmulet = false; playerHP = 1; cout << endl << "	Schala's Amulet shatters and restores you to 1 HP!" << endl; } else { cout << endl << " You fall to the ground... Your journey ends here." << endl; return 0; } }

    if (playerDEF < 0) playerDEF = 0;


    // Scene 11 — Boss Fight: Bjorne the Rogue Hollow
    cout << "   <-------------------------------------------------------------------------->" << endl
         << endl
         << "	The ground splits. Bjorne, a towering Hollow, rises from the shadows." << endl
         << endl
         << "	Bjorne: \"Foolish soul… your resistance amuses me.\"" << endl
         << endl;
    cin.get();
    
    // Boss Stats
    cout << "	Boss Stats: HP 400, ATK 21, DEF 20" << endl;
    cout << "	Current Boss HP: " << bossHP << "  Boss DEF: " << bossDEF << endl;
    cout << "	Your current stats: HP: " << playerHP << "  ATK: " << playerATK << "  DEF: " << playerDEF << endl;
    cout << endl;

    cout << "   Boss Status" << "                 " << "    Player Status" << endl
         << "   Name: Bjorne" << "                 " << "   Name: Jun Arashi" << endl
         << "   Race: Hollow" << "                 " << "   Race: Soul Reaper" << endl
         << "   HP: " << bossHP << "                   " << "      HP: " << playerHP << endl
         << "   ATK: "  << bossATK << "                    " << "     ATK: "  << playerATK << endl
         << "   DEF: " << bossDEF << "                 " << "        DEF: " << playerDEF << endl
         << endl;

    // Track Fights
    bool fightOver = false;
    bool playerDead = false;
    bool bossDead = false;

    // TURN 1 
    if (!fightOver) {
        cout << "   --- Turn 1 ---" << endl
             << "   Player HP: " << playerHP << " | ATK: " << playerATK << " | DEF: " << playerDEF << endl
             << "   Boss HP: " << bossHP << " | DEF: " << bossDEF << endl
             << "   Choose action: "<< endl 
             << "   [1] Attack  " << endl
             << "   [2] Use item" << endl
             << "   Move: ";
        cin >> choicechar;
        cout << endl;
        switch (choicechar) 
        {
        case '1':
            {            
            int dmg = max(1, playerATK - bossDEF);
            bossHP -= dmg;
            cout << "   You Dealt " << dmg << " damage." << endl;
            break;
        }
        case '2':
        if (hasRapier == true || hasNet == true || hasSunglasses == true || hasAmulet == true || hasRustbite == true) {
            cout << "   Items: " << endl;
                if (hasRapier == true){cout << "   [1] Divine Rapier [Active] - One-time use, deals 275 true damage (ignores DEF)." << endl;}
                if (hasNet == true){cout << "   [2] 90-Caliber Net [Active] - Free action, once. Skips the next boss attack." << endl;}
                if (hasSunglasses == true){cout << "   [3] Sunglasses [Active] - Free action, once. Skips the next boss attack." << endl;}
                if (hasRustbite == true){cout << "   [4] Rustbite Charge [Active] - Permanently reduces Bjorne’s DEF by 6." << endl;}
                if (hasAmulet == true){cout << "   Schala's Amulet [Passive] - If Jun’s HP falls to 0 or less, the amulet shatters and restores him to 1 HP instead. (Cannot be Used)" << endl;}
            cout << endl
				 << "   Which Item To Use? ";
            cin >> choicechar;
                switch (choicechar)
                {
                case 1:
                    if (hasRapier == true)
                    {cout << "	You use the Divine Rapier! (275 true damage)" << endl;
                    bossHP -= 275; hasRapier = false;} else {cout << "  Not a Valid Item. Attack Missed";}
                    break;
                case 2:
                    if (hasNet == true){
					cout << "	You use the 90-Caliber Net. Boss's next attack will be skipped." << endl;
                    skipNextBossAttack = true; 
					hasNet = false; 
					int dmg = max(1, playerATK - bossDEF);
            		bossHP -= dmg;
            		cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
					} else {
					cout << " Not a Valid Item. Attack Missed";
					}
                    break;
                case 3:
                    if (hasSunglasses == true)
                    {cout << "	You use the Sunglasses. Boss's next attack will be skipped." << endl;
                    skipNextBossAttack = true; 
					hasNet = false; 
					int dmg = max(1, playerATK - bossDEF);
            		bossHP -= dmg;
            		cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
					} else {
					cout << " Not a Valid Item. Attack Missed";
					}
                    break;
                    break;
                case 4:
                    if (hasRustbite == true)
                    {cout << "	You use the Rustbite Charge. Boss Defense Permanently reduced by 6" << endl;
                    bossDEF -= 6;} else {cout << "  Not a Valid Item. Attack Missed";}
                    break;
                default:
                    cout << "	No Item Found! You Skip a Turn!";
                    break;
                }
        	break;
        } 
        default:
            int dmg = max(1, playerATK - bossDEF);
            bossHP -= dmg;
            cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
            break;
    }
    
        // Check boss death
        if (bossHP <= 0) {
            cout << "	Bjorne falls beneath your strike!" << endl;
            bossDead = true; fightOver = true;
        } else {
            // Boss taunt
            if (bossHP > 300) cout << "    Bjorne: Tiny spark. I will crush you slowly." << endl;
            else if (bossHP > 200) cout << "    Bjorne: You sting… nothing more." << endl;
            else if (bossHP > 100) cout << "	Bjorne: Impossible… you persist?!" << endl;
            else cout << "	Bjorne: I will DEVOUR YOU!" << endl;

            // Boss attack
            if (skipNextBossAttack) {
                cout << "	Boss's attack is skipped this turn." << endl;
                skipNextBossAttack = false;
            } else {
                int dmg = max(1, bossATK - playerDEF);
                playerHP -= dmg;
                cout << "	Bjorne Dealt " << dmg << " damage." << endl;
                if (playerHP <= 0 && hasAmulet) {
                    hasAmulet = false;
                    playerHP = 1;
                    cout << "	Schala's Amulet shatters and restores you to 1 HP." << endl;
                }
                if (playerHP <= 0) {
                    cout << "	You fall to the ground..." << endl;
                    playerDead = true; fightOver = true;
                }
            }
        }
    }
    // TURN 2 
    if (!fightOver) {
                cout << endl << "   --- Turn 2 ---" << endl
             << "   Player HP: " << playerHP << " | ATK: " << playerATK << " | DEF: " << playerDEF << endl
             << "   Boss HP: " << bossHP << " | DEF: " << bossDEF << endl
             << "   Choose action: "<< endl 
             << "   [1] Attack  " << endl
             << "   [2] Use item" << endl
             << "   Move: ";
        cin >> choicechar;
        cout << endl;
        switch (choicechar) 
        {
        case 1:
            {            
            int dmg = max(1, playerATK - bossDEF);
            bossHP -= dmg;
            cout << "   You Dealt " << dmg << " damage." << endl;
            break;
        }
        case 2:
        if (hasRapier == true || hasNet == true || hasSunglasses == true || hasAmulet == true || hasRustbite == true) {
            cout << "   Items: " << endl;
                if (hasRapier == true){cout << "   [1] Divine Rapier [Active] - One-time use, deals 275 true damage (ignores DEF)." << endl;}
                if (hasNet == true){cout << "   [2] 90-Caliber Net [Active] - Free action, once. Skips the next boss attack." << endl;}
                if (hasSunglasses == true){cout << "   [3] Sunglasses [Active] - Free action, once. Skips the next boss attack." << endl;}
                if (hasRustbite == true){cout << "   [4] Rustbite Charge [Active] - Permanently reduces Bjorne’s DEF by 6." << endl;}
                if (hasAmulet == true){cout << "   Schala's Amulet [Passive] - If Jun’s HP falls to 0 or less, the amulet shatters and restores him to 1 HP instead. (Cannot be Used)" << endl;}
            cout << endl
				 << "   Which Item To Use? ";
            cin >> choicechar;
                switch (choicechar)
                {
                case 1:
                    if (hasRapier == true)
                    {cout << "	You use the Divine Rapier! (275 true damage)" << endl;
                    bossHP -= 275; hasRapier = false;} else {cout << "  Not a Valid Item. Attack Missed";}
                    break;
                case 2:
                    if (hasNet == true){
					cout << "	You use the 90-Caliber Net. Boss's next attack will be skipped." << endl;
                    skipNextBossAttack = true; 
					hasNet = false; 
					int dmg = max(1, playerATK - bossDEF);
            		bossHP -= dmg;
            		cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
					} else {
					cout << " Not a Valid Item. Attack Missed";
					}
                    break;
                case 3:
                    if (hasSunglasses == true)
                    {cout << "	You use the Sunglasses. Boss's next attack will be skipped." << endl;
                    skipNextBossAttack = true; 
					hasNet = false; 
					int dmg = max(1, playerATK - bossDEF);
            		bossHP -= dmg;
            		cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
					} else {
					cout << " Not a Valid Item. Attack Missed";
					}
                    break;
                    break;
                case 4:
                    if (hasRustbite == true)
                    {cout << "	You use the Rustbite Charge. Boss Defense Permanently reduced by 6" << endl;
                    bossDEF -= 6;} else {cout << "  Not a Valid Item. Attack Missed";}
                    break;
                default:
                    cout << "	No Item Found! You Skip a Turn!";
                    break;
                }
        	break;
        } 
        default:
            int dmg = max(1, playerATK - bossDEF);
            bossHP -= dmg;
            cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
            break;
    }
    
        // Check boss death
        if (bossHP <= 0) {
            cout << "	Bjorne falls beneath your strike!" << endl;
            bossDead = true; fightOver = true;
        } else {
            // Boss taunt
            if (bossHP > 300) cout << "    Bjorne: Tiny spark. I will crush you slowly." << endl;
            else if (bossHP > 200) cout << "    Bjorne: You sting… nothing more." << endl;
            else if (bossHP > 100) cout << "	Bjorne: Impossible… you persist?!" << endl;
            else cout << "	Bjorne: I will DEVOUR YOU!" << endl;

            // Boss attack
            if (skipNextBossAttack) {
                cout << "	Boss's attack is skipped this turn." << endl;
                skipNextBossAttack = false;
            } else {
                int dmg = max(1, bossATK - playerDEF);
                playerHP -= dmg;
                cout << "	Bjorne Dealt " << dmg << " damage." << endl;
                if (playerHP <= 0 && hasAmulet) {
                    hasAmulet = false;
                    playerHP = 1;
                    cout << "	Schala's Amulet shatters and restores you to 1 HP." << endl;
                }
                if (playerHP <= 0) {
                    cout << "	You fall to the ground..." << endl;
                    playerDead = true; fightOver = true;
                }
            }
        }
    }
    // TURN 3
    if (!fightOver) {
                cout << endl << "   --- Turn 3 ---" << endl
             << "   Player HP: " << playerHP << " | ATK: " << playerATK << " | DEF: " << playerDEF << endl
             << "   Boss HP: " << bossHP << " | DEF: " << bossDEF << endl
             << "   Choose action: "<< endl 
             << "   [1] Attack  " << endl
             << "   [2] Use item" << endl
             << "   Move: ";
        cin >> choicechar;
        cout << endl;
        switch (choicechar) 
        {
        case 1:
            {            
            int dmg = max(1, playerATK - bossDEF);
            bossHP -= dmg;
            cout << "   You Dealt " << dmg << " damage." << endl;
            break;
        }
        case 2:
        if (hasRapier == true || hasNet == true || hasSunglasses == true || hasAmulet == true || hasRustbite == true) {
            cout << "   Items: " << endl;
                if (hasRapier == true){cout << "   [1] Divine Rapier [Active] - One-time use, deals 275 true damage (ignores DEF)." << endl;}
                if (hasNet == true){cout << "   [2] 90-Caliber Net [Active] - Free action, once. Skips the next boss attack." << endl;}
                if (hasSunglasses == true){cout << "   [3] Sunglasses [Active] - Free action, once. Skips the next boss attack." << endl;}
                if (hasRustbite == true){cout << "   [4] Rustbite Charge [Active] - Permanently reduces Bjorne’s DEF by 6." << endl;}
                if (hasAmulet == true){cout << "   Schala's Amulet [Passive] - If Jun’s HP falls to 0 or less, the amulet shatters and restores him to 1 HP instead. (Cannot be Used)" << endl;}
            cout << endl
				 << "   Which Item To Use? ";
            cin >> choicechar;
                switch (choicechar)
                {
                case 1:
                    if (hasRapier == true)
                    {cout << "	You use the Divine Rapier! (275 true damage)" << endl;
                    bossHP -= 275; hasRapier = false;} else {cout << "  Not a Valid Item. Attack Missed";}
                    break;
                case 2:
                    if (hasNet == true){
					cout << "	You use the 90-Caliber Net. Boss's next attack will be skipped." << endl;
                    skipNextBossAttack = true; 
					hasNet = false; 
					int dmg = max(1, playerATK - bossDEF);
            		bossHP -= dmg;
            		cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
					} else {
					cout << " Not a Valid Item. Attack Missed";
					}
                    break;
                case 3:
                    if (hasSunglasses == true)
                    {cout << "	You use the Sunglasses. Boss's next attack will be skipped." << endl;
                    skipNextBossAttack = true; 
					hasNet = false; 
					int dmg = max(1, playerATK - bossDEF);
            		bossHP -= dmg;
            		cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
					} else {
					cout << " Not a Valid Item. Attack Missed";
					}
                    break;
                    break;
                case 4:
                    if (hasRustbite == true)
                    {cout << "	You use the Rustbite Charge. Boss Defense Permanently reduced by 6" << endl;
                    bossDEF -= 6;} else {cout << "  Not a Valid Item. Attack Missed";}
                    break;
                default:
                    cout << "	No Item Found! You Skip a Turn!";
                    break;
                }
        	break;
        } 
        default:
            int dmg = max(1, playerATK - bossDEF);
            bossHP -= dmg;
            cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
            break;
    }
    
        // Check boss death
        if (bossHP <= 0) {
            cout << "	Bjorne falls beneath your strike!" << endl;
            bossDead = true; fightOver = true;
        } else {
            // Boss taunt
            if (bossHP > 300) cout << "    Bjorne: Tiny spark. I will crush you slowly." << endl;
            else if (bossHP > 200) cout << "    Bjorne: You sting… nothing more." << endl;
            else if (bossHP > 100) cout << "	Bjorne: Impossible… you persist?!" << endl;
            else cout << "	Bjorne: I will DEVOUR YOU!" << endl;

            // Boss attack
            if (skipNextBossAttack) {
                cout << "	Boss's attack is skipped this turn." << endl;
                skipNextBossAttack = false;
            } else {
                int dmg = max(1, bossATK - playerDEF);
                playerHP -= dmg;
                cout << "	Bjorne Dealt " << dmg << " damage." << endl;
                if (playerHP <= 0 && hasAmulet) {
                    hasAmulet = false;
                    playerHP = 1;
                    cout << "	Schala's Amulet shatters and restores you to 1 HP." << endl;
                }
                if (playerHP <= 0) {
                    cout << "	You fall to the ground..." << endl;
                    playerDead = true; fightOver = true;
                }
            }
        }
    }
    // TURN 4
    if (!fightOver) {
                cout << endl << "   --- Turn 4 ---" << endl
             << "   Player HP: " << playerHP << " | ATK: " << playerATK << " | DEF: " << playerDEF << endl
             << "   Boss HP: " << bossHP << " | DEF: " << bossDEF << endl
             << "   Choose action: "<< endl 
             << "   [1] Attack  " << endl
             << "   [2] Use item" << endl
             << "   Move: ";
        cin >> choicechar;
        cout << endl;
        switch (choicechar) 
        {
        case 1:
            {            
            int dmg = max(1, playerATK - bossDEF);
            bossHP -= dmg;
            cout << "   You Dealt " << dmg << " damage." << endl;
            break;
        }
        case 2:
        if (hasRapier == true || hasNet == true || hasSunglasses == true || hasAmulet == true || hasRustbite == true) {
            cout << "   Items: " << endl;
                if (hasRapier == true){cout << "   [1] Divine Rapier [Active] - One-time use, deals 275 true damage (ignores DEF)." << endl;}
                if (hasNet == true){cout << "   [2] 90-Caliber Net [Active] - Free action, once. Skips the next boss attack." << endl;}
                if (hasSunglasses == true){cout << "   [3] Sunglasses [Active] - Free action, once. Skips the next boss attack." << endl;}
                if (hasRustbite == true){cout << "   [4] Rustbite Charge [Active] - Permanently reduces Bjorne’s DEF by 6." << endl;}
                if (hasAmulet == true){cout << "   Schala's Amulet [Passive] - If Jun’s HP falls to 0 or less, the amulet shatters and restores him to 1 HP instead. (Cannot be Used)" << endl;}
            cout << endl
				 << "   Which Item To Use? ";
            cin >> choicechar;
                switch (choicechar)
                {
                case 1:
                    if (hasRapier == true)
                    {cout << "	You use the Divine Rapier! (275 true damage)" << endl;
                    bossHP -= 275; hasRapier = false;} else {cout << "  Not a Valid Item. Attack Missed";}
                    break;
                case 2:
                    if (hasNet == true){
					cout << "	You use the 90-Caliber Net. Boss's next attack will be skipped." << endl;
                    skipNextBossAttack = true; 
					hasNet = false; 
					int dmg = max(1, playerATK - bossDEF);
            		bossHP -= dmg;
            		cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
					} else {
					cout << " Not a Valid Item. Attack Missed";
					}
                    break;
                case 3:
                    if (hasSunglasses == true)
                    {cout << "	You use the Sunglasses. Boss's next attack will be skipped." << endl;
                    skipNextBossAttack = true; 
					hasNet = false; 
					int dmg = max(1, playerATK - bossDEF);
            		bossHP -= dmg;
            		cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
					} else {
					cout << " Not a Valid Item. Attack Missed";
					}
                    break;
                    break;
                case 4:
                    if (hasRustbite == true)
                    {cout << "	You use the Rustbite Charge. Boss Defense Permanently reduced by 6" << endl;
                    bossDEF -= 6;} else {cout << "  Not a Valid Item. Attack Missed";}
                    break;
                default:
                    cout << "	No Item Found! You Skip a Turn!";
                    break;
                }
        	break;
        } 
        default:
            int dmg = max(1, playerATK - bossDEF);
            bossHP -= dmg;
            cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
            break;
    }
    
        // Check boss death
        if (bossHP <= 0) {
            cout << "	Bjorne falls beneath your strike!" << endl;
            bossDead = true; fightOver = true;
        } else {
            // Boss taunt
            if (bossHP > 300) cout << "    Bjorne: Tiny spark. I will crush you slowly." << endl;
            else if (bossHP > 200) cout << "    Bjorne: You sting… nothing more." << endl;
            else if (bossHP > 100) cout << "	Bjorne: Impossible… you persist?!" << endl;
            else cout << "	Bjorne: I will DEVOUR YOU!" << endl;

            // Boss attack
            if (skipNextBossAttack) {
                cout << "	Boss's attack is skipped this turn." << endl;
                skipNextBossAttack = false;
            } else {
                int dmg = max(1, bossATK - playerDEF);
                playerHP -= dmg;
                cout << "	Bjorne Dealt " << dmg << " damage." << endl;
                if (playerHP <= 0 && hasAmulet) {
                    hasAmulet = false;
                    playerHP = 1;
                    cout << "	Schala's Amulet shatters and restores you to 1 HP." << endl;
                }
                if (playerHP <= 0) {
                    cout << "	You fall to the ground..." << endl;
                    playerDead = true; fightOver = true;
                }
            }
        }
    }
    // TURN 5 
    if (!fightOver) {
                cout << endl << "   --- Turn 5 ---" << endl
             << "   Player HP: " << playerHP << " | ATK: " << playerATK << " | DEF: " << playerDEF << endl
             << "   Boss HP: " << bossHP << " | DEF: " << bossDEF << endl
             << "   Choose action: "<< endl 
             << "   [1] Attack  " << endl
             << "   [2] Use item" << endl
             << "   Move: ";
        cin >> choicechar;
        cout << endl;
        switch (choicechar) 
        {
        case 1:
            {            
            int dmg = max(1, playerATK - bossDEF);
            bossHP -= dmg;
            cout << "   You Dealt " << dmg << " damage." << endl;
            break;
        }
        case 2:
        if (hasRapier == true || hasNet == true || hasSunglasses == true || hasAmulet == true || hasRustbite == true) {
            cout << "   Items: " << endl;
                if (hasRapier == true){cout << "   [1] Divine Rapier [Active] - One-time use, deals 275 true damage (ignores DEF)." << endl;}
                if (hasNet == true){cout << "   [2] 90-Caliber Net [Active] - Free action, once. Skips the next boss attack." << endl;}
                if (hasSunglasses == true){cout << "   [3] Sunglasses [Active] - Free action, once. Skips the next boss attack." << endl;}
                if (hasRustbite == true){cout << "   [4] Rustbite Charge [Active] - Permanently reduces Bjorne’s DEF by 6." << endl;}
                if (hasAmulet == true){cout << "   Schala's Amulet [Passive] - If Jun’s HP falls to 0 or less, the amulet shatters and restores him to 1 HP instead. (Cannot be Used)" << endl;}
            cout << endl
				 << "   Which Item To Use? ";
            cin >> choicechar;
                switch (choicechar)
                {
                case 1:
                    if (hasRapier == true)
                    {cout << "	You use the Divine Rapier! (275 true damage)" << endl;
                    bossHP -= 275; hasRapier = false;} else {cout << "  Not a Valid Item. Attack Missed";}
                    break;
                case 2:
                    if (hasNet == true){
					cout << "	You use the 90-Caliber Net. Boss's next attack will be skipped." << endl;
                    skipNextBossAttack = true; 
					hasNet = false; 
					int dmg = max(1, playerATK - bossDEF);
            		bossHP -= dmg;
            		cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
					} else {
					cout << " Not a Valid Item. Attack Missed";
					}
                    break;
                case 3:
                    if (hasSunglasses == true)
                    {cout << "	You use the Sunglasses. Boss's next attack will be skipped." << endl;
                    skipNextBossAttack = true; 
					hasNet = false; 
					int dmg = max(1, playerATK - bossDEF);
            		bossHP -= dmg;
            		cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
					} else {
					cout << " Not a Valid Item. Attack Missed";
					}
                    break;
                    break;
                case 4:
                    if (hasRustbite == true)
                    {cout << "	You use the Rustbite Charge. Boss Defense Permanently reduced by 6" << endl;
                    bossDEF -= 6;} else {cout << "  Not a Valid Item. Attack Missed";}
                    break;
                default:
                    cout << "	No Item Found! You Skip a Turn!";
                    break;
                }
        	break;
        } 
        default:
            int dmg = max(1, playerATK - bossDEF);
            bossHP -= dmg;
            cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
            break;
    }
    
        // Check boss death
        if (bossHP <= 0) {
            cout << "	Bjorne falls beneath your strike!" << endl;
            bossDead = true; fightOver = true;
        } else {
            // Boss taunt
            if (bossHP > 300) cout << "    Bjorne: Tiny spark. I will crush you slowly." << endl;
            else if (bossHP > 200) cout << "    Bjorne: You sting… nothing more." << endl;
            else if (bossHP > 100) cout << "	Bjorne: Impossible… you persist?!" << endl;
            else cout << "	Bjorne: I will DEVOUR YOU!" << endl;

            // Boss attack
            if (skipNextBossAttack) {
                cout << "	Boss's attack is skipped this turn." << endl;
                skipNextBossAttack = false;
            } else {
                int dmg = max(1, bossATK - playerDEF);
                playerHP -= dmg;
                cout << "	Bjorne Dealt " << dmg << " damage." << endl;
                if (playerHP <= 0 && hasAmulet) {
                    hasAmulet = false;
                    playerHP = 1;
                    cout << "	Schala's Amulet shatters and restores you to 1 HP." << endl;
                }
                if (playerHP <= 0) {
                    cout << "	You fall to the ground..." << endl;
                    playerDead = true; fightOver = true;
                }
            }
        }
    }
    // TURN 6 
    if (!fightOver) {
                cout << endl << "   --- Turn 6 ---" << endl
             << "   Player HP: " << playerHP << " | ATK: " << playerATK << " | DEF: " << playerDEF << endl
             << "   Boss HP: " << bossHP << " | DEF: " << bossDEF << endl
             << "   Choose action: "<< endl 
             << "   [1] Attack  " << endl
             << "   [2] Use item" << endl
             << "   Move: ";
        cin >> choicechar;
        cout << endl;
        switch (choicechar) 
        {
        case 1:
            {            
            int dmg = max(1, playerATK - bossDEF);
            bossHP -= dmg;
            cout << "   You Dealt " << dmg << " damage." << endl;
            break;
        }
        case 2:
        if (hasRapier == true || hasNet == true || hasSunglasses == true || hasAmulet == true || hasRustbite == true) {
            cout << "   Items: " << endl;
                if (hasRapier == true){cout << "   [1] Divine Rapier [Active] - One-time use, deals 275 true damage (ignores DEF)." << endl;}
                if (hasNet == true){cout << "   [2] 90-Caliber Net [Active] - Free action, once. Skips the next boss attack." << endl;}
                if (hasSunglasses == true){cout << "   [3] Sunglasses [Active] - Free action, once. Skips the next boss attack." << endl;}
                if (hasRustbite == true){cout << "   [4] Rustbite Charge [Active] - Permanently reduces Bjorne’s DEF by 6." << endl;}
                if (hasAmulet == true){cout << "   Schala's Amulet [Passive] - If Jun’s HP falls to 0 or less, the amulet shatters and restores him to 1 HP instead. (Cannot be Used)" << endl;}
            cout << endl
				 << "   Which Item To Use? ";
            cin >> choicechar;
                switch (choicechar)
                {
                case 1:
                    if (hasRapier == true)
                    {cout << "	You use the Divine Rapier! (275 true damage)" << endl;
                    bossHP -= 275; hasRapier = false;} else {cout << "  Not a Valid Item. Attack Missed";}
                    break;
                case 2:
                    if (hasNet == true){
					cout << "	You use the 90-Caliber Net. Boss's next attack will be skipped." << endl;
                    skipNextBossAttack = true; 
					hasNet = false; 
					int dmg = max(1, playerATK - bossDEF);
            		bossHP -= dmg;
            		cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
					} else {
					cout << " Not a Valid Item. Attack Missed";
					}
                    break;
                case 3:
                    if (hasSunglasses == true)
                    {cout << "	You use the Sunglasses. Boss's next attack will be skipped." << endl;
                    skipNextBossAttack = true; 
					hasNet = false; 
					int dmg = max(1, playerATK - bossDEF);
            		bossHP -= dmg;
            		cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
					} else {
					cout << " Not a Valid Item. Attack Missed";
					}
                    break;
                    break;
                case 4:
                    if (hasRustbite == true)
                    {cout << "	You use the Rustbite Charge. Boss Defense Permanently reduced by 6" << endl;
                    bossDEF -= 6;} else {cout << "  Not a Valid Item. Attack Missed";}
                    break;
                default:
                    cout << "	No Item Found! You Skip a Turn!";
                    break;
                }
        	break;
        } 
        default:
            int dmg = max(1, playerATK - bossDEF);
            bossHP -= dmg;
            cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
            break;
    }
    
        // Check boss death
        if (bossHP <= 0) {
            cout << "	Bjorne falls beneath your strike!" << endl;
            bossDead = true; fightOver = true;
        } else {
            // Boss taunt
            if (bossHP > 300) cout << "    Bjorne: Tiny spark. I will crush you slowly." << endl;
            else if (bossHP > 200) cout << "    Bjorne: You sting… nothing more." << endl;
            else if (bossHP > 100) cout << "	Bjorne: Impossible… you persist?!" << endl;
            else cout << "	Bjorne: I will DEVOUR YOU!" << endl;

            // Boss attack
            if (skipNextBossAttack) {
                cout << "	Boss's attack is skipped this turn." << endl;
                skipNextBossAttack = false;
            } else {
                int dmg = max(1, bossATK - playerDEF);
                playerHP -= dmg;
                cout << "	Bjorne Dealt " << dmg << " damage." << endl;
                if (playerHP <= 0 && hasAmulet) {
                    hasAmulet = false;
                    playerHP = 1;
                    cout << "	Schala's Amulet shatters and restores you to 1 HP." << endl;
                }
                if (playerHP <= 0) {
                    cout << "	You fall to the ground..." << endl;
                    playerDead = true; fightOver = true;
                }
            }
        }
    }
    // TURN 7 
    if (!fightOver) {
                cout << endl << "   --- Turn 7 ---" << endl
             << "   Player HP: " << playerHP << " | ATK: " << playerATK << " | DEF: " << playerDEF << endl
             << "   Boss HP: " << bossHP << " | DEF: " << bossDEF << endl
             << "   Choose action: "<< endl 
             << "   [1] Attack  " << endl
             << "   [2] Use item" << endl
             << "   Move: ";
        cin >> choicechar;
        cout << endl;
        switch (choicechar) 
        {
        case 1:
            {            
            int dmg = max(1, playerATK - bossDEF);
            bossHP -= dmg;
            cout << "   You Dealt " << dmg << " damage." << endl;
            break;
        }
        case 2:
        if (hasRapier == true || hasNet == true || hasSunglasses == true || hasAmulet == true || hasRustbite == true) {
            cout << "   Items: " << endl;
                if (hasRapier == true){cout << "   [1] Divine Rapier [Active] - One-time use, deals 275 true damage (ignores DEF)." << endl;}
                if (hasNet == true){cout << "   [2] 90-Caliber Net [Active] - Free action, once. Skips the next boss attack." << endl;}
                if (hasSunglasses == true){cout << "   [3] Sunglasses [Active] - Free action, once. Skips the next boss attack." << endl;}
                if (hasRustbite == true){cout << "   [4] Rustbite Charge [Active] - Permanently reduces Bjorne’s DEF by 6." << endl;}
                if (hasAmulet == true){cout << "   Schala's Amulet [Passive] - If Jun’s HP falls to 0 or less, the amulet shatters and restores him to 1 HP instead. (Cannot be Used)" << endl;}
            cout << endl
				 << "   Which Item To Use? ";
            cin >> choicechar;
                switch (choicechar)
                {
                case 1:
                    if (hasRapier == true)
                    {cout << "	You use the Divine Rapier! (275 true damage)" << endl;
                    bossHP -= 275; hasRapier = false;} else {cout << "  Not a Valid Item. Attack Missed";}
                    break;
                case 2:
                    if (hasNet == true){
					cout << "	You use the 90-Caliber Net. Boss's next attack will be skipped." << endl;
                    skipNextBossAttack = true; 
					hasNet = false; 
					int dmg = max(1, playerATK - bossDEF);
            		bossHP -= dmg;
            		cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
					} else {
					cout << " Not a Valid Item. Attack Missed";
					}
                    break;
                case 3:
                    if (hasSunglasses == true)
                    {cout << "	You use the Sunglasses. Boss's next attack will be skipped." << endl;
                    skipNextBossAttack = true; 
					hasNet = false; 
					int dmg = max(1, playerATK - bossDEF);
            		bossHP -= dmg;
            		cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
					} else {
					cout << " Not a Valid Item. Attack Missed";
					}
                    break;
                    break;
                case 4:
                    if (hasRustbite == true)
                    {cout << "	You use the Rustbite Charge. Boss Defense Permanently reduced by 6" << endl;
                    bossDEF -= 6;} else {cout << "  Not a Valid Item. Attack Missed";}
                    break;
                default:
                    cout << "	No Item Found! You Skip a Turn!";
                    break;
                }
        	break;
        } 
        default:
            int dmg = max(1, playerATK - bossDEF);
            bossHP -= dmg;
            cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
            break;
    }
    
        // Check boss death
        if (bossHP <= 0) {
            cout << "	Bjorne falls beneath your strike!" << endl;
            bossDead = true; fightOver = true;
        } else {
            // Boss taunt
            if (bossHP > 300) cout << "    Bjorne: Tiny spark. I will crush you slowly." << endl;
            else if (bossHP > 200) cout << "    Bjorne: You sting… nothing more." << endl;
            else if (bossHP > 100) cout << "	Bjorne: Impossible… you persist?!" << endl;
            else cout << "	Bjorne: I will DEVOUR YOU!" << endl;

            // Boss attack
            if (skipNextBossAttack) {
                cout << "	Boss's attack is skipped this turn." << endl;
                skipNextBossAttack = false;
            } else {
                int dmg = max(1, bossATK - playerDEF);
                playerHP -= dmg;
                cout << "	Bjorne Dealt " << dmg << " damage." << endl;
                if (playerHP <= 0 && hasAmulet) {
                    hasAmulet = false;
                    playerHP = 1;
                    cout << "	Schala's Amulet shatters and restores you to 1 HP." << endl;
                }
                if (playerHP <= 0) {
                    cout << "	You fall to the ground..." << endl;
                    playerDead = true; fightOver = true;
                }
            }
        }
    }
    // TURN 8 
    if (!fightOver) {
                cout << endl << "   --- Turn 8 ---" << endl
             << "   Player HP: " << playerHP << " | ATK: " << playerATK << " | DEF: " << playerDEF << endl
             << "   Boss HP: " << bossHP << " | DEF: " << bossDEF << endl
             << "   Choose action: "<< endl 
             << "   [1] Attack  " << endl
             << "   [2] Use item" << endl
             << "   Move: ";
        cin >> choicechar;
        cout << endl;
        switch (choicechar) 
        {
        case 1:
            {            
            int dmg = max(1, playerATK - bossDEF);
            bossHP -= dmg;
            cout << "   You Dealt " << dmg << " damage." << endl;
            break;
        }
        case 2:
        if (hasRapier == true || hasNet == true || hasSunglasses == true || hasAmulet == true || hasRustbite == true) {
            cout << "   Items: " << endl;
                if (hasRapier == true){cout << "   [1] Divine Rapier [Active] - One-time use, deals 275 true damage (ignores DEF)." << endl;}
                if (hasNet == true){cout << "   [2] 90-Caliber Net [Active] - Free action, once. Skips the next boss attack." << endl;}
                if (hasSunglasses == true){cout << "   [3] Sunglasses [Active] - Free action, once. Skips the next boss attack." << endl;}
                if (hasRustbite == true){cout << "   [4] Rustbite Charge [Active] - Permanently reduces Bjorne’s DEF by 6." << endl;}
                if (hasAmulet == true){cout << "   Schala's Amulet [Passive] - If Jun’s HP falls to 0 or less, the amulet shatters and restores him to 1 HP instead. (Cannot be Used)" << endl;}
            cout << endl
				 << "   Which Item To Use? ";
            cin >> choicechar;
                switch (choicechar)
                {
                case 1:
                    if (hasRapier == true)
                    {cout << "	You use the Divine Rapier! (275 true damage)" << endl;
                    bossHP -= 275; hasRapier = false;} else {cout << "  Not a Valid Item. Attack Missed";}
                    break;
                case 2:
                    if (hasNet == true){
					cout << "	You use the 90-Caliber Net. Boss's next attack will be skipped." << endl;
                    skipNextBossAttack = true; 
					hasNet = false; 
					int dmg = max(1, playerATK - bossDEF);
            		bossHP -= dmg;
            		cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
					} else {
					cout << " Not a Valid Item. Attack Missed";
					}
                    break;
                case 3:
                    if (hasSunglasses == true)
                    {cout << "	You use the Sunglasses. Boss's next attack will be skipped." << endl;
                    skipNextBossAttack = true; 
					hasNet = false; 
					int dmg = max(1, playerATK - bossDEF);
            		bossHP -= dmg;
            		cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
					} else {
					cout << " Not a Valid Item. Attack Missed";
					}
                    break;
                    break;
                case 4:
                    if (hasRustbite == true)
                    {cout << "	You use the Rustbite Charge. Boss Defense Permanently reduced by 6" << endl;
                    bossDEF -= 6;} else {cout << "  Not a Valid Item. Attack Missed";}
                    break;
                default:
                    cout << "	No Item Found! You Skip a Turn!";
                    break;
                }
        	break;
        } 
        default:
            int dmg = max(1, playerATK - bossDEF);
            bossHP -= dmg;
            cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
            break;
    }
    
        // Check boss death
        if (bossHP <= 0) {
            cout << "	Bjorne falls beneath your strike!" << endl;
            bossDead = true; fightOver = true;
        } else {
            // Boss taunt
            if (bossHP > 300) cout << "    Bjorne: Tiny spark. I will crush you slowly." << endl;
            else if (bossHP > 200) cout << "    Bjorne: You sting… nothing more." << endl;
            else if (bossHP > 100) cout << "	Bjorne: Impossible… you persist?!" << endl;
            else cout << "	Bjorne: I will DEVOUR YOU!" << endl;

            // Boss attack
            if (skipNextBossAttack) {
                cout << "	Boss's attack is skipped this turn." << endl;
                skipNextBossAttack = false;
            } else {
                int dmg = max(1, bossATK - playerDEF);
                playerHP -= dmg;
                cout << "	Bjorne Dealt " << dmg << " damage." << endl;
                if (playerHP <= 0 && hasAmulet) {
                    hasAmulet = false;
                    playerHP = 1;
                    cout << "	Schala's Amulet shatters and restores you to 1 HP." << endl;
                }
                if (playerHP <= 0) {
                    cout << "	You fall to the ground..." << endl;
                    playerDead = true; fightOver = true;
                }
            }
        }
    }
    // TURN 9 
    if (!fightOver) {
                cout << endl << "   --- Turn 9 ---" << endl
             << "   Player HP: " << playerHP << " | ATK: " << playerATK << " | DEF: " << playerDEF << endl
             << "   Boss HP: " << bossHP << " | DEF: " << bossDEF << endl
             << "   Choose action: "<< endl 
             << "   [1] Attack  " << endl
             << "   [2] Use item" << endl
             << "   Move: ";
        cin >> choicechar;
        cout << endl;
        switch (choicechar) 
        {
        case 1:
            {            
            int dmg = max(1, playerATK - bossDEF);
            bossHP -= dmg;
            cout << "   You Dealt " << dmg << " damage." << endl;
            break;
        }
        case 2:
        if (hasRapier == true || hasNet == true || hasSunglasses == true || hasAmulet == true || hasRustbite == true) {
            cout << "   Items: " << endl;
                if (hasRapier == true){cout << "   [1] Divine Rapier [Active] - One-time use, deals 275 true damage (ignores DEF)." << endl;}
                if (hasNet == true){cout << "   [2] 90-Caliber Net [Active] - Free action, once. Skips the next boss attack." << endl;}
                if (hasSunglasses == true){cout << "   [3] Sunglasses [Active] - Free action, once. Skips the next boss attack." << endl;}
                if (hasRustbite == true){cout << "   [4] Rustbite Charge [Active] - Permanently reduces Bjorne’s DEF by 6." << endl;}
                if (hasAmulet == true){cout << "   Schala's Amulet [Passive] - If Jun’s HP falls to 0 or less, the amulet shatters and restores him to 1 HP instead. (Cannot be Used)" << endl;}
            cout << endl
				 << "   Which Item To Use? ";
            cin >> choicechar;
                switch (choicechar)
                {
                case 1:
                    if (hasRapier == true)
                    {cout << "	You use the Divine Rapier! (275 true damage)" << endl;
                    bossHP -= 275; hasRapier = false;} else {cout << "  Not a Valid Item. Attack Missed";}
                    break;
                case 2:
                    if (hasNet == true){
					cout << "	You use the 90-Caliber Net. Boss's next attack will be skipped." << endl;
                    skipNextBossAttack = true; 
					hasNet = false; 
					int dmg = max(1, playerATK - bossDEF);
            		bossHP -= dmg;
            		cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
					} else {
					cout << " Not a Valid Item. Attack Missed";
					}
                    break;
                case 3:
                    if (hasSunglasses == true)
                    {cout << "	You use the Sunglasses. Boss's next attack will be skipped." << endl;
                    skipNextBossAttack = true; 
					hasNet = false; 
					int dmg = max(1, playerATK - bossDEF);
            		bossHP -= dmg;
            		cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
					} else {
					cout << " Not a Valid Item. Attack Missed";
					}
                    break;
                    break;
                case 4:
                    if (hasRustbite == true)
                    {cout << "	You use the Rustbite Charge. Boss Defense Permanently reduced by 6" << endl;
                    bossDEF -= 6;} else {cout << "  Not a Valid Item. Attack Missed";}
                    break;
                default:
                    cout << "	No Item Found! You Skip a Turn!";
                    break;
                }
        	break;
        } 
        default:
            int dmg = max(1, playerATK - bossDEF);
            bossHP -= dmg;
            cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
            break;
    }
    
        // Check boss death
        if (bossHP <= 0) {
            cout << "	Bjorne falls beneath your strike!" << endl;
            bossDead = true; fightOver = true;
        } else {
            // Boss taunt
            if (bossHP > 300) cout << "    Bjorne: Tiny spark. I will crush you slowly." << endl;
            else if (bossHP > 200) cout << "    Bjorne: You sting… nothing more." << endl;
            else if (bossHP > 100) cout << "	Bjorne: Impossible… you persist?!" << endl;
            else cout << "	Bjorne: I will DEVOUR YOU!" << endl;

            // Boss attack
            if (skipNextBossAttack) {
                cout << "	Boss's attack is skipped this turn." << endl;
                skipNextBossAttack = false;
            } else {
                int dmg = max(1, bossATK - playerDEF);
                playerHP -= dmg;
                cout << "	Bjorne Dealt " << dmg << " damage." << endl;
                if (playerHP <= 0 && hasAmulet) {
                    hasAmulet = false;
                    playerHP = 1;
                    cout << "	Schala's Amulet shatters and restores you to 1 HP." << endl;
                }
                if (playerHP <= 0) {
                    cout << "	You fall to the ground..." << endl;
                    playerDead = true; fightOver = true;
                }
            }
        }
    }
    // TURN 10 
    if (!fightOver) {
                cout << endl << "   --- Turn 10 ---" << endl
             << "   Player HP: " << playerHP << " | ATK: " << playerATK << " | DEF: " << playerDEF << endl
             << "   Boss HP: " << bossHP << " | DEF: " << bossDEF << endl
             << "   Choose action: "<< endl 
             << "   [1] Attack  " << endl
             << "   [2] Use item" << endl
             << "   Move: ";
        cin >> choicechar;
        cout << endl;
        switch (choicechar) 
        {
        case 1:
            {            
            int dmg = max(1, playerATK - bossDEF);
            bossHP -= dmg;
            cout << "   You Dealt " << dmg << " damage." << endl;
            break;
        }
        case 2:
        if (hasRapier == true || hasNet == true || hasSunglasses == true || hasAmulet == true || hasRustbite == true) {
            cout << "   Items: " << endl;
                if (hasRapier == true){cout << "   [1] Divine Rapier [Active] - One-time use, deals 275 true damage (ignores DEF)." << endl;}
                if (hasNet == true){cout << "   [2] 90-Caliber Net [Active] - Free action, once. Skips the next boss attack." << endl;}
                if (hasSunglasses == true){cout << "   [3] Sunglasses [Active] - Free action, once. Skips the next boss attack." << endl;}
                if (hasRustbite == true){cout << "   [4] Rustbite Charge [Active] - Permanently reduces Bjorne’s DEF by 6." << endl;}
                if (hasAmulet == true){cout << "   Schala's Amulet [Passive] - If Jun’s HP falls to 0 or less, the amulet shatters and restores him to 1 HP instead. (Cannot be Used)" << endl;}
            cout << endl
				 << "   Which Item To Use? ";
            cin >> choicechar;
                switch (choicechar)
                {
                case 1:
                    if (hasRapier == true)
                    {cout << "	You use the Divine Rapier! (275 true damage)" << endl;
                    bossHP -= 275; hasRapier = false;} else {cout << "  Not a Valid Item. Attack Missed";}
                    break;
                case 2:
                    if (hasNet == true){
					cout << "	You use the 90-Caliber Net. Boss's next attack will be skipped." << endl;
                    skipNextBossAttack = true; 
					hasNet = false; 
					int dmg = max(1, playerATK - bossDEF);
            		bossHP -= dmg;
            		cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
					} else {
					cout << " Not a Valid Item. Attack Missed";
					}
                    break;
                case 3:
                    if (hasSunglasses == true)
                    {cout << "	You use the Sunglasses. Boss's next attack will be skipped." << endl;
                    skipNextBossAttack = true; 
					hasNet = false; 
					int dmg = max(1, playerATK - bossDEF);
            		bossHP -= dmg;
            		cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
					} else {
					cout << " Not a Valid Item. Attack Missed";
					}
                    break;
                    break;
                case 4:
                    if (hasRustbite == true)
                    {cout << "	You use the Rustbite Charge. Boss Defense Permanently reduced by 6" << endl;
                    bossDEF -= 6;} else {cout << "  Not a Valid Item. Attack Missed";}
                    break;
                default:
                    cout << "	No Item Found! You Skip a Turn!";
                    break;
                }
        	break;
        } 
        default:
            int dmg = max(1, playerATK - bossDEF);
            bossHP -= dmg;
            cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
            break;
    }
    
        // Check boss death
        if (bossHP <= 0) {
            cout << "	Bjorne falls beneath your strike!" << endl;
            bossDead = true; fightOver = true;
        } else {
            // Boss taunt
            if (bossHP > 300) cout << "    Bjorne: Tiny spark. I will crush you slowly." << endl;
            else if (bossHP > 200) cout << "    Bjorne: You sting… nothing more." << endl;
            else if (bossHP > 100) cout << "	Bjorne: Impossible… you persist?!" << endl;
            else cout << "	Bjorne: I will DEVOUR YOU!" << endl;

            // Boss attack
            if (skipNextBossAttack) {
                cout << "	Boss's attack is skipped this turn." << endl;
                skipNextBossAttack = false;
            } else {
                int dmg = max(1, bossATK - playerDEF);
                playerHP -= dmg;
                cout << "	Bjorne Dealt " << dmg << " damage." << endl;
                if (playerHP <= 0 && hasAmulet) {
                    hasAmulet = false;
                    playerHP = 1;
                    cout << "	Schala's Amulet shatters and restores you to 1 HP." << endl;
                }
                if (playerHP <= 0) {
                    cout << "	You fall to the ground..." << endl;
                    playerDead = true; fightOver = true;
                }
            }
        }
    }
    // TURN 11 
    if (!fightOver) {
                cout << endl << "   --- Turn 11 ---" << endl
             << "   Player HP: " << playerHP << " | ATK: " << playerATK << " | DEF: " << playerDEF << endl
             << "   Boss HP: " << bossHP << " | DEF: " << bossDEF << endl
             << "   Choose action: "<< endl 
             << "   [1] Attack  " << endl
             << "   [2] Use item" << endl
             << "   Move: ";
        cin >> choicechar;
        cout << endl;
        switch (choicechar) 
        {
        case 1:
            {            
            int dmg = max(1, playerATK - bossDEF);
            bossHP -= dmg;
            cout << "   You Dealt " << dmg << " damage." << endl;
            break;
        }
        case 2:
        if (hasRapier == true || hasNet == true || hasSunglasses == true || hasAmulet == true || hasRustbite == true) {
            cout << "   Items: " << endl;
                if (hasRapier == true){cout << "   [1] Divine Rapier [Active] - One-time use, deals 275 true damage (ignores DEF)." << endl;}
                if (hasNet == true){cout << "   [2] 90-Caliber Net [Active] - Free action, once. Skips the next boss attack." << endl;}
                if (hasSunglasses == true){cout << "   [3] Sunglasses [Active] - Free action, once. Skips the next boss attack." << endl;}
                if (hasRustbite == true){cout << "   [4] Rustbite Charge [Active] - Permanently reduces Bjorne’s DEF by 6." << endl;}
                if (hasAmulet == true){cout << "   Schala's Amulet [Passive] - If Jun’s HP falls to 0 or less, the amulet shatters and restores him to 1 HP instead. (Cannot be Used)" << endl;}
            cout << endl
				 << "   Which Item To Use? ";
            cin >> choicechar;
                switch (choicechar)
                {
                case 1:
                    if (hasRapier == true)
                    {cout << "	You use the Divine Rapier! (275 true damage)" << endl;
                    bossHP -= 275; hasRapier = false;} else {cout << "  Not a Valid Item. Attack Missed";}
                    break;
                case 2:
                    if (hasNet == true){
					cout << "	You use the 90-Caliber Net. Boss's next attack will be skipped." << endl;
                    skipNextBossAttack = true; 
					hasNet = false; 
					int dmg = max(1, playerATK - bossDEF);
            		bossHP -= dmg;
            		cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
					} else {
					cout << " Not a Valid Item. Attack Missed";
					}
                    break;
                case 3:
                    if (hasSunglasses == true)
                    {cout << "	You use the Sunglasses. Boss's next attack will be skipped." << endl;
                    skipNextBossAttack = true; 
					hasNet = false; 
					int dmg = max(1, playerATK - bossDEF);
            		bossHP -= dmg;
            		cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
					} else {
					cout << " Not a Valid Item. Attack Missed";
					}
                    break;
                    break;
                case 4:
                    if (hasRustbite == true)
                    {cout << "	You use the Rustbite Charge. Boss Defense Permanently reduced by 6" << endl;
                    bossDEF -= 6;} else {cout << "  Not a Valid Item. Attack Missed";}
                    break;
                default:
                    cout << "	No Item Found! You Skip a Turn!";
                    break;
                }
        	break;
        } 
        default:
            int dmg = max(1, playerATK - bossDEF);
            bossHP -= dmg;
            cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
            break;
    }
    
        // Check boss death
        if (bossHP <= 0) {
            cout << "	Bjorne falls beneath your strike!" << endl;
            bossDead = true; fightOver = true;
        } else {
            // Boss taunt
            if (bossHP > 300) cout << "    Bjorne: Tiny spark. I will crush you slowly." << endl;
            else if (bossHP > 200) cout << "    Bjorne: You sting… nothing more." << endl;
            else if (bossHP > 100) cout << "	Bjorne: Impossible… you persist?!" << endl;
            else cout << "	Bjorne: I will DEVOUR YOU!" << endl;

            // Boss attack
            if (skipNextBossAttack) {
                cout << "	Boss's attack is skipped this turn." << endl;
                skipNextBossAttack = false;
            } else {
                int dmg = max(1, bossATK - playerDEF);
                playerHP -= dmg;
                cout << "	Bjorne Dealt " << dmg << " damage." << endl;
                if (playerHP <= 0 && hasAmulet) {
                    hasAmulet = false;
                    playerHP = 1;
                    cout << "	Schala's Amulet shatters and restores you to 1 HP." << endl;
                }
                if (playerHP <= 0) {
                    cout << "	You fall to the ground..." << endl;
                    playerDead = true; fightOver = true;
                }
            }
        }
    }
    // TURN 12
    if (!fightOver) {
                cout << endl << "   --- Turn 12 ---" << endl
             << "   Player HP: " << playerHP << " | ATK: " << playerATK << " | DEF: " << playerDEF << endl
             << "   Boss HP: " << bossHP << " | DEF: " << bossDEF << endl
             << "   Choose action: "<< endl 
             << "   [1] Attack  " << endl
             << "   [2] Use item" << endl
             << "   Move: ";
        cin >> choicechar;
        cout << endl;
        switch (choicechar) 
        {
        case 1:
            {            
            int dmg = max(1, playerATK - bossDEF);
            bossHP -= dmg;
            cout << "   You Dealt " << dmg << " damage." << endl;
            break;
        }
        case 2:
        if (hasRapier == true || hasNet == true || hasSunglasses == true || hasAmulet == true || hasRustbite == true) {
            cout << "   Items: " << endl;
                if (hasRapier == true){cout << "   [1] Divine Rapier [Active] - One-time use, deals 275 true damage (ignores DEF)." << endl;}
                if (hasNet == true){cout << "   [2] 90-Caliber Net [Active] - Free action, once. Skips the next boss attack." << endl;}
                if (hasSunglasses == true){cout << "   [3] Sunglasses [Active] - Free action, once. Skips the next boss attack." << endl;}
                if (hasRustbite == true){cout << "   [4] Rustbite Charge [Active] - Permanently reduces Bjorne’s DEF by 6." << endl;}
                if (hasAmulet == true){cout << "   Schala's Amulet [Passive] - If Jun’s HP falls to 0 or less, the amulet shatters and restores him to 1 HP instead. (Cannot be Used)" << endl;}
            cout << endl
				 << "   Which Item To Use? ";
            cin >> choicechar;
                switch (choicechar)
                {
                case 1:
                    if (hasRapier == true)
                    {cout << "	You use the Divine Rapier! (275 true damage)" << endl;
                    bossHP -= 275; hasRapier = false;} else {cout << "  Not a Valid Item. Attack Missed";}
                    break;
                case 2:
                    if (hasNet == true){
					cout << "	You use the 90-Caliber Net. Boss's next attack will be skipped." << endl;
                    skipNextBossAttack = true; 
					hasNet = false; 
					int dmg = max(1, playerATK - bossDEF);
            		bossHP -= dmg;
            		cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
					} else {
					cout << " Not a Valid Item. Attack Missed";
					}
                    break;
                case 3:
                    if (hasSunglasses == true)
                    {cout << "	You use the Sunglasses. Boss's next attack will be skipped." << endl;
                    skipNextBossAttack = true; 
					hasNet = false; 
					int dmg = max(1, playerATK - bossDEF);
            		bossHP -= dmg;
            		cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
					} else {
					cout << " Not a Valid Item. Attack Missed";
					}
                    break;
                    break;
                case 4:
                    if (hasRustbite == true)
                    {cout << "	You use the Rustbite Charge. Boss Defense Permanently reduced by 6" << endl;
                    bossDEF -= 6;} else {cout << "  Not a Valid Item. Attack Missed";}
                    break;
                default:
                    cout << "	No Item Found! You Skip a Turn!";
                    break;
                }
        	break;
        } 
        default:
            int dmg = max(1, playerATK - bossDEF);
            bossHP -= dmg;
            cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
            break;
    }
    
        // Check boss death
        if (bossHP <= 0) {
            cout << "	Bjorne falls beneath your strike!" << endl;
            bossDead = true; fightOver = true;
        } else {
            // Boss taunt
            if (bossHP > 300) cout << "    Bjorne: Tiny spark. I will crush you slowly." << endl;
            else if (bossHP > 200) cout << "    Bjorne: You sting… nothing more." << endl;
            else if (bossHP > 100) cout << "	Bjorne: Impossible… you persist?!" << endl;
            else cout << "	Bjorne: I will DEVOUR YOU!" << endl;

            // Boss attack
            if (skipNextBossAttack) {
                cout << "	Boss's attack is skipped this turn." << endl;
                skipNextBossAttack = false;
            } else {
                int dmg = max(1, bossATK - playerDEF);
                playerHP -= dmg;
                cout << "	Bjorne Dealt " << dmg << " damage." << endl;
                if (playerHP <= 0 && hasAmulet) {
                    hasAmulet = false;
                    playerHP = 1;
                    cout << "	Schala's Amulet shatters and restores you to 1 HP." << endl;
                }
                if (playerHP <= 0) {
                    cout << "	You fall to the ground..." << endl;
                    playerDead = true; fightOver = true;
                }
            }
        }
    }
    // TURN 13 
    if (!fightOver) {
        cout << endl << "   --- Turn 13 ---" << endl
             << "   Player HP: " << playerHP << " | ATK: " << playerATK << " | DEF: " << playerDEF << endl
             << "   Boss HP: " << bossHP << " | DEF: " << bossDEF << endl
             << "   Choose action: "<< endl 
             << "   [1] Attack  " << endl
             << "   [2] Use item" << endl
             << "   Move: ";
        cin >> choicechar;
        cout << endl;
        switch (choicechar) 
        {
        case 1:
            {            
            int dmg = max(1, playerATK - bossDEF);
            bossHP -= dmg;
            cout << "   You Dealt " << dmg << " damage." << endl;
            break;
        }
        case 2:
        if (hasRapier == true || hasNet == true || hasSunglasses == true || hasAmulet == true || hasRustbite == true) {
            cout << "   Items: " << endl;
                if (hasRapier == true){cout << "   [1] Divine Rapier [Active] - One-time use, deals 275 true damage (ignores DEF)." << endl;}
                if (hasNet == true){cout << "   [2] 90-Caliber Net [Active] - Free action, once. Skips the next boss attack." << endl;}
                if (hasSunglasses == true){cout << "   [3] Sunglasses [Active] - Free action, once. Skips the next boss attack." << endl;}
                if (hasRustbite == true){cout << "   [4] Rustbite Charge [Active] - Permanently reduces Bjorne’s DEF by 6." << endl;}
                if (hasAmulet == true){cout << "   Schala's Amulet [Passive] - If Jun’s HP falls to 0 or less, the amulet shatters and restores him to 1 HP instead. (Cannot be Used)" << endl;}
            cout << endl
				 << "   Which Item To Use? ";
            cin >> choicechar;
                switch (choicechar)
                {
                case 1:
                    if (hasRapier == true)
                    {cout << "	You use the Divine Rapier! (275 true damage)" << endl;
                    bossHP -= 275; hasRapier = false;} else {cout << "  Not a Valid Item. Attack Missed";}
                    break;
                case 2:
                    if (hasNet == true){
					cout << "	You use the 90-Caliber Net. Boss's next attack will be skipped." << endl;
                    skipNextBossAttack = true; 
					hasNet = false; 
					int dmg = max(1, playerATK - bossDEF);
            		bossHP -= dmg;
            		cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
					} else {
					cout << " Not a Valid Item. Attack Missed";
					}
                    break;
                case 3:
                    if (hasSunglasses == true)
                    {cout << "	You use the Sunglasses. Boss's next attack will be skipped." << endl;
                    skipNextBossAttack = true; 
					hasNet = false; 
					int dmg = max(1, playerATK - bossDEF);
            		bossHP -= dmg;
            		cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
					} else {
					cout << " Not a Valid Item. Attack Missed";
					}
                    break;
                    break;
                case 4:
                    if (hasRustbite == true)
                    {cout << "	You use the Rustbite Charge. Boss Defense Permanently reduced by 6" << endl;
                    bossDEF -= 6;} else {cout << "  Not a Valid Item. Attack Missed";}
                    break;
                default:
                    cout << "	No Item Found! You Skip a Turn!";
                    break;
                }
        	break;
        } 
        default:
            int dmg = max(1, playerATK - bossDEF);
            bossHP -= dmg;
            cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
            break;
    }
    
        // Check boss death
        if (bossHP <= 0) {
            cout << "	Bjorne falls beneath your strike!" << endl;
            bossDead = true; fightOver = true;
        } else {
            // Boss taunt
            if (bossHP > 300) cout << "    Bjorne: Tiny spark. I will crush you slowly." << endl;
            else if (bossHP > 200) cout << "    Bjorne: You sting… nothing more." << endl;
            else if (bossHP > 100) cout << "	Bjorne: Impossible… you persist?!" << endl;
            else cout << "	Bjorne: I will DEVOUR YOU!" << endl;

            // Boss attack
            if (skipNextBossAttack) {
                cout << "	Boss's attack is skipped this turn." << endl;
                skipNextBossAttack = false;
            } else {
                int dmg = max(1, bossATK - playerDEF);
                playerHP -= dmg;
                cout << "	Bjorne Dealt " << dmg << " damage." << endl;
                if (playerHP <= 0 && hasAmulet) {
                    hasAmulet = false;
                    playerHP = 1;
                    cout << "	Schala's Amulet shatters and restores you to 1 HP." << endl;
                }
                if (playerHP <= 0) {
                    cout << "	You fall to the ground..." << endl;
                    playerDead = true; fightOver = true;
                }
            }
        }
    }
    // TURN 14 
    if (!fightOver) {
        cout << endl << "   --- Turn 14 ---" << endl
             << "   Player HP: " << playerHP << " | ATK: " << playerATK << " | DEF: " << playerDEF << endl
             << "   Boss HP: " << bossHP << " | DEF: " << bossDEF << endl
             << "   Choose action: "<< endl 
             << "   [1] Attack  " << endl
             << "   [2] Use item" << endl
             << "   Move: ";
        cin >> choicechar;
        cout << endl;
        switch (choicechar) 
        {
        case 1:
            {            
            int dmg = max(1, playerATK - bossDEF);
            bossHP -= dmg;
            cout << "   You Dealt " << dmg << " damage." << endl;
            break;
        }
        case 2:
        if (hasRapier == true || hasNet == true || hasSunglasses == true || hasAmulet == true || hasRustbite == true) {
            cout << "   Items: " << endl;
                if (hasRapier == true){cout << "   [1] Divine Rapier [Active] - One-time use, deals 275 true damage (ignores DEF)." << endl;}
                if (hasNet == true){cout << "   [2] 90-Caliber Net [Active] - Free action, once. Skips the next boss attack." << endl;}
                if (hasSunglasses == true){cout << "   [3] Sunglasses [Active] - Free action, once. Skips the next boss attack." << endl;}
                if (hasRustbite == true){cout << "   [4] Rustbite Charge [Active] - Permanently reduces Bjorne’s DEF by 6." << endl;}
                if (hasAmulet == true){cout << "   Schala's Amulet [Passive] - If Jun’s HP falls to 0 or less, the amulet shatters and restores him to 1 HP instead. (Cannot be Used)" << endl;}
            cout << endl
				 << "   Which Item To Use? ";
            cin >> choicechar;
                switch (choicechar)
                {
                case 1:
                    if (hasRapier == true)
                    {cout << "	You use the Divine Rapier! (275 true damage)" << endl;
                    bossHP -= 275; hasRapier = false;} else {cout << "  Not a Valid Item. Attack Missed";}
                    break;
                case 2:
                    if (hasNet == true){
					cout << "	You use the 90-Caliber Net. Boss's next attack will be skipped." << endl;
                    skipNextBossAttack = true; 
					hasNet = false; 
					int dmg = max(1, playerATK - bossDEF);
            		bossHP -= dmg;
            		cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
					} else {
					cout << " Not a Valid Item. Attack Missed";
					}
                    break;
                case 3:
                    if (hasSunglasses == true)
                    {cout << "	You use the Sunglasses. Boss's next attack will be skipped." << endl;
                    skipNextBossAttack = true; 
					hasNet = false; 
					int dmg = max(1, playerATK - bossDEF);
            		bossHP -= dmg;
            		cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
					} else {
					cout << " Not a Valid Item. Attack Missed";
					}
                    break;
                    break;
                case 4:
                    if (hasRustbite == true)
                    {cout << "	You use the Rustbite Charge. Boss Defense Permanently reduced by 6" << endl;
                    bossDEF -= 6;} else {cout << "  Not a Valid Item. Attack Missed";}
                    break;
                default:
                    cout << "	No Item Found! You Skip a Turn!";
                    break;
                }
        	break;
        } 
        default:
            int dmg = max(1, playerATK - bossDEF);
            bossHP -= dmg;
            cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
            break;
    }
    
        // Check boss death
        if (bossHP <= 0) {
            cout << "	Bjorne falls beneath your strike!" << endl;
            bossDead = true; fightOver = true;
        } else {
            // Boss taunt
            if (bossHP > 300) cout << "    Bjorne: Tiny spark. I will crush you slowly." << endl;
            else if (bossHP > 200) cout << "    Bjorne: You sting… nothing more." << endl;
            else if (bossHP > 100) cout << "	Bjorne: Impossible… you persist?!" << endl;
            else cout << "	Bjorne: I will DEVOUR YOU!" << endl;

            // Boss attack
            if (skipNextBossAttack) {
                cout << "	Boss's attack is skipped this turn." << endl;
                skipNextBossAttack = false;
            } else {
                int dmg = max(1, bossATK - playerDEF);
                playerHP -= dmg;
                cout << "	Bjorne Dealt " << dmg << " damage." << endl;
                if (playerHP <= 0 && hasAmulet) {
                    hasAmulet = false;
                    playerHP = 1;
                    cout << "	Schala's Amulet shatters and restores you to 1 HP." << endl;
                }
                if (playerHP <= 0) {
                    cout << "	You fall to the ground..." << endl;
                    playerDead = true; fightOver = true;
                }
            }
        }
    }
    // TURN 15 
    if (!fightOver) {
        cout << endl << "   --- Turn 15 ---" << endl
             << "   Player HP: " << playerHP << " | ATK: " << playerATK << " | DEF: " << playerDEF << endl
             << "   Boss HP: " << bossHP << " | DEF: " << bossDEF << endl
             << "   Choose action: "<< endl 
             << "   [1] Attack  " << endl
             << "   [2] Use item" << endl
             << "   Move: ";
        cin >> choicechar;
        cout << endl;
        switch (choicechar) 
        {
        case 1:
            {            
            int dmg = max(1, playerATK - bossDEF);
            bossHP -= dmg;
            cout << "   You Dealt " << dmg << " damage." << endl;
            break;
        }
        case 2:
        if (hasRapier == true || hasNet == true || hasSunglasses == true || hasAmulet == true || hasRustbite == true) {
            cout << "   Items: " << endl;
                if (hasRapier == true){cout << "   [1] Divine Rapier [Active] - One-time use, deals 275 true damage (ignores DEF)." << endl;}
                if (hasNet == true){cout << "   [2] 90-Caliber Net [Active] - Free action, once. Skips the next boss attack." << endl;}
                if (hasSunglasses == true){cout << "   [3] Sunglasses [Active] - Free action, once. Skips the next boss attack." << endl;}
                if (hasRustbite == true){cout << "   [4] Rustbite Charge [Active] - Permanently reduces Bjorne’s DEF by 6." << endl;}
                if (hasAmulet == true){cout << "   Schala's Amulet [Passive] - If Jun’s HP falls to 0 or less, the amulet shatters and restores him to 1 HP instead. (Cannot be Used)" << endl;}
            cout << endl
				 << "   Which Item To Use? ";
            cin >> choicechar;
                switch (choicechar)
                {
                case 1:
                    if (hasRapier == true)
                    {cout << "	You use the Divine Rapier! (275 true damage)" << endl;
                    bossHP -= 275; hasRapier = false;} else {cout << "  Not a Valid Item. Attack Missed";}
                    break;
                case 2:
                    if (hasNet == true){
					cout << "	You use the 90-Caliber Net. Boss's next attack will be skipped." << endl;
                    skipNextBossAttack = true; 
					hasNet = false; 
					int dmg = max(1, playerATK - bossDEF);
            		bossHP -= dmg;
            		cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
					} else {
					cout << " Not a Valid Item. Attack Missed";
					}
                    break;
                case 3:
                    if (hasSunglasses == true)
                    {cout << "	You use the Sunglasses. Boss's next attack will be skipped." << endl;
                    skipNextBossAttack = true; 
					hasNet = false; 
					int dmg = max(1, playerATK - bossDEF);
            		bossHP -= dmg;
            		cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
					} else {
					cout << " Not a Valid Item. Attack Missed";
					}
                    break;
                    break;
                case 4:
                    if (hasRustbite == true)
                    {cout << "	You use the Rustbite Charge. Boss Defense Permanently reduced by 6" << endl;
                    bossDEF -= 6;} else {cout << "  Not a Valid Item. Attack Missed";}
                    break;
                default:
                    cout << "	No Item Found! You Skip a Turn!";
                    break;
                }
        	break;
        } 
        default:
            int dmg = max(1, playerATK - bossDEF);
            bossHP -= dmg;
            cout << "   Auto Move: You Attack and Dealt " << dmg << " damage." << endl;
            break;
    }
    
        // Check boss death
        if (bossHP <= 0) {
            cout << "	Bjorne falls beneath your strike!" << endl;
            bossDead = true; fightOver = true;
        } else {
            // Boss taunt
            if (bossHP > 300) cout << "    Bjorne: Tiny spark. I will crush you slowly." << endl;
            else if (bossHP > 200) cout << "    Bjorne: You sting… nothing more." << endl;
            else if (bossHP > 100) cout << "	Bjorne: Impossible… you persist?!" << endl;
            else cout << "	Bjorne: I will DEVOUR YOU!" << endl;

            // Boss attack
            if (skipNextBossAttack) {
                cout << "	Boss's attack is skipped this turn." << endl;
                skipNextBossAttack = false;
            } else {
                int dmg = max(1, bossATK - playerDEF);
                playerHP -= dmg;
                cout << "	Bjorne Dealt " << dmg << " damage." << endl;
                if (playerHP <= 0 && hasAmulet) {
                    hasAmulet = false;
                    playerHP = 1;
                    cout << "	Schala's Amulet shatters and restores you to 1 HP." << endl;
                }
                if (playerHP <= 0) {
                    cout << "	You fall to the ground..." << endl;
                    playerDead = true; fightOver = true;
                }
            }
        }
    }
    
    
    // Ending sequence
    cout << endl << "   --- Encounter Resolution ---" << endl;
    if (bossHP <= 0) {

        // Victory
        cout << "   Victory: Jun slays Bjorne, shinigami arrive, Jun is invited to the Academy." << endl;
    } else if (playerHP <= 0) {

        // Defeat
        cout << "   Defeat: Jun dies, but his stand delays Bjorne until shinigami finish it. Remembered as a hero." << endl;
    } else {

        // Fatigue Defeat (15 turns passed)
        cout << "   Fatigue Defeat: 15 turns have passed and Bjorne still stands." << endl;
        cout << "   Jun collapses, shinigami arrive too late. The district is saved, but Jun dies a hero." << endl;
    }


    // Final stats summary
    cout << endl << "   Final Stats:" << endl;
    cout << "   Player HP: " << playerHP << " | ATK: " << playerATK << " | DEF: " << playerDEF << endl;
    cout << "   Boss HP: " << bossHP << " | DEF: " << bossDEF << endl;

    if (hasRapier == true || hasNet == true || hasSunglasses == true || hasAmulet == true || hasRustbite == true) {cout << "   Items: " << endl;}
    if (hasRapier == true){cout << "   Divine Rapier [Active]" << endl;}
    if (hasNet == true){cout << "   90-Caliber Net [Active]" << endl;}
    if (hasSunglasses == true){cout << "   Sunglasses [Active]" << endl;}
    if (hasAmulet == true){cout << "   Schala's Amulet [Passive]" << endl;}
    if (hasRustbite == true){cout << "   Rustbite Charge [Active]" << endl;}

    cout << endl << "   --- END ---" << endl;
    if (fightOver == true) {exit(0);}
    return 0;
}

