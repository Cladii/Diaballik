#include "infoPlay.h"
#include <QVBoxLayout>
namespace diaballik {
InfoPlay::InfoPlay(){
    QVBoxLayout * layout=new QVBoxLayout(this);
    error_=new QLabel();
    layout->addWidget(this->error_);
    error_->setStyleSheet("color : red;");
    this->setTitle("Infos du play");
    this->setMaximumSize(200,300);
}
void InfoPlay::setError(std::string e){
    if(e.size()>30){
        unsigned i=20;
        while (e.at(i)!=' ') {
            i++;
        }
        e.insert(i,"\n");
    }
    this->error_->setText(QString::fromStdString(e));
}
}
