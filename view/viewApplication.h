#ifndef VIEWAPPLICATION_H
#define VIEWAPPLICATION_H
#include <QtWidgets>
#include "model/game.h"
#include "viewBoard.h"
#include "infosTurn.h"
#include "infoPlay.h"
#include "../observer/observer.h"
namespace diaballik {
/*!
 * \brief The ViewApplication class, contains the board and the zones of informations of the currentGame.
 */
class ViewApplication : public QWidget , public Observer
{
    Q_OBJECT
public:
    /*!
     * \brief ViewApplication, the constructeur of the viewApplication.
     * \param size, the size of the board.
     * \param variante, the variant of the game.
     * \param nom1, the name of the first player.
     * \param nom2, the name of the second player.
     */
    ViewApplication(int size, bool variante, std::string nom1, std::string nom2);
    /*!
     *Destructor of the viewApplication.
     */
    ~ViewApplication() override;
    void update() override;
public slots:
    /*!
     * \brief verifySelected, play an action if a piece is selected. Else verify if we can select a piece at this position.
     * \param pos, the position cliqued.
     */
    void verifySelected(Position pos);
    /*!
     * \brief passTurn, pass the turn after cliqued the button pass.
     */
    void passTurn();
private :
    Game game_;
    ViewBoard * viewboard_;
    InfoPlay * infosPlay_;
    InfosTurn * infosTurn_;
    Position selected_;
    void verifyThrow();
    void verifyMove();
};
}
#endif // VIEWAPPLICATION_H
