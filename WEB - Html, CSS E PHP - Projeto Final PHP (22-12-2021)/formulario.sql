-- phpMyAdmin SQL Dump
-- version 4.9.0.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Tempo de geração: 01-Set-2019 às 17:53
-- Versão do servidor: 10.3.16-MariaDB
-- versão do PHP: 7.1.30

--
-- Banco de dados: `funcionario`
--

-- --------------------------------------------------------|

/*Tabelas*/

CREATE TABLE `gestor` (
  `id_gestor` int PRIMARY KEY,
  
  `nome_gestor` varchar(100) NOT NULL

) ENGINE=InnoDB DEFAULT CHARSET=latin1;

CREATE TABLE `funcionario` (
  `idFuncionario` INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
  `nome` varchar(255) NOT NULL,
  `email` varchar(150) NOT NULL,
  `senha` varchar(45) NOT NULL,
  `data_cadastro` datetime NOT NULL,
  `imagem` varchar(100) NOT NULL, 
  `descricao` varchar(255) NOT NULL,
  `id_gestor` int NOT NULL,  
  
   constraint fk_codigo_estoque_control
   
  FOREIGN KEY (id_gestor) REFERENCES gestor (id_gestor)
) ENGINE=InnoDB;

/*Inserção de Testes [Gestores]*/

insert into gestor (id_gestor, nome_gestor)
values('1','Roger Gamer da Silva');

insert into gestor (id_gestor, nome_gestor)
values('2','Felipe Neto da Silva');

insert into gestor (id_gestor, nome_gestor)
values('3','Irineu Mario da Silva');


/*Inserção de Testes [Funcionarios]*/

insert into funcionario (idFuncionario, nome, email, senha, data_cadastro, imagem, descricao, id_gestor)
values ('1','Michael Vidi', 'michaelgamer@msn.br', '40028922', '2021/07/19 01:19:16', 'roger.png', 'Ex usuario de drogas, Jogador de Fifa', '1');

insert into funcionario (idFuncionario, nome, email, senha, data_cadastro, imagem, descricao, id_gestor)
values ('2','Raimundo Guzangui', 'guzanguiplays@gmail.com', '623423423', '2021/08/12 11:13:00', 'raimundo.png', 'Jovem Gamer, fica 24 horas por dia jogando Lol', '2');

insert into funcionario (idFuncionario, nome, email, senha, data_cadastro, imagem, descricao, id_gestor)
values ('3','Olavo Giaretta', 'giaretoboy@hotmail.com.br', '15325115', '2022/06/09 03:19:05', 'olavo.png', 'Trabalha no restaurante de dia e na esquina a noite', '3');

insert into funcionario (idFuncionario, nome, email, senha, data_cadastro, imagem, descricao, id_gestor)
values ('4','Pitter Parker', 'miranha@hotmail.com', '412432314', '2020/07/08 01:21:35', 'pitter.png', 'Gosta de Fotografar a Mary Jane no banho', '1');

insert into funcionario (idFuncionario, nome, email, senha, data_cadastro, imagem, descricao, id_gestor)
values ('5','Jiuberto Guima Ram', 'jijiuguigui@outloock.com.br', '126561', '2019/12/11 04:14:16', 'jiuberto.png', 'Fazendeiro criador de gado', '2');

insert into funcionario (idFuncionario, nome, email, senha, data_cadastro, imagem, descricao, id_gestor)
values ('6','Maira Santos', 'mariagamer@msn.br', '1346263', '2021/10/14 10:29:01', 'maira.png','Gosta de jogar Roblox nas horas vagas', '3');

insert into funcionario (idFuncionario, nome, email, senha, data_cadastro, imagem, descricao, id_gestor)
values ('7','Mirabel Oliveira', 'mirabellanche@gmail.com', '745435', '2020/01/15 07:14:45', 'mirabel.png', 'Menino bom de Bola', '1');

insert into funcionario (idFuncionario, nome, email, senha, data_cadastro, imagem, descricao, id_gestor)
values ('8','Alberto Janiquim', 'albertin@hotmail.com.br', '86585365', '2019/03/07 16:11:00', 'alberto.png', 'Gosta de Assistir BBB nas horas vagas', '2');

insert into funcionario (idFuncionario, nome, email, senha, data_cadastro, imagem, descricao, id_gestor)
values ('9','Stifler Miranda', 'stiflerboy@hotmail.com', '9567542', '2019/02/03 17:02:02', 'stifler.png', 'Esse cara provavelmente conhece sua mae', '3');

insert into funcionario (idFuncionario, nome, email, senha, data_cadastro, imagem, descricao, id_gestor)
values ('10','Pitter Pam', 'pampitter@outloock.com.br', '3215416', '2021/06/11 11:10:31', 'pitpam.png', 'Ele nao a fa de Piratas do Caribe', '1');

insert into funcionario (idFuncionario, nome, email, senha, data_cadastro, imagem, descricao, id_gestor)
values ('11','Kratos Almeida', 'Kratosspartan@msn.com.br', '3213132', '2022/02/11 18:19:07', 'kratos.png', 'Ele parece um pouco nervoso', '1');

insert into funcionario (idFuncionario, nome, email, senha, data_cadastro, imagem, descricao, id_gestor)
values ('12','Steve Quadra Domin', 'steve@hotmail.com.br', '1525134', '2022/01/11 20:20:20', 'steve.png', 'Definitivamente um sobrevivente', '2');

insert into funcionario (idFuncionario, nome, email, senha, data_cadastro, imagem, descricao, id_gestor)
values ('13','Cijinei Jhonson', 'Cjbitch@outloock.com', '264364', '2021/07/17 02:01:21', 'cj.png', 'Agaragã Bitch, fuck you man', '3');

insert into funcionario (idFuncionario, nome, email, senha, data_cadastro, imagem, descricao, id_gestor)
values ('14','Kianu Rivens', 'Kiianuu@gmail.com', '3463246', '2020/08/19 19:01:09', 'kianu.png', 'Não parece, mas é o bicho papao', '1');

insert into funcionario (idFuncionario, nome, email, senha, data_cadastro, imagem, descricao, id_gestor)
values ('15','Dava Jonas', 'davajonas@yahoo.com.br', '098123813', '2019/01/03 05:19:15', 'dava.png', 'Sete Videos ou mais todos os dias', '2');

insert into funcionario (idFuncionario, nome, email, senha, data_cadastro, imagem, descricao, id_gestor)
values ('16','Jaque Cham', 'chamjaque@yahoo.com.br', '1231213', '2020/09/09 19:01:54', 'jaquecham.png', 'O grande magico do youtube', '3');