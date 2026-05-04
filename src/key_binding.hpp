#ifndef KEY_BINDING_HPP
#define KEY_BINDING_HPP

#include <map>

enum class PlayerAction;

// Classe pour gérer le mapping des touches (configurable)
class KeyBinding
{
private:
  std::map<int, PlayerAction> keyMap;

public:
  KeyBinding();

  // Obtenir l'action associée à une touche
  PlayerAction *getAction(int key);

  // Rebinder une touche
  void rebindKey(int key, enum PlayerAction action);

  // Débinder une touche
  void unbindKey(int key);
};

#endif