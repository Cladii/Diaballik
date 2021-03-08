/*!
 * \file controller.h
 *
 * \brief Definition of the class diaballik::Controller.
 */
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../model/game.h"
#include "../view/view.h"
#include "../observer/observer.h"

/*!
 * \brief Namespace of Diaballik.
 */
namespace diaballik {

/*!
 * \brief The Controller class represent the controller of the game Diaballik.
 */
class Controller :public Observer{

    /*!
     * \brief game_ the game.
     */
    Game game_;
    /*!
     * \brief view_ the view.
     */
    View view_;

public :

    /*!
     * \brief Constructor of the controller.
     */
    Controller(View view);

    /*!
     *\brief Destructor of Controller.
     */
    ~Controller();

    void update() override;

    /*!
     * \brief Starts the Diaballik game.
     */
    void start();

private :
    Action takeCommand();
    void splitCommand(char * s,std::vector<char *> &tab);
    int askSize();
    std::string askName(int num);
    bool askVariant();
    bool verifyPosAreNumbers(std::vector<char *> & tab);
    bool verifyisNumber(char * s);
    void vider_buffer();
    void playGame();
    void playAction(bool & isAntijeu, bool & over);
};
}
#endif // CONTROLLER_H
