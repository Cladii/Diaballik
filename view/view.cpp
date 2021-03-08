#include "../view/view.h"
using namespace std;
namespace diaballik {

void View::initalise(Player player)const{
    cout<<"===================================== \n DEBUT DE LA PARTIE \n"
       <<"===================================== \n"
      <<player<<" commence la partie"<<endl;
}
void View::displayError(const std::string message)const{
    cout<<message<<endl;
}
void View::displayMessage(const std::string message) const{
    cout<<message<<endl;
}
void View::askSize()const{
    cout<<"veuillez entrer votre taille voulue (5,7 ou 9)"<<endl;
}
void View::askName(int i)const{
    cout<<"Veuillez entrer le nom du joueur "<<i<<" :"<<std::endl;
}
void View::askVariante()const{
    cout<<"Voulez vous utiliser la variante du jeu ? \n Entrez o pour oui et n pour non :"<<endl;
}
void View::askAction()const{
    cout<<"Entrez l'action <ACTION> la position de depart <i,j> et la position de fin <i,j>"<<endl;
    cout<<"4 actions sont possibles : \n"<<"-throw \n"<<"-move \n"<<"-pass \n" <<"-quit \n"
       <<"======================================================================"<<endl;
}
void View::displayCurrentPlayer(Player current)const{
    cout<<"C'est le tour de : "<<current<<endl;
}
void View::displayActionsLeft(int moves, bool throwed){
    cout<<"Il vous reste "<<moves<<" mouvements et "<<throwed<<" passe"<<endl;
}
void View::displayBoard(Board board)const{
    cout<<board<<endl;
}
void View::displayWinner(Player winner, bool antiJeu)const{
    if(antiJeu)
        cout<<winner<<" remporte la victoire pour anti jeu !"<<endl;
    else
        cout<<winner<<" remporte la victoire !"<<endl;
}
}
