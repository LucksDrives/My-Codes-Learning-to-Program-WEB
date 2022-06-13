<?php

include_once "Conexao.class.php";
include_once "Funcoes.class.php";
include_once "FuncionarioDAO.class.php";

class FuncionarioDAO {
    
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
}
