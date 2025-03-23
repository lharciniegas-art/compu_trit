#pragma once
#include <vector>
#include <memory>
#include "Trit.hpp"

class Message {
public:
    enum class Type { Data, Control };
    Type type;
    Trit sender;
    Trit receiver;
    std::vector<Trit> payload;

    Message(Type t, Trit s, Trit r, std::vector<Trit> p);
};

using MessagePtr = std::shared_ptr<Message>;
