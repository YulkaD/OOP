#include "EventDispatcher.h"
#include "Logger.h"

EventDispatcher& EventDispatcher::instance() {
    static EventDispatcher instance;
    return instance;
}

void EventDispatcher::addListener(EventListener listener) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_listeners.push_back(listener);
}

void EventDispatcher::removeAllListeners() {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_listeners.clear();
}

void EventDispatcher::dispatch(const std::string& eventType, const std::string& data) {
    std::lock_guard<std::mutex> lock(m_mutex);

    Logger::instance().debug("Dispatching event: " + eventType + " | " + data);

    for (auto& listener : m_listeners) {
        try {
            listener(eventType, data);
        }
        catch (const std::exception& e) {
            Logger::instance().error("Listener failed: " + std::string(e.what()));
        }
    }
}