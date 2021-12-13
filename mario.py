while True:
    n = input("Height: ")
    if(n.isdigit()):
        if(int(n) > 0 and int(n) <= 8):
            break



n = int(n)
for i in range(n):
    for j in range(n - i - 1):
        print(" ", end='')
    for j in range (i + 1):
        print("#", end = '')
    print()

