#pragma once
#include <string>
#include <map>
#include "EventType.h"

class EventListener {
public:
    virtual void ReceiveEvent(const EventType eventType) = 0;
};

typedef std::multimap<EventType, EventListener*>::iterator EventIterator;

class EventEmitter {
public:
    static void RegisterForEvent(const EventType& eventType, EventListener* l);
    static void EmitEvent(const EventType& eventType);
    static void RemoveListner(EventListener* l);

protected:
    static std::multimap<EventType, EventListener*> listeners;
};