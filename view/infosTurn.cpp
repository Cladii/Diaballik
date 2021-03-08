#include "infosTurn.h"
#include <QGridLayout>
namespace diaballik {
InfosTurn::InfosTurn(std::string current, int moves, int throws){
    QGridLayout * layout=new QGridLayout(this);
    QLabel * currentPlayer=new QLabel("Joueur courant :");
    this->current=new QLabel(QString::fromStdString(current));
    this->nbMoves=new QLabel(QString::fromStdString(std::to_string(moves)));
    this->nbThrow=new QLabel(QString::fromStdString(std::to_string(throws)));
    QLabel * Lmoves=new QLabel("moves");
    QLabel * Lthrowed=new QLabel("throw");
    this->pass=new QPushButton("PASS");
    pass->setEnabled(false);
    pass->setStyleSheet("background-color: rgb(240,217,123);");

    layout->addWidget(currentPlayer,0,0);
    layout->addWidget(this->current,0,1);
    layout->addWidget(this->nbMoves,1,0);
    layout->addWidget(Lmoves,1,1);
    layout->addWidget(this->nbThrow,2,0);
    layout->addWidget(Lthrowed,2,1);
    layout->addWidget(pass,3,1);

    this->setTitle("Infos du tour");
    this->setMaximumSize(200,300);

}
void InfosTurn::update(std::string current, int moves, bool throws){
    this->current->setText(QString::fromStdString(current));
    this->nbMoves->setText(QString::fromStdString(std::to_string(moves)));
    this->nbThrow->setText(QString::fromStdString(std::to_string(throws)));
}
QPushButton* InfosTurn::getPass(){
    return this->pass;
}
void InfosTurn::setButton(bool disable){
    pass->setEnabled(disable);
    if(disable){
        pass->setStyleSheet("background-color: rgb(120,243,141);");
    }else{
        pass->setStyleSheet("background-color: rgb(240,217,123);");
    }
}
}
