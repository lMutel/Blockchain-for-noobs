import MyHash


def interface():

    lastHash = "0000"
    print("Type exit() to quit")
    print("Please, put new note here: ")

    newChain = []

    while(True):
        s = input()
        if s == "exit()":
            break
        newBlock = MyHash.MyHash()
        newBlock.hashing(s, lastHash)
        newChain.append(newBlock)

        lastHash = str(newBlock.geter())


    for block in newChain:
        print(block)
