#ifndef OBSERVER_H
#define OBSERVER_H
namespace diaballik {
class Observable;
/*!
 * \brief The Observer class that observe the changes of a subject.
 */
class Observer{
public :
    /*!
    * \brief update, virtual methode called by the Observable that is used to update what has changed.
    * \param observale, the observable that notify.
    */
    virtual void update()=0;

    /*!
    * \brief Virtual Destructor, because there is polymorphism.
    */
    virtual ~Observer()=default;

    /*!
    * \brief Constructeur par recopie par défaut.
    * Le destructeur virtuel par defaut a des effets en cascade.
    */
    Observer(const Observer &)=default;

    /*!
    * \brief Constructeur par déplacement par défaut.
    */
    Observer(Observer &&)=default;

    /*!
    * \brief Opérateur d'assignation par recopie par défaut.
    */
    Observer & operator=(const Observer &)=default;

    /*!
    * \brief Opérateur d'assignation par déplacement par défaut.
    */
    Observer & operator=(Observer &&)=default;
protected:
    /*!
    * \brief Constructeur privé pour éviter l'instanciation hors héritage
    */
    Observer()=default;
};
}
#endif // OBSERVER_H
