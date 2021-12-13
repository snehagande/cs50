from cs50 import get_float
while True:
    n = get_float("Change owed: ")
    if n > 0:
        break
n = n * 100
a = n // 25
n = n % 25
b = n // 10
n = n % 10
c = n // 5
n = n % 5

res = a + b + c + n
print(int(res))
submit50 cs50/problems/2021/x/sentimental/cash