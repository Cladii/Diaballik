#include "controller/controller.h"
#include <QApplication>
#include "view/formulaire.h"
#include <QMainWindow>
#include "view/mainWindow.h"
using namespace diaballik;

/*!
 * \brief Start the Diaballil Game.
 *  No args needed.
 */
int main(int argc, char * arv[])
{
    //partie console :
/*    View view=View();
    Controller ctr=Controller(view);
    ctr.start();*/

    //partie GUI :
    QApplication app(argc,arv);
    MainWindow mainWin;
    mainWin.show();
    return app.exec();
}
