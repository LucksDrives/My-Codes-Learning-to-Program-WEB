<?php
/*----------------------------------------------------------------------------------------------------------*/
	
	/*Realizar conexão*/
																													
	$servidor = 'localhost'; // Servidor Hospedado
	$usuario = 'root'; // Usuário do Mysql
	$senha = ''; // Senha
	$bancoDados = 'produto'; // Nome do Banco de Dados
	
	$conexao = mysqli_connect($servidor, $usuario, $senha, $bancoDados); // Código para Estabeler a conexão			
	
/*----------------------------------------------------------------------------------------------------------*/

	/*Inserir Produtos*/
	
	$nome = filter_input(INPUT_POST, 'nome', FILTER_SANITIZE_STRING);
	$quantidade = filter_input(INPUT_POST, 'quantidade', FILTER_SANITIZE_STRING);
	$descricao = filter_input(INPUT_POST, 'descricao', FILTER_SANITIZE_STRING);
	$data_lancamento = filter_input(INPUT_POST, 'data_lancamento', FILTER_SANITIZE_STRING);
	$numero_galpao = filter_input(INPUT_POST, 'numero_galpao', FILTER_SANITIZE_STRING);
	$nome_imagem = $_FILES['imagem']['name'];
	
	$sql="INSERT INTO produto (nome, quantidade, descricao, data_lancamento,numero_galpao, imagem) VALUES ('$nome', '$quantidade', '$descricao', '$data_lancamento','$numero_galpao', '$nome_imagem')";
	
	$res = mysqli_query($conexao,$sql);
	
	$diretorio = 'produtos/'; //Direcitório da Imagem
	
	move_uploaded_file($_FILES['imagem']['tmp_name'], $diretorio.$nome_imagem);
	
/*----------------------------------------------------------------------------------------------------------*/

	/*Realizar Redirecionamento*/
	
	header("Location: avaliacao2.php");	
	
/*----------------------------------------------------------------------------------------------------------*/	
?>