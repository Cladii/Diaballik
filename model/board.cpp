#include "../model/board.h"

namespace diaballik {

Board::Board(int size, bool isVariant):
    size_ {size}
{
    if(size_<5 || size_%2==0 || size_>9){
        throw std::invalid_argument("La taille du plateau doit etre impair et au moins de taille 5 et maximum de taille 9.");
    }
    initialiseBoard(isVariant);
}
void Board::deleteBoard(){
    for (std::vector<std::vector<Piece*>>::iterator it = board_.begin(); it != board_.end(); ++it) {
        for (std::vector<Piece*>::iterator it2=it->begin();it2!=it->end();++it2)
            if(*it2!= nullptr){
                delete *it2;
            }
    }
}

void Board::initialiseBoard(bool isVariant){
    for (int i=0;i<this->size_;++i) {
        std::vector<Piece*> tab;
        this->board_.push_back(tab);
    }
     insertPieces(isVariant);
}


void Board::fillFirstRow(int i, int j, bool isVariant)
{
    if(isVariant && (j==1 || j==this->size_-2)){
        this->board_.at(i).push_back(new Piece(PlayerColor::BLACK,false));
    }else{
        if(j==this->size()/2){
            this->board_.at(i).push_back(new Piece(PlayerColor::WHITE,true));
        }else{
            this->board_.at(i).push_back(new Piece(PlayerColor::WHITE,false));
        }
    }
}

void Board::fillLastRow(int i, int j , bool isVariant)
{
    if(isVariant && (j==1 || j==this->size_-2)){
        this->board_.at(i).push_back(new Piece(PlayerColor::WHITE,false));
    }else{
        if(j==this->size_/2){
            this->board_.at(i).push_back(new Piece(PlayerColor::BLACK,true));
        }else{
            this->board_.at(i).push_back(new Piece(PlayerColor::BLACK,false));
        }
    }
}

void Board::insertPieces(bool isVariant){
    for (int i=0;i<this->size_;++i) {
        for (int j=0;j<this->size_;++j) {
            if(i==0){
                fillFirstRow(i,j,isVariant);
            }else if(i==this->size_-1){
                fillLastRow(i,j,isVariant);
            }else {
                this->board_.at(i).push_back(nullptr);
            }
        }
    }
}

void Board::put(Piece * piece, Position position){
    std::vector<Piece*>::iterator it=this->board_.at(position.row()).begin()+position.column();
    this->board_.at(position.row()).erase(it);
    this->board_.at(position.row()).insert(it,piece);
}
Piece * Board::remove(Position position){
    Piece * piece=this->board_.at(position.row()).at(position.column());
    std::vector<Piece*>::iterator it=this->board_.at(position.row()).begin()+position.column();
    this->board_.at(position.row()).erase(it);
    this->board_.at(position.row()).insert(it,nullptr);
    return piece;
}

bool Board::isAntiJeu(PlayerColor current) const{
    if(current == PlayerColor::BLACK)
        return !hasPieceIn(current) && hasBlockLine(PlayerColor::WHITE);
    else
        return !hasPieceIn(current) && hasBlockLine(PlayerColor::BLACK);
}
bool Board::hasPieceIn(PlayerColor current) const{
    if (current==PlayerColor::WHITE){
        return whiteHasPassed();
    }else{
        return blackHasPassed();
    }
}
bool Board::whiteHasPassed() const{
    int j=0;
    bool whiteFound = false;
    while (!whiteFound && j<this->size()) {
        int i=this->size()-1;
        bool blackFound=false;
        while(!whiteFound && !blackFound && i>=0){
            Position pos=Position(i,j);
            if(!isFree(pos)){
                if(getPiece(pos)->color()==PlayerColor::WHITE)
                    whiteFound=true;
                else
                    blackFound=true;
            }
            i--;
            if(i == -1 && !blackFound)
                return true; //there is a gap in the wall.
        }
        j++;
    }
    return whiteFound;
}
bool Board::blackHasPassed() const{
    int j=0;
    bool blackFound=false;
    while (!blackFound && j<this->size()) {
        int i=0;
        bool whiteFound=false;
        while(!blackFound && !whiteFound && i<this->size()){
            Position pos=Position(i,j);
            if(!isFree(pos)){
                if(getPiece(pos)->color()==PlayerColor::BLACK)
                    blackFound=true;
                else
                    whiteFound=true;
            }
            i++;
            if(i == this->size() && !whiteFound)
                return true; //there is a gap in the wall.
        }
        j++;
    }
    return blackFound;
}
bool Board::verifyNext(Position pos,PlayerColor color) const{
    return isInside(pos) && !isFree(pos) && getPiece(pos)->color()==color;
}
/**
 * @brief Board::hasBlockLine, begin by searching the first piece of the block. It only search on the first column
 * because if no one is on the first column, there is no block.
 * Then while we find a piece (in the 3 directions possible) that can continue the chain's block until the end of the board,
 * verify if there are pieces close to the block.
 * @param opponentColor, the color of the opponent.
 * @return true if we find a completed block and if there are at least 3 ennemies close to the block.
 */
bool Board::FindFirstBrick(Position & current, PlayerColor opponentColor, int & j) const
{
    bool found=false;
    int i=this->size()-1;
    while (!found && i>=0) {
        current =Position(i,j);
        if(!isFree(current) && getPiece(current)->color()==opponentColor){
            found=true;
        }
        i--;
    }
    return found;
}

bool Board::findNextBrick(Position current, Position & next, PlayerColor opponentColor) const
{
    bool found=false;
    next=current+to_position(Direction::UP_RIGHT);
    found= verifyNext(next,opponentColor);
    if(!found){
        next=current+to_position(Direction::RIGHT);
        found=verifyNext(next,opponentColor);
    }
    if (!found) {
        next=current+to_position(Direction::DOWN_RIGHT);
        found=verifyNext(next,opponentColor);
    }
    return found;
}

bool Board::hasBlockLine(PlayerColor opponentColor) const{
    int j=0,cpt=0;
    Position current, next;
    bool found= FindFirstBrick(current, opponentColor, j);
    if(!found)
        return false;
    if(hasBlockedPieces(opponentColor,current))
        cpt++;
    while (j<this->size()-1) {
        if(!findNextBrick(current, next, opponentColor)){
            return false;
        }else{
            current=next;
            if(hasBlockedPieces(opponentColor,current))
                cpt++;
        }
        j++;
    }
    return cpt>=3;
}
bool Board::verifyBlacksBlocked(Position pos) const{
    Position close=Position(pos+to_position(Direction::UP));
    return isInside(close) && !isFree(close)&& getPiece(close)->color()==PlayerColor::WHITE;
}
bool Board::verifyWhitesBlocked(Position pos) const{
    Position close=Position(pos+to_position(Direction::DOWN));
    return isInside(close) && !isFree(close)&& getPiece(close)->color()==PlayerColor::BLACK;
}
bool Board::hasBlockedPieces(PlayerColor color, Position pos)const{
    if(color==PlayerColor::BLACK){
        return verifyBlacksBlocked(pos);
    }else{
        return verifyWhitesBlocked(pos);
    }
}
std::string Board::addColumnsNumbers()const{
    std::string retour;
    for (int i=0;i<this->size();++i) {
        retour+="  "+std::to_string(i);
    }
    return retour;
}
}
