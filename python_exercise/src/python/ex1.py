import random
secret = random.randint(1,10)
print('-------I love fish C -------')
temp = input("guess a number, and you only have two chances.")
guess = int(temp)
time =0
while(guess != secret and time < 4):
      temp = input("No, guess one again")
      guess = int(temp)
      if guess == secret:
            print("you are right")
      else:
            print("wrong answer again!")
            time = time + 1
print("game over!")
