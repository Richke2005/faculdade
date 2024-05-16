CREATE DATABASE banco;

USE banco;

CREATE TABLE depto(
    cod_depto INT PRIMARY KEY,
    nome VARCHAR(50)
);

CREATE TABLE empregado(
    cod_empregado INT PRIMARY KEY,
    cod_depto INT FOREIGN KEY REFERENCES depto(cod_depto),
    nome VARCHAR(50),
    dt_nascimento DATE,
    sexo CHAR(1),
    dt_admissao DATE,
    est_civil CHAR(1),
    salario DECIMAL(10,2)
);

CREATE TABLE dependente(
    cod_dependente INT PRIMARY KEY,
    cod_empregado INT FOREIGN KEY REFERENCES empregado(cod_empregado),
    nome VARCHAR(50),
    dt_nascimento DATE,
    sexo CHAR(1)
);


/*11) Criar uma trigger que assim que um dependente for cadastrado,
o salário do respectivo empregado será atualizado com mais 10%.*/

DELIMITER $$
CREATE TRIGGER atualiza_salario
    AFTER INSERT ON dependente
    FOR EACH ROW
    BEGIN
        DECLARE novo_salario DECIMAL(10, 2);

        SELECT salario * 1.1 INTO novo_salario 
        FROM empregado
        WHERE cod_empregado = NEW.cod_empregado;

        UPDATE empregado
        SET salario = novo_salario
        WHERE cod_empregado = NEW.cod_empregado;
    END$$
DELIMITER ;

/*12)Criar uma trigger que assim que um dependente for excluído, o
salário do respectivo empregado será atualizado com menos 10%.*/

DELIMITER $$
CREATE TRIGGER abaixa_salario
    AFTER DELETE ON dependente
    FOR EACH ROW
    BEGIN 
    DECLARE salario_reduzido DECIMAL(10, 2);

    SELECT salario - (salario * 0.1)
    FROM empregado 
    WHERE cod_empregado = OLD.cod_empregado;

    UPDATE empregado
    SET salario = salario_reduzido
    WHERE cod_empregado = OLD.cod_empregado;
    END$$
DELIMITER ;

/*13)Criar uma trigger que impeça de excluir qualquer departamento
contido na tabela departamento, caso haja funcionário cadastrado
no departamento em questão.*/
DELIMITER $$
    CREATE TRIGGER impede_exclusao_depto
    BEFORE DELETE ON depto
    FOR EACH ROW
    BEGIN
        DECLARE num_empregados INT;
        
        SELECT COUNT(*) INTO num_empregados 
        FROM empregado 
        WHERE cod_depto = OLD.cod_depto;

        IF num_empregados > 0 THEN
            SIGNAL SQLSTATE '45000'
             SET MESSAGE_TEXT = 'Não é possível excluir um departamento que possui funcionários cadastrados!';
        END IF;
    END$$
DELIMITER ;

/*14)Criar uma trigger diferente das criadas, definindo em comentário
no script qual o objetivo dela.*/

DELIMITER $$
-- Esta trigger atualiza automaticamente a data de admissão de um empregado
-- para a data atual quando o sexo do empregado é alterado para feminino.
CREATE TRIGGER atualizar_data_admissao
AFTER UPDATE ON empregado
FOR EACH ROW
BEGIN
    IF NEW.sexo = 'F' THEN
        UPDATE empregado
        SET dt_admissao = CURDATE()
        WHERE cod_empregado = NEW.cod_empregado;
    END IF;
END$$
DELIMITER ;