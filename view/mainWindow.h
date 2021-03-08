#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "model/game.h"
#include <QLabel>
#include "viewApplication.h"
#include "formulaire.h"
namespace diaballik {
/*!
 * \brief The MainWindow class represent the mainWindow of the application.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    /*!
     * \brief MainWindow, represents the construcotr of the MainWindow. Start by setting the formulaire as the central widget.
     */
    MainWindow();

public slots:
    /*!
     * \brief swapWindow, swap the central widget as the viewApplication.
     * \param size, the size of the board to create.
     * \param variante, the variant of the game.
     * \param nom1, the name of the firs player.
     * \param nom2, the name of the second player.
     */
    void swapWindow(int size, bool variante, std::string nom1, std::string nom2);
    /*!
     * \brief sendInfos, when the menuItem is pressed, throw a url.
     */
    void sendInfos();

private:
    Formulaire *form;
    ViewApplication * application;
    QMenuBar * menu;
    void createMenuBar();
};
}
#endif // MAINWINDOW_H
