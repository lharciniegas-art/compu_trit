#include "Component.hpp"
#include "Message.hpp"
#include <queue>
class CommunicationBus : public Component {
private:
    std::vector<std::shared_ptr<Component>> components;
    std::queue<std::shared_ptr<Message>> msg_queue;

public:
    void attach(std::shared_ptr<Component> comp) {
        components.push_back(comp);
    }

    void receive(std::shared_ptr<Message> msg) override {
        msg_queue.push(msg);
        dispatch();
    }

    void dispatch() {
        while (!msg_queue.empty()) {
            auto msg = msg_queue.front();
            for (auto& comp : components) {
                if (comp.get() == this) continue; // Evitar loops
                comp->receive(msg);
            }
            msg_queue.pop();
        }
    }
};
