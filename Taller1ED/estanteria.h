
#ifndef TALLER1_ESTANTERIA_H
#define TALLER1_ESTANTERIA_H
#include "NodoZapato.h"
#include "Zapato.h"
#include <vector>
#include "unordered_map"

class Estanteria
{
private:

    //Atributos de la estanteria
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


    /**
     * Constructor de la estanteria
     */
    Estanteria();


    /**
     * Constructor con parametros
     * @param largo Largo de la matriz
     * @param alto Alto de la matriz
     */
    Estanteria(int largo, int alto);

    /**
     * Destructor de la estanteria
     * @param largo Largo de la matriz
     * @param alto Alto de la matriz
     */
    virtual ~Estanteria();

    /**
     * Get's & Set's de la clase
     */
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

    /**
     * Metodo que busca el zapato en base al modelo
     * @param modeloBuscado Modelo del zapato
     * @return True si lo encuentra, false si no
     */
    bool buscarModeloZapato(int modeloBuscado);

    /**
     * Metodo que busca el zapato en base a la talla
     * @param tallaBuscada Talla del zapato
     * @return True si lo encuentra, false si no
     */
    bool buscarTallaZapato(int tallaBuscada);

    /**
     * Metodo que vende el zapato como tal
     */
    void venderZapato();


    /**
     * Metodo que muestra los zapatos mas vendidos segin el modelo
     * @param modelosVendidos Modelos de los zapatos que se han vendido
     */
     //No retorna el arreglo con los zapatos vendidos segun el modelo porque el mismo metodo los imprime
    std::vector <std::string> modeloMasVendido(std::vector <std::string> modelosVendidos);

    /**
     * Metodo que muestra los zapatos mas vendidos segun la talla
     * @param tallasVendidas Tallas de los zapatos que se han vendido
     * */
     //No retorna el arreglo con los zapatos vendidos segun la talla porque el mismo metodo los imprime
    std::vector <int> tallaMasVendida(std::vector <int> tallasVendidas);

    /**
     * Metodo que define el porcentaje de zapatos blancos vendidos
     * @param cantZapatosBlancosVendidos Cantidad de zapatos blancos que se han vendido
     * @param cantZapatosVendidos Cantidad total de zapatos vendidos
     * @return El porcentaje de zapatos blancos vendidos
     */
    int porcentajeColorBlancoVendido(int cantZapatosBlancosVendidos, int cantZapatosVendidos);

    /**
     * Metodo que define el porcentaje de zapatos negros vendidos
     * @param cantZapatosNegrosVendidos Cantidad de zapatos negros que se han vendido
     * @param cantZapatosVendidos Cantidad total de zapatos vendidos
     * @return El porcentaje de zapatos negros vendidos
     */
    int porcentajeColorNegroVendido(int cantZapatosNegrosVendidos, int cantZapatosVendidos);

    /**
     * Metodo que agrega un zapato de la bodega al estante
     * @param nodo El nodo  que hace referencia al zapato
     */
    void agregarAEstante(NodoZapato* nodo);


    void agregarArchivo(NodoZapato* nodo);

    void ModeloTallaRelleno(Estanteria* e, Estanteria* e2);

    void imprimirEstante(Estanteria* e);



};

#endif //TALLER1_ESTANTERIA_H
