# tiger-game
A simple game where the user takes turns with the computer playing cards

How to run:

make

./tiger-game.out

How to play:
At the start of each game the user enters how many cards they would like to draw, the computer will draw the same amount
The computer goes first and randomly selects a card from its hand
You will be shown your hand where you can make a selection using the corresponding number key
The value of your card will be compared to the computer's card and the highest value wins
Continue to play rounds until you run out of cards and the final scores will be shown
You can choose to play more games if you wish
When you are done playing, a summary of all games will be shown including games played, games won, points per game, and total points

Rules:
Cannot draw more than 10 cards per game
Purple cards have their value set to their rank and orange cards are double their rank
  for example: 
  purple : 2 has a value of 2
  orange : 2 has a value of 3
The winner of each round gains the sum of the 2 cards in points
If the value of the cards are the same then there is a tie and no points are awarded
If a player plays the "tiger : 10" card then the game is over and whoever played the card wins and gains 20 points
