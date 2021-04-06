from cs50 import get_float

change = get_float("Change:");

while change <= 0:
    change = get_float("Change:")


rounder = round(change*100)
counter = 0

while rounder > 0:
    if rounder < 5:
        rounder -= 1
        counter += 1
    elif rounder == 5:
        rounder -= 5
        counter += 1
    elif rounder > 5 and rounder < 10:
        rounder -= 5
        counter += 1
    elif rounder < 25:
        rounder -= 10
        counter += 1
    elif rounder >= 25:
        rounder -= 25
        counter += 1


print(counter)



