/* GRUPO ISABELLI BICA */

-- SELECT que retorna o nome do candidato e o partido politico juntamente com a sigla que ele 
-- o referido faz parte
-- TESTED
SELECT candidatos.nome as 'nome candidato', 
partidosPoliticos.nome, 
partidosPoliticos.sigla 
FROM candidatos INNER JOIN partidosPoliticos
ON candidatos.partidoPoliticoID = partidosPoliticos.partidoID;

/* GRUPO LUCAS PIOVEZAN */

-- SELECT que retorna o local da entrega juntamente com nome do colaborador e cliente associado
SELECT pedido.local_entrega,
colaborador.nome_colaborador,
cliente.nome_cliente,
cliente.cpf_cliente
FROM pedido INNER JOIN cliente
ON pedido.id_cliente = cliente.id_cliente
INNER JOIN colaborador 
ON pedido.id_colaborador = colaborador.id_colaborador;

-- SELECT para visao geral da entrega do produto solicitado
-- juntamente com cliente associado
SELECT 
    c.nome_cliente, 
    c.telefone_cliente, 
    col.nome_colaborador, 
    p.id_pedido, 
    p.local_partida, 
    p.local_entrega, 
    v.tipo_veiculo, 
    tv.carga_altura, 
    tv.carga_largura, 
    tv.carga_profundidade
FROM 
    pedido p
JOIN 
    cliente c ON p.id_cliente = c.id_cliente
JOIN 
    colaborador col ON p.id_colaborador = col.id_colaborador
JOIN 
    veiculo v ON p.id_veiculo = v.id_veiculo
JOIN 
    tipo_veiculo tv ON v.tipo_veiculo = tv.tipo_veiculo;


/* GRUPO FELIPE CHAVES */
-- SELECT que retorna o nome do livro e nome do cliente associado ao livro vendido
-- retorna a data da venda
SELECT Livro.nome as 'nomde do livro' ,
Cliente.nome as 'nome do cliente' ,
Venda.data FROM 
Livro INNER JOIN itemDaVenda  
ON itemDaVenda.cod_livro = Livro.cod_livro
INNER JOIN Venda ON Venda.cod_venda = itemDaVenda.cod_venda
INNER JOIN Cliente ON Cliente.cod_cliente = Venda.cod_cliente;

