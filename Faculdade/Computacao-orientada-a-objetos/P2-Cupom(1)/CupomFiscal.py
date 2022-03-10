import tkinter as tk
from tkinter import messagebox
import os.path
import pickle
import Produto as prod

class CupomFiscalDuplicado(Exception):
    pass

class CampoPreenchimentoVazio(Exception):
    pass

class CupomFiscalInexistente(Exception):
    pass

class CupomFiscal:
    def __init__(self, numerocp, itensCupom):
        self.__numerocp = numerocp
        self.__itensCupom = itensCupom
    
    def getNumerocp(self):
        return self.__numerocp
    
    def getitensCupom(self):
        return self.__itensCupom

class LimiteInserecp:
    def __init__(self, controle, root, listaCodProdutos):
        self.janela = tk.Toplevel()
        self.janela.geometry('400x300')
        self.janela.title('Cadastramento de Cupom Fiscal')
        self.janela.transient(root)


        self.frameNumerocp = tk.Frame(self.janela)
        self.frameitensCupom = tk.Frame(self.janela)    
        self.frameNumerocp.pack()
        self.frameitensCupom.pack()

        self.labelNumerocp = tk.Label(self.frameNumerocp, text='Numero do cupom: ')
        self.labelitensCupom = tk.Label(self.frameitensCupom, text='Itens do Cupom: ')
        self.labelNumerocp.pack(side='left')
        self.labelitensCupom.pack(side='left')

        self.inputNumerocp = tk.Entry(self.frameNumerocp, width=20)
        self.inputNumerocp.pack(side='left')

        self.listboxItem = tk.Listbox(self.frameitensCupom)
        self.listboxItem.pack(side='left')
        for produto in listaCodProdutos:
            self.listboxItem.insert(tk.END, produto.getCodigo())

        self.buttonConcluir = tk.Button(self.janela, text='Fechar cupom')
        self.buttonConcluir.pack(side='right')
        self.buttonConcluir.bind('<Button>', controle.concluirCompra)

        self.buttonCadastro = tk.Button(self.janela, text='Cadastrar')
        self.buttonCadastro.pack(side='right')
        self.buttonCadastro.bind('<Button>', controle.inserirProduto)

    def mostraMessagebox(self, titulo, mensagem, identificador):
        if identificador == True:
            messagebox.showinfo(titulo, mensagem)
        else:
            messagebox.showerror(titulo, mensagem)

class LimiteConsultacp:
    def __init__(self, controle, root):
        self.janela = tk.Toplevel()
        self.janela.geometry('300x100')
        self.janela.title('Consulta de Cupom')
        self.janela.transient(root)

        self.frameNumerocp = tk.Frame(self.janela)
        self.frameNumerocp.pack()

        self.labelNumerocp = tk.Label(self.frameNumerocp, text='Codigo')
        self.labelNumerocp.pack(side='left')

        self.inputNumerocp = tk.Entry(self.frameNumerocp, width=20)
        self.inputNumerocp.pack(side='left')

        self.buttonConsulta = tk.Button(self.janela, text='Consultar')
        self.buttonConsulta.pack(side='left')
        self.buttonConsulta.bind('<Button>', controle.consultar)

        self.buttonClear = tk.Button(self.janela, text='Clear')
        self.buttonClear.pack(side='left')
        self.buttonClear.bind('<Button>', controle.clearConsulta)

        self.buttocpinaliza = tk.Button(self.janela, text='Finalizar')
        self.buttocpinaliza.pack(side='left')
        self.buttocpinaliza.bind('<Button>', controle.finalizarConsulta)

    def mostraMessagebox(self, titulo, mensagem, identificador):
        if identificador == True:
            messagebox.showinfo(titulo, mensagem)
        else:
            messagebox.showerror(titulo, mensagem)

#acresecntar agrupamento

class CtrlCupomFiscal:
    def __init__(self, controlePrincipal):
        self.ctrlPrincipal = controlePrincipal
        self.listaProdutoscp = []

        if not os.path.isfile("CupomFiscal.pickle"):
            self.listaCuponsFiscais =  []
        else:
            with open("CupomFiscal.pickle", "rb") as f:
                self.listaCuponsFiscais = pickle.load(f)
    
    def salvaCuponsFiscais(self):
        if len(self.listaCuponsFiscais) != 0:
            with open("CupomFiscal.pickle","wb") as f:
                pickle.dump(self.listaCuponsFiscais, f)

    def getCupomFiscal(self, numerocp):
        for cp in self.listaCuponsFiscais:
            if cp.getNumerocp() == numerocp:
                return cp
        return None

    def insereCuponsFiscais(self, root):
        listaProdutos = self.ctrlPrincipal.ctrlProduto.listaProdutos
        self.limiteInsere = LimiteInserecp(self, root, listaProdutos)

    def consultaCuponsFiscais(self, root):
        self.limiteConsulta = LimiteConsultacp(self, root)
    
    def inserirProduto(self, event):
        produtoSelecionado = self.limiteInsere.listboxItem.get(tk.ACTIVE)
        produto = self.ctrlPrincipal.ctrlProduto.getProduto(produtoSelecionado)
        self.listaProdutoscp.append(produto)
        self.limiteInsere.mostraMessagebox('Sucesso', 'Compra realizada com sucesso', True)
    
    def concluirCompra(self, event):
        numerocp = self.limiteInsere.inputNumerocp.get()
        try:
            if len(numerocp)==0:
                raise CampoPreenchimentoVazio()
            if self.getCupomFiscal(numerocp) != None:
                raise CupomFiscalDuplicado()
        except CampoPreenchimentoVazio:
            self.limiteInsere.mostraMessagebox('Error', 'Todos os campos devem ser preenchidos', False)
        except CupomFiscalDuplicado:
            self.limiteInsere.mostraMessagebox('Error', 'Numero {} de Cupom já existe!'.format(numerocp), False)
        else:
            cp = CupomFiscal(numerocp, self.listaProdutoscp)
            self.listaCuponsFiscais.append(cp)
            self.limiteInsere.mostraMessagebox('Sucesso', 'Cupom fiscal gerado com sucesso', True)
            self.limiteInsere.janela.destroy()

    def consultar(self, event):
        numerocp = self.limiteConsulta.inputNumerocp.get()
        cp = self.getCupomFiscal(numerocp)
        try:
            if len(numerocp)==0:
                raise CampoPreenchimentoVazio()
            if cp == None:
                raise CupomFiscalInexistente()
        except CampoPreenchimentoVazio:
            self.limiteConsulta.mostraMessagebox('Atenção', 'Todos os campos devem ser preenchidos', False)
        except CupomFiscalInexistente:
            self.limiteConsulta.mostraMessagebox('Atenção', 'Cupom {} não existe!'.format(numerocp), False)
        else:
            soma=0
            string = 'Cupom encontrado \n\nNumero do cupom: {} \n'.format(cp.getNumerocp())
            string += '\n\nLista de Produtos: \n'
            for produto in self.listaProdutoscp:
                string += produto.getCodigo()+' -- '+produto.getDescricao()+' -- R$ '+produto.getValorUnitario()+'\n'
                soma += float(produto.getValorUnitario())
            string += '\n\nTotal de compra: R$ {}'.format(soma)
            self.limiteConsulta.mostraMessagebox('Consulta', string, True)
            self.clearConsulta(event)

    def clearConsulta(self, event):
        self.limiteConsulta.inputNumerocp.delete(0, len(self.limiteConsulta.inputNumerocp.get()))

    def finalizarConsulta(self, event):
        self.limiteConsulta.janela.destroy()