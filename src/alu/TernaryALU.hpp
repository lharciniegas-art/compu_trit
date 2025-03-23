// src/alu/TernaryALU.hpp
#include "../core/Component.hpp"
#include <iostream>

class TernaryALU : public Component {
    Trit add(Trit a, Trit b) {
        int sum = static_cast<int>(a) + static_cast<int>(b);
        // Lógica corregida
        if (sum > 1) return Trit::Pos;
        if (sum < -1) return Trit::Neg;
        return static_cast<Trit>(sum);
    }
public:
    void receive(MessagePtr msg) override {
        if (msg->type == Message::Type::Data && msg->payload.size() == 2) {
            Trit result = add(msg->payload[0], msg->payload[1]);
            std::cout << "[ALU] Resultado: " << static_cast<int>(result) << "\n";
        }
    }
};