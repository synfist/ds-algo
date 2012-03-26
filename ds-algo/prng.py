import random

P = 295075153L   # about 2^28

class WeakPrng(object):
    def __init__(self, p):   # generate seed with 56 bits of entropy
        self.p = p
        self.x = random.randint(0, p)
        self.y = random.randint(0, p)
        self.orgx = self.x
        self.orgy = self.y
        self.bx = 0
        self.by = 0

    def prgbreak(x,y):
        self.x = x
        self.y = y

    def next(self):
        # x_{i+1} = 2*x_{i}+5  (mod p)
        self.x = (2*self.x + 5) % self.p

        # y_{i+1} = 3*y_{i}+7 (mod p)
        self.y = (3*self.y + 7) % self.p

        # z_{i+1} = x_{i+1} xor y_{i+1}
        return (self.x ^ self.y)

prng = WeakPrng(P)
"""
for i in range(1, 10):
    print "output #%d: %d" % (i, prng.next())
"""
"""
i = 0L
while 1:
    prng = WeakPrng(P)
    i += 1
    if i%1000000 == 0:
        print i
    #prg = prng.next()
    if prng.next() == 210205973:
        print prng.orgx, prng.orgy
        for j in range(1, 10):
            print "output #%d: %d" % (j, prng.next())
        break
"""
"""
prng = WeakPrng(P)
for i in range(295075153L):
    x = i
    for i in range(295075153L):
        y = j
        x = (2*x + 5) % 295075153L
        y = (3*y + 7) % 295075153L
        if x ^ y == 210205973
            print i, j
            for j in range(1, 10):
            print "output #%d: %d" % (j, prng.next())
            break
"""
prng = WeakPrng(P)
for i in range(295075153L):
    for i in range(295075153L):
        if prng.next() == 210205973:
            print i, j
            for j in range(1, 10):
                print "output #%d: %d" % (j, prng.next())
            break


"""
output #1: 210205973
output #2: 22795300
output #3: 58776750
output #4: 121262470
output #5: 264731963
output #6: 140842553
output #7: 242590528
output #8: 195244728
output #9: 86752752
"""