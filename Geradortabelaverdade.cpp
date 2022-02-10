#include <iostream>
#include <vector>
#include <math.h>

bool resultado_g(std::vector<bool> Lista){
    if ((Lista[0]^Lista[5])^(Lista[1]^Lista[4]))// argumentos para tratamento dos dados;
    {
        return 1;
    }
    else
    {
        return 0;
    } 
}

int main(){
    int num_repeticoes=0,i=0, Num_Bits=6, Num_1=0, Num_0=0;// tamanho do array de bits;
    std::vector<bool> Lista(Num_Bits,0);
    Lista.back()=1;
    std::vector<bool> semente=Lista;
    bool g,saida=Lista.back();
    for(i=0; i<Lista.size(); i++)
    {
        std::cout<< Lista[i] << " ";
        if (i==Lista.size()-1)
        {
            std::cout<< "   ->  "<< saida << std::endl;
        }
    }
    g=resultado_g(Lista);
    Lista.pop_back();
    Lista.insert(Lista.begin(),g);
    num_repeticoes++;
    saida==1 ? Num_1++ : Num_0++;
    while (1)
    {
        saida=Lista.back();
        for(i=0; i<Lista.size(); i++)
        {
            std::cout<< Lista[i] << " ";
            if (i==Lista.size()-1)
            {
                std::cout<< "   ->  "<< saida << std::endl;
            }
        
        }
        saida==1 ? Num_1+=1 : Num_0++ ;
        g=resultado_g(Lista);
        Lista.pop_back();
        Lista.insert(Lista.begin(),g);
        num_repeticoes++;
        if(Lista==semente){
            std::cout<< " Chegou na semente " << std::endl;
            break;
        }
        else if(num_repeticoes==pow(2,Lista.size())-1){
            std::cout<< " Loop infinito " << std::endl;
            break;
        }
    }
    std::cout<< " Numero de saidas : "<< num_repeticoes << std::endl;
    std::cout<< " Numero 1 : "<< Num_1 << std::endl;
    std::cout<< " Numero 0 : "<< Num_0 << std::endl;
    return 0;
}