# Game-Probabilities
Various Probabilities of Common Casino Games

Most games at casinos are always set so the house always makes more profit than the average player.
These simulations show the exact probabilities and are all set using built in rng's.
For a more accurate simulation a more rigorous approach to random number generation should be used such as a mersenne twister, philox, square rng, etc. 
All simulations can be run with an extra function to have buy in change dynamically till probability equals constant you set which is useful when making sure games are within certain threshold for gaming laws. This would require use of a Markov chain Monte Carlo method to run simulation and make sure standard deviations are within certain range.