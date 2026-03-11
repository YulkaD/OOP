#ifndef EVENT_DISPATCHER_H
#define EVENT_DISPATCHER_H

#include <string>
#include <vector>
#include <functional>
#include <mutex>

using EventListener = std::function<void(const std::string&, const std::string&)>;

class EventDispatcher {
public:
    static EventDispatcher& instance();

    EventDispatcher(const EventDispatcher&) = delete;
    EventDispatcher& operator=(const EventDispatcher&) = delete;

    void addListener(EventListener listener);
    void removeAllListeners();
    void dispatch(const std::string& eventType, const std::string& data);

private:
    EventDispatcher() = default;

    std::vector<EventListener> m_listeners;
    std::mutex m_mutex;
};

#endif // EVENT_DISPATCHER_H