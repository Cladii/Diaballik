#include "formulaire.h"
#include <QPushButton>
#include <QMessageBox>
#include "mainWindow.h"
namespace diaballik{

Formulaire::Formulaire(){
    this->layout =new QFormLayout(this);
    variante=new QRadioButton(this);
    variante->setText("Oui");
    size=new QComboBox(this);
    size->addItems(QStringList()<<"5"<<"7"<<"9");
    nom1=new QLineEdit (this);
    nom2=new QLineEdit (this);
    layout->addRow("Voulez vous utiliser la variante de jeu ?",this->variante );
    layout->addRow("Quelle taille de plateau voulez vous ?", this->size);
    layout->addRow("Veuillez entrer le nom du joueur 1 :",this->nom1);
    layout->addRow("Veuillez entrer le nom du joueur 2 :",this->nom2);

    valider=new QPushButton(this);
    layout->addWidget(valider);
    valider->setText("VALIDER");
    QObject::connect(valider, &QPushButton::clicked,this, &Formulaire::ValidateForm);
}
void Formulaire::ValidateForm(){
    if(this->nom1->text().length()==0 || this->nom2->text().length()==0){
        QMessageBox::information(this,"Formulaire incorrect","Veuillez donner des noms à vos joueurs !");
    }else{
        try {
            emit swapToGame(size->currentText().toInt(),variante->isChecked(),nom1->text().toStdString(),nom2->text().toStdString());
        } catch (const std::exception & e) {
            std::cout<<"raté";
            QMessageBox::critical(this,"OUPS !", e.what());
        }
    }
}
}
