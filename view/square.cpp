#include "square.h"
namespace diaballik {
Square::Square(int x, int y):
   i{x},
   j{y}
{
    this->setStyleSheet("background-color: rgb(40,82,138);");
    this->setMinimumSize(100,100);
    this->setMaximumSize(140,140);
    this->setScaledContents(true);
    this->setAlignment(Qt::AlignHCenter);
}
void Square::setSeleted(bool selected){
    if(selected)
        this->setStyleSheet("background-color: rgb(90,45,20);");
    else
        this->setStyleSheet("background-color: rgb(40,82,138);");
}
void Square::mousePressEvent(QMouseEvent *event){
    emit clicked(Position(i,j));
}
}
