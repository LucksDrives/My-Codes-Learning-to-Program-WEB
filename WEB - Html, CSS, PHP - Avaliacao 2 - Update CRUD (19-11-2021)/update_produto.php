<?php
/*----------------------------------------------------------------------------------------------------------*/
	
	/*Realizar conexão*/
																													
	$servidor = 'localhost'; // Servidor Hospedado
	$usuario = 'root'; // Usuário do Mysql
	$senha = ''; // Senha
	$bancoDados = 'produto'; // Nome do Banco de Dados
	
	$conexao = mysqli_connect($servidor, $usuario, $senha, $bancoDados); // Código para Estabeler a conexão			
	
/*----------------------------------------------------------------------------------------------------------*/

	/*Editar Produtos*/
	
	$id = filter_input(INPUT_GET, 'id', FILTER_SANITIZE_NUMBER_INT);
	
	$nome = filter_input(INPUT_POST, 'nome', FILTER_SANITIZE_STRING);
	$quantidade = filter_input(INPUT_POST, 'quantidade', FILTER_SANITIZE_STRING);
	$descricao = filter_input(INPUT_POST, 'descricao', FILTER_SANITIZE_STRING);
	$data_lancamento = filter_input(INPUT_POST, 'data_lancamento', FILTER_SANITIZE_STRING);
	$numero_galpao = filter_input(INPUT_POST, 'numero_galpao', FILTER_SANITIZE_STRING);
	$nome_imagem = $_FILES['imagem']['name'];
	
	if($nome == ""){
		
	}
	else{
		$sql="UPDATE produto SET nome = '$nome' WHERE idproduto = $id";
		$res = mysqli_query($conexao,$sql);
	}
	
	if($quantidade == ""){
		
	}
	else{
		$sql="UPDATE produto SET quantidade = '$quantidade' WHERE idproduto = $id";
		$res = mysqli_query($conexao,$sql);
	}
	
	if($descricao == ""){
		
	}
	else{
		$sql="UPDATE produto SET descricao = '$descricao' WHERE idproduto = $id";
		$res = mysqli_query($conexao,$sql);
	}
	
	if($data_lancamento == ""){
		
	}
	else{
		$sql="UPDATE produto SET data_lancamento = '$data_lancamento' WHERE idproduto = $id";
		$res = mysqli_query($conexao,$sql);
	}
	
	if($numero_galpao == ""){
		
	}
	else{
		$sql="UPDATE produto SET numero_galpao = '$numero_galpao' WHERE idproduto = $id";
		$res = mysqli_query($conexao,$sql);
	}
	if($nome_imagem == ""){
		
	}
	else{
		$sql="UPDATE produto SET imagem = '$nome_imagem' WHERE idproduto = $id";
		$res = mysqli_query($conexao,$sql);
	}
	

	$res = mysqli_query($conexao,$sql);
	
	$diretorio = 'produtos/'; //Direcitório da Imagem
	
	move_uploaded_file($_FILES['imagem']['tmp_name'], $diretorio.$nome_imagem);
	
/*----------------------------------------------------------------------------------------------------------*/

	/*Realizar Redirecionamento*/
	
	header("Location: avaliacao2.php");
	
/*----------------------------------------------------------------------------------------------------------*/	
?>