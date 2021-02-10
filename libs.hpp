#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#define WHITE 1
#define BLACK 0

typedef sf::Vector2i Coordinates;
static const float VIEW_SIZE = 1000.0f;
static const float VIEW_STEP = (VIEW_SIZE * 0.9)/2; /// describes how much one part of board takes 
