#pragma once
#include "Monster.h"
#include <ostream>


class Frog : public Monster
{

public:

	//----Constructor for Frog object------
	Frog(sf::Vector2i location, char icon);

	void draw(sf::RenderWindow& window, float clock_sample)override; //draw func

	void update_time_counter(float add) ; // func to update time counter

	void set_direction() ; // sets Birds direction

	directions_t get_direction() const; // gets directions from enam
	const sf::Vector2f get_location() const; // gets location vertex

	void move(float x, float y, float dirc) override {}; // empty definition used for polymorphism

	void movement(float x, float y, float dirc) override; // empty definition used for polymorphism
	void set_y_position(float y) override { m_location.y = y; }; // empty definition used for polymorphism
	void setLocation(float newState) { m_location.x *= newState; };
	const sf::Sprite get_sprite() const { return m_pic; }; // gets Bird picture

	void set_location(sf::Vector2f location); // sets Bird location
	void fix_position(); // fixes Bird position

private:

	float m_x;
	float m_time_counter;
};
