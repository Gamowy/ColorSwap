#pragma once
#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

//Constants
const int FRAME_RATE = 60;
const int WINDOW_WIDTH = 600; //px
const int WINDOW_HEIGHT = 800; //px;

const float GRAVITY = 0.5f;
const float JUMP_HEIGHT = -5.f;

const sf::Color COLOR_SWAP_CYAN(31, 77, 82);
const sf::Color COLOR_SWAP_PURPLE(49, 7, 82);
const sf::Color COLOR_SWAP_YELLOW(87, 76, 20);
const sf::Color COLOR_SWAP_RED(94, 5, 27);