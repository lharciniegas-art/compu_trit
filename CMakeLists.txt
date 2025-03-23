cmake_minimum_required(VERSION 3.12)
project(ternary_computer)

set(CMAKE_CXX_STANDARD 17)

# Buscar SFML instalado en el sistema
find_package(SFML REQUIRED COMPONENTS graphics window system)

# Incluir ImGui (si se instaló via synaptic)
find_package(ImGui REQUIRED) # Opcional: Si ImGui está en el sistema
include_directories(
    ${SFML_INCLUDE_DIR}
    /usr/include/imgui       # Ruta estándar de ImGui en Linux
)

# Fuentes del proyecto
file(GLOB_RECURSE SOURCES
    "src/*.cpp"
    "src/core/*.cpp"
    "src/alu/*.cpp"
    "src/memory/*.cpp"
    "src/gui/*.cpp"
)

add_executable(ternary_computer ${SOURCES})

# Enlazar con SFML
target_link_libraries(ternary_computer
    PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
)

# Enlazar con ImGui (si es necesario)
if(IMGUI_FOUND)
    target_link_libraries(ternary_computer PRIVATE ImGui::ImGui)
endif()
