from models.avaliacao import Avaliacao
from models.cardapio.item_cardapio import ItemCardapio

class Restaurante:

    restaurantes = []
    def __init__(self, nome, categoria):  
        self._nome = nome.title()
        self._categoria = categoria.upper()
        self._ativo = False
        self._avaliacao = []
        self._cardapio = []
        Restaurante.restaurantes.append(self)
        
    def __str__(self):
        return f"Nome: {self._nome} - Categoria: {self._categoria} - Ativo: {self.ativo}"
    
    @classmethod
    def listar_restaurantes(cls):
        print(f'{'NOME DO RESTAURANTE'.ljust(25)} | {'CATEGORIA'.ljust(25)} | {'AVALIAÇÃO'.ljust(25)} | {'ATIVO'.ljust(25)} ')
        for restaurante in cls.restaurantes:
            print(f'{restaurante._nome.ljust(25)} | {restaurante._categoria.ljust(25)} | {str(restaurante.media_avaliacao).ljust(25)} | {restaurante.ativo} ')

    @property
    def ativo(self):
        return 'verdadeiro' if self._ativo else 'falso'
    
    def alternar_estado(self):
        self._ativo = not self._ativo

    def receber_avaliacao(self, cliente, nota):
        self._avaliacao.append(Avaliacao(cliente, nota))

    @property
    def media_avaliacao(self):
        if not self._avaliacao:
            return '-'
    
        soma = sum(avaliacao._nota for avaliacao in self._avaliacao)
        quantidade_de_notas = len(self._avaliacao)
        return round(soma / quantidade_de_notas, 1)
    
    def adicionar_item_no_cardapio(self, item):
        if isinstance(item, ItemCardapio):
            self._cardapio.append(item)
        else:
            raise TypeError('O item deve ser do tipo ItemCardapio')
        
    @property
    def exibir_cardapio(self):
        print(f'Cardapio do restaurante {self._nome}\n')
        for i, item in enumerate(self._cardapio, start = 1):
            if hasattr(item, '_descricao'):
                print(f'{i}.Nome - {item._nome} | Preço R$ {item._preco} | Descrição: {item._descricao}')
            else: 
                 print(f'{i}.Nome - {item._nome} | Preço R$ {item._preco} | Tamanho: {item._tamanho}')
            
