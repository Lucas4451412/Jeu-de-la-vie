# Compilateur et options
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -I. -Imodel -Iview -Icontroller -Iio

# Options pour SFML (décommenter la ligne LDFLAGS quand tu installeras SFML)
LDFLAGS  :=
# LDFLAGS  := -lsfml-graphics -lsfml-window -lsfml-system

# Dossiers et exécutable final
BUILD_DIR := build
TARGET    := $(BUILD_DIR)/app

# Liste tous les fichiers .cpp (à la racine et dans les sous-dossiers MVC)
SRCS := $(wildcard *.cpp model/*.cpp view/*.cpp controller/*.cpp io/*.cpp)

# Génère les chemins des fichiers objets correspondants dans build/
OBJS := $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Règle par défaut ("make")
all: $(TARGET)

# Édition des liens : assemble tous les .o en un exécutable final
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Compilation séparée : crée le sous-dossier dans build/ si besoin et compile le .o
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Lance le programme directement après compilation ("make run")
run: all
	./$(TARGET)

# Nettoie tous les fichiers générés ("make clean")
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all run clean