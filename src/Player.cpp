#include "Player.hpp"
#include "fogpi/fogpi.hpp"
#include "Room.hpp"

void Player::Start()
{
    m_character = 'P';

    playerStats.level = 1;
    playerStats.exp = 0;
    playerStats.gold = 0; 

    //class dependent stats
    char StatsInput;
    StatsInput = request_char("Select your class! F for fighter, C for cleric, W for wizard, R for rouge.");


    switch(StatsInput) {
        case 'F':
            playerStats.strength = 4;
            playerStats.dexterity = 2;
            playerStats.wit = 0;
            playerStats.wisdom = 1;
            playerStats.health = 12;

            printf("you are a fighter! Stats:\n Strength: %i\n Dexterity: %i\n Wit: %i\n Wisdom: %i\n Health: %i\n You are strong, but not vested in the arcane arts. Do not hesitate with your sword.\n", 
                    playerStats.strength, playerStats.dexterity, playerStats.wit, playerStats.wisdom, playerStats.health);
                    //class ability: add an extra die to your attack once per 3 rooms
            break;

        case 'C':
            playerStats.strength = 0;
            playerStats.dexterity = 2;
            playerStats.wit = 2;
            playerStats.wisdom = 4;
            playerStats.health = 14;

        printf("you are a Cleric! Stats:\n Strength: %i\n Dexterity: %i\n Wit: %i\n Wisdom: %i\n Health: %i\n You shield yourself from the dark forces who hunt you. Banish them with your magic.");
            //special ability: Fully heal yourself once per 3 rooms
            break;
        
        case 'W':
            playerStats.strength = 0;
            playerStats.dexterity = 3;
            playerStats.wit = 4;
            playerStats.wisdom = 2;
            playerStats.health = 10;

            printf("you are a Wizard! Stats: \n Strength: %i\n Dexterity: %i\n Wit: %i\n Wisdom: %i\n Health: %i\n You are vested in the arcane arts. Blast away your enemies with your spellbook before they can touch you.");
                //special ability: you get slighltly more exp from each enemy that you kill
            break;
        
        case 'R':
            playerStats.strength = 3;
            playerStats.dexterity = 4;
            playerStats.wit = 2;
            playerStats.wisdom = 0;
            playerStats.health = 12;

            printf("you are a Rouge! Stats:", "%c\n",
                "strength: ", playerStats.strength, "%c\n",
                "dexterity: ", playerStats.dexterity, "%c\n",
                "wit: ", playerStats.wit, "%c\n",
                "wisdom", playerStats.wisdom, "%c\n",
                "health: ", playerStats.health, "%c\n",
                "You become one with the shadows. Strike your enemies before they see you." "%c\n");
                //special ability: you get slightly more gold from each enemy that you kill
            break;
        
        default:
            playerStats.strength = 3;
            playerStats.dexterity = 4;
            playerStats.wit = 2;
            playerStats.wisdom = 0;
            playerStats.health = 12;

            printf("you are secret class X! It SUCKS. Stats:", "%c\n",
                "strength: ", playerStats.strength, "%c\n",
                "dexterity: ", playerStats.dexterity, "%c\n",
                "wit: ", playerStats.wit, "%c\n",
                "wisdom", playerStats.wisdom, "%c\n",
                "health: ", playerStats.health, "%c\n",
                "You're not good at much of anything. Good luck bozo!" "%c\n");
            break;
      }
}

void Player::Update()
{
    char directionInput;
    
    do {
        directionInput = request_char("wasd and Enter to move");
    } while (directionInput != 'w' &&
             directionInput != 'a' &&
             directionInput != 's' &&
             directionInput != 'd');
    
    Vector2D direction(0.0f);

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
    default:
        direction = {0.0f, 1.0f};
        break;
    }

    Vector2D tryPos = m_position + direction;

    // check for a key
    if (room->GetLocation(tryPos) == 'K')
    {
        m_keyCount++;
        room->ClearLocation(tryPos);
    }

    //open door unlocked door
    if (room->GetLocation(tryPos) == 'D')
    {
        room->OpenDoor(tryPos);
    }
    //open locked door
    if (room->GetLocation(tryPos) == 'L')
    {
        //end if statement if you don't have the key
        if (m_keyCount <= 0)
        {
            printf("it's locked.");
            return;
        }

        room->SetLocation(tryPos, 'D');
        printf("your key unlocks the door with a satisfying click.");
        m_position = tryPos;
        m_keyCount--;
    }

    if (room->GetLocation(tryPos) == ' ') 
        m_position = tryPos;
    
    printf("%c\n", directionInput);

    //cout << playerStats.exp << " " << playerStats.level << " " << playerStats.gold << "\n";
}
