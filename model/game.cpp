#include "../model/game.h"

namespace diaballik {

Game::Game(std::string currentName, std::string opponentName, int size, bool isVariant):
    board_{size, isVariant},
    current_{new Player(PlayerColor::WHITE,currentName)},
    opponent_{new Player(PlayerColor::BLACK,opponentName)},
    nbMoves_{2},
    throwed_{false}
{}
Game::~Game(){
    delete current_;
    delete opponent_;
    board_.deleteBoard();
}
void Game::swapPlayer(){
    Player * temp {current_};
    current_=opponent_;
    opponent_=temp;
}
Player Game::current(){
    return *current_;
}
int Game::nbMoves(){
    return this->nbMoves_;
}
bool Game::throwed(){
    return this->throwed_;
}
Board Game::board(){
    return this->board_;
}
bool Game::canPlay(){
    return nbMoves_>0 || !throwed_;
}
bool Game::isOver(){
    if(current().color()==PlayerColor::WHITE){
        return hasFinished(board().size()-1);
    }else{
        return hasFinished(0);
    }
}
void Game::endTurn(){
    if(nbMoves()<2 || throwed()){
        swapPlayer();
        setMoves(2);
        setThrowed(false);
        notifyAll();
    }else{
        throw std::string("Vous ne pouvez pas finir votre tour");
    }
}
bool Game::hasFinished(int i){
    for (int j=0;j<board().size();j++) {
        Position actuel=Position(i,j);
        if(!board().isFree(actuel)&& board().getPiece(actuel)->color()==current().color() && board().getPiece(actuel)->has_ball()){
            return true;
        }
    }
    return false;
}
bool Game::isLegal(Position posStart,Position posEnd){
    return (posStart!=posEnd && board().isInside(posStart) && board().isInside(posEnd) &&
            !board().isFree(posStart) && board().getPiece(posStart)->color()==current().color());
}
void Game::play(Action action, Position posStart, Position posEnd)
{
    if(!isLegal(posStart,posEnd))
        throw std::string("Your start or end position is not valid");
    if(action == Action::THROW){
        if(throwed()){
            throw std::string("Vous avez deja lancé la balle");
        }
        throwBall(posStart, posEnd);
    }else if(action==Action::MOVE){
        if(nbMoves()<=0){
            throw std::string("Vous ne pouvez plus avancer");
        }
        if(board().getPiece(posStart)->has_ball()){
            throw std::string("Vous ne pouvez pas avancer avec la balle");
        }
        move(posStart,posEnd);
    }
    notifyAll();
}
void Game::move(Position posStart, Position posEnd){
    Direction dir=calculPente(posStart,posEnd);
    if(dir==Direction::UP_LEFT || dir==Direction::UP_RIGHT || dir==Direction::DOWN_LEFT || dir==Direction::DOWN_RIGHT){
        throw std::string("You cannot move in diagonals");
    }
    if(canMove(posStart,posEnd,dir)){
        Piece * maPiece=board_.remove(posStart);
        board_.put(maPiece,posEnd);
        setMoves(nbMoves()-1);
    }else{
        throw std::string("you can not move there");
    }
}
bool Game::canMove(Position posStart, Position posEnd, Direction dir){
    Position currentPos=next(posStart,dir);
    return !board().getPiece(posStart)->has_ball() && currentPos==posEnd && board().isFree(posEnd);
}

void Game::setMoves(int nbMoves){
    this->nbMoves_ = nbMoves;
}

void Game::throwBall(Position posStart, Position posEnd)
{
    if(!board().getPiece(posStart)->has_ball()){
        throw std::string("You don't have the ball");
    }
    if(board().isFree(posEnd) || board().getPiece(posEnd)->color()!=current().color()){
        throw std::string("You can not throw the ball there");
    }
    Direction dir=calculPente(posStart,posEnd);
    Position currentPos=posStart;
    while(currentPos!=posEnd && this->board().isInside(currentPos)){
        if(!this->board().isFree(currentPos) && this->board().getPiece(currentPos)->color()!=current().color())
            throw std::string("Vous ne pouvez pas passer la balle a"+to_string(posEnd));
        currentPos=next(currentPos,dir);
    }
    if(currentPos==posEnd && this->board().isInside(currentPos)){
        this->board().getPiece(posStart)->set_has_ball(false);
        this->board().getPiece(posEnd)->set_has_ball(true);
        setThrowed(true);
    }else
        throw std::string("Vous ne pouvez pas passer la balle a"+to_string(posEnd));
}

void Game::setThrowed(bool hasThrow){
    this->throwed_ = hasThrow;
}

Direction Game::calculPente(Position posStart, Position posEnd)
{
    int deltaJ = posEnd.column()-posStart.column();
    int deltaI = posEnd.row()-posStart.row();
    if(deltaJ == 0){
        return (posStart.row() > posEnd.row()) ? Direction::UP : Direction::DOWN;
    }
    int pente = (deltaI/deltaJ)*10;
    if(pente==0){
        return (posStart.column()>posEnd.column()) ? Direction::LEFT : Direction::RIGHT;
    }else if(pente==10){
        return (posStart.row() >posEnd.row()) ? Direction::UP_LEFT : Direction::DOWN_RIGHT;
    }else if(pente==-10){
        return (posStart.row() >posEnd.row()) ? Direction::UP_RIGHT : Direction::DOWN_LEFT;
    }else{
        throw std::string("Direction non valide");
    }
}
bool Game::isAntiJeu(){
    return this->board_.isAntiJeu(current_->color());
}
}
