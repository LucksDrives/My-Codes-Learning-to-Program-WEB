-- phpMyAdmin SQL Dump
-- version 4.9.0.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Tempo de geração: 01-Set-2019 às 17:53
-- Versão do servidor: 10.3.16-MariaDB
-- versão do PHP: 7.1.30

--
-- Banco de dados: `Produto`
--

-- --------------------------------------------------------|

/*Tabela de Criação da Tabela dos Produtos*/

CREATE TABLE `estoque_control` (

  `numero_galpao` int PRIMARY KEY AUTO_INCREMENT,
  
  `nome_galpao` varchar(100) NOT NULL

) ENGINE=InnoDB DEFAULT CHARSET=latin1;

CREATE TABLE `produto` (

  `idproduto` int(11) PRIMARY KEY AUTO_INCREMENT,

  `nome` varchar(100) NOT NULL,
  
  `quantidade` int NOT NULL,
  
  `imagem` varchar(100) NOT NULL,
  
  `descricao` varchar(2000) NOT NULL,
  
  `data_lancamento` date NOT NULL,
  
  `numero_galpao` int NOT NULL,
  
  constraint fk_codigo_estoque_control
   
  FOREIGN KEY (numero_galpao) REFERENCES estoque_control (numero_galpao) 

) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------|

/*Inserção de Testes [Estoques]*/

insert into estoque_control (numero_galpao, nome_galpao)
values('1','Nova Prata');

insert into estoque_control (numero_galpao, nome_galpao)
values('2','Caxias');

insert into estoque_control (numero_galpao, nome_galpao)
values('3','Veranópolis');

-- --------------------------------------------------------|

/*Inserção de Testes [Produtos]*/

insert into produto (idproduto, nome, imagem, quantidade, descricao, data_lancamento, numero_galpao)
values('1','Far Cry 6 PS5', '1.png', '15', 'Far Cry 6 é um jogo eletrônico de tiro em primeira pessoa desenvolvido pela Ubisoft Toronto e publicado pela Ubisoft. É o sexto título principal da série Far Cry e foi lançado em 7 de outubro de 2021 para Amazon Luna, Google Stadia, Microsoft Windows, PlayStation 4, PlayStation 5, Xbox One e Xbox Series X/S. O jogo se passa em uma ilha fictícia do Caribe chamada "Yara", inspirada em Cuba, governada por uma ditadura do "El Presidente" Anton Castillo (dublado e modelado por Giancarlo Esposito), que está criando seu filho Diego (dublado por Anthony Gonzalez), para seguir seu governo. O jogador assume o papel de um guerrilheiro tentando recuperar a ilha para seu povo. Far Cry 6 foi bem recebido pela crítica, com muitos elogiando a jogabilidade, os visuais, o design do mundo e as performances, mas com algumas críticas em relação à falta de inovação, questões técnicas e a fórmula de jogo envelhecida.,', '2021/07/19', '1');

insert into produto (idproduto, nome, imagem, quantidade, descricao, data_lancamento, numero_galpao)
values('2','Spider Man Miles Morales PS5', '2.png', '25', 'Spider-Man: Miles Morales é um jogo eletrônico de ação-aventura desenvolvido pela Insomniac Games e publicado pela Sony Interactive Entertainment para o PlayStation 4 e PlayStation 5. É baseado nos personagens, mitologia e adaptações em outras mídias dos personagens de histórias em quadrinhos Miles Morales e Homem-Aranha da Marvel Comics, tendo sido lançado para PlayStation 4 e como um título de lançamento do PlayStation 5 em novembro de 2020. O jogo é a uma expansão autônoma de Spider-Man, de 2018. E retrata a luta de Miles para equilibrar os deveres de sua personalidade civil e do Homem-Aranha quando sua nova casa, Harlem, está ameaçada por uma guerra entre a Roxxon Energy Corporation e o exército criminoso de alta tecnologia do Tinkerer, o Underground. A jogabilidade é apresentada a partir da perspectiva em terceira pessoa com um foco principal nas habilidades de travessia e combate de Miles.', '2020/10/03', '2');

insert into produto (idproduto, nome, imagem, quantidade, descricao, data_lancamento, numero_galpao)
values('3','Mortal Kombat 11 PS5', '3.png', '18', 'Mortal Kombat 11 é um jogo eletrônico de luta desenvolvido pela NetherRealm Studios e publicado pela Warner Bros. Interactive Entertainment. É a décima primeira edição principal da série de jogos eletrônicos de luta, Mortal Kombat, e uma continuação direta de Mortal Kombat X (2015). Um trailer de anúncio do jogo foi lançado durante o The Game Awards 2018. O jogo foi lançado em 23 de abril de 2019, para Microsoft Windows, Nintendo Switch, PlayStation 4 e Xbox One. Mortal Kombat 11 é um jogo de luta em que dois jogadores lutam um contra o outro, usando uma enorme variedade de ataques. Além de incluir várias mecânicas usadas em capítulos anteriores, em Mortal Kombat 11 cada lutador tem três ‘variações’ predefinidas pelos desenvolvedores, cada uma com o seu próprio estilo e lista de movimentos e com possibilidade de modificá-las e adicionar mais estilos definidos pelo próprio jogador.', '2021/01/01', '3');

insert into produto (idproduto, nome, imagem, quantidade, descricao, data_lancamento, numero_galpao)
values('4','Battlefield 2042', '4.png', '31', 'Battlefield 2042 é um jogo eletrônico de tiro em primeira pessoa desenvolvido pela DICE e publicado pela Electronic Arts. É a décima sétima edição da série Battlefield e sequência de Battlefield V de 2018. O jogo está programado para ser lançado em 19 de novembro de 2021, para Microsoft Windows, PlayStation 4, PlayStation 5, Xbox One e Xbox Series X/S Ao contrário dos jogos Battlefield recentes, Battlefield 2042 será exclusivamente multijogador e não terá uma campanha para um jogador e contará com o multiplataforma, o primeiro da série. Semelhante aos seus predecessores, Battlefield 2042 é um jogo de tiro em primeira pessoa com foco em multijogador. Como o jogo se passa em um futuro próximo, ele apresenta armas modernas e dispositivos como torres e drones implantáveis, bem como veículos que os jogadores podem comandar. Os jogadores agora podem solicitar um lançamento aéreo do veículo para qualquer local.', '2013/06/03', '1');

insert into produto (idproduto, nome, imagem, quantidade, descricao, data_lancamento, numero_galpao)
values('5','Demons Souls PS5', '5.png', '10', 'Demons Souls é um RPG de ação desenvolvido pela Bluepoint Games, com assistência do Japan Studio, e publicado pela Sony Interactive Entertainment. O jogo apresenta novas armas, armaduras, anéis e itens chamados "Grãos", que oferecem aos jogadores uma resistência temporária a efeitos como veneno, fogo e sangramento. Assim como no original, os jogadores são limitados em quanto podem carregar antes que seu personagem fique sobrecarregado, embora alguns aspectos desse sistema de sobrecarga tenham sido ajustados. Por exemplo, no jogo original, as gramas de cura não têm peso, então os jogadores podem carregar centenas delas; no remake, esses itens de cura agora têm um peso associado a eles, de forma que a quantidade que os jogadores podem carregar é significativamente reduzida e as gramas mais potentes pesam mais do que as menos eficazes.  Um novo recurso, chamado "Fractured World".', '2018/09/21', '2');

insert into produto (idproduto, nome, imagem, quantidade, descricao, data_lancamento, numero_galpao)
values('6','Fifa 2022 PS5', '6.png', '24', 'FIFA 22 é um jogo eletrônico de simulação de futebol desenvolvido e publicado pela Electronic Arts. O jogo foi anunciado no dia 11 de julho de 2021 e lançado no dia 1 de outubro de 2021 para PlayStation 5, Xbox Series X/S, Google Stadia, Microsoft Windows, PlayStation 4, Xbox One e PC. Quatro times novos foram adicionados nas equipes do resto do mundo: APOEL, Hajduk Split, Ferencváros e Wrexham. As equipes italianas também foram alteradas, em relação ao jogo anterior. Brescia, Chievo e SPAL não tiveram suas licenças renovadas. Nas seleções, a Seleção Ucraniana de Futebol foi adicionada, mas foram retiradas dezessete seleções do jogo: África do Sul, Bolívia, Bulgária, Camarões, Chile, Colômbia, Costa do Marfim, Egito, Equador, Eslovênia, Índia, Paraguai, Peru, Suíça, Turquia, Uruguai e Venezuela. Também foi retirado dessa edição, a Seleção Japonesa de Futebol Feminino.', '2015/03/25', '3');

insert into produto (idproduto, nome, imagem, quantidade, descricao, data_lancamento, numero_galpao)
values('7','Ghost of Tsushima PS5', '7.png', '5', 'Ghost of Tsushima é um jogo eletrônico de ação-aventura desenvolvido pela Sucker Punch Productions e publicado pela Sony Interactive Entertainment. Foi lançado em 17 de julho de 2020 exclusivamente para PlayStation 4. A história gira em torno de Jin Sakai, o último samurai na Ilha de Tsushima durante a primeira invasão Mongol no Japão no século XIII. Ghost of Tsushima recebeu análises geralmente favoráveis da crítica após o seu lançamento, com elogios direcionados para seus visuais e combate, e críticas por suas atividades do mundo aberto. O jogo vendeu mais de 2,4 milhões de unidades em seus primeiros três dias de lançamento.', '2017/12/03', '1');

insert into produto (idproduto, nome, imagem, quantidade, descricao, data_lancamento, numero_galpao)
values('8','Davil May Cry V PS5', '8.png', '17', 'Devil May Cry 5 é um jogo eletrônico de ação-aventura hack and slash desenvolvido e publicado pela Capcom. É o quinto título principal da série Devil May Cry e foi lançado em 8 de março de 2019 para Microsoft Windows, PlayStation 4 e Xbox One. O jogo acontece cinco anos depois de Devil May Cry 4 e segue um trio de personagens com poderes demoníacos: Dante, Nero e um novo protagonista chamado V. Eles tentam impedir que o Rei Demoníaco Urizen, destrua o mundo humano. Ao longo do jogo, o jogador pode usar qualquer um desses três personagens em missões diferentes, com cada personagem tendo sua própria maneira de lutar e de evolução de força. Quando isso acontece, o mistério por trás de V é revelado ao lado de sua conexão com Urizen.', '2014/01/02', '2');

insert into produto (idproduto, nome, imagem, quantidade, descricao, data_lancamento, numero_galpao)
values('9','Metro Exodus PS5', '9.png', '13', 'Metro Exodus é um jogo eletrônico de tiro em primeira pessoa e Survival horror; desenvolvido pela 4A Games e publicado pela Deep Silver. Foi lançado em 15 de fevereiro de 2019 para Microsoft Windows, PlayStation 4 e Xbox One. É o terceiro título da série de jogos eletrônicos Metro, baseado nos romances de Dmitry Glukhovsky. Ele é a sequência dos eventos ocorridos em Metro 2033 e Metro: Last Light. Metro Exodus é um jogo eletrônico de tiro em primeira pessoa com elementos de survival horror e stealth. Situado no terreno baldio pós-apocalíptico da antiga Federação Russa, o jogador deve lidar com os novos perigos e se envolver em combate contra criaturas mutantes, assim como contra humanos hostis. O jogador empunha um arsenal de armamento feito à mão que pode ser personalizado através de materiais de looting e de um sistema de crafting. O jogo apresenta uma mistura de níveis lineares e ambientes de sandbox.', '2019/05/11', '3');

insert into produto (idproduto, nome, imagem, quantidade, descricao, data_lancamento, numero_galpao)
values('10','Minecraft PS5', '10.png', '150', 'Minecraft é um jogo eletrônico sandbox de sobrevivência criado pelo desenvolvedor sueco Markus "Notch" Persson e posteriormente desenvolvido e publicado pela Mojang Studios, cuja propriedade intelectual foi obtida pela Microsoft em 2014. Lançado inicialmente em maio de 2009 como um projeto em desenvolvimento, seu lançamento completo ocorreu em novembro de 2011 para Microsoft Windows, macOS e Linux, sendo posteriormente relançado para uma ampla variedade de plataformas. É o jogo eletrônico mais vendido de todos os tempos, vendendo mais de 238 milhões de cópias em todas as plataformas até abril de 2021, com mais de 140 milhões de jogadores ativos mensalmente.', '2001/02/20', '1');

