#ifndef INFOPLAY_H
#define INFOPLAY_H
#include <QLabel>
#include <QGroupBox>
namespace diaballik {
/*!
 * \brief The InfoPlay class that represent the zone that shows errors of play.
 */
class InfoPlay : public QGroupBox
{
public:
    /*!
     * \brief InfoPlay, constructor of the infoPlay.
     */
    InfoPlay();
    /*!
     * \brief setError, set the string of the label error_
     * \param e, the string to put.
     */
    void setError(std::string e);
private:
    QLabel * error_;
};
}
#endif // INFOPLAY_H
