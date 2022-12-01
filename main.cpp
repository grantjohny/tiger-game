/*
 * Player takes turns playing against a computer in Tiger Game
 * Each player has a set number of cards to play numbered 1-9 and either orange or purple color
 * There is one tiger color card that ends the game and gives the player +20 points
 * The value of purple cards is equal to their rank, but orange cards are double their rank
 * At the end of each round the player with the highest value wins, winner receives sum of both cards played
 * Choose to play again at the end of each game, or quit and check the summary of every game played
 */

#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include <vector>

int main() {

	//Variable declarations to implement play again functionality 
	int totalRounds = 0;
	int cpuWins = 0;
	int humanWins = 0;
	int cpuTotalScore = 0;
	int humanTotalScore = 0;
	vector<int> cpuScores;
	vector<int> humanScores;
	char playAgain = 'y';
	
	//Start while loop to continue playing after game ends
	while(playAgain == 'y'){
	  int numRounds;
	  
	  cout << "Welcome to Tiger Game!" << endl;

	  //Allows the user to choose how many rounds to play, if there are enough cards in the deck
	  cout << "How many rounds would you like to play? " << endl;
	  cin >> numRounds;
	  while(numRounds > 10){
		  cout << "Please enter a different number, not enough cards in deck" << endl;
		  cin >> numRounds;
	  }

	  //Create a deck of cards and shuffle it.
	  Deck deckOfCards;
	  deckOfCards.shuffle();
	  cout << "The deck has been shuffled and each player has drawn " << numRounds << " cards" << endl;

	  //Create two players, each one with X cards in their hand.
	  Player human(deckOfCards, numRounds);
	  Player cpu(deckOfCards, numRounds);
	  
	  //Start Game

	  //Creating objects to copy cards to 
	  Card cpuCard;
	  Card humanCard;
	  int cardSelection;

	  //Try if cpu or player plays tiger card
	  try{
		  for(int i = 1; i <= numRounds; ++i){
				cout << "\nRound " << i << endl;
				cout << "------" << endl;

				//Slection of computer card is randomized
				int cpuSelection = rand() % cpu.hand.getHandSize();
				cpuCard = cpu.hand.dealCard(cpuSelection);
				cout << "The computer plays: " << cpuCard.printCard() << endl;
				
				//Throws exception if cpu plays tiger card
				if(cpuCard.getColor() == Card::tiger){
					throw (1);
				}

				//Print the user their hand and ask for card slection
				cout << endl << human.hand.printHand() << endl;
				cout << "Which card do you want to play? " << endl;
				cin >> cardSelection;
				while(cardSelection > human.hand.getHandSize()){
					cout << "Please enter a valid number: " << endl;
					cin >> cardSelection;
				}
				humanCard = human.hand.dealCard(cardSelection - 1);
				cout << "You Played: " << humanCard.printCard() << endl;
				
				//Throws exception if human plays tiger card
				if(humanCard.getColor() == Card::tiger){
					throw (2);
				}

				//Compare values of each card and determine round winner
				if(cpuCard.getValue() > humanCard.getValue()){
					cout << "\nThe computer wins this round!" << endl;
					cpu.score += (cpuCard.getValue() + humanCard.getValue());
				}
				else if(cpuCard.getValue() < humanCard.getValue()){
					cout << "\nYou win this round!" << endl;
					human.score += (cpuCard.getValue() + humanCard.getValue());
				}
				else{
					cout << "Tie!" << endl;
				}

				//Print current scores after round
				cout << "Current scores: " << endl;
				cout << "Human: " << human.score << endl;
				cout << "Computer: " << cpu.score << endl << endl;

		  } //End of for loop
		} //End try

		//Catch end the game
		catch (int tigerWin){
			cout << "Tiger card, GAME OVER!" << endl;
			if(tigerWin == 1){
				cpu.score += 20;
			}
			else{
				human.score += 20;
			}
		}
	  

		//Print final game results.  
		cout << "FINAL SCORE: " << endl;
		cout << "Human: " << human.score << endl;
		cout << "Compuer: " << cpu.score << endl;
		if(cpu.score > human.score){
			cout << "Computer has won!" << endl << endl;
			cpuWins++;
		}
		else{
			cout << "Human has won!" << endl;
			humanWins++;
		}

		//Collecting data for game summary
		totalRounds++;
		cpuScores.push_back(cpu.score);
		humanScores.push_back(human.score);
		cpuTotalScore += cpu.score;
		humanTotalScore += human.score;

		//Ask the user if they want to play another game
		cout << "Would you like to play again? (y/n)" << endl;
		cin >> playAgain;
		cout << endl << endl;
	} //End of while loop
	
	//Prints a summary of all games including number of games played, wins for each player, score per game and total score
	cout << endl << "Game Summary for " << totalRounds;
	if(totalRounds == 1){
		cout << " Game Played" << endl;
	}
	else{
		cout << " Games Played" << endl;
	}
	cout << "--------------------------" << endl;
	cout << "Computer won " << cpuWins;
  if(cpuWins == 1){
		cout << " Game" << endl;
	}
	else{
		cout << " Games" << endl;
	}
	cout << "Human won " << humanWins;
	if(humanWins == 1){
		cout << " Game" << endl << endl;
	}
	else{
		cout << " Games" << endl << endl;
	}
  
 
  //game summary
  for(int i = 1; i <= totalRounds; i++){
  	cout << "Game " << i << "" << endl;
  	cout << "Computer scored: " << cpuScores[i-1] << endl;
  	cout << "Human scored: " <<  humanScores[i-1] << endl << endl;

  }
  
	
	cout << "Total Scores" << endl;
	cout << "------------" << endl;
	cout << "Computer scored " << cpuTotalScore << " total points" << endl;
	cout << "Human scored " << humanTotalScore << " total points" << endl;
	return 0;
}
