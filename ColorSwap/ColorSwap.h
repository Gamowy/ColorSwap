#pragma once
#include <iostream>
#include <random>
#include <ctime>
#include <chrono>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>
#include <lmcons.h>
#include "Collision.h"

//XOR wstring cipher for file read/write
static std::wstring crypt(std::wstring str)
{
	std::wstring result = str;
	for (int i = 0; i < result.size(); i++) result[i] = str[i] ^ 83;
	return result;
}

//Random generator
static std::random_device rd;
static std::mt19937 gen(rd());

//Constants
const int FRAME_RATE = 60;
const int WINDOW_WIDTH = 600; //px
const int WINDOW_HEIGHT = 800; //px;
const int DEFAULT_FONT_SIZE = 35;

const float GRAVITY = 0.5f;
const float JUMP_HEIGHT = -8.f;

const sf::Color COLOR_SWAP_CYAN(79, 196, 209);
const sf::Color COLOR_SWAP_PURPLE(125, 18, 209);
const sf::Color COLOR_SWAP_YELLOW(222, 194, 51);
const sf::Color COLOR_SWAP_RED(240, 14, 76);