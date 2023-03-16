#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <qfiledialog.h>
#include <QDebug>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <qtablewidget.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->grafico->setScene(escena);

}

MainWindow::~MainWindow()
{
    delete ui;
}

administraNeu::administraNeu()
{
    inicializa();
}

administraNeu::~administraNeu()
{
}

bool administraNeu::vacia()
{
    if(h==NULL and t== NULL)
    return true;
    else
    return false;
}

void administraNeu::inicializa(void)
{
    h=NULL;
    t=NULL;
}

void administraNeu::insertaInicio(Neurona x)
{
    nodo *tmp=new nodo();
    tmp->dato=x;

    if(vacia())
    {
        h=tmp;
        t=tmp;
    }
    else
    {
        tmp->sig=h;
        h->ant=tmp;
        h=tmp;
    }
    contadorNeuronas++;
}
void administraNeu::insertaFinal(Neurona x)
{
    nodo *tmp=new nodo();
    tmp->dato=x;
    nodo *aux=h;

    if(aux==NULL)
    {
        h=tmp;
    }
    else
    {
        while(aux->sig) //null=false
        {
            aux=aux->sig;
        }
        aux->sig=tmp;
    }
    contadorNeuronas++;
}
void administraNeu::Burbuja()
{
    nodo *aux, *aux2;
    Neurona temp;

    aux=h;
    while(aux->sig !=NULL)
    {
        aux2=aux->sig;
        while(aux2 != NULL)
        {
            if(aux2->dato.getId() < aux->dato.getId())
            {
                temp= aux->dato;
                aux->dato= aux2->dato;
                aux2->dato = temp;
            }
            aux2=aux2->sig;
        }
        aux=aux->sig;
    }
    cout<<"Lista ordenada"<<endl;
}

void administraNeu::print()
{
    nodo *aux=h;


    if(aux)
    {
        while(aux)
        {

        cout << " Id:     #" << aux->dato.getId() << endl;
        cout << " Voltaje: " << aux->dato.getVoltaje() << endl;
        cout << " posicion_x: " << aux->dato.getPosicion_x() << endl;
        cout << " posicion_y: " << aux->dato.getPosicion_y() << endl;
        cout << " Red: " << aux->dato.getRed() << endl;
        cout << " Green: " << aux->dato.getGreen() << endl;
        cout << " Blue: " << aux->dato.getBlue() << endl;
            aux=aux->sig;
        }
    }
    else
        cout<<"Lista vacia"<<endl;
}

nodo* administraNeu::buscar(int id)
{
    nodo* aux=h;

    while (aux)
    {
        if (aux->dato.id == id)
            return aux;

        aux = aux->sig;
    }

    std::cout << "No existe \n";
    return nullptr;
}

int administraNeu::getContadorNeuronas(){return contadorNeuronas;}

void administraNeu::setContadorNeuronas(int& contador){contadorNeuronas = contador;}

void administraNeu::vaciar()
{
    h=NULL;
    t=NULL;
}



int administraNeu::size()
{
    int i = 0;
    nodo* p = h;

    while(p)
    {
        i++;
        p = p->sig;
    }
    return i;
}

std::string administraNeu::toString()//capturar datos para su impresion
{
    nodo *aux=h;
    std::string stringAdmin;


    if(aux)
    {
        while(aux)
        {

        stringAdmin += " Id:     #"; stringAdmin += std::to_string(aux->dato.getId()); stringAdmin += "\n";
        stringAdmin += " Voltaje: "; stringAdmin += std::to_string(aux->dato.getVoltaje()); stringAdmin += "\n";
        stringAdmin += " posicion_x: "; stringAdmin += std::to_string(aux->dato.getPosicion_x()); stringAdmin += "\n";
        stringAdmin += " posicion_y: "; stringAdmin += std::to_string(aux->dato.getPosicion_y()); stringAdmin+= "\n";
        stringAdmin += " Red: "; stringAdmin+= std::to_string(aux->dato.getRed()); stringAdmin += "\n";
        stringAdmin += " Green: "; stringAdmin+= std::to_string(aux->dato.getGreen()); stringAdmin += "\n";
        stringAdmin += " Blue: "; stringAdmin += std::to_string(aux->dato.getBlue()); stringAdmin += "\n";
        stringAdmin += "---------------------------------- \n";
            aux=aux->sig;
        }
    }
    else
        stringAdmin+= "La lista esta vacia";

    return stringAdmin;
}


nodo::nodo()
{
    sig=NULL;
    ant=NULL;
}

nodo::~nodo()
{
}

void nodo::eliminar_todo()
{
    if(sig and ant)
    sig->eliminar_todo();
    delete this;
}

Neurona::Neurona()
{
}


Neurona::Neurona(int id, float voltaje,int posicion_x, int posicion_y, int red, int green, int blue)
{
    this->id = id;
    this->voltaje = voltaje;
    this->posicion_x= posicion_x;
    this->posicion_y= posicion_y  ;
    this->red = red;
    this->green= green;
    this->blue = blue;

}

Neurona::~Neurona()
{
}

int Neurona::getId(void){return id;}
void Neurona::setId(int id){this->id = id;}

float Neurona::getVoltaje(void){return voltaje;}
void Neurona::setVoltaje(float voltaje){this->voltaje = voltaje;}

int Neurona::getPosicion_x(void){return posicion_x;}
void Neurona::setPosicion_x(int posicion_x){this->posicion_x = posicion_x;}

int Neurona::getPosicion_y(void){return posicion_y;}
void Neurona::setPosicion_y(int posicion_y){this->posicion_y = posicion_y;}

int Neurona::getRed(void){return red;}
void Neurona::setRed(int red){this->red = red;}


int Neurona::getGreen(void){return green;}
void Neurona::setGreen(int green){this->green = green;}

int Neurona::getBlue(void){return blue;}
void Neurona::setBlue(int  blue){this-> blue = blue;}





void MainWindow::on_botonmostrar_clicked()
{
    ui->plainTextEdit->setPlainText(QString::fromStdString(listaNeuronas.toString()));//mostramos los datos en el plaintext
}


void MainWindow::on_botonagregainicio_clicked()//agregar datos al inicio
{
    listaNeuronas.insertaInicio
    (
        Neurona(ui->spinBox->text().toInt(),
                ui->line_voltaje->text().toFloat(),
                ui->line_posx->text().toInt(),
                ui->line_posy->text().toInt(),
                ui->line_red->text().toInt(),
                ui->line_green->text().toInt(),
                ui->line_blue->text().toInt())

    );

}


void MainWindow::on_botonagregarfinal_clicked()//agregar datos al final
{
    listaNeuronas.insertaFinal
    (
        Neurona(ui->spinBox->text().toInt(),
                ui->line_voltaje->text().toFloat(),
                ui->line_posx->text().toInt(),
                ui->line_posy->text().toInt(),
                ui->line_red->text().toInt(),
                ui->line_green->text().toInt(),
                ui->line_blue->text().toInt())
    );
}






void MainWindow::on_actionguardar_triggered()
{
    std::cout<<"Guardar"<<std::endl;
    QString Filename= QFileDialog::getSaveFileName(this, "Guardar archivo", ".", "wb+");
    char* fname = Filename.toLocal8Bit().data();

    FILE* archivo = fopen(fname, "w+");


         unsigned char size = listaNeuronas.size();
         fwrite(&size, 1, 1, archivo);

       // recorrer nuestra lista desde el inicio
       nodo* aux = listaNeuronas.h;
       while (aux)
       {


           // id
           int id = aux->dato.getId();
           fwrite(&id, sizeof(int), 1, archivo);

           // VOLTAJE
           float voltaje = aux->dato.getVoltaje();
           fwrite(&voltaje, sizeof(float), 1, archivo);

           // posicion x
           int posicion_x = aux->dato.getPosicion_x();
           fwrite(&posicion_x, sizeof(int), 1,archivo);

           // posicion y
           int posicion_y = aux->dato.getPosicion_y();
           fwrite(&posicion_y, sizeof(int), 1, archivo);

           // red
           int red = aux->dato.getRed();
           fwrite(&red, sizeof(int), 1,archivo);

           // green
           int green = aux->dato.getGreen();
           fwrite(&green, sizeof(int), 1, archivo);

           // blue
           int blue = aux->dato.getBlue();
           fwrite(&blue, sizeof(int), 1, archivo);

           // continuar con el siguiente producto
           aux = aux->sig;
       }
        fclose(archivo);
}


void MainWindow::on_actionabrir_triggered()
{
    QString Filename= QFileDialog::getOpenFileName(this, "Guardar archivo", ".", "texto(*.txt)");
    char* fname = Filename.toLocal8Bit().data();
      FILE* archivo = fopen(fname, "rb");

                    // Vaciar lista
                    listaNeuronas.vaciar();

                    // leer registros totales
                    unsigned char size;
                    fread(&size, 1, 1, archivo);

                    // Mientras el archivo no haya terminado
                    while (size > 0)
                    {


                        // ID
                        int id;
                        fread(&id, sizeof(int), 1, archivo);

                        // voltaje
                        float voltaje;
                        fread(&voltaje, sizeof(float), 1, archivo);

                        // posicion x
                        int posicion_x;
                        fread(&posicion_x, sizeof(int), 1, archivo);

                        // posicion y
                        int posicion_y;
                        fread(&posicion_y, sizeof(int), 1, archivo);

                        // red
                        int red;
                        fread(&red, sizeof(int), 1, archivo);

                        // green
                        int green;
                        fread(&green, sizeof(int), 1, archivo);

                        // blue
                        int blue;
                        fread(&blue, sizeof(int), 1, archivo);

                        // agregarlo a la lista
                        Neurona p  (id, voltaje, posicion_x, posicion_y, red, green, blue);
                        listaNeuronas.insertaInicio(p);
                        size--;
                    }

                    fclose(archivo);
}

//ui->graphicsview.setscene(&ecena);


void MainWindow::on_boton_buscar_clicked()
{
    nodo* neubusca = listaNeuronas.buscar(ui->line_buscar->text().toInt());

    if(neubusca != nullptr)
    {
        ui->tableWidget->setEnabled(true);

         ui->tableWidget->setColumnCount(7);
         QStringList  headers = {"ID","VOLTAJE","X","Y","RED","GREEN","BLUE"};
         ui->tableWidget->setHorizontalHeaderLabels(headers);
         ui->tableWidget->setRowCount(10);
        QTableWidgetItem* idItem = new QTableWidgetItem (QString::number(neubusca->dato.id));
        QTableWidgetItem* voltItem = new QTableWidgetItem(QString::number(neubusca->dato.voltaje));
        QTableWidgetItem* posXItem = new QTableWidgetItem(QString::number(neubusca->dato.posicion_x));
        QTableWidgetItem* posYItem = new QTableWidgetItem(QString::number(neubusca->dato.posicion_y));
        QTableWidgetItem* rItem = new QTableWidgetItem (QString::number(neubusca->dato.red));
        QTableWidgetItem* gItem = new QTableWidgetItem (QString::number(neubusca->dato.green));
        QTableWidgetItem* bItem = new QTableWidgetItem (QString::number(neubusca->dato.blue));

        ui->tableWidget->setItem(0,0, idItem);
        ui->tableWidget->setItem(0,1, voltItem);
        ui->tableWidget->setItem(0,2, posXItem);
        ui->tableWidget->setItem(0,3, posYItem);
        ui->tableWidget->setItem(0,4, rItem);
        ui->tableWidget->setItem(0,5, gItem);
        ui->tableWidget->setItem(0,6, bItem);
    }

}




void MainWindow::on_dibujar_pushButton_clicked()
{
    QColor colorNeurona;
    QPen pen;
    nodo* aux = listaNeuronas.h;
    while (aux)
    {

        colorNeurona.setRgb(aux->dato.red, aux->dato.green, aux->dato.blue);
        escena->addEllipse(aux->dato.posicion_x, aux->dato.posicion_y, aux->dato.voltaje, aux->dato.voltaje, pen, QBrush(QColor(colorNeurona)));
        aux = aux->sig;

    }


}

void MainWindow::on_limpiar_pushButton_2_clicked()
{
    escena->clear();
}

void MainWindow::on_boton_ordenar_clicked()
{
    if (listaNeuronas.getContadorNeuronas() > 0 ){listaNeuronas.Burbuja(); (true);}
        else {ui->plainTextEdit->setPlainText( " No hay neuronas registradas... " ); ui-> tableWidget -> setEnabled ( false );}
}

