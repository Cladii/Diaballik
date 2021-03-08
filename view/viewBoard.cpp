#include "viewBoard.h"
#include <QLabel>
#include <QMessageBox>
#include <QPixmap>
namespace diaballik {
ViewBoard::ViewBoard(Board board){
    for (int i=0;i<board.size();i++) {
        for (int j=0;j<board.size();j++) {
            Square * square=new Square(i,j);
            this->addWidget(square,i,j);
            QWidget::connect(square,SIGNAL(clicked(Position)),this,SLOT(selectedSquare(Position)));
            displayPieces(board, i, j);
        }
    }
}
void ViewBoard::displayBoard(Board board){
    for (int i=0;i<board.size();i++) {
        for (int j=0;j<board.size();j++) {
            displayPieces(board,i,j);
        }
    }
}
void ViewBoard::displayPieces(Board board, int i, int j){
    QLayoutItem * item=this->itemAtPosition(i,j);
    QWidget * widget=item->widget();
    Square * squareXY=static_cast<Square *>(widget);
    if(!board.isFree(Position(i,j))){
        if(board.getPiece(Position(i,j))->color()==PlayerColor::BLACK){
            if(board.getPiece(Position(i,j))->has_ball()){
                QPixmap pix(":/Pictures/myPionB_ball .png");
                squareXY->setPixmap(pix);
            }else{
                QPixmap pix(":/Pictures/myPionB.png");
                squareXY->setPixmap(pix);
            }
        }else{
            if(board.getPiece(Position(i,j))->has_ball()){
                QPixmap pix(":/Pictures/myPionW_ball.png");
                squareXY->setPixmap(pix);
            }else{
                QPixmap pix(":/Pictures/myPionW.png");
                squareXY->setPixmap(pix);
            }
        }
    }else{
        squareXY->setPixmap(QPixmap());
        squareXY->repaint();
    }
}
void ViewBoard::selectedSquare(Position pos){
    emit VerifyselectedSquare(pos);
}
void ViewBoard::setColor(Position pos, bool selected){
    if(pos!=Position(-2,-2)){
        QLayoutItem * item=this->itemAtPosition(pos.row(),pos.column());
        QWidget * widget=item->widget();
        Square * squareXY=static_cast<Square *>(widget);
        squareXY->setSeleted(selected);
    }
}
}

