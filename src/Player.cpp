#include "Player.hpp"
#include "fogpi/fogpi.hpp"
#include "Room.hpp"
#include "Monster.hpp"
#include "Boss.hpp"
void Player::Start()
{
    m_character = 'P';

    // declare stats

    if (started == false)
    {
        started = true;
        StatsPick();
    }
}

// Roll a 20-sided dice
int rollD20() 
{
    return rand() % 20 + 1;
}

void Player::Update()
{
    char directionInput;

    if (playerStats.health <= 0)
    {
        //handle death
        printf("You have died.\n Final Level: %i\n Gold Amount: %i\n", playerStats.level, playerStats.exp);
        exit(0);
    }

    do
    {
        directionInput = request_char("wasd and Enter to move");
    } while (directionInput != 'w' &&
             directionInput != 'a' &&
             directionInput != 's' &&
             directionInput != 'd' &&
             directionInput != 'r' &&
             directionInput != 'W' &&
             directionInput != 'A' &&
             directionInput != 'S' &&
             directionInput != 'D');

    Vector2D direction(0.0f);
    int moveCount = 1;

    switch (directionInput)
    {
    case 'w':
        direction = {0.0f, -1.0f};
        break;
    case 'a':
        direction = {-1.0f, 0.0f};
        break;
    case 's':
        direction = {0.0f, 1.0f};
        break;
    case 'd':
        direction = {1.0f, 0.0f};
        break;
    case 'r':
        printf("Player has initiated dice roll!\n");
        printf("Player rolled d20: %d\n", rollD20());
        break;  

    case 'W':       //MOVE THREE SPACES IF CAPS LOCK
        direction = {0.0f, -1.0f};
        moveCount = 3;
        //printf("dbug");
        break;
    case 'A':
        direction = {-1.0f, 0.0f};
        moveCount = 3;
        break;
    case 'S':
        direction = {0.0f, 1.0f};
        moveCount = 3;
        break;
    case 'D':
        direction = {1.0f, 0.0f};
        moveCount = 3;
        break;
    default:
        direction = {0.0f, 1.0f};
        break;
    }

    

    //something to compare player location it room size (m_map.size)
    //if player location [y][x] > than room size [y][y] {stop player and send to last position}

    for(int i = 0; i < moveCount; i++){
        Vector2D tryPos = m_position + direction;
    // check for a key
    if (room->GetLocation(tryPos) == 'K')
    {
        m_keyCount++;
        room->ClearLocation(tryPos);
    }

    // cheak for gold
    if (room->GetLocation(tryPos) == 'G')
    {
        playerStats.gold++;
        room->ClearLocation(tryPos);
        printf("You collected +1 Gold\n");
    }
    // Check for treasure chest
    if (room->GetLocation(tryPos) == 'X'){
        playerStats.gold = playerStats.gold + 13;
        room->ClearLocation(tryPos);
        printf("You opened the Treasure Chest and collected +13 Gold\n");
    }
        // Check for monsters
    if (room->GetLocation(tryPos) == 'M'){
        //room->ClearLocation(tryPos);
        std::vector<Entity*> monsters = room->GetMonsters();

        for(Entity* e : monsters)
        {
            if (e->GetPosition() == tryPos)
            {
                ((Monster*)e)->Fight();
                //((Player*)e)->StatsPick();

                break;
            }
        }
        
        //printf("the monster is on break right now\n");
    }
    if (room->GetLocation(tryPos) == 'B'){      //Boss fight
        //room->ClearLocation(tryPos);
        std::vector<Entity*> boss = room->GetBoss();

        for(Entity* e : boss)
        {
            if (e->GetPosition() == tryPos)
            {
                ((Boss*)e)->Fight();
                break;
            }
        }
    }

    // open door unlocked door
    if (room->GetLocation(tryPos) == 'D')
    {
        room->OpenDoor(tryPos);
        return;
    }
    // open locked door
    if (room->GetLocation(tryPos) == 'L'){
        // end if statement if you don't have the key
        if (m_keyCount <= 0)
        {
            printf("it's locked.\n");
            return;
        }

        if(room->monsterCount >= 1){
            printf("You cannot leave yet, there are monsters everywere!\n");
                            //when it gets to that point, somewhere in the monster script we need a monsterCount --
            return;

        }
        //     //end if monsters still in room
        // if(m_monster -> 0){
        //     printf("You cannot leave yet, there are monsters everywere!");
        //     return;
        // }

        room->SetLocation(tryPos, 'D');
        printf("your key unlocks the door with a satisfying click.\n");
        // m_position = tryPos;
        m_keyCount--;
    }

    if (room->GetLocation(tryPos) == ' '){
        m_position = tryPos;

    }
    }
    

    // printf("%c\n", directionInput);

    // cout << playerStats.exp << " " << playerStats.level << " " << playerStats.gold << "\n";
}

void Player::StatsPick()
{
    playerStats.strength = 0;
    playerStats.dexterity = 0;
    playerStats.wit = 0;
    playerStats.wisdom = 0;
    playerStats.health = 0;

    playerStats.level = 1;
    playerStats.exp = 0;
    playerStats.gold = 0;

    // class dependent stats
    char StatsInput;
    StatsInput = request_char("Select your class! F for fighter, C for cleric, W for wizard, R for rogue.");

    switch (StatsInput)
    {
    case 'F':
        playerStats.strength = 4;
        playerStats.dexterity = 2;
        playerStats.wit = 0;
        playerStats.wisdom = 1;
        playerStats.health = 12;

        printf("you are a fighter! Stats:\n Strength: %i\n Dexterity: %i\n Wit: %i\n Wisdom: %i\n Health: %i\n You are strong, but not vested in the arcane arts. Do not hesitate with your sword.\n",
               playerStats.strength, playerStats.dexterity, playerStats.wit, playerStats.wisdom, playerStats.health);
        // class ability: add an extra die to your attack once per 3 rooms
        break;

    case 'C':
        playerStats.strength = 0;
        playerStats.dexterity = 2;
        playerStats.wit = 2;
        playerStats.wisdom = 4;
        playerStats.health = 14;

        printf("you are a Cleric! Stats:\n Strength: %i\n Dexterity: %i\n Wit: %i\n Wisdom: %i\n Health: %i\n You shield yourself from the dark forces who hunt you. Banish them with your magic.\n", playerStats.strength, playerStats.dexterity, playerStats.wit, playerStats.wisdom, playerStats.health);
        // special ability: Fully heal yourself once per 3 rooms
        break;

    case 'W':
        playerStats.strength = 0;
        playerStats.dexterity = 3;
        playerStats.wit = 4;
        playerStats.wisdom = 2;
        playerStats.health = 10;

        printf("you are a Wizard! Stats: \n Strength: %i\n Dexterity: %i\n Wit: %i\n Wisdom: %i\n Health: %i\n You are vested in the arcane arts. Blast away your enemies with your spellbook before they can touch you.\n", playerStats.strength, playerStats.dexterity, playerStats.wit, playerStats.wisdom, playerStats.health);
        // special ability: you get slighltly more exp from each enemy that you kill
        break;

    case 'R':
        playerStats.strength = 3;
        playerStats.dexterity = 4;
        playerStats.wit = 2;
        playerStats.wisdom = 0;
        playerStats.health = 12;

        printf("you are a Rouge! Stats:\n Strength: %i\n Dexterity: %i\n Wit: %i\n Wisdom: %i\n Health: %i\n You become one with the shadows. Strike your enemies before they see you.\n", playerStats.strength, playerStats.dexterity, playerStats.wit, playerStats.wisdom, playerStats.health);
        // special ability: you get slightly more gold from each enemy that you kill
        break;

    default:
        playerStats.strength = 1;
        playerStats.dexterity = 2;
        playerStats.wit = 1;
        playerStats.wisdom = 0;
        playerStats.health = 8;

        printf("you are secret class X! It SUCKS. Stats:\n Strength: %i\n Dexterity: %i\n Wit: %i\n Wisdom: %i\n Health: %i\n You're not good at much of anything. Good luck bozo!\n", playerStats.strength, playerStats.dexterity, playerStats.wit, playerStats.wisdom, playerStats.health);
        break;
    }
}

