import tkinter as tk
from tkinter import messagebox
from tkinter import ttk

class Curso():

    def __init__(self, nome):
        self.__nome = nome
        self.__alunos = []
    
    def getNome(self):
        return self.__nome
    
    def getAlunos(self):
        return self.__alunos
    
    def setAlunos(self, aluno):
        self.__alunos = aluno
    

class LimiteInsereCurso(tk.Toplevel):
    def __init__(self, controle, alunos):

        tk.Toplevel.__init__(self)
        self.geometry('350x325')
        self.title("Curso")
        self.controle = controle

        self.frameNome = tk.Frame(self)
        self.frameAlunos = tk.Frame(self)
        self.frameNome.pack()
        self.frameAlunos.pack()


        self.labelNome = tk.Label(self.frameNome, text="Nome: ")
        self.labelNome.pack(side="left")
        self.inputNome = tk.Entry(self.frameNome, width=20)
        self.inputNome.pack(side="left")

        self.labelAlunos = tk.Label(self.frameAlunos,text="Lista de alunos: ")
        self.labelAlunos.pack(side="left")
        self.listbox = tk.Listbox(self.frameAlunos)
        self.listbox.pack(side="left")
        for nome in alunos:
            self.listbox.insert(tk.END, nome.getNome())

        self.buttonInsereAluno = tk.Button(self, text='Insere Aluno')
        self.buttonInsereAluno.pack(side='left')
        self.buttonInsereAluno.bind('<Button>', controle.insereAluno)

        self.buttonCadastrarCurso = tk.Button(self, text='Cadastrar Curso')
        self.buttonCadastrarCurso.pack(side='left')
        self.buttonCadastrarCurso.bind('<Button>', controle.cadastrarCurso)

        self.buttonClear = tk.Button(self, text='Limpar')
        self.buttonClear.pack(side='left')
        self.buttonClear.bind('<Button>', controle.clear)
 
    def mostraJanela(self, titulo, msg):
        messagebox.showinfo(titulo, msg) 

class MostraCurso():
    def __init__(self, str):
        messagebox.showinfo("Lista de Cursos", str)

class CtrlCurso():
    def __init__(self, controlePrincipal):
        self.controlePrincipal = controlePrincipal
        self.ListaDeCursos = []
        self.ListaDeAlunos = []
        self.ListaAlunosNoCurso = []
    
    def insereCursos(self):
        self.ListaDeAlunos = self.controlePrincipal.ctrlAluno.listaAlunos
        self.limiteInsere = LimiteInsereCurso(self, self.ListaDeAlunos)
    
    def mostraCursos(self):
        palavra = ''
        for curso in self.ListaDeCursos:
            palavra += 'Curso: ' + curso.getNome()
            palavra += '\nLista de alunos matriculados no curso: \n'
            for aluno in self.ListaAlunosNoCurso:
                palavra += aluno.getNroMatric()+' -- '+aluno.getNome()+'\n'
        palavra += '\n--------------------------------------------------------'

        MostraCurso(palavra)

    def insereAluno(self, event):
        selecaoDeAluno = self.limiteInsere.listbox.get(tk.ACTIVE)
        aluno = self.controlePrincipal.ctrlAluno.getAluno(selecaoDeAluno)
        self.ListaAlunosNoCurso.append(aluno)
        self.limiteInsere.mostraJanela('Sucesso', 'ALuno inserido')
        self.limiteInsere.listbox.delete(tk.ACTIVE)

    def cadastrarCurso(self, event):
        nomeDoCurso = self.limiteInsere.inputNome.get()
        curso = Curso(nomeDoCurso)
        curso.setAlunos(self.ListaAlunosNoCurso)
        self.ListaDeCursos.append(curso)
        self.limiteInsere.mostraJanela('Sucesso', 'Curso cadastrado')
        self.limiteInsere.destroy()
    
    def clear(self, event):
        self.limiteInsere.inputNome.delete(0, len(self.limiteInsere.inputNome.get()))