
#pragma once
#include "../core/Component.hpp"
#include <vector>
#include <cstddef> // Para size_t

class TernaryMemory : public Component {
    std::vector<Trit> data;
    public:
        TernaryMemory(size_t size) : data(size, Trit::Zero) {}
        
        void write(size_t addr, Trit value) { data[addr] = value; }
        Trit read(size_t addr) const { return data[addr]; }
        
        void receive(MessagePtr msg) override {
            if (msg->type == Message::Type::Data && msg->payload.size() >= 2) {
                size_t addr = static_cast<size_t>(msg->payload[0]);
                write(addr, msg->payload[1]);
            }
        }
};