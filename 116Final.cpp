//I pledge my honor that I have abided by the Stevens Honor System. Nicholas Katzenberger
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

class Player
{
public:
int defense, strength, health, charisma, intelligence, wisdom, dexterity;
string name = "";

Player(){
    defense = 0;
    strength = 0;
    charisma =0;
    health = 1;
    charisma =0;
    intelligence =0;
    wisdom = 0;
    dexterity =0;
}
bool PlayerDeath(){
if (health <= 0){
    return true;

}
else{
    return false;
}
}

void revive_player(){
    health = 1;
}
void damagePlayer(int dg){
    health -=dg;
}
void setStats(string n, int c, int s, int ch, int in, int wi, int dx, int d){
    name = n;
    health+=c;
    strength =s;
    charisma = ch;
    intelligence = in;
    wisdom = wi;
    dexterity = dx;
    defense =d;
}
void printStats(){
    cout<<name<<"'s status\nHP: "<<health<<"\nStrength: "<<strength<<"\nCharisma: "<<intelligence<<"\nWisdom: "<<wisdom<<"\nDexterity: "<<dexterity;
    cout<<endl<<endl;
}
};

class Enemy{
public:
int HP, attack;
string call;
Enemy(){
    HP =0;
    call ="";
    attack =0;
}
void spawn(int h, string ty, int a){
    HP=h;
    call = ty;
    attack = a;
}
void damageEnemy(int dt){
    HP-=dt;
}
};

int diceroll(int dnumb);
int diceroll(int dnumb){
  return rand() % dnumb+1;
}
void successrate(int roll);
void successrate(int roll){
    if (roll>=20){
        cout<<"\nCritical success!"<<endl;
    }
    else if (roll>=15){
        cout<<"\nSuccess!"<<endl;
    }
    else if (roll>= 10){
        cout<< "\nPartial success."<<endl;
    }
    else if (roll>=5){
        cout<< "\nPartial failure."<<endl;
    }
    else if (roll==1){
        cout<<"\nCritical Failure!"<<endl;
    }
    else{
        cout<<"Failure"<<endl;
    }
}

int main(){
    int c, cons, str, chari, inte, wi, dx;
    string n;
    cout<<"To get started enter random number seed: ";
    cin>>c;
    for (int r =0; r<c; r++){
    diceroll(20);
    }
    cout<<"Welcome players to the dungeon master assistant PVP program. Enter the number of players: ";
    cin>>c;
    vector<Player> playerlist(c);
    vector<Enemy> enemylist(c);
    Player *p1;
    for(int i=0; i<c; i++){
        cons, str, chari, inte, wi, dx =0;
        cout<<"Enter player name: "<<endl;
        cin>>n;
        cout<<"Note: DungeonMaster should make sure players do not enter values that add up to a number greater than 27."<<endl;
        cout<<n<<" Enter constitution points: ";
        cin>>cons;
        cout<<n<<" Enter strength points: ";
        cin>>str;
        cout<<n<<" Enter charisma points: ";
        cin>>chari;
        cout<<n<<" Enter intelligence points: ";
        cin>>inte;
        cout<<n<<" Enter wisdom points: ";
        cin>>wi;
        cout<<n<<" Enter dexterity points: ";
        cin>>dx;
        cout<<n<<" Enter race: [1 for Dragonborn, 2 for Dwarf, 3 for Elf, 4 for Gnome, 5 for Half-Elf, 6 for Halfling, 7 for Half-Orc, 8 for Human, 9 for Tiefling.]"<<endl;
        int choice;
        cin>>choice;
        p1 = new Player;
        bool ch = false;
        while (ch==false){
        switch(choice){
            case 1: {
                p1->setStats(n, cons, str+2, chari+1, inte, wi, dx, 0);
                ch=true;
                break;
            }
            case 2: {
                p1->setStats(n, cons+2, str, chari, inte, wi, dx, 0);
                ch=true;
                break;
            }
            case 3: {
                p1->setStats(n, cons, str, chari, inte, wi, dx+2, 0);
                ch=true;
                break;
            }
            case 4: {
                p1->setStats(n, cons, str, chari, inte+2, wi, dx, 0);
                ch=true;
                break;
            }
            case 5: {
                int y = 2;
                int x;
                while (y>0){
                cout<<"Enter an ability score should be increased by 1: [1 for constitution, 2 for strength, 3 for intelligence, 4 for wisdom, 5 for dexterity, 6 for charisma]"<<endl;
                cin>>x;
                switch(x){
                    case 1:{
                        cons+=1;
                        break;
                    }
                    case 2:{
                        str+=1;
                        break;
                    }
                    case 3:{
                        inte+=1;
                        break;
                    }
                    case 4:{
                        wi +=1;
                        break;
                    }
                    case 5:{
                        dx+=1;
                        break;
                    }
                    case 6:{
                        cons+=1;
                        break;
                    }
                    default: {cout<<"Invalid entry try again."<<endl;
                    y= y+1;
                    break;
                    }
                }
                y=y-1;
                }
                p1->setStats(n, cons, str, chari+2, inte, wi, dx, 0);
                ch=true;
                break;
            }
            case 6: {
                p1->setStats(n, cons, str, chari, inte, wi, dx+2, 0);
                ch=true;
                break;
            }
            case 7: {
                p1->setStats(n, cons+1, str+2, chari, inte, wi, dx, 0);
                ch=true;
                break;
            }
            case 8: {
                p1->setStats(n, cons+1, str+1, chari+1, inte+1, wi+1, dx+1, 0);
                ch=true;
                break;
            }
            case 9:{
                p1->setStats(n, cons, str, chari+2, inte, wi, dx, 0);
                ch=true;
                break;
            }
            default:{cout<<"Invalid entry try again."<<endl;
                    break;
                }
        }
        playerlist.push_back(*p1);
        cin.get();
        }
    }
         vector<Player>::iterator it;
         //vector<Enemy>::iterator that;
         int en = c-1;
         if(c>1){
             for(int v =0; v<en; v++){
        playerlist.erase(playerlist.begin());
             }
         }
        for (it = playerlist.begin()+1; it != playerlist.end(); ++it ) {
            it->printStats();
        }
        cout<<"Here's a prompt to start your adventure: "<<endl;
        int prompt = diceroll(10);
        int line;
    switch(prompt){
        case 1: {
            line = 1;
            break;
        }
        case 2: {
            line = 3;
            break;
        }
        case 3: {
            line = 5;
            break;
        }

        case 4: {
            line = 7;
            break;
        }
        case 5: {
            line = 9;
            break;
        }
        case 6: {
            line = 11;
            break;
        }
        case 7: {
            line = 13;
            break;
        }
        case 8: {
            line = 15;
            break;
        }
        case 9: {
            line = 17;
            break;
        }
        case 10: {
            line = 19;
            break;
        }
    }
        ifstream reader;
        string s;
        reader.open("DnD locations.txt");
        if(reader.is_open()){
for (int i =1; i <= line; i++)
        getline(reader, s);
        cout << s;
        }

    cout<<"\nDungeon Master, add any additional details.."<<endl;
    bool Gameon = true;
    while (Gameon == true){
    for (it = playerlist.begin()+1; it != playerlist.end(); ++it ) {
        if(it->health>0){
    cout<<it->name<<": what will you do? describe your action to Dungeon Master.\n Enter the type of action performed: [1 for attack, 2 for movement, 3 for free action, 4 for non-attacking spell, any other number for do nothing]"<<endl;
    cin>>c;
    int success, damage;
    string target;
    switch(c){
        case 1:{
            cout<<"Who are you attacking? Enter name of player or enemy exactly: "<<endl;
            cin>>target;
            cout<<"Physical attack [1] or Spell attack [2]?"<<endl;
            int x;
            cin>>x;
            vector<Player>::iterator wh;
            vector<Enemy>::iterator ev;
            if(x==1){
                success = diceroll(20)+it->strength;
                damage = diceroll(6);
            cout<<"Result of D20 dice roll+player strength status: "<<success<<" ";
            successrate(success);
            cout<<endl;
                if(success>=10){
            cout<<"Result of D6 dice roll for damage done: "<<damage<<endl;
             for (wh = playerlist.begin()+1; wh != playerlist.end(); ++wh){
                    if(target.compare(wh->name)==0){
                        wh->damagePlayer(damage);
                        cout<<target<<"Took "<<damage<<"damage!"<<endl;
                    }
                   }
            /* for (ev = enemylist.begin()+1; ev != enemylist.end(); ++ev ){
                       if(target.compare(ev->call)==0){
                            ev->HP-=damage;
                        cout<<target<<"Took "<<damage<<"damage!"<<endl;
                }
             }
             */
                }
            }
            else{
                success =  diceroll(20)+it->wisdom;
                damage = diceroll(6);
            cout<<"Result of D20 dice roll+player wisdom status: "<<success<<endl;
            successrate(success);
           if(success>=10){
           cout<<"Result of D6 dice roll for damage done: "<<damage<<endl;
                for (wh = playerlist.begin()+1; wh != playerlist.end(); ++wh){
                    if(target.compare(wh->name)==0){
                        wh->damagePlayer(damage);
                        cout<<target<<" Took "<<damage<<"damage!"<<endl;
                    }
                    }
                   }
           /*  for (ev = enemylist.begin()+1; ev != enemylist.end(); ++ev ){
                       if(target.compare(ev->call)==0){
                            ev->HP-=damage;
                        cout<<target<<"Took "<<damage<<"damage!"<<endl;
                }
             }
             */
            }
        break;
        }
        case 2:{
            cout<<"Describe to Dungeon Master where you are moving to and how. Enter any character to proceed"<<endl;
            string a;
            cin>>a;
            success = diceroll(20)+it->dexterity;
            cout<<"Result of D20 dice roll+player dexterity status: "<<success<<endl;
            successrate(success);
            break;
        }
        case 3:{
            cout<<"Describe action being performed to the Dungeon Master. Does the action involve speaking [1], checking general surroundings [2], checking statistics of players[3], or an unlisted action [enter any other number]?"<<endl;
            int e;
            cin>>e;
             vector<Player>::iterator gee;
        switch(e){
            case 1:{
                success = diceroll(20)+it->charisma;
                cout<<"Result of D20 dice roll+player charisma status: "<<success<<endl;
                successrate(success);
                break;
            }
            case 2: {
                success = diceroll(20)+it->intelligence;
                cout<<"Result of D20 dice roll+player intelligence status: "<<success<<endl;
                successrate(success);
                if(success>=10){
                    cout<<"Dungeon Master, inform player on requested information about surroundings based off of level of success"<<endl;
                }
                break;
            }
            case 3:
            {
                 success = diceroll(20)+it->intelligence;
                cout<<"Result of D20 dice roll+player intelligence status: "<<success<<endl;
                successrate(success);
                  if(success>=10){
                    cout<<"Check the stats of whom? Enter the name of enemy or player exactly: "<<endl;
                    string t;
                    cin>>t;
                
                   // vector<Enemy>::iterator whiz;
                   for (gee = playerlist.begin()+1; gee != playerlist.end(); ++gee){
                    if(t.compare(gee->name)==0){
                        it->printStats();
                    }
                   }
                 /*  for (whiz = enemylist.begin()+1; whiz != enemylist.end(); ++whiz ){
                       if(t.compare(whiz->call)==0){
                       cout<<t<<"'s health: "<<whiz->HP<<endl;
                }
                   }*/
            break;
            }
            default:{
                cout<<"Describe action to Dungeon Master, this action does not require a dice roll."<<endl;
                break;
            }
        }
        }
            break;
        }
        case 4: {
            success = diceroll(20)+it->wisdom;
            damage = diceroll(4);
            cout<<"Describe the spell being attempted. Which stat of all players will be affected? [Enter 1 for defense, 2 for strength, 3 for intelligence, 4 for charisma, 5 for Hit points, 6 for wisdom, 7 for dexterity, 8 to revive a player]"<<endl;
            int r;
            cin>>r;
            cout<<"Result of D20 dice roll+player wisdom status: "<<success<<endl;
            successrate(success);
            if(success>=10){
                cout<<"Result of D4 dice roll for points to be added: "<<damage<<endl;
            switch(r){
                case 1:{
                        it->defense+=damage;
                
                    break;
                }
                case 2:{
                        it->strength+=damage;
                
                    break;
                }
                case 3:{
                        it->strength+=damage;
                    break;
                }
                case 4:{
                        it->charisma+=damage;
                    
                    break;
                }
                case 5:{
                        it->health+=damage;
                    break;
                }
                case 6:{
                        it->wisdom+=damage;
                    break;
                }
                case 7:{
                        it->dexterity+=damage;
                    
                    break;
                }
                case 8:{
                    string u;
                    cout<<"Enter player's name exactly"<<endl;
                    cin>>u;
                    vector<Player>::iterator who;
                    for (who = playerlist.begin()+1; who != playerlist.end(); ++who){
                    if(u.compare(who->name)==0){
                        who->revive_player();
                        cout<<u<<"was revived!"<<endl;
                    }
                    }
                    break;
                }
                
                default:{
                cout<<"Invalid input"<<endl;
                break;
            }
            }
        }
        break;
        }
        
        default: {
         cout<<it->name<<" twiddles his thumbs and does nothing."<<endl;
            break;
    }
    }
    }
    else{
        cout<<it->name<<" is deceased!"<<endl;
    }
    }
    /*int present;
    cout<<"Dungeon Master, add enemies to the board? y/n"<<endl;
    char yn;
    cin>>yn;
    if(yn=='y'){
        cout<<"Define number of enemies to be added: "<<endl;
        cin>>start;
        present+=start;
        vector<Enemy> enemylist(start);
    Enemy *e1;
    for(int b =0; b<start; b++){
        e1 = new Enemy;
        cout<<"Enter enemy "<<b+1<<"'s health:"<<endl;
        cin>>str;
        cout<<"Enter enemy "<<b+1<<"'s name:"<<endl;
        cin>>n;
        cout<<"Enter enemy attack modifier: "<<endl;
        cin>>dx;
        e1->spawn(str, n, dx);
        enemylist.push_back(*e1);
        cin.get();
    }

    }
    else if(yn=='n'){
        cout<<"The players take another turn without surprises...";
    }
    int suc, dmg;
    string playa;
    if(start>1){
        enemylist.erase(enemylist.begin());
         }
    if (present>0){
    for (that = enemylist.begin(); that != enemylist.end(); ++that ){
        if(that->HP>0){
        cout<<"Enter action for "<<that->call<<". [Enter 1 for attack, 2 for movement, 3 for speech, any other number for do nothing]";
        cin>>wi;
        switch(wi){
            case 1:{
                suc = diceroll(20)+that->attack;
                cout<<"Who is "<<that->call<<" attacking?"<<endl;
                cin>>playa;
                cout<<"Result of D20 dice roll+enemy modifier: "<<suc<<endl;
                successrate(suc);
                 if(suc>=10){
                    cout<<that->call<<"attacks as per the Dungeon Master's description."<<endl;
                    dmg = diceroll(6);
                    cout<<"Result of D6 dice roll: "<<dmg<<endl;
                    for (it = playerlist.begin()+1; it != playerlist.end(); ++it){
                    if(playa.compare(it->name)==0){
                        it->damagePlayer(dmg);
                    }
                   }

                }
                break;
            }
            case 2:{
                suc=diceroll(20);
                cout<<"Result of D20 dice roll: "<<suc<<endl;
                if(suc>=10){
                    cout<<that->call<<"moves as per the Dungeon Master's description."<<endl;
                }
                break;
            }
            case 3:{
                suc = diceroll(20);
                cout<<"Result of D20 dice roll: "<<suc<<endl;
                if(suc>=10){
                    cout<<that->call<<"speaks as per the Dungeon Master's description."<<endl;
                }
                break;
            }
            default:{
                cout<<that->call<<" does nothing."<<endl;
                break;
            }
        }
    }
    else{
        enemylist.erase(that);
    }
    }
    }
    */
   char yn;
    cout<<"Continue game? y/n"<<endl;
    cin>>yn;
    if(yn=='n'){
        Gameon = false;
    }
    }
    cout<<"Thank you for playing!"<<endl;
    return 0;
}
