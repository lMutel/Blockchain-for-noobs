class MyHash:

    def __init__(self):
        self.str_hash = 0
        self.massage = ""
        self.lastHash = "0000"


    def hashing(self, s, last):
        on = 0
        while (True):
            self.massage = s
            self.lastHash = last
            self.str_hash = hash(self.massage + str(on) + self.lastHash)

            if (self.str_hash % 10000 == 0):
                self.nonce = on
                break
            else:
                on += 1


    def __str__(self):
        return "{} ({}) {} -----> {}".format(self.massage,self.nonce, self.lastHash, self.str_hash)

    def geter(self):
        return self.str_hash

