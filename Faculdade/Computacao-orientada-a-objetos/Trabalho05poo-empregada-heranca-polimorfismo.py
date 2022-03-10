from abc import ABC, abstractmethod

class EmpDomestica(ABC):

    def __init__(self, nome, telefone):
        self.__nome = nome
        self.__telefone = telefone
    
    def getNome(self):
        return self.__nome

    def getTelefone(self):
        return self.__telefone
    
    @abstractmethod
    def getSalario(self):
        pass

class horista(EmpDomestica):

    def __init__(self, nome, telefone, horasTrabalhadas, valorPorHora):
        super().__init__(nome, telefone)
        self.__horasTrabalhadas = horasTrabalhadas
        self.__valorPorHora = valorPorHora
    
    def getHorasTrabalhadas(self):
        return self.__horasTrabalhadas
    
    def getValorPorHora(self):
        return self.__valorPorHora
    
    def getSalario(self):
        salario = self.getHorasTrabalhadas() * self.getValorPorHora()
        return salario

class diarista(EmpDomestica):

    def __init__(self, nome, telefone, diasTrabalhados, valorPorDia):
        super().__init__(nome, telefone)
        self.__diasTrabalhados = diasTrabalhados
        self.__valorPorDia = valorPorDia
    
    def getDiasTrabalhados(self):
        return self.__diasTrabalhados
    
    def getValorPorDia(self):
        return self.__valorPorDia
    
    def getSalario(self):
        salario = self.getDiasTrabalhados() * self.getValorPorDia()
        return salario

class mensalista(EmpDomestica):
  
    def __init__(self, nome, telefone, valorMensal):
        super().__init__(nome, telefone)
        self.__ValorMensal = valorMensal
    
    def getValorMensal(self):
        return self.__ValorMensal
    
    def getSalario(self):
        return self.getValorMensal()
    
    


print('Candidatas:\n')
#definindo para os testes
horista = horista('Clotilde', '89224002', 160, 10)
print("""Nome: {}
Telefone: {}
Salário Mensal: {}R$""".format(horista.getNome(), horista.getTelefone(), horista.getSalario()))
print()

diarista = diarista('Joana', '99531130', 20, 55)
print("""Nome: {}
Telefone: {}
Salário Mensal: {}R$""".format(diarista.getNome(), diarista.getTelefone(), diarista.getSalario()))
print()

mensalista = mensalista('Matilde', '40028922', 1000)
print("""Nome: {}
Telefone: {}
Salário Mensal: {}R$""".format(mensalista.getNome(), mensalista.getTelefone(), mensalista.getSalario()))
print()



if horista.getSalario() < diarista.getSalario():
    if horista.getSalario() < mensalista.getSalario():
        print('A empregada com salário mais em conta é:')
        print("""Nome: {}
Telefone: {}
Salário Mensal: {}R$""".format(horista.getNome(), horista.getTelefone(), horista.getSalario()))



    else:
        print('A empregada com salário mais em conta é:')
        print("""Nome: {}
Telefone: {}
Salário Mensal: {}R$""".format(mensalista.getNome(), mensalista.getTelefone(), mensalista.getSalario()))



if diarista.getSalario() < horista.getSalario():
    if diarista.getSalario() < mensalista.getSalario():
        print('A empregada com salário mais em conta é:')
        print("""Nome: {}
Telefone: {}
Salário Mensal: {}R$""".format(diarista.getNome(), diarista.getTelefone(), diarista.getSalario()))



    else:
        print('A empregada com salário mais em conta é:')
        print("""Nome: {}
Telefone: {}
Salário Mensal: {}R$""".format(mensalista.getNome(), mensalista.getTelefone(), mensalista.getSalario()))