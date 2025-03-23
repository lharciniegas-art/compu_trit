#include "Component.hpp"
#include "Message.hpp"
#include "bus.hpp"
class TernaryProcessor : public Component {
private:
    std::shared_ptr<CommunicationBus> bus;
    size_t program_counter = 0;

public:
    TernaryProcessor(std::shared_ptr<CommunicationBus> b) : bus(b) {}

    void execute_cycle() {
        // 1. Fetch
        std::vector<Trit> instruction = {/* Simular lectura de memoria */};
        
        // 2. Decode & Send
        auto msg = std::make_shared<Message>(
            Message::Type::Data,
            Trit::Zero, // Emisor: CPU
            Trit::Pos,  // Receptor: ALU
            instruction
        );
        bus->receive(msg);
        
        program_counter++;
    }

    void receive(std::shared_ptr<Message> msg) override {
        // Manejar interrupciones/respuestas
    }
};
