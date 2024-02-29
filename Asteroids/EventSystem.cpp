#include "EventSystem.h"

std::multimap<EventType, EventListener*> EventEmitter::listeners;

void EventEmitter::RegisterForEvent(const EventType& eventType, EventListener* l) {
    listeners.insert(std::make_pair(eventType, l));
}

void EventEmitter::EmitEvent(const EventType& eventType) {
    std::pair<EventIterator, EventIterator> ii = listeners.equal_range(eventType);
    for (EventIterator i = ii.first; i != ii.second; ++i) {
        if (i->second == nullptr) continue;
        i->second->ReceiveEvent(eventType);
    }
}

void EventEmitter::RemoveListner(EventListener* l) {
    for (auto it = listeners.begin(); it != listeners.end();) {
        if (it->second == l)
            it = listeners.erase(it);
        else
            ++it;
    }
}