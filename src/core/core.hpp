#include <iostream>
#include <vector>
#include <queue>
#include <memory>

//========================================
//          Tipos Fundamentales
//========================================
enum class Trit { Neg, Zero, Pos };

//========================================
//          Componentes como Objetos
//========================================
class Message; // Declaración anticipada

class Component {
public:
    virtual void receive(std::shared_ptr<Message> msg) = 0;
    virtual ~Component() = default;
};

//========================================
//          Sistema de Mensajería
//========================================
class Message {
public:
    enum class Type { Data, Control, Error };
    
    Type type;
    Trit sender;
    Trit receiver;
    std::vector<Trit> payload;

    Message(Type t, Trit s, Trit r, std::vector<Trit> p)
        : type(t), sender(s), receiver(r), payload(p) {}
};
