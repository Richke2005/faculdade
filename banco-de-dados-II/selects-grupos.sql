/* GRUPO ISABELLI BICA */

-- SELECT que retorna o nome do candidato e o partido politico juntamente com a sigla que ele 
-- o referido faz parte

SELECT candidatos.nome as 'nome candidato', 
partidosPoliticos.nome, 
partidosPoliticos.sigla 
FROM candidatos INNER JOIN partidosPoliticos
ON candidatos.partidoPoliticoID = partidosPoliticos.partidoID;

/* GRUPO LUCAS PIOVEZAN */
SELECT pedido.local_entrega,
cliente.nome_cliente,
cliente.cpf_cliente,
colaborador.nome_colaborador
FROM pedido INNER JOIN cliente
ON pedido.id_cliente = cliente.id_cliente
INNER JOIN colaborador 
ON pedido.id_colaborador = colaborador.id_colaborador;

/* GRUPO FELIPE CHAVES */
SELECT Livro.nome,
Cliente.nome,
Venda.data FROM 
Livro INNER JOIN itemDaVenda ON 
ON itemDaVenda.cod_livro = Livro.cod_livro
INNER JOIN Venda ON Venda.cod_venda = itemDaVenda.cod_venda
INNER JOIN Cliente ON Cliente.cod_cliente = Venda.cod_cliente;
