import requests
import json



def app():
    url = 'https://guilhermeonrails.github.io/api-restaurantes/restaurantes.json'
    response = requests.get(url)

    if response.status_code == 200:
        dados_json = response.json()
        
        dados_restaurante = {}
        for item in dados_json:
            nome_do_restaurante = item['Company']
            if nome_do_restaurante not in dados_restaurante:
                dados_restaurante[nome_do_restaurante] = []

            dados_restaurante[nome_do_restaurante].append({
                'item': item['Item'],
                'price': item['price'],
                'description': item['description'],
            })

        for nome_do_restaurante, dados in dados_restaurante.items():
            nome_do_arquivo = f'{nome_do_restaurante}.json'
            with open(nome_do_arquivo, 'w') as file:
                json.dump(dados, file, indent = 4)
    else: 
        print(f'Ocorreu um erro ao acessar a url {url}')



if __name__ == "__main__":
    app()
