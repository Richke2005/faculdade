import os

restaurantes = [
    {'nome': 'Praca', 'categoria': "Japonesa", "is_active": False},
    {'nome': 'pizza suprema', 'categoria': 'italiana', 'is_active': True}
]

def voltar_ao_menu_principal():
    input("Digite uma tecla para voltar ao menu principal\n")
    main()

def exibir_titulo(titulo):
    os.system("clear")
    linha = '*' * len(titulo)
    print(f"{linha}")
    print(f"{titulo}")
    print(f"{linha}")

def cadastrar_novo_restarante():
    '''Essa função é responsavel por cadastrar um novo restaurante
    
    Inputs:
    - Nome do restaurante
    - categoria

    Outputs:
    - Adiciona um novo restaurante a lista de restaurantes
    '''
    exibir_titulo("Cadastrar novo restarante")
    nome = input("Digite o nome do restaurante: ")
    categoria = input("Digite a categoria: ")
    restaurantes.append({"nome": nome, 'categoria': categoria, 'is_active': False})
    print(f"restaurante {nome} cadastrado com sucesso\n")
    voltar_ao_menu_principal()

def listar_restaurantes():
    exibir_titulo("Lista de restaurantes")
    for r in restaurantes:
        ativo = 'ativado' if r["is_active"] else 'desativado'
        print(f"- Nome: {r['nome']}\n- Categoria: {r['categoria']}\n{ativo}\n")


    voltar_ao_menu_principal()

def alternar_estado():
    exibir_titulo("Alternar estado")
    nome = input("Deseja ativar qual restaurante: ")
    is_founded = False
    for restaurante in restaurantes:
        if nome ==  restaurante["nome"]:
            is_founded = True
            restaurante["is_active"] = not restaurante["is_active"]
            # ternario
            menssagem = f"O restaurante {nome} foi ativado com sucesso" if restaurante["is_active"] else f"O restaurante {nome} foi desatvado com sucesso"
            print(menssagem)
    
    if not is_founded:
        print(f"Restaurante {nome} não foi encontrado")
        
    voltar_ao_menu_principal()


def opcao_invalida():
    exibir_titulo("Opção inválida")
    voltar_ao_menu_principal()

def teste_opcao():
    try:
        opcao = int(input("Escolha uma opção: "))
        if opcao == 1:
            cadastrar_novo_restarante()
        elif opcao == 2:
            listar_restaurantes()
        elif opcao == 3:
            alternar_estado()
        elif opcao == 4:
            print("Finalizando App")
    except:
        opcao_invalida()

def exibir_nome_opcao():
    print("""
    ░██████╗░█████╗░██████╗░░█████╗░██████╗░  ███████╗██╗░░██╗██████╗░██████╗░███████╗░██████╗░██████╗
    ██╔════╝██╔══██╗██╔══██╗██╔══██╗██╔══██╗  ██╔════╝╚██╗██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝██╔════╝
    ╚█████╗░███████║██████╦╝██║░░██║██████╔╝  █████╗░░░╚███╔╝░██████╔╝██████╔╝█████╗░░╚█████╗░╚█████╗░
    ░╚═══██╗██╔══██║██╔══██╗██║░░██║██╔══██╗  ██╔══╝░░░██╔██╗░██╔═══╝░██╔══██╗██╔══╝░░░╚═══██╗░╚═══██╗
    ██████╔╝██║░░██║██████╦╝╚█████╔╝██║░░██║  ███████╗██╔╝╚██╗██║░░░░░██║░░██║███████╗██████╔╝██████╔╝
    ╚═════╝░╚═╝░░╚═╝╚═════╝░░╚════╝░╚═╝░░╚═╝  ╚══════╝╚═╝░░╚═╝╚═╝░░░░░╚═╝░░╚═╝╚══════╝╚═════╝░╚═════╝░\n""")

def exibir_opcoes():
    print("1 - Cadastrar restaurante")  
    print("2 - Listar restaurante")
    print("3 - Ativar / Desativar restaurante")
    print("4 - Sair\n")

def main():
    os.system("clear")
    exibir_nome_opcao()
    exibir_opcoes()
    teste_opcao()


if __name__ == "__main__":
    main()