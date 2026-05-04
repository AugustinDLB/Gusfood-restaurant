#include "player_action.hpp"
#include "view.hpp"
#include "key_binding.hpp"

KeyBinding::KeyBinding()
{
    // Configuration par défaut
    keyMap[KEY_LEFT] = PlayerAction::MOVE_LEFT;
    keyMap[KEY_RIGHT] = PlayerAction::MOVE_RIGHT;
    keyMap[KEY_UP] = PlayerAction::MOVE_UP;
    keyMap[KEY_DOWN] = PlayerAction::MOVE_DOWN;
}

enum PlayerAction *KeyBinding::getAction(int key)
{
    auto it = keyMap.find(key);
    if (it != keyMap.end())
    {
        return &it->second;
    }
    return nullptr;
}

void KeyBinding::rebindKey(int key, PlayerAction action)
{
    keyMap[key] = action;
}

// Débinder une touche
void KeyBinding::unbindKey(int key)
{
    keyMap.erase(key);
}