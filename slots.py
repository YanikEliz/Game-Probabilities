import random
import time

class SlotMachine:
    def __init__(self):
        self.reels = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
        self.payout_table = {
            (0, 0, 0): 100,
            (1, 1, 1): 50,
            (2, 2, 2): 30,
            (3, 3, 3): 20,
            (4, 4, 4): 10,
            (5, 5, 5): 5,
            (6, 6, 6): 3,
            (7, 7, 7): 2,
            (8, 8, 8): 1,
            (9, 9, 9): 0.5
        }

    def pull_lever(self):
        return [random.choice(self.reels) for _ in range(3)]

def play_slot_machine(machine, num_trials, bet_amount):
    wins = 0
    total_payout = 0
    for _ in range(num_trials):
        reels = machine.pull_lever()
        if tuple(reels) in machine.payout_table:
            wins += 1
            total_payout += machine.payout_table[tuple(reels)] * bet_amount
    win_rate = (wins / num_trials) * 100
    average_payout = total_payout / num_trials
    return win_rate, average_payout

def display_reels(reels):
    for _ in range(3):
        print("   ".join(str(reel) for reel in reels))
        time.sleep(0.5)
        reels = reels[1:] + [reels[0]]
        print()

if __name__ == "__main__":
    slot_machine = SlotMachine()
    num_trials = 1000000
    bet_amount = 1
    win_rate, average_payout = play_slot_machine(slot_machine, num_trials, bet_amount)
    print(f"Win rate after {num_trials} trials: {win_rate:.2f}%")
    print(f"Average payout per trial: ${average_payout:.2f}")
