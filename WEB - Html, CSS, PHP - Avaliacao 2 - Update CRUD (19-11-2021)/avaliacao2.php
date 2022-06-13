<?php //Abertura do PHP
/*----------------------------------------------------------------------------------------------------------*/ 

/*Título e Informações do Projeto*/

print('<h1 style="text-align:center">Avaliação 2 - Desenvolvimento Web II</h1>');

print('A ideia abordada no projeto, nessa avaliação, é uma contabilização de estoque de uma loja de games mídea física, a tabela contém informações relevantes do produto como Id, para identificação, Nome, Foto e Quantidade em Estoque. O projeto possibilita a Inserção e a Exclusão dos produtos.');

print('<br><strong>|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|</strong><br>');
/*----------------------------------------------------------------------------------------------------------*/

	/*Realizar conexão*/
																													
	$servidor = 'localhost'; // Servidor Hospedado
	$usuario = 'root'; // Usuário do Mysql
	$senha = ''; // Senha
	$bancoDados = 'produto'; // Nome do Banco de Dados
	
	$conexao = mysqli_connect($servidor, $usuario, $senha,$bancoDados); // Código para Estabeler a conexão			
	
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
	
	/*Criação da Tabela de Produtos*/
	
	print('<HTML><HEAD></HEAD><BODY><table border="1">'); // Abertura do Html
	
	print('<h2 style="text-align:center">Produtos</h2>'); // Título da Tabela
	
	print('<button onclick="Botao1(\'bt_1\',\'pe_1\')" id="bt_1">Inserir→&nbsp;</button><br>'); // Botão para Mostrar Formulário de Inserção
	
	//Script de Ocultar e Mostar Formulario de Inserção
	print('<script type="text/javascript">
	function Botao1(id,p){
		var bt = document.getElementById(id);
		var par = document.getElementById(p);
		
		if(bt.innerText == \'Inserir\xa0↓\xa0\') {
			bt.innerText = \'Inserir\xa0→\xa0\';
			par.style.display = \'none\';
		}
		else{
			bt.innerText = \'Inserir\xa0↓\xa0\';
			par.style.display = \'block\';
		}
	}
	</script>');
	
	// Formulário de Insersão
	print('
	<p id="pe_1" style="display:none;">	
	<form method="POST" action="inserir_produto.php" enctype="multipart/form-data">
	
		<label>Nome&nbsp;&nbsp;</label>	<input type="text" name="nome" placeholder="Nome do Produto" style="width: 112px;"required><br><br>
	
		<label>Quantidade&nbsp;&nbsp;</label>	<input type="text" name="quantidade" placeholder="Quantidade" style="width: 100px;"required><br><br>
	
		<label>Data de Lançamento&nbsp;&nbsp;</label>	<input type="date" name="data_lancamento" placeholder="Data de Lançamento" style="width: 130px;"required><br><br>
	
		<label>Descrição&nbsp;&nbsp;&nbsp;&nbsp;</label><br>	<textarea type="text" name="descricao" placeholder="Descrição do Produto" style="width: 195px; margin: 0px; height: 68px;"required></textarea><br><br>
		
		<label>Arquivo </label>	<input type="file" name="imagem"><br><br>
		
		<label>Localização</label> <select name="numero_galpao">
									<option value="1">Nova Prata</option>
									<option value="2">Caxias</option>
									<option value="3">Veranópolis</option>
								</select>
		
	<br><br><input type="submit" name="enviar" value="Enviar"></form></p>');

	// Título da Tabela
	print('<tr>');
	print('<th> Id </th><th> Nome </th><th> Foto </th><th> Estoque </th><th> Descrição </th><th> Data de Lançamento </th><th> Localização </th><th> Ação </th>');
	print('</tr>');	

	$sql = "select * from produto";

	$res = mysqli_query($conexao,$sql);
	
	//Armazenar Valores na Tabela
	while($produto = mysqli_fetch_array($res)){
	$id = $produto['idproduto'];
	print('<tr>');
	print('<td style="text-align: center">' . $produto['idproduto'] . '</td>');
	print('<td style="text-align: center">' . $produto['nome'] . '</td>');
	print('<td><img src="produtos/'.$produto['imagem'].'" width="100px"></img></td>');
	print('<td style="text-align: center">' . $produto['quantidade'] . '</td>');
	print('<td style="text-align: justify">' . $produto['descricao'] . '</td>');
	print('<td style="text-align: center">' . $produto['data_lancamento'] . '</td>');

	//Verficiação de Galpão de Estoque 'Esse atributo é para ser fechado, sem disponibilidade de Inserção e Modificação
	if($produto['numero_galpao']  == 1){
	print('<td style="text-align: center">Nova Prata</td>');}
	
	else if($produto['numero_galpao']  == 2){
	print('<td style="text-align: center">Caxias</td>');}
	
	else if($produto['numero_galpao']  == 3){
	print('<td style="text-align: center">Veranópolis</td>');}
	
	echo "<td style='text-align: center'><a href='editar_produto.php?id=" . $produto['idproduto'] . "' href=''style='color: green; text-align: center;'>Editar<br><br></a><a id='a' href='deletar_produto.php?id=" . $produto['idproduto'] . "'onClick='a_onClick()' style='color: red'>Deletar</a></td>"; // Botões para Deletar e Editar
}

	//Alerta de Produto Deletado
	print('<html><head></head><body><script type="text/javascript">
	function a_onClick() {
		alert(\'Produto Deletado!\');
	}
	</script></body></html>');
	
	print('</table></BODY></HTML>'); // Fechamento do Html
	
/*----------------------------------------------------------------------------------------------------------*/
?>