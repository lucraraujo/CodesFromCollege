/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package mypkg;

import java.io.*;
import java.util.StringTokenizer;

class Lista {

    private class No {

        private int valor;
        private No proximo;

        public No(int x) {
            valor = x;
            proximo = null;
        }

        public int GetValor() {
            return valor;
        }

        public No GetProximo() {
            return proximo;
        }

        public void Set(No no) {
            proximo = no;
        }
    }
    private No primeiro;
    private No ultimo;
    private int tamanho;

    public Lista() {
        primeiro = null;
        ultimo = null;
        tamanho = 0;
    }

    public boolean EstaNaLista(int x) {
        if (tamanho == 0) {
            return false;
        }

        No aux = null;
        aux = primeiro;
//aux->Set(primeiro); //faz aux apontar para o primeiro elemento da lista
        int i;
        for (i = 0; i < tamanho; ++i) {
            if (aux.GetValor() == x) {
                return true;
            }

            aux = aux.GetProximo();
        }

        return false;
    }

    public boolean InsereNaLista(int x) {
        if (EstaNaLista(x)) //não pode inserir valores repetidos
        {
            return false;
        }

        No no = new No(x);

        if (tamanho == 0) {
            primeiro = no;
            ultimo = no;
        } else if (x < primeiro.GetValor()) //se o valor for menor que o valor do primeiro da lista
        {
            no.Set(primeiro);	//no aponta para o primeiro elemento da lista
            primeiro = no;
        } else if (x > ultimo.GetValor()) //se o valor for maior que o valor do ultimo elemento da lista
        {
            ultimo.Set(no); //faz o ultimo ponteiro que estava aterrado apontar para a nova celula
            ultimo = ultimo.GetProximo();
            no.Set(null); //aterra o ponteiro
        } else {
            int i;
            No aux = null;
            aux = primeiro; //aux aponta para o 1º elemento da lista

            for (i = 0; i < tamanho; ++i) //aux sempre vai apontar para o elemento imediatamente anterior a x
            {
                if (x < aux.GetProximo().GetValor()) //se x for menor, insere ali
                {
                    no.Set(aux.GetProximo());
                    aux.Set(no);
                    break;
                }

                aux = aux.GetProximo();
            }
        }

        tamanho++;
        return true;

    }

    public void Imprime() {
        No no = primeiro;
        for (int i = 0; i < tamanho; ++i) {
            System.out.print(no.GetValor() + " ");
            no = no.GetProximo();
        }
        System.out.println();
    }

    public boolean RetiraDaLista(int x) {
        if (!EstaNaLista(x)) //se o elemento não estiver na lista
        {
            return false;
        }

        No aux;
        if (primeiro.GetValor() == x) //se o elemento a ser retirado for o primeiro da lista
        {
            aux = primeiro;
            primeiro = primeiro.GetProximo();
//delete aux;
            tamanho--;
            return true;
        }

        No aux1 = primeiro; //aux1 aponta para o elemento anterior
        aux = primeiro.GetProximo(); //aux aponta para o elemento a ser removido

        for (int i = 0; i < tamanho; ++i) {
            if (aux.GetValor() == x) {
                if (aux.GetProximo() == null) //se for o ultimo elemento da lista
                {
                    ultimo = aux1;
                    aux1.Set(null); //aterra o ponteiro
//delete aux;
                    break;
                } else {
                    aux1.Set(aux.GetProximo());
//delete aux;
                    break;
                }
            }
            aux1 = aux;
            aux = aux.GetProximo();
        }

        tamanho--;
        return true;
    }

    public void Exportar(String saida) {
        //try {
            //BufferedWriter out = new BufferedWriter(new FileWriter(saida));
            StringBuffer out = new StringBuffer(saida);
            //PrintWriter out  = new PrintWriter (saida);
            
            No aux = primeiro;
            for (int i = 0; i < tamanho; ++i)
            {
                out.append(aux.GetValor());
                aux = aux.GetProximo();
            }
        //} catch (IOException e) {
         //   System.out.println(e);
        //}
    }

    public void Importar(String entrada) {
        int numero;

        try {
            BufferedReader in = new BufferedReader(new FileReader(entrada));
            String linha = new String();

            linha = in.readLine();
            StringTokenizer separador;
            separador = new StringTokenizer(linha);

            int a = separador.countTokens();
            for (int i = 0; i < a; ++i)
            {
                numero = Integer.parseInt(separador.nextToken());
                InsereNaLista(numero);
            }
            in.close();
        } catch (IOException e) {
            System.out.println(e);
        }
    }

}



public class Main {

    public static void main(String[] args) {

        Lista l = new Lista();
        
        l.Importar("exemplo.txt");
        l.RetiraDaLista(10);
        l.Exportar("saida.txt");

        l.Imprime();
    }
}
