from models.restaurante import Restaurante
from models.cardapio.bebida import Bebida
from models.cardapio.prato import Prato 

def app():
    restaurante1 = Restaurante('Praca', 'Italiana')
    
    bebida = Bebida('Suco de melancia', 5, 'Grande')
    prato_pao = Prato('Pãozinho', 2, 'O melhor pão da cidade')
    bebida.aplicar_desconto()
    restaurante1.adicionar_item_no_cardapio(bebida)
    restaurante1.adicionar_item_no_cardapio(prato_pao)
    restaurante1.exibir_cardapio

if __name__ == "__main__":
    app()