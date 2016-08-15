def highestScore(friends):
    FRIEND = "Y"

    relationship = []

    iMe = 0
    for me in friends:
        relationship.append(set([]))
        iYou = 0
        for you in me:
            if you == FRIEND:
                relationship[iMe].add(iYou)

                iYourFriend = 0
                for yourFriend in friends[iYou]:
                    if yourFriend == FRIEND and iYourFriend != iMe:
                        relationship[iMe].add(iYourFriend)
                    iYourFriend += 1
            iYou += 1
        iMe += 1

    mostFamous = max(relationship, key=len)

    return len(mostFamous)

#friend0 = highestScore(["NNN", "NNN", "NNN"])
#assert friend0 == 0

friend1 = highestScore(["NYY", "YNY", "YYN"])
assert friend1 == 2

friend2 = highestScore(["NYNNN",
    "YNYNN",
    "NYNYN",
    "NNYNY",
    "NNNYN"])
assert friend2 == 4

friend3 = highestScore(["NNNNYNNNNN",
    "NNNNYNYYNN",
    "NNNYYYNNNN",
    "NNYNNNNNNN",
    "YYYNNNNNNY",
    "NNYNNNNNYN",
    "NYNNNNNYNN",
    "NYNNNNYNNN",
    "NNNNNNYNNN",
    "NNNNNYNNNN"])
assert friend3 == 8

friend4 = highestScore(["NNNNNNNNNNNNNNY",
    "NNNNNNNNNNNNNNN",
    "NNNNNNNYNNNNNNN",
    "NNNNNNNYNNNNNNY",
    "NNNNNNNNNNNNNNY",
    "NNNNNNNNYNNNNNN",
    "NNNNNNNNNNNNNNN",
    "NNYYNNNNNNNNNNN",
    "NNNNNYNNNNNYNNN",
    "NNNNNNNNNNNNNNY",
    "NNNNNNNNNNNNNNN",
    "NNNNNNNNYNNNNNN",
    "NNNNNNNNNNNNNNN",
    "NNNNNNNNNNNNNNN",
    "YNNYYNNNNYNNNNN"])
assert friend4 == 6

print("succeeded")