#pragma once
//--------------------include Section --------------------
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib> 
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include <ostream>
#include <iterator>
#include "Board.h"
#include "knife.h"
#include "singleton.h"
#include "Object.h"
#include "StatusBar.h"
#include "Floor.h"
#include "Apple.h"
#include "StaticObject.h"
#include "KeyGate.h"
#include "Key.h"
#include "Spikes.h"
#include "Vine.h"
#include "NinjaStar.h"
#include "Frog.h"
#include "PresentLife.h"
#include "windows.h"

// const expresions initialization of the controller object
constexpr int	MINUSTHIRTY = -30 ,NEGONE = -1, ZERO = 0, ONE = 1, TWO = 2, THREE = 3, FOUR = 4,
				FIVE = 5,SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10, ELEVEN = 11, TWELVE = 12,
				THIRTEEN = 13, TWENTY = 20, THIRTYONE = 31, THIRTYTWO = 32, THIRTYTHREE = 33,
				STARTPIC = 39, FORTYFIVE = 45, HUNDREDFIFTY = 150, GROUNDLEVEL = 690,
				LEVELHEIGHT = 1000, LEVELWIDTH = 1500, SLEEPSCREEN = 3000;

constexpr double NEGPOINTTHIRYFIVE = -0.35, POINTTHIRYFIVE = 0.35, EIGHTPOINTFIVE = 8.5;

// directions enumeration
enum Direction { Down, Left, Right, Up };

// The Controller class represents the movement of all objects on the screen and sets the game

class Controller
{
public:

	//----Constructor for Controller------
	Controller(); 
	void run(float width, float height, int choice) ; // the main function of the actual game
	void draw(sf::RenderWindow& window, sf::RectangleShape& rec, sf::Vector2f& screen_focus1, sf::View& view, Board& level, float clock_sample, float GameClock);
	void setGame() ; // the function that sets all sounds and pictures of the game
	void jump(sf::RenderWindow& window, sf::RectangleShape& rec, sf::Vector2f& screen_focus1, sf::View& view, float x,sf::Event &event, Board& level ,
				float clock_sample, float gameClock, int level_num) ;

	void knifeMode(Board& level) ; // enables to use knives (kunais)
	void starMode(Board& level) ; // enables to use ninja stars (shurikens)


	float distance(float clock_sample) const;

	void move(float distance_x, float distance_y, Board& level, // movement function
					bool move, float dirc, float clock_sample) ;

	void gifts(bool& if_points, bool& if_stone, bool& if_clock, float clock_sample, Board& level) ; // creates gifts
	void gift_status(bool& if_points, bool& if_stone, bool& if_clock, float clock_sample, Board& level) ; // handles gifts on game board
	void setLevel(int& playerChoose, int& levelNum, Board& level) ; // sets the level before playing
	void setGameLevels(sf::RenderWindow& window, sf::View& v, int x, int y) ; // sets the screens between levels
	void isKnife(Board& level, sf::RenderWindow& window, float& clockSample) ; // enables operations while using knife
	void isClimb(Board& level, Player& player) const; // enables operations while climbing

private:  

	Board m_board; // board object member
	std::ifstream gameFile; // the stream of level files
	sf::Sound menuMusic, m_knifeSound, m_ninjaStarSound; // sounds of menu and weapons
	sf::Sprite jillSpr; // picture of the player
	sf::Texture backTex; // texture of background
	sf::RectangleShape background[EIGHT]; // backgrounds array
	sf::Texture tex; // text of texture
	sf::Clock clock, game_clock; // game clock member
	sf::Vector2f gifts_loc;

	int m_throw_distance = ZERO; // distance for throwing objects
	bool m_jumping; // jumping status
	bool m_knife = false; // knife use status
	bool keyPressed = false; // key pressed status
	bool win = false, isFirst = true, inMenu = true; // game screen status
	bool m_lvlDone = false; // level status

	bool if_stone = false; //if stone gift exist on the board
	bool if_points = false; //if points gift exist on the board
	bool if_clock = false; //if clock gift exist on the board

	float m_gift_clock; // gifts timer
	float m_gifts_counter; // gifts number in curent moment
	float m_pic;  // picture of present
	// members for jump function 
	float m_x = ZERO; // x location
	float m_y = GROUNDLEVEL; // ground level y location
	float m_velocityX = ZERO; // velocity on x
	float m_velocityY = ZERO; // velocity on y
	float m_accelerationX = ZERO; // acceleration on x
	float m_accelerationY = ZERO; // acceleration on y
	float m_gravity = THREE; // gravity of the game
	float m_direction; // direction of object

	Player player; // player object
	std::vector<Knife> m_knifes; // knives vector
	std::vector<NinjaStar> m_Nstars; // ninja star vector
	directions_t side = stand_t; // directions enum

};