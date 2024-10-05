answer = ''
for i in input():
    if i.isupper():
        if (65 <= ord(i) <= 77):
            answer += chr(ord(i) + 13)  # A ~ M
        else:
            answer += chr(ord(i) - 13)  # N ~ Z
    elif i.islower():
        if (97 <= ord(i) <= 109):
            answer += chr(ord(i) + 13)  # a ~ m
        else:
            answer += chr(ord(i) - 13)  # n ~ z
    else:
        answer += i
        
print(answer)