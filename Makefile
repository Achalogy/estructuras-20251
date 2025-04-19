# Nombre del ejecutable
PROG = proyecto.out

# Directorios
SRC_DIR = src

# Buscar archivos fuente (.cpp y .cxx) en todos los subdirectorios
SOURCES := $(shell find $(SRC_DIR) -type f \( -name "*.cxx" -o -name "*.cpp" \))

# Convertir a archivos objeto
OBJECTS := $(SOURCES:.cxx=.o)
OBJECTS := $(OBJECTS:.cpp=.o)

# Archivos de dependencias (.d)
DEPS := $(OBJECTS:.o=.d)

# Compilador y opciones
CXX = g++
CXXFLAGS = -I$(SRC_DIR) -std=c++11 -Wall -MMD -MP -O2

# Regla principal
all: $(PROG)

# Enlazar el ejecutable
$(PROG): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compilar cada archivo fuente
%.o: %.cxx
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Incluir dependencias generadas automáticamente
-include $(DEPS)

# Limpiar archivos generados
clean:
	rm -rf $(PROG) $(OBJECTS) $(DEPS)
