#include <iostream>
#include <Porcentaje.hpp>

int main(){
    std::list<Porcentaje> focos;
    Porcentaje foco;
    Porcentaje foco1;
    Porcentaje foco2;
    Porcentaje foco3;

    focos.emplace_back(foco1);
    focos.emplace_back(foco2);
    focos.emplace_back(foco3);
    for (auto &&f : focos)
    {
        f.Incrementar(10);
    }
    

    foco1.Incrementar(10);
    foco1.Incrementar(10);
}