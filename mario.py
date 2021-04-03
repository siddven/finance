height = int(input("Height: "))
while height < 1 or height > 8:
    height = int(input("Height: "))

n = 0
for i in range(height):
    n += 1
    u = height - i
    u -= 1
    for j in range(u):
        print(" ",end="")
    for a in range(n):
        print("#", end="")

    print(" ", end="")
    print(" ", end="")
    for m in range(n):
        print("#", end="")
    print("\n",end = "")







