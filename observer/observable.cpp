#include "../observer/observable.h"
#include "../observer/observer.h"
namespace diaballik {
void Observable::addObserver(Observer * observer){
    this->observers_.insert(observer);
}
void Observable::removeObserver(Observer * observer){
    this->observers_.erase(observer);
}
void Observable::notifyAll() const{
    for(Observer * observer : observers_){
        observer->update();
    }
}
}
