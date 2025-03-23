#include "Message.hpp"

// Implementar el constructor
Message::Message(Type t, Trit s, Trit r, std::vector<Trit> p)
    : type(t), sender(s), receiver(r), payload(p) {}
