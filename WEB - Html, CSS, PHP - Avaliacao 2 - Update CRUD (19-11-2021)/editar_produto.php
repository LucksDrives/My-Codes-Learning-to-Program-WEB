<?php
/*----------------------------------------------------------------------------------------------------------*/

	/*Realizar conexão*/
																													
	$servidor = 'localhost'; // Servidor Hospedado
	$usuario = 'root'; // Usuário do Mysql
	$senha = ''; // Senha
	$bancoDados = 'produto'; // Nome do Banco de Dados
	
	$conexao = mysqli_connect($servidor, $usuario, $senha,$bancoDados); // Código para Estabeler a conexão		

	print('<HTML><HEAD></HEAD><BODY>');

	print('<h1 style="text-align:center">Avaliação 2 - Desenvolvimento Web II</h1>');

	print('A ideia abordada no projeto, nessa avaliação, é uma contabilização de estoque de uma loja de games mídea física, a tabela contém informações relevantes do produto como Id, para identificação, Nome, Foto e Quantidade em Estoque. O projeto possibilita a Inserção e a Exclusão dos produtos.');

	print('<br><strong>|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|</strong><br>');
	
	$id = filter_input(INPUT_GET, 'id', FILTER_SANITIZE_NUMBER_INT); //Salvar ID do Produto
	
/*----------------------------------------------------------------------------------------------------------*/

	/*Testar Funcionalidade da Conexão*/																			
	
	print('<br><p style="float:left"> Situação da Conexão: <p>'); //Printar Situação da Conexão
	
	if(mysqli_connect_errno()){ //Verificação do Funcionamento - Caso Não Efetue a Conexão Corretamente
		print('<p style="color:red">&nbsp; Conexão com Problemas</p>'); //Print de Conexão Não Estabelecida
	}
	else{ //Verificação do Funcionamento - Caso Efetue a Conexão Corretamente
		echo "<p style='color: green'>&nbsp; Conexão Realizada com Sucesso</p>"; //Print de Conexão Estabelecida
	}																												

	print('<br><strong>|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|</strong><br>');

/*----------------------------------------------------------------------------------------------------------*/
	/*Salvar Informações*/
	$sql = "select * from produto";
	$res = mysqli_query($conexao,$sql);
	$i=$id;

	while($produto = mysqli_fetch_array($res)){
		
		if($produto['idproduto']==$id){
			$nome = $produto['nome'];
			$imagem = $produto['imagem'];
			$quantidade = $produto['quantidade'];
			$descricao = $produto['descricao'];
			$data_lancamento = $produto['data_lancamento'];
		}
		else{
			$produto['idproduto'];
			$produto['nome'];
			$produto['imagem'];
			$produto['quantidade'];
			$produto['descricao'];
			$produto['data_lancamento'];
		}

	//Verficiação de Galpão de Estoque 'Esse atributo é para ser fechado, sem disponibilidade de Inserção e Modificação
		if($produto['numero_galpao']  == 1){
			$valor_galpao = "Nova Prata";}
	
		else if($produto['numero_galpao']  == 2){
			$valor_galpao = "Caxias";}
	
		else if($produto['numero_galpao']  == 3){
			$valor_galpao = "Veranópolis";}
	}
	
	
	/*Criar Formulário de Update*/
		
	print('<p><h2>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Editar Produto<br></h2>
	|------------------------------------------|</p>');
	
	print('<td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<img src="produtos/'.$imagem.'" width="100px"></img></td><br><br>');
	
	print('
	<p id="pe_1" style="display:none;">	
	<form method="POST" action="update_produto.php?id='.$id.' " enctype="multipart/form-data">
	
		<label>Nome&nbsp;&nbsp;</label>	<input type="text" name="nome" placeholder="Nome do Produto" style="width: 112px;">  ➨ ' . $nome .'<br><br>
	
		<label>Quantidade&nbsp;&nbsp;</label>	<input type="text" name="quantidade" placeholder="Quantidade" style="width: 100px;">  ➨ ' . $quantidade .' Unidades<br><br>
	
		<label>Data de Lançamento&nbsp;&nbsp;</label>	<input type="date" name="data_lancamento" placeholder="Data de Lançamento" style="width: 130px;">  ➨ ' . $data_lancamento .'<br><br>
	
		<label>Descrição&nbsp;&nbsp;&nbsp;&nbsp;</label><br>	<textarea type="text" name="descricao" placeholder="Descrição do Produto" style="width: 368px; margin: 0px; height: 68px;">' . $descricao .'</textarea><br><br>
		
		<label>Arquivo </label>	<input type="file" name="imagem"> ➨ ' . $imagem .'<br><br>
		
		<label>Localização</label> <select name="numero_galpao">
									<option value="1">Nova Prata</option>
									<option value="2">Caxias</option>
									<option value="3">Veranópolis</option>
								</select> ➨ ');
		
	print('<br><br><input type="submit" name="enviar" value="Enviar"></form></p>');
	
/*----------------------------------------------------------------------------------------------------------*/

	print('</BODY></HTML>');

?>