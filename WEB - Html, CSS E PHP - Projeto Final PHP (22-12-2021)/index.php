<?php
require_once 'classes/Funcionario.class.php';
require_once 'classes/Funcoes.class.php';
include_once "FuncionarioDAO.class.php";

$objFcn = new Funcionario();
$objFcs = new Funcoes();

if(isset($_POST['btCadastrar'])){
    if($objFcn->queryInsert($_POST) == 'ok'){
        header('location: /ProjetoFinalPhp');
    }else{
        echo '<script type="text/javascript">alert("Erro em cadastrar");</script>';
    }
}

if(isset($_POST['btAlterar'])){
    if($objFcn->queryUpdate($_POST) == 'ok'){
        header('location: ?acao=edit&func='.$objFcs->base64($_POST['func'],1));
    }else{
        echo '<script type="text/javascript">alert("Erro em alterar");</script>';
    }
}

if(isset($_GET['acao'])){
    switch($_GET['acao']){
        case 'edit': $func = $objFcn->querySeleciona($_GET['func']); break;
        case 'delet':
            if($objFcn->queryDelete($_GET['func']) == 'ok'){
                header('location: /ProjetoFinalPhp');
            }else{
                echo '<script type="text/javascript">alert("Erro em deletar");</script>';
            }
                break;        
    }
        
}

?>
<!DOCTYPE HTML>
<html lang="pt-br">
<head>
	<meta charset="utf-8">
	<title>Formulário de cadastro</title>
	<link href="css/estilo.css" rel="stylesheet" type="text/css" media="all">
</head>
<body class="body1">
    
    <header>
        
        <img class="cabecalho" src="img/cabecalho.png">
        
    </header>    

<div class="tudo1">
<div id="lista">
    <?php foreach($objFcn->querySelect() as $rst){ ?>
    <div class="funcionario">
        <div class="nome"><?=$objFcs->tratarCaracter($rst['nome'], 2)?></div>        
        <div class="visualizar"><a href="visu.php" title="Visualizar dados"><img src="img/ico-visu.png" width="16" height="16" alt="Visualizar"></a></div>
        <div class="editar"><a href="?acao=edit&func=<?=$objFcs->base64($rst['idFuncionario'], 1)?>" title="Editar dados"><img src="img/ico-editar.png" width="16" height="16" alt="Editar"></a></div>
        <div class="excluir"><a href="?acao=delet&func=<?=$objFcs->base64($rst['idFuncionario'], 1)?>" title="Excluir esse dado"><img src="img/ico-excluir.png" width="16" height="16" alt="Excluir"></a></div>
    </div>
    <?php } ?>
</div>

<div id="formulario">
    <form name="formCad" action="" method="post">
        
       	<label>Nome: </label><br>
        <input type="text" name="nome" placeholder="Nome do Funcionário" required="required" style="background-color: #e4f2f7;" value="<?=$objFcs->tratarCaracter((isset($func['nome']))?($func['nome']):(''), 2)?>"><br>
        
        <label>E-mail: </label><br>
        <input type="mail" name="email" placeholder="E-mail do Funcionário"  required="required" pattern="[a-z0-9._%+-]+@[a-z0-9.-]+\.[a-z]{2,4}$" style="background-color: #e4f2f7;" value="<?=$objFcs->tratarCaracter((isset($func['email']))?($func['email']):(''), 2)?>"><br>
        
        <?php if(isset($_GET['acao']) <> 'edit'){ ?>
        <label>Senha: </label><br>
        <input type="password" name="senha" placeholder="Senha do Funcionário"  required="required" style="background-color: #e4f2f7;"><br>
        <?php } ?>
        
        <br><label>Foto: </label> <?=$objFcs->tratarCaracter((isset($func['imagem']))?($func['imagem']):(''), 2)?>
        <input class="button" type="file" name="imagem" required="required"><br><br>
        
        <label>Descrição:</label><br> <textarea type="text" name="descricao" placeholder="Descrição do Funcionário" style="background-color: #e4f2f7; width: 300px; margin: 0px; height: 68px;"required><?=$objFcs->tratarCaracter((isset($func['descricao']))?($func['descricao']):(''), 2)?></textarea><br><br>
        
        <label>Gestor:</label> <select name="id_gestor" style="background-color: #e4f2f7; cursor: pointer;">                                        
					<option value="1">Roger Gamer da Silva</option>
					<option value="2">Felipe Neto da Silva</option>
                                        <option value="3">Irineu Mario da Silva</option>
				   </select>        
        <?=$objFcs->tratarCaracter((isset($func['id_gestor']))?($func['id_gestor']):(''), 2)?>
        <br> <br>
        
        <input class="button" type="submit" name="<?=(isset($_GET['acao']) == 'edit')?('btAlterar'):('btCadastrar')?>" value="<?=(isset($_GET['acao']) == 'edit')?('Alterar'):('Cadastrar')?>">
        <input type="hidden" name="func" value="<?=(isset($func['idFuncionario']))?($objFcs->base64($func['idFuncionario'], 1)):('')?>">
    </form>
</div>
</div>
 
</body>
</html>
