#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stdlib.h>
#include <QGraphicsScene>
#include <QPen>
#include <QColor>
#include <iostream>
#include<qtablewidget.h>
#include<QTableWidget>
class Neurona
{


    public:
        Neurona();
        Neurona(int id, float voltaje,int posicion_x, int posicion_y, int red, int green, int blue);
       ~Neurona();

        int id;
        float voltaje;
        int posicion_x;
        int posicion_y;
        int red;
        int green;
        int blue;


        int getId(void);
        void setId(int);

        float getVoltaje(void);
        void setVoltaje(float);

        int getPosicion_x(void);
        void setPosicion_x(int);

        int getPosicion_y(void);
        void setPosicion_y(int);

        int getRed(void);
        void setRed(int);

        int getGreen(void);
        void setGreen(int);

        int getBlue(void);
        void setBlue(int);
};
class nodo
{
    public:
        nodo();
        ~nodo();
        Neurona dato;
        nodo *sig;
        nodo *ant;
        void eliminar_todo();
    protected:
};


class administraNeu
{
    public:
       administraNeu();
        ~administraNeu();

        nodo *h;
        nodo *t;
        int contadorNeuronas = 0;
        //lista de operaciones

        void inicializa(void);
        void insertaInicio(Neurona);
        void insertaFinal(Neurona);
        void Burbuja();
        void setContadorNeuronas(int& contador);
        int getContadorNeuronas();
        void print();
        bool vacia();
        nodo* buscar(int id);
        nodo* anterior(Neurona);
        nodo* siguiente(Neurona);
        void vaciar();
        int size();

        std::string toString();
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    administraNeu listaNeuronas;
    Neurona Neu;
private slots:


    void on_botonmostrar_clicked();

    void on_botonagregainicio_clicked();

    void on_botonagregarfinal_clicked();

    void on_actionguardar_triggered();

    void on_actionabrir_triggered();

    void on_boton_buscar_clicked();

    void on_dibujar_pushButton_clicked();

    void on_limpiar_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_boton_ordenar_clicked();

private:
    Ui::MainWindow *ui;
   //QGraphicsScene ecena;
    QGraphicsScene *escena = new QGraphicsScene();
};
#endif // MAINWINDOW_Hz



