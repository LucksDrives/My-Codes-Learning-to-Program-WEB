<?php //Abertura do PHP

include_once "Conexao.class.php";
include_once "Funcoes.class.php";
include_once "Funcionario.class.php";

/*----------------------------------------------------------------------------------------------------------*/ 

	/*Realizar conexão*/
																													
	$servidor = 'localhost'; // Servidor Hospedado
	$usuario = 'root'; // Usuário do Mysql
	$senha = ''; // Senha
	$bancoDados = 'funcionario'; // Nome do Banco de Dados
	
	$conexao = mysqli_connect($servidor, $usuario, $senha,$bancoDados); // Código para Estabeler a conexão			
	
/*----------------------------------------------------------------------------------------------------------*/
	
	/*Criação da Tabela de Produtos*/
	
	print('<HTML><head>
	<meta charset="utf-8">
	<title>Formulário de cadastro</title>
	<link href="css/estilo.css" rel="stylesheet" type="text/css" media="all">
        </head><BODY class="body2">
        <header>
        
        <img class="cabecalho" src="img/cabecalho.png">
        
        </header>         
        <table border="1">'); // Abertura do Html
              
	// Título da Tabela
	print('<a class="voltar" style="background-color: #e4f2f7;" href="index.php"><button style="background-color: #e4f2f7;" href="index.php">Voltar</button></a><br><p></p><tr>');
	print('<th class="titul"> Foto </th><th class="titul"> Id </th><th class="titul"> Nome </th><th class="titul"> E-mail </th><th class="titul"> Descrição </th><th class="titul"> Data de Cadastro </th><th class="titul"> Gestor </th>');
	print('</tr>');

	$sql = "select * from funcionario";

	$res = mysqli_query($conexao,$sql);

	while($funcionario = mysqli_fetch_array($res)){
	$id = $funcionario['idFuncionario'];
	
	print('<tr>');
	
	print('<td><img src="funcionarios/'.$funcionario['imagem'].'" width="100px"></img></td>');
	print('<td style="text-align: center">' . $funcionario['idFuncionario'] . '</td>');
	print('<td style="text-align: center">' . $funcionario['nome'] . '</td>');
	print('<td style="text-align: center">' . $funcionario['email'] . '</td>');
	print('<td style="text-align: center">' . $funcionario['descricao'] . '</td>');
	print('<td style="text-align: center">' . $funcionario['data_cadastro'] . '</td>');
	
	//Verficiação de Galpão de Estoque 'Esse atributo é para ser fechado, sem disponibilidade de Inserção e Modificação
	if($funcionario['id_gestor']  == 1){
	print('<td style="text-align: center">Roger Gamer da Silva</td>');}
	
	else if($funcionario['id_gestor']  == 2){
	print('<td style="text-align: center">Felipe Neto da Silva</td>');}
	
	else if($funcionario['id_gestor']  == 3){
	print('<td style="text-align: center">Irineu Mario da Silva</td>');}
	
	print('</tr>');
	}
/*	//Armazenar Valores na Tabela
	
	
	print('<td style="text-align: center">' . $produto['quantidade'] . '</td>');

	
	echo "<td style='text-align: center'><a href='editar_produto.php?id=" . $produto['idproduto'] . "' href=''style='color: green; text-align: center;'>Editar<br><br></a><a id='a' href='deletar_produto.php?id=" . $produto['idproduto'] . "'onClick='a_onClick()' style='color: red'>Deletar</a></td>"; // Botões para Deletar e Editar
}
*/	
	print('</table></BODY></HTML>'); // Fechamento do Html
	
/*----------------------------------------------------------------------------------------------------------*/
?>