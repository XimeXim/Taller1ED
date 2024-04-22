
#ifndef TALLER1_ESTANTERIA_H
#define TALLER1_ESTANTERIA_H
#include "NodoZapato.h"
#include "Zapato.h"
#include <vector>
#include "unordered_map"

class Estanteria
{
private:

    int largo;
    int alto;
    int cantZapatosBlancosVendidos = 0;
    int cantZapatosNegrosVendidos = 0;
    int cantZapatosVendidos = 0;
    int ventasTotales = 0;
    NodoZapato** Modelo = new NodoZapato * [largo];
    NodoZapato** Talla = new NodoZapato * [alto];
    std::vector<std::string> modelosVendidos;
    std::vector<int> tallasVendidas;
    std::vector<std::string> coloresVendidos;
    


public:

    explicit Estanteria();

    virtual ~Estanteria();

    int getLargo() const;

    void setLargo(int largo);

    int getAlto() const;

    void setAlto(int alto);

    NodoZapato** getModelo() const;

    void setModelo(NodoZapato** modelo);

    NodoZapato** getTalla() const;

    void setTalla(NodoZapato** talla);

    const std::vector<std::string> &getModelosVendidos() const;

    void setModelosVendidos(const std::vector<std::string> &modelosVendidos);

    const std::vector<int> &getTallasVendidas() const;

    void setTallasVendidas(const std::vector<int> &tallasVendidas);

    const std::vector<std::string> &getColoresVendidos() const;

    void setColoresVendidos(const std::vector<std::string> &coloresVendidos);

    int getCantZapatosBlancosVendidos() const;

    void setCantZapatosBlancosVendidos(int cantZapatosBlancosVendidos);

    int getCantZapatosNegrosVendidos() const;

    void setCantZapatosNegrosVendidos(int cantZapatosNegrosVendidos);

    int getVentasTotales() const;

    void setVentasTotales(int ventasTotales);

    int getCantZapatosVendidos() const;

    void setCantZapatosVendidos(int cantZapatosVendidos);

    bool buscarModeloZapato(int modeloBuscado);

    bool buscarTallaZapato(int tallaBuscada);

    bool venderZapato(int modeloBuscado, int tallaBuscada);

    std::vector <std::string> modeloMasVendido(std::vector <std::string> modelosVendidos);

    std::vector <int> tallaMasVendida(std::vector <int> tallasVendidas);

    int porcentajeColorBlancoVendido(int cantZapatosBlancosVendidos, int cantZapatosVendidos);

    int porcentajeColorNegroVendido(int cantZapatosNegrosVendidos, int cantZapatosVendidos);

    void agregarAEstante(NodoZapato* nodo);

    void agregarArchivo(NodoZapato* nodo);

};

#endif //TALLER1_ESTANTERIA_H
