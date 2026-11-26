# Compilateur et options
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude

# Options pour SFML (décommenter la ligne LDFLAGS quand tu installeras SFML)
LDFLAGS  :=
# LDFLAGS  := -lsfml-graphics -lsfml-window -lsfml-system

# Dossiers et fichiers
SRC_DIR  := src
BUILD_DIR:= build
TARGET   := $(BUILD_DIR)/app

# Récupère automatiquement tous les .cpp dans src/ et génère les .o correspondants dans build/
SRCS     := $(wildcard $(SRC_DIR)/*.cpp)
OBJS     := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Règle par défaut (lancée avec la commande "make")
all: $(TARGET)

# Édition des liens : assemble tous les .o en un exécutable final
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Compilation séparée : transforme chaque .cpp en .o dans build/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Crée le dossier build/ s'il n'existe pas encore
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Lance le programme directement après compilation ("make run")
run: all
	./$(TARGET)

# Nettoie tous les fichiers générés ("make clean")
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all run clean