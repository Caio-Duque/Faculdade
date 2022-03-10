import tkinter as tk
from tkinter import messagebox
import os.path
import pickle
import Produto as prod
import CupomFiscal as cp

class LimitePrincipal:
    def __init__(self, root, controle):
        self.controle = controle
        self.root = root
        self.root.geometry("500x400")
        self.menubar = tk.Menu(self.root)
        self.produto = tk.Menu(self.menubar)
        self.CupomFiscal = tk.Menu(self.menubar)
        self.salva = tk.Menu(self.menubar)
        self.sair = tk.Menu(self.menubar)

        self.produto.add_command(label="Cadastrar", command=self.controle.insereProdutos)
        self.produto.add_command(label="Consultar", command=self.controle.consultaProdutos)
        self.menubar.add_cascade(label="Produto", menu=self.produto)

        self.CupomFiscal.add_command(label="Criar", command=self.controle.insereCuponsFiscais)
        self.CupomFiscal.add_command(label="Consultar", command=self.controle.consultaCuponsFiscais)
        self.menubar.add_cascade(label="Cupom Fiscal", menu=self.CupomFiscal)

        self.salva.add_command(label="Salvar os Dados", command=self.controle.salvaDados)
        self.menubar.add_cascade(label="Salvar", menu=self.salva)

        self.sair.add_command(label="Sair do Programa", command=self.controle.sair)
        self.menubar.add_cascade(label="Sair", menu=self.sair)

        self.root.config(menu=self.menubar)
    
    def mostraMessagebox(self, titulo, mensagem):
        messagebox.showinfo(titulo, mensagem)

class ControlePrincipal:
    def __init__(self):
        self.root = tk.Tk()

        self.ctrlProduto = prod.CtrlProduto()
        self.ctrlCupomFiscal = cp.CtrlCupomFiscal(self)

        self.limite = LimitePrincipal(self.root, self)

        self.root.title('Sistema para loja de conveniencia')
        self.root.mainloop()

    def insereProdutos(self):
        self.ctrlProduto.insereProdutos(self.root)
    
    def consultaProdutos(self):
        self.ctrlProduto.consultaProdutos(self.root)

    def insereCuponsFiscais(self):
        self.ctrlCupomFiscal.insereCuponsFiscais(self.root)
    
    def consultaCuponsFiscais(self):
        self.ctrlCupomFiscal.consultaCuponsFiscais(self.root)
    
    def salvaDados(self):
        self.ctrlProduto.salvaProdutos()
        self.ctrlCupomFiscal.salvaCuponsFiscais()
        self.limite.mostraMessagebox('Backup', 'Dados salvos com sucesso')
        
    def sair(self):
        self.root.destroy()

if __name__ == '__main__':
    c = ControlePrincipal()