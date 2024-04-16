CREATE DATABASE escola; 

USE escola;

CREATE TABLE disciplina(
id_disciplina INT AUTO_INCREMENT,
nome VARCHAR(40),
ementa TEXT,
cargaH INT,
PRIMARY KEY(id_disciplina)
);

CREATE TABLE professor(
id_professor INT AUTO_INCREMENT,
nome VARCHAR(40),
cpf CHAR(11),
email VARCHAR(50),
PRIMARY KEY(id_professor)
);

CREATE TABLE disciplina_professor(
disciplina_key INT NOT NULL,
professor_key INT NOT NULL,
FOREIGN KEY(disciplina_key) REFERENCES disciplina(id_disciplina),
FOREIGN KEY(professor_key) REFERENCES professor(id_professor),
PRIMARY KEY(disciplina_key, professor_key)
);

CREATE TABLE turma(
id_turma INT AUTO_INCREMENT,
disciplina_key INT NOT NULL,
professor_key INT NOT NULL,
FOREIGN KEY (disciplina_key) REFERENCES disciplina(id_disciplina),
FOREIGN KEY (professor_key) REFERENCES professor(id_professor),
PRIMARY KEY(id_turma)
);

CREATE TABLE atividade(
id_atividade INT AUTO_INCREMENT,
titulo VARCHAR(30),
descricao TEXT,
turma_key INT NOT NULL,
FOREIGN KEY(turma_key) REFERENCES turma(id_turma),
PRIMARY KEY(id_atividade)
);

CREATE TABLE sexo(
id_sexo INT AUTO_INCREMENT,
sexo VARCHAR(10),
PRIMARY KEY(id_sexo)
);

CREATE TABLE aluno(
id_aluno INT AUTO_INCREMENT,
nome VARCHAR(40),
email VARCHAR(40),
idade DATE,
sexo INT NOT NULL,
primeira_graduacao CHAR(1),
est_civil CHAR(1),
FOREIGN KEY (sexo) REFERENCES sexo(id_sexo),
PRIMARY KEY(id_aluno)
);

CREATE TABLE log_alunos (
id_log INT AUTO_INCREMENT,
acao VARCHAR(20),
descricao TEXT,
data TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
PRIMARY KEY (id_log)
);

CREATE TABLE aluno_turma(
aluno_key INT NOT NULL,
turma_key INT NOT NULL,
FOREIGN KEY (aluno_key) REFERENCES aluno(id_aluno),
FOREIGN KEY (turma_key) REFERENCES turma(id_turma),
PRIMARY KEY(aluno_key, turma_key)
);

-- CREATE TABLE administracao(
-- id_adm INT AUTO_INCREMENT,
-- nome VARCHAR(40),
-- email VARCHAR(50),
-- PRIMARY KEY(id_adm)
-- );

-- CREATE TABLE cargo(
-- id_cargo INT AUTO_INCREMENT,
-- nome_cargo VARCHAR(30),
-- adm_key INT NOT NULL,
-- FOREIGN KEY (adm_key) REFERENCES administracao(id_adm),
-- PRIMARY KEY(id_cargo)
-- );


/* insert disciplinas*/
INSERT INTO `escola`.`disciplina` (`nome`, `ementa`, `cargaH`) VALUES ('Banco de dados II', 'Consultas avançadas em linguagem de consulta estruturada (SQL). Conceitos de banco de dados que proporcionam mais performance no trabalho com o banco: visões, gatilhos e procedimentos armazenados. Processamento de transações. Cursores. Funções. Análise e representação de dados.', '80');
INSERT INTO `escola`.`disciplina` (`nome`, `ementa`, `cargaH`) VALUES ('Algoritmos e est. de dados', 'Introdução ao conceito de algoritmo. Tipos de dados e operações primitivas. Elementos ', '65');

/* insert professores*/
INSERT INTO `escola`.`professor` (`nome`, `cpf`, `email`) VALUES ('Carlinho', '3647756388', 'carlaoProfão@gmail.com');
INSERT INTO `escola`.`professor` (`nome`, `cpf`, `email`) VALUES ('José', '84475563746', 'Josézinho@gmail.com');

/* insert associativa dis_professores */
INSERT INTO `escola`.`disciplina_professor` (`disciplina_key`, `professor_key`) VALUES ('1', '1');
INSERT INTO `escola`.`disciplina_professor` (`disciplina_key`, `professor_key`) VALUES ('2', '2');

/* insert turma*/
INSERT INTO `escola`.`turma` (`disciplina_key`, `professor_key`) VALUES ('1', '1');
INSERT INTO `escola`.`turma` (`disciplina_key`, `professor_key`) VALUES ('1', '2');
INSERT INTO `escola`.`turma` (`disciplina_key`, `professor_key`) VALUES ('2', '2');

/* insert atividade*/
INSERT INTO `escola`.`atividade` (`titulo`, `descricao`, `turma_key`) VALUES ('Análise de Vendas com SQL', 'Descrição:\nNesta atividade, os alunos serão desafiados a utilizar a linguagem SQL para realizar uma análise de vendas de uma empresa fictícia. Eles serão fornecidos com um conjunto de dados contendo informações sobre vendas, clientes, produtos e regiões. A tarefa consistirá em escrever consultas SQL para responder a uma série de perguntas específicas relacionadas às vendas, como o total de vendas por região, o produto mais vendido, o cliente com o maior número de compras, entre outros. Além disso, os alunos serão incentivados a elaborar consultas mais complexas, utilizando funções agregadas, junções, subconsultas e outras técnicas avançadas de SQL para obter insights mais detalhados sobre os dados de vendas. Ao final da atividade, os alunos serão solicitados a apresentar seus resultados e análises, demonstrando sua compreensão e habilidades em SQL para análise de dados.', '1');

/* insert sexo*/
INSERT INTO `escola`.`sexo` (`sexo`) VALUES ('M');
INSERT INTO `escola`.`sexo` (`sexo`) VALUES ('Masculino');

/* insert aluno*/
INSERT INTO `escola`.`aluno` (`nome`, `email`, `idade`, `sexo`, `primeira_graduacao`, `est_civil`) VALUES ('richard', 'richardke18@gmail.com', '2005-06-22', 1, "S","S" );
INSERT INTO `escola`.`aluno` (`nome`, `email`, `idade`, `sexo`, `primeira_graduacao`, `est_civil`) VALUES ('marcelinho', 'marcelo@hotmail.com', '2004-07-18', 2, "N","C");

/* insert aluno_turma*/
INSERT INTO `escola`.`aluno_turma` (`aluno_key`, `turma_key`) VALUES ('1', '1');
INSERT INTO `escola`.`aluno_turma` (`aluno_key`, `turma_key`) VALUES ('2', '1');

/* insert administracao*/
-- INSERT INTO `escola`.`administracao` (`nome`, `email`) VALUES ('Raquel', 'raquel@hotmail.com');
-- INSERT INTO `escola`.`administracao` (`nome`, `email`) VALUES ('Hebert', 'Hebert@hotamail.com');

/* insert cargo*/
-- INSERT INTO `escola`.`cargo` (`nome_cargo`, `adm_key`) VALUES ('Diretor', '2');
-- INSERT INTO `escola`.`cargo` (`nome_cargo`, `adm_key`) VALUES ('Secretaria', '1');


-- Procedure:

-- procedure que retorna todos os alunos matriculados em uma determinada turma:

DELIMITER $$
CREATE PROCEDURE listar_alunos_por_turma(IN turma_id INT)
	BEGIN
		SELECT aluno.nome
		FROM aluno
		INNER JOIN aluno_turma ON aluno.id_aluno = aluno_turma.aluno_key
		WHERE aluno_turma.turma_key = turma_id;
	END $$
DELIMITER ;

CALL listar_alunos_por_turma(1);

-- Procedure:

-- procedure que retorna todos os professores que lecionam determinada disciplina:

DELIMITER $$
	CREATE PROCEDURE listar_professores_por_disciplina(IN disciplina_id INT)
    BEGIN 
		SELECT professor.nome 
        FROM professor 
        INNER JOIN disciplina_professor ON professor.id_professor = disciplina_professor.professor_key
        WHERE disciplina_professor.disciplina_key = disciplina_id;
	END $$
DELIMITER ;

CALL  listar_professores_por_disciplina(2);

-- Função:

-- Função que retorna a media das idades dos alunos

DELIMITER $$

CREATE FUNCTION calcular_idade_media() RETURNS FLOAT
BEGIN
    DECLARE idade_total FLOAT;
    DECLARE total_alunos INT;
    SELECT SUM(YEAR(CURRENT_DATE) - YEAR(idade)) INTO idade_total FROM aluno;
    SELECT COUNT(*) INTO total_alunos FROM aluno;
    RETURN idade_total / total_alunos;
END $$

DELIMITER ;

SELECT calcular_idade_media();



-- Inner Join

-- Consulta que faz uso de uma união de tabelas para recuperar informações de aluno_turma, turma e disciplina.


SELECT aluno.nome AS nome_aluno, turma.id_turma, disciplina.nome AS nome_disciplina
FROM aluno
INNER JOIN aluno_turma ON aluno.id_aluno = aluno_turma.aluno_key
INNER JOIN turma ON aluno_turma.turma_key = turma.id_turma
INNER JOIN disciplina ON turma.disciplina_key = disciplina.id_disciplina;

-- Gatilho:

-- Trigger que registra quando um novo aluno é 
-- inserido na tabela de alunos:


DELIMITER $$

CREATE TRIGGER log_insert_aluno
AFTER INSERT ON aluno
FOR EACH ROW
BEGIN
    INSERT INTO log_alunos (acao, descricao, data) VALUES ('Inserção', CONCAT('Novo aluno inserido: ', NEW.nome), NOW());
END $$

DELIMITER ;