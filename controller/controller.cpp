#include "../controller/controller.h"
#include <string.h>
#include <limits>
using namespace std;
namespace diaballik {

Controller::Controller(View view):
    game_{Game(askName(1),askName(2),askSize(),askVariant())},
    view_{view}
{
    game_.addObserver(this);
}
Controller::~Controller(){
    game_.removeObserver(this);
}
void Controller::update(){
    view_.displayBoard(game_.board());
    if(!game_.throwed() && game_.nbMoves()==2){
        bool antiJeu=game_.isAntiJeu();
        if(game_.isOver() || antiJeu){
            view_.displayWinner(game_.current(),antiJeu);
        }else{
            view_.displayCurrentPlayer(game_.current());
            view_.displayActionsLeft(game_.nbMoves(),!game_.throwed());
        }
    }else{
        view_.displayCurrentPlayer(game_.current());
        view_.displayActionsLeft(game_.nbMoves(),!game_.throwed());
    }
}

int Controller::askSize(){
    vider_buffer();
    int taille;
    view_.askSize();
    cin>>taille;
    while (taille!=5 && taille!=7 && taille!=9) {
        if(cin.fail()){
            view_.displayError("Saisie incorrecte, recommencez :");
        }else{
            view_.displayError("Taille incorrecte");
        }
        vider_buffer();
        view_.askSize();
        cin>>taille;
    }
    return taille;
}
std::string Controller::askName(int num){
    vider_buffer();
    string name;
    view_.askName(num);
    cin>>name;
    return name;
}
bool Controller::askVariant(){
    string isVariant;
    view_.askVariante();
    cin>>isVariant;
    while (true) {
        if(isVariant=="o"){
            return true;
        }else if (isVariant=="n"){
            return false;
        }
        if(std::cin.fail()){
            view_.displayError("Saisie incorrecte, recommencez");
        }else{
            view_.displayError("commande incorrecte, Veuillez reessayer.");
        }
        vider_buffer();
        view_.askVariante();
        std::cin>>isVariant;
    }
}
void Controller::playAction(bool & isAntijeu, bool & over)
{
    if(game_.canPlay()){
        Action played=takeCommand();
        if(played==Action::THROW){
            over=game_.isOver();
        }else if(played==Action::PASS){
            game_.endTurn();
            isAntijeu=game_.isAntiJeu();
        }
    }else{
        view_.displayMessage("Fin du tour");
        game_.endTurn();
        isAntijeu=game_.isAntiJeu();
    }
}

void Controller::playGame()
{
    bool isAntijeu{false};
    bool over{false};
    while (!over && !isAntijeu) {
        try {
            playAction(isAntijeu, over);
        } catch (std::string const & e) {
            view_.displayError("erreur :"+e);
        } catch (exception const &){
            view_.displayError("Une erreur est survenue");
        }
        vider_buffer();
    }
}

void Controller::start(){
    vider_buffer();
    view_.initalise(game_.current());
    view_.displayBoard(game_.board());
    view_.displayActionsLeft(game_.nbMoves(),!game_.throwed());
    playGame();
}

Action Controller::takeCommand(){
    view_.askAction();
    char s2[15];
    cin.getline(s2,14);
    vector<char *>tab2;
    splitCommand(s2,tab2);
    if(strcmp(tab2.at(0),"pass")==0){
        return  Action::PASS;
    }
    if(strcmp(tab2.at(0),"quit")==0){
        exit(0);
    }
    if(tab2.size()==5 && verifyPosAreNumbers(tab2)){
        int rowStart=atoi(tab2.at(1));
        int columnStart=atoi(tab2.at(2));
        int rowEnd=atoi(tab2.at(3));
        int columnEnd=atoi(tab2.at(4));
        if(strcmp(tab2.at(0),"throw")==0){
            game_.play(Action::THROW, Position(rowStart,columnStart),Position(rowEnd,columnEnd));
            return Action::THROW;
        }else if(tab2.size()==5 && strcmp(tab2.at(0),"move")==0){
            game_.play(Action::MOVE, Position(rowStart,columnStart),Position(rowEnd,columnEnd));
            return Action::MOVE;
        }
    }else{
        view_.displayError("Commande non valide");
        vider_buffer();
        return takeCommand();
    }
    return Action::MOVE;
}
void Controller::splitCommand(char * s,std::vector<char *> &tab){
    char * token=strtok(s," ,");
    while (token != nullptr) {
        tab.push_back(token);
        token=strtok(nullptr, " ,");
    }
}
bool Controller::verifyPosAreNumbers(std::vector<char *> &tab){
    return (verifyisNumber(tab.at(1)) && verifyisNumber(tab.at(2)) && verifyisNumber(tab.at(3)) && verifyisNumber(tab.at(4)));
}
bool Controller::verifyisNumber(char * s){
    return (strlen(s)==1 && isdigit(s[0]));
}
/*!
 * \brief vider_buffer is used to clean std::cin in case he is not
 * in a good state. And ignore the rest of the buffer if he is not empty.
 */
void Controller::vider_buffer(){
    cin.clear();
    cin.seekg(0,ios::end);
    if(!cin.fail()){
        cin.ignore(numeric_limits<streamsize>::max());
    }else{
        cin.clear();
    }
}
}
