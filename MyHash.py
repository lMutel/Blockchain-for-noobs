import hashlib



class MyHash:
    def __init__(self):
        self.__str_hash = ''
        self.__massage = ""
        self.__lastHash = "0000"


    def hashing(self, s, last):
        on = 0
        while (True):
            self.__massage = s
            self.__lastHash = last
            self.__str_hash = str(hashlib.sha256(self.__massage.encode() + str(on).encode() + self.__lastHash.encode()).hexdigest())
            if self.__str_hash[-1] == '0':
                self.nonce = on
                break
            else:
                on += 1
            print(self.__str_hash)


    def info(self):
        return ("{} ({}) {} -----> {}".format(self.__massage,self.nonce, self.__lastHash, self.__str_hash)+ '\n')

    def geter(self):
        return self.__str_hash

