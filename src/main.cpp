#include "gui/GUI.hpp"
#include "memory/TernaryMemory.hpp"
#include <SFML/Graphics.hpp>

int main() {
    TernaryMemory mem(1024);  // Memoria de 1024 trits
    GUI gui(mem);             // Interfaz gráfica

    sf::Clock clock;
    while (gui.isWindowOpen()) {
        float delta_time = clock.restart().asSeconds();
        
        // Actualizar GUI
        gui.handleEvents();
        gui.update(delta_time);
        gui.render();
    }

    return 0;
}
