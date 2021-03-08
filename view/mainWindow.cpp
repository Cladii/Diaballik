#include "mainWindow.h"
#include "formulaire.h"
namespace diaballik {
MainWindow::MainWindow(){
    createMenuBar();
    form=new Formulaire();
    this->setCentralWidget(form);
    QObject::connect(form, SIGNAL(swapToGame(int, bool, std::string, std::string)),this,SLOT(swapWindow(int, bool, std::string, std::string)));
}
void MainWindow::createMenuBar(){
    this->menu=new QMenuBar(this);
    this->setMenuBar(menu);
    QMenu * menuGame=new QMenu("Game");
    QMenu * menuInfos=new QMenu("Infos");
    menu->addMenu(menuGame);
    menu->addMenu(menuInfos);
    QAction * quitter=new QAction("Quitter");
    QAction * infosGame=new QAction("Regles du jeu");
    menuGame->addAction(quitter);
    menuInfos->addAction(infosGame);
    connect(infosGame,SIGNAL(triggered()),this,SLOT(sendInfos()));
    connect(quitter,SIGNAL(triggered()),qApp,SLOT(quit()));
}
void MainWindow::swapWindow(int size, bool variante, std::string nom1, std::string nom2){
    application=new ViewApplication(size,variante,nom1,nom2);
    this->setCentralWidget(application);
}
void MainWindow::sendInfos(){
    QDesktopServices::openUrl(QUrl("http://regle.jeuxsoc.fr/diaba_rg.pdf"));
}
}
