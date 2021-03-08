#include "viewApplication.h"
#include <QHBoxLayout>
namespace diaballik {
ViewApplication::ViewApplication(int size, bool variante, std::string nom1, std::string nom2):
    game_{Game(nom1,nom2,size,variante)},
    viewboard_{new ViewBoard(game_.board())},
    infosPlay_{new InfoPlay()},
    infosTurn_{new InfosTurn(nom1,game_.nbMoves(),!game_.throwed())},
    selected_{Position(-2,-2)}
{
    game_.addObserver(this);
    QHBoxLayout * layout=new QHBoxLayout();
    QVBoxLayout * layout2=new QVBoxLayout();
    this->setLayout(layout);
    QWidget * partG=new QWidget();
    partG->setLayout(viewboard_);
    layout->addWidget(partG);
    layout->addLayout(layout2);
    layout2->addWidget(infosPlay_);
    layout2->addWidget(infosTurn_);
    QObject::connect(viewboard_,SIGNAL(VerifyselectedSquare(Position)),this,SLOT(verifySelected(Position)));
    QWidget::connect(infosTurn_->getPass(),SIGNAL(clicked()),this,SLOT(passTurn()));
}
ViewApplication::~ViewApplication(){
    game_.removeObserver(this);
}
void ViewApplication::verifySelected(Position pos){
    try {
        if(selected_!=Position(-2,-2)){
            if(pos==selected_){
                selected_=Position(-2,-2);
                this->viewboard_->setColor(pos,false);
            }else if(game_.board().isFree(pos)){
                game_.play(Action::MOVE,selected_,pos);
            }else if(game_.board().getPiece(selected_)->has_ball() && game_.board().getPiece(pos)->color()==game_.current().color()){
                game_.play(Action::THROW,selected_,pos);
            }
        } else{
            if(!game_.board().isFree(pos) && game_.board().getPiece(pos)->color()==game_.current().color()){
                selected_=pos;
                this->viewboard_->setColor(pos,true);
            }
        }
    } catch (std::exception & e) {
        QMessageBox::critical(this,"OUPS !", e.what());
    } catch (std::string & e){
        infosPlay_->setError(e);
    }
}
void ViewApplication::update(){
    using namespace std;
    infosPlay_->setError("");
    viewboard_->setColor(selected_,false);
    this->selected_=Position(-2,-2);
    this->viewboard_->displayBoard(game_.board());
    this->infosTurn_->update(game_.current().name(),game_.nbMoves(),!game_.throwed());
    infosTurn_->setButton(true);
    if (game_.isAntiJeu()) {
        std::cout<<"anti jeu"<<endl;
        QString msgWinner=QString(QString::fromStdString(game_.current().name())+" remporte la victoire pour anti jeu !");
        QMessageBox::information(this,"Fin de partie",msgWinner);
        this->setEnabled(false);
    }
    if(game_.isOver()){
        QString msgWinner=QString(QString::fromStdString(game_.current().name())+" remporte la victoire!");
        QMessageBox::information(this,"Fin de partie",msgWinner);
        this->setEnabled(false);
    }
    if(!game_.canPlay()){
        game_.endTurn();
        infosTurn_->setButton(false);
    }
}
void ViewApplication::passTurn(){
    try {
        game_.endTurn();
        infosTurn_->setButton(false);
    } catch (std::exception & e) {
        QMessageBox::critical(this,"OUPS !", e.what());
    } catch (std::string & e){
        QMessageBox::critical(this,"OUPS !", QString::fromStdString(e));
    }
}
}
