<?php

include_once "Conexao.class.php";
include_once "Funcoes.class.php";
include_once "FuncionarioDAO.class.php";

class Funcionario {
    
    private $con;
    private $objfc;
    private $idFuncionario;
    private $nome;
    private $email;
    private $senha;
    private $dataCadastro;
    private $imagem;
    private $descricao;
    private $id_gestor;
    
    public function __construct(){
        $this->con = new Conexao();
        $this->objfc = new Funcoes();
    }
    
    public function __set($atributo, $valor){
        $this->$atributo = $valor;
    }
    public function __get($atributo){
        return $this->$atributo;
    }
    
    public function querySeleciona($dado){
        try{
            $this->idFuncionario = $this->objfc->base64($dado, 2);
            $cst = $this->con->conectar()->prepare("SELECT idFuncionario, nome, email, data_cadastro, imagem, descricao, id_gestor FROM `funcionario` WHERE `idFuncionario` = :idFunc;");
            $cst->bindParam(":idFunc", $this->idFuncionario, PDO::PARAM_INT);
            $cst->execute();
            return $cst->fetch();
        } catch (PDOException $ex) {
            return 'error '.$ex->getMessage();
        }
    }
    
    public function querySelect(){
        try{
            $cst = $this->con->conectar()->prepare("SELECT `idFuncionario`, `nome`, `email`, `data_cadastro`, `imagem`, `descricao`, `id_gestor` FROM `funcionario`;");
            $cst->execute();
            return $cst->fetchAll();
        } catch (PDOException $ex) {
            return 'erro '.$ex->getMessage();
        }
    }
    
    public function queryInsert($dados){
        try{
            $this->nome = $this->objfc->tratarCaracter($dados['nome'], 1);
            $this->email = $dados['email'];
            $this->senha = sha1($dados['senha']);
            $this->dataCadastro = $this->objfc->dataAtual(2);
            $this->imagem = $dados['imagem'];
            $this->descricao = $dados['descricao'];
            $this->id_gestor = $dados['id_gestor'];
            
            $cst = $this->con->conectar()->prepare("INSERT INTO `funcionario` (`nome`, `email`, `senha`, `data_cadastro`, `imagem`, `descricao`, `id_gestor`) VALUES (:nome, :email, :senha, :dt, :imagem, :descricao, :id_gestor);");
            
            $cst->bindParam(":nome", $this->nome, PDO::PARAM_STR);
            $cst->bindParam(":email", $this->email, PDO::PARAM_STR);
            $cst->bindParam(":senha", $this->senha, PDO::PARAM_STR);
            $cst->bindParam(":dt", $this->dataCadastro, PDO::PARAM_STR);
            $cst->bindParam(":imagem", $this->imagem, PDO::PARAM_STR);
            $cst->bindParam(":descricao", $this->descricao, PDO::PARAM_STR);
            $cst->bindParam(":id_gestor", $this->id_gestor, PDO::PARAM_STR);
                      
            $diretorio = 'funcionarios/'; //Direcitório da Imagem
            
            $nome_imagem = $_FILES['imagem']['name'];
            
            move_uploaded_file($_FILES['imagem']['nome_imagem'], $diretorio.$nome_imagem);
            
            if($cst->execute()){
                return 'ok';
            }else{
                return 'erro';
            }
        } catch (PDOException $ex) {
            return 'error '.$ex->getMessage();
        }
    }
    
    public function queryUpdate($dados){
        try{
            $this->idFuncionario = $this->objfc->base64($dados['func'], 2);
            $this->nome = $this->objfc->tratarCaracter($dados['nome'], 1);
            $this->email = $dados['email'];
            $this->imagem = $dados['imagem'];
            $this->descricao = $dados['descricao'];
            $this->id_gestor = $dados['id_gestor'];
            
            $cst = $this->con->conectar()->prepare("UPDATE `funcionario` SET  `nome` = :nome, `email` = :email, `imagem` = :imagem, `descricao` = :descricao, `id_gestor` = :id_gestor  WHERE `idFuncionario` = :idFunc;");
            
            $cst->bindParam(":idFunc", $this->idFuncionario, PDO::PARAM_INT);
            $cst->bindParam(":nome", $this->nome, PDO::PARAM_STR);
            $cst->bindParam(":email", $this->email, PDO::PARAM_STR);
            $cst->bindParam(":imagem", $this->imagem, PDO::PARAM_STR);
            $cst->bindParam(":descricao", $this->descricao, PDO::PARAM_STR);
            $cst->bindParam(":id_gestor", $this->id_gestor, PDO::PARAM_STR);
            
            if($cst->execute()){
                return 'ok';
            }else{
                return 'erro';
            }
        } catch (PDOException $ex) {
            return 'error '.$ex->getMessage();
        }
    }
    
    public function queryDelete($dado){
        try{
            $this->idFuncionario = $this->objfc->base64($dado, 2);
            $cst = $this->con->conectar()->prepare("DELETE FROM `funcionario` WHERE `idFuncionario` = :idFunc;");
            $cst->bindParam(":idFunc", $this->idFuncionario, PDO::PARAM_INT);
            if($cst->execute()){
                return 'ok';
            }else{
                return 'erro';
            }
        } catch (PDOException $ex) {
            return 'error'.$ex->getMessage();
        }
    }     
}

?>
