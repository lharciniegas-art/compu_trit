#pragma once
#include <memory>
#include "Message.hpp"

class Component {
public:
    virtual void receive(std::shared_ptr<Message> msg) = 0;
    virtual ~Component() = default;
};
