#pragma once

#include <functional>
#include <string>

namespace sf
{
struct Event;
}

namespace events
{

struct Event_listener
{
    using Callback = std::function<void(const sf::Event& event)>;
    std::string name{"undefined"};
    Callback callback;
};

}  // namespace events