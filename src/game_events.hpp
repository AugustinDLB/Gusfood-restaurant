/*
This header file describes the interface between an observable object and its observers !
*/

#ifndef GAME_EVENTS_HPP
#define GAME_EVENTS_HPP

#include <variant>

struct CharacterPosChanged;
struct CharacterSpeedChanged;

using GameEvents = std::variant<CharacterPosChanged, CharacterSpeedChanged>;

#endif