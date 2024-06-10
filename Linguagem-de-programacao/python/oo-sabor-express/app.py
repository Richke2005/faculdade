from models.restaurante import Restaurante

def app():
    restaurante_praca = Restaurante("Praca", "Italiana")
    restaurante_nordestino = Restaurante("Barro verde", "Nordestina")
    restaurante_japones = Restaurante("Japa", "Japonesa")

    restaurante_praca.receber_avaliacao('Richard', 10)
    restaurante_praca.receber_avaliacao('Leo', 8)

    Restaurante.listar_restaurantes()

if __name__ == "__main__":
    app()