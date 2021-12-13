from cs50 import get_string

text = get_string("Text: ")
letters = 0
words = 0
sen = 0
for i in text:
    if(i.isalpha()):
        letters += 1

    if i == ' ':
        words += 1

    if i == '.' or i == '!' or i == '?':
        sen += 1
words = words + 1


L = ((100 * letters) / words)
S = ((100 * sen) / words)

res = round(0.0588 * L - 0.296 * S - 15.8)
if res > 16:
    print("Grade 16+")
elif res < 1:
    print("Before Grade 1")
else:
    print("Grade " + str(res))