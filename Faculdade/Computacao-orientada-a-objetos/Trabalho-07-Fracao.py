def mdc(m, n):
    while m%n != 0:
        oldm = m
        oldn = n
        m = oldn
        n = oldm%oldn
    return n

def mesmaFracao(f1, f2):
    return (f1.getNum() == f2.getNum()) and (f1.getDen() == f2.getDen())    

class Fracao:
    
    def __init__(self, num, den):
        self.__num = num        
        self.__den = den     

    def __str__(self):
        return str(self.__num) + "/" + str(self.__den)

    def getNum(self):
        return self.__num

    def getDen(self):
        return self.__den       

    def simplifica(self):
        divComum = mdc(self.__num, self.__den)
        self.__num = self.__num // divComum
        self.__den = self.__den // divComum   

    def __add__(self,outraFrac):
        novoNum = self.__num * outraFrac.getDen() + self.__den * outraFrac.getNum()
        novoDen = self.__den * outraFrac.getDen()
        divComum = mdc(novoNum, novoDen)
        novaFracao = Fracao(novoNum//divComum, novoDen//divComum)        
        if novaFracao.getNum() / novaFracao.getDen() < 1:
            return novaFracao

        elif novaFracao.getNum() % novaFracao.getDen() == 0:
            return novaFracao.getNum() / novaFracao.getDen()

        else:
            inteiro = novaFracao.getNum() // novaFracao.getDen()
            newNum = novaFracao.getNum() - inteiro * novaFracao.getDen()
            F = fracaoMista(inteiro, newNum, novaFracao.getDen())
            return F
            
class fracaoMista(Fracao):

    def __init__(self, parteInteira, num, den):
        super().__init__(num, den)
        self.__parteInteira = parteInteira

    def getPartInteira(self):
        return self.__parteInteira

    def __str__(self):
        return str(self.__parteInteira) + ' ' + str(self.getNum()) + '/' + str(self.getDen())

    def __add__(self, segundafunc):
        novoNum1 = self.getPartInteira() * self.getDen() + self.getNum()
        PrimeiraFracao = Fracao(novoNum1, self.getDen())
        novoNum2 = segundafunc.getPartInteira() * segundafunc.getDen() + segundafunc.getNum()
        SegundaFracao = Fracao(novoNum2, segundafunc.getDen())
        return PrimeiraFracao + SegundaFracao
    
print('Soma: 7/6 + 13/7')
frac1 = Fracao (7, 6)
frac2 = Fracao(13, 7)
frac3 = frac1 + frac2
print('RESULTADO =', frac3)
print()

print('Soma: 1/3 + 2/3')
frac1 = Fracao (1, 3)
frac2 = Fracao(2, 3)
frac3 = frac1 + frac2
print('RESULTADO =', frac3)
print()

print('Soma: 3 1/2 + 4 2/3')
frac1 = fracaoMista (3, 1, 2)
frac2 = fracaoMista (4, 2, 3)
frac3 = frac1 + frac2
print('RESULTADO =', frac3)