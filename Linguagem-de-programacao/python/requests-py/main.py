from fastapi import FastAPI, Query
import requests

app = FastAPI()

@app.get("/api")
def read_root():
    '''

    Endpoint que exibe uma menssagem incrível do mundo da programação

    '''
    return {"message": "Hello World"}


@app.get('/api/restaurantes')
def get_restaurantes(restaurante: str = Query(None)):
    '''
    Endpoint para ver o cardapio dos restaurantes

    '''
    url = 'https://guilhermeonrails.github.io/api-restaurantes/restaurantes.json'
    response = requests.get(url)

    if response.status_code == 200:
        dados_json = response.json()
        if restaurante is None:
            return dados_json
        
        dados_restaurante = []
        for item in dados_json:
            if item['Company'] == restaurante:
                dados_restaurante.append({
                    'item': item['Item'],
                    'price': item['price'],
                    'description': item['description'],
                })
        return {'restaurante': restaurante, 'cardapio': dados_restaurante}
    else: 
        return{f'erro': f'{response.status_code} - {response.text}'}