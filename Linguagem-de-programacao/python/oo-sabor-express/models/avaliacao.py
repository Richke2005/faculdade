class Avaliacao:
    def __init__(self, cliente, nota):
        self._cliente = cliente.title()
        self._nota = nota
    
    def __str__(self):
        return f"Cliente: {self._cliente} - Nota: {self._nota}"
    
    