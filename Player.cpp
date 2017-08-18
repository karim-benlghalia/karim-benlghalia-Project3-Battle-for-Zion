#include <iostream>
#include <string>
#include "Robot.h"
#include "Player.h"
#include "Arena.h"
#include "globals.h"
using namespace std;

Player::Player(Arena* ap, int r, int c)
{
	if (ap == nullptr)
	{
		cout << "***** The player must be in some Arena!" << endl;
		exit(1);
	}
	if (r < 1 || r > ap->rows() || c < 1 || c > ap->cols())
	{
		cout << "**** Player created with invalid coordinates (" << r
			<< "," << c << ")!" << endl;
		exit(1);
	}
	m_arena = ap;
	m_row = r;
	m_col = c;
	m_age = 0;
	m_dead = false;
}

int Player::row() const
{

	return m_row;
}

int Player::col() const
{

	return m_col;
}

int Player::age() const
{

	return m_age;
}

string Player::takeComputerChosenTurn()
{

	//  If there is no danger shoot any robots withn 5 steps.
	if (m_arena->nRobotsAt(m_row - 1, m_col) == 0 && m_arena->nRobotsAt(m_row + 1, m_col) == 0 && m_arena->nRobotsAt(m_row, m_col - 1) == 0 && m_arena->nRobotsAt(m_row, m_col + 1) == 0) {

		for (int i = 0; i <= MAXSHOTLEN; i++){


			if (m_arena->nRobotsAt(m_row + i, m_col) >= 1)	{

				if (shoot(DOWN))
					return "Shot and hit!";
				else
					return "Shot and missed!";

			}
			else if (m_arena->nRobotsAt(m_row - i, m_col) >= 1)	{

				if (shoot(DOWN))
					return "Shot and hit!";
				else
					return "Shot and missed!";

			}
			else if (m_arena->nRobotsAt(m_row, m_col + i) >= 1)	{

				if (shoot(RIGHT))
					return "Shot and hit!";
				else
					return "Shot and missed!";

			}
			else if (m_arena->nRobotsAt(m_row, m_col - i) >= 1)	{

				if (shoot(LEFT))
					return "Shot and hit!";
				else
					return "Shot and missed!";
			}

		}
		stand();
		return "Stood!";
	}
	//If the player is by one of the 4 edges of the arena.
	else if (m_row == 1){
		if (m_arena->nRobotsAt(m_row + 1, m_col) == 0 && m_arena->nRobotsAt(m_row + 2, m_col) == 0 && m_arena->nRobotsAt(m_row + 1, m_col + 1) == 0 && m_arena->nRobotsAt(m_row + 1, m_col - 1) == 0)
		{
			move(DOWN);
			return "moved";
		}
		else if (m_arena->nRobotsAt(m_row, m_col - 1) == 0 && m_arena->nRobotsAt(m_row, m_col - 2) == 0 && m_arena->nRobotsAt(m_row + 1, m_col - 1) == 0) {
			move(LEFT);
			return "moved";
		}
		else if (m_arena->nRobotsAt(m_row, m_col + 1) == 0 && m_arena->nRobotsAt(m_row, m_col + 2) == 0 && m_arena->nRobotsAt(m_row + 1, m_col + 1) == 0)  {
			move(RIGHT);
			return "moved";
		}
		else {
			switch (rand() % 3)
			{
			case 0:
				move(RIGHT);
				break;
			case 1:
				move(DOWN);
				break;
			case 2:
				move(LEFT);
				break;
			}
			return "Moved";

		}
	}
	else if (m_row == m_arena->rows()){
		if (m_arena->nRobotsAt(m_row - 1, m_col) == 0 && m_arena->nRobotsAt(m_row - 2, m_col) == 0 && m_arena->nRobotsAt(m_row - 1, m_col + 1) == 0 && m_arena->nRobotsAt(m_row - 1, m_col - 1) == 0)
		{
			move(UP);
			return "moved";
		}
		else if (m_arena->nRobotsAt(m_row, m_col - 1) == 0 && m_arena->nRobotsAt(m_row, m_col - 2) == 0 && m_arena->nRobotsAt(m_row - 1, m_col - 1) == 0) {
			move(LEFT);
			return "moved";
		}
		else if (m_arena->nRobotsAt(m_row, m_col + 1) == 0 && m_arena->nRobotsAt(m_row, m_col + 2) == 0 && m_arena->nRobotsAt(m_row - 1, m_col + 1) == 0) {
			move(RIGHT);
			return "moved";
		}
		else {
			switch (rand() % 3)
			{
			case 0:
				move(UP);
				break;
			case 1:
				move(RIGHT);
				break;
			case 2:
				move(LEFT);
				break;
			}
			return "Moved";

		}
	}
	else if (m_col == m_arena->cols()){
		if (m_arena->nRobotsAt(m_row, m_col - 1) == 0 && m_arena->nRobotsAt(m_row, m_col - 2) == 0 && m_arena->nRobotsAt(m_row - 1, m_col - 1) == 0 && m_arena->nRobotsAt(m_row + 1, m_col - 1) == 0)
		{
			move(LEFT);
			return "moved";
		}
		else if (m_arena->nRobotsAt(m_row - 1, m_col) == 0 && m_arena->nRobotsAt(m_row - 2, m_col) == 0 && m_arena->nRobotsAt(m_row - 1, m_col - 1) == 0) {
			move(UP);
			return "moved";
		}
		else if (m_arena->nRobotsAt(m_row + 1, m_col) == 0 && m_arena->nRobotsAt(m_row + 2, m_col) == 0 && m_arena->nRobotsAt(m_row + 1, m_col - 1) == 0) {
			move(DOWN);
			return "moved";
		}
		else {
			switch (rand() % 3)
			{
			case 0:
				move(UP);
				break;
			case 1:
				move(DOWN);
				break;
			case 2:
				move(LEFT);
				break;
			}
			return "Moved";

		}
	}
	else if (m_col == 1){
		if (m_arena->nRobotsAt(m_row, m_col + 1) == 0 && m_arena->nRobotsAt(m_row, m_col + 2) == 0 && m_arena->nRobotsAt(m_row - 1, m_col + 1) == 0 && m_arena->nRobotsAt(m_row + 1, m_col + 1) == 0)
		{
			move(RIGHT);
			return "moved";
		}
		else if (m_arena->nRobotsAt(m_row - 1, m_col) == 0 && m_arena->nRobotsAt(m_row - 2, m_col) == 0 && m_arena->nRobotsAt(m_row - 1, m_col + 1) == 0) {
			move(UP);
			return "moved";
		}
		else if (m_arena->nRobotsAt(m_row + 1, m_col) == 0 && m_arena->nRobotsAt(m_row + 2, m_col) == 0 && m_arena->nRobotsAt(m_row + 1, m_col + 1) == 0) {
			move(DOWN);
			return "moved";
		}
		else {
			switch (rand() % 3)			  //otherwise take a random move to just move away from the danger.
			{
			case 0:
				move(UP);
				break;
			case 1:
				move(DOWN);
				break;
			case 2:
				move(RIGHT);
				break;
			}
			return "Moved";

		}
	}
	//if the player is in the middle of the aena, but there is a robot close.
	else if (m_arena->nRobotsAt(m_row, m_col) >= 1 || m_arena->nRobotsAt(m_row - 1, m_col) >= 1 || m_arena->nRobotsAt(m_row + 1, m_col) >= 1 || m_arena->nRobotsAt(m_row, m_col - 1) >= 1 || m_arena->nRobotsAt(m_row, m_col + 1) >= 1){

		//If Down is safe, then move down.
		if (m_arena->nRobotsAt(m_row + 1, m_col) == 0 && m_arena->nRobotsAt(m_row + 2, m_col) == 0 && m_arena->nRobotsAt(m_row + 1, m_col + 1) == 0 && m_arena->nRobotsAt(m_row + 1, m_col - 1) == 0){
			move(DOWN);
			return "moved";
		} //If left is safe then move left.
		else if (m_arena->nRobotsAt(m_row, m_col - 1) == 0 && m_arena->nRobotsAt(m_row, m_col - 2) == 0 && m_arena->nRobotsAt(m_row + 1, m_col - 1) == 0 && m_arena->nRobotsAt(m_row - 1, m_col - 1) == 0) {
			move(LEFT);
			return "moved";
		}
		//if up is safe, then move up
		else if (m_arena->nRobotsAt(m_row - 1, m_col) == 0 && m_arena->nRobotsAt(m_row - 2, m_col) == 0 && m_arena->nRobotsAt(m_row - 1, m_col + 1) == 0 && m_arena->nRobotsAt(m_row - 1, m_col - 1) == 0){
			move(UP);
			return "moved";
		}			//if right is safe, then  move right
		else if (m_arena->nRobotsAt(m_row, m_col + 1) == 0 && m_arena->nRobotsAt(m_row, m_col + 2) == 0 && m_arena->nRobotsAt(m_row + 1, m_col + 1) == 0 && m_arena->nRobotsAt(m_row - 1, m_col + 1) == 0){
			move(RIGHT);
			return "moved";
		}

		else {
			switch (rand() % 4)							   //otherwise take a random move to just move away from the danger.
			{
			case 0:
				move(UP);
				break;
			case 1:
				move(RIGHT);
				break;
			case 2:
				move(LEFT);
				break;
			case 3:
				move(DOWN);
				break;
			}
			return "moved";
		}
	}

	else {
		stand();
		return "Stood!";
	}

}

void Player::stand()
{
	m_age++;
}

void Player::move(int dir)
{
	m_age++;
	switch (dir)
	{
	case UP:
		if (m_row > 1)
			m_row--;
		break;
	case DOWN:
		if (m_row < m_arena->rows())
			m_row++;
		break;
	case LEFT:
		if (m_col > 1)
			m_col--;
		break;
	case RIGHT:
		if (m_col < m_arena->cols())
			m_col++;
		break;
	}
}

bool Player::shoot(int dir)
{
	m_age++;

	if (rand() % 3 == 0)  // miss with 1/3 probability
		return false;
	switch (dir){

	case UP:
		
			for (int i = 1; i <= MAXSHOTLEN; i++)	 {
				if (m_arena->nRobotsAt(m_row - i, m_col) >= 1){
					m_arena->damageRobotAt(m_row - i, m_col);
					return true;
		
				}
				
			}
		
		
		
	case DOWN:
		
			for (int i = 1; i <= MAXSHOTLEN; i++){

				if (m_arena->nRobotsAt(m_row + i, m_col) >= 1){

					m_arena->damageRobotAt(m_row + i, m_col);
					return true;
					
					
				}
				
			}
	
		
	case RIGHT:

			for (int i = 1; i <= MAXSHOTLEN; i++){

				if (m_arena->nRobotsAt(m_row, m_col + i) >= 1){

					m_arena->damageRobotAt(m_row, m_col + i);
					return true;
					
			
				}
			
			}
		
		
		


		
	case LEFT:
		
			for (int i = 1; i <= MAXSHOTLEN; i++){

				if (m_arena->nRobotsAt(m_row, m_col - i)>=1){

					m_arena->damageRobotAt(m_row, m_col - i);
					return true;
					
			
				}
				
			}
		

	}
	// Damage the nearest robot in direction dir, returning
	// true if a robot is hit and damaged, false if not hit.
	return false;  // This implementation compiles, but is incorrect.
}

bool Player::isDead() const
{

	return m_dead;
}

void Player::setDead()
{
	m_dead = true;
}