from abc import ABC, abstractmethod

##exceptions

class profNaoEhDoutor(Exception):
    pass

class idadeAbaixoDaPermitida(Exception):
    pass

class cursoInvalido(Exception):
    pass

class cpfDuplicado(Exception):
    pass


##classes
class Pessoa(ABC):
    def __init__(self, nome, idade, endereco, cpf):
        self.__nome = nome
        self.__idade = idade 
        self.__endereco = endereco
        self.__cpf = cpf

    def getNome(self):
        return self.__nome
    
    def getIdade(self):
        return self.__idade
    
    def getEndereco(self):
        return self.__endereco

    def getCpf(self):
        return self.__cpf
    
    @abstractmethod
    def printDescricao(self):
        pass

class Professor(Pessoa):
    def __init__(self, nome, idade, endereco, cpf, titulacao):
        super().__init__(nome, idade, endereco, cpf)
        self.__titulacao = titulacao
    
    def getTitulacao(self):
        return self.__titulacao
    
    def printDescricao(self):
        print("""PROFESSOR: {} IDADE: {} TITULACAO: {} ENDERECO: {} CPF: {}""".format(self.getNome(),self.getIdade(), self.getTitulacao(), self.getEndereco(), self.getCpf()))

class Aluno(Pessoa):
    def __init__(self, nome, idade, endereco, cpf, curso):
        super().__init__(nome, idade, endereco, cpf)
        self.__curso = curso
    
    def getCurso(self):
        return self.__curso
    
    def printDescricao(self):
        print("""ALUNO: {} IDADE: {} CURSO: {} ENDERECO: {} CPF: {} """.format(self.getNome(),self.getIdade(), self.getCurso(), self.getEndereco(), self.getCpf()))

Professores = [
("Glauco Silva", 50, "Fortaleza, Avenida Matheus Isla, n° 241", "123.456.789-12", "Mestre"),
("Andreia Matos", 27, "Porto Alegre, Rua das Flores, n° 282", "123.456.789-14", "Especializado"),
("Paulo Henrique", 30, "Santa Rita, Rua dos Carpinteiros, n° 303", "123.456.789-13", "Doutor"),
("Eduardo Damas", 56, "Sao Leopoldo, Avenida Ribeirinha das Garças, n° 530", "123.456.789-13", "Mestre"),
("Claudia Trindade", 34, "Rio das Ostras, Rua Costa Azul, n° 309", "123.456.789-15", "Especializado"),
("Fernanda Fonseca", 40, "Nova Friburgo, Rua Sertaozinho, n° 108", "123.456.789-16", "Doutor"),
]

Alunos = [
("Joao Neto", 18, "Sao Paulo, Avenida Barueri, n° 454", "123.456.789-20", "SIN"),
("Vitor Michel", 19, "Amapá, Rua Armando, n° 115", "123.456.789-21", "SIN"),
("Caio Amauri", 15, "Minas Gerais, Rua Ferreira, n° 454", "123.456.789-22", "CCO"),
("Gustavo Ferreira", 24, "Macaé, Rua Cesário, n° 888", "123.456.789-23", "SIN"),
("Artur Silva", 99, "Acre, Avenidade da liberdade, nº 993", "123.456.789-23", "SIN"),
("Gabriel Maia", 19, "Campos, Rua Alvim, 104", "123.456.789-24", "ADM"),
]

Cadastro = {}

print("PROFESSORES:\n\n")
for nome, idade, endereco, cpf, titulacao in Professores:
    try:
        if cpf in Cadastro:
            raise cpfDuplicado()
        if idade < 30:
            raise idadeAbaixoDaPermitida()
        if titulacao != 'Doutor':
            raise profNaoEhDoutor()
    except cpfDuplicado:
        print('NAO PERMITIDO POIS O CPF {} DO(A) PROFESSOR(A) {} JÁ ESTÁ EM USO!'.format(cpf, nome))
    except idadeAbaixoDaPermitida:
        print('NAO PERMITIDO POIS O(A) PROFESSOR(A) {} POSSUI IDADE {}, SENDO INFERIOR DO QUE A PERMITADA.'. format(nome, idade))
    except profNaoEhDoutor:
        print('NAO PERMITIDO POIS O(A) PROFESSOR(A) {} NÃO POSSUI DOUTORADO, ELE(A) É {}.'.format(nome, titulacao))
    else:
        pessoa = Professor(nome, idade, endereco, cpf, titulacao)
        Cadastro[cpf] = pessoa
        print("{} FOI CADASTRADO(A) COM SUCESSO,".format(nome))
        pessoa.printDescricao()

print("\n\nALUNOS:\n\n")
for nome, idade, endereco, cpf, curso in Alunos:
    try:
        if cpf in Cadastro:
            raise cpfDuplicado()
        if idade < 18:
            raise idadeAbaixoDaPermitida()
        if curso != 'CCO' and curso != 'SIN':
            raise cursoInvalido()
    except cpfDuplicado:
        print('NAO PERMITIDO POIS O CPF {} DO(A) ALUNO(A) {} JÁ ESTÁ EM USO!'.format(cpf, nome))
    except idadeAbaixoDaPermitida:
        print('NAO PERMITIDO POIS O(A) ALUNO(A) {} POSSUI IDADE {}, SENDO INFERIOR DO QUE A PERMITADA.'. format(nome, idade))
    except cursoInvalido:
        print('NAO PERMITIDO POIS (A) ALUNO(A) {} NÃO CURSA SISTEMAS OU CIÊNCIA, ELE(A) É DO CURSO {}'.format(nome, curso))
    else:
        pessoa = Aluno(nome, idade, endereco, cpf, curso)
        Cadastro[cpf] = pessoa
        print("{} FOI CADASTRADO(A) COM SUCESSO".format(nome))
        pessoa.printDescricao()