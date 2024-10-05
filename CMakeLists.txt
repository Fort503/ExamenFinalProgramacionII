# Versión mínima de CMake
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto y versión
project(ExamenFinalV2 VERSION 1.0)

# Establecer el estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Incluir directorios de encabezados (inclusión recursiva)
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include/class)
include_directories(${PROJECT_SOURCE_DIR}/include/clientes)
include_directories(${PROJECT_SOURCE_DIR}/include/pagos)
include_directories(${PROJECT_SOURCE_DIR}/include/prestamos)

# Buscar wxWidgets en el sistema
find_package(wxWidgets REQUIRED COMPONENTS core base)

# Incluir los flags de wxWidgets
include(${wxWidgets_USE_FILE})

# Agregar todos los archivos fuente de los subdirectorios
file(GLOB_RECURSE SRC_FILES 
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

# Crear el ejecutable
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Enlazar wxWidgets con el ejecutable
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

