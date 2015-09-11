#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()//CrearArbol
{
    raiz = new Nodo(4, "Initial Node");
    raiz->hijos[0] = new Nodo(4, "10");
    raiz->hijos[1] = new Nodo(4, "20");
    raiz->hijos[2] = new Nodo(4, "");
    raiz->hijos[3] = new Nodo(4, "");

    Nodo* hijo1 = new Nodo(4, "5");
    Nodo* hijo2 = new Nodo(4, "6");
    Nodo* hijo3 = new Nodo(4, "9");
    raiz->hijos[0]->addHijo(hijo1);
    raiz->hijos[0]->addHijo(hijo2);
    raiz->hijos[0]->addHijo(hijo3);

    Nodo* hijo4 = new Nodo(4, "12");
    Nodo* hijo5 = new Nodo(4, "18");
    raiz->hijos[1]->addHijo(hijo4);
    raiz->hijos[1]->addHijo(hijo5);

    Nodo* hijo6 = new Nodo(4, "25");
    Nodo* hijo7 = new Nodo(4, "92");
    Nodo* hijo8 = new Nodo(4, "99");
    raiz->hijos[2]->addHijo(hijo6);
    raiz->hijos[2]->addHijo(hijo7);
    raiz->hijos[2]->addHijo(hijo8);
}

void MainWindow::on_pushButton_2_clicked()//Dibujar Arbol
{
    QGraphicsScene* scena = new QGraphicsScene();
    drawNodo(raiz, scena);
    ui->graphicsView->setScene(scena);
}

void MainWindow::drawNodo(Nodo* raiz, QGraphicsScene* scene){
    string names[raiz->orden];
    for(int x = 0; x < raiz->orden; x++)
        names[x] = raiz->hijos[x]->valor;
    scene->addItem(createVisualNodo(names, raiz->orden));
}

QGraphicsItemGroup* MainWindow::createVisualNodo(string* names, int cant){
    QGraphicsItemGroup* grupo = new QGraphicsItemGroup();
    int posx = 0;
    int dim = 50;

    for(int x = 0; x < cant; x++){
        QGraphicsRectItem* cuadro = new QGraphicsRectItem(posx,0,50,50);
        cuadro->setBrush(QBrush(Qt::gray));
        QGraphicsTextItem* texto = new QGraphicsTextItem();
        texto->setPos(posx, dim/3);
        texto->setPlainText(QString::fromStdString(names[x]));
        grupo->addToGroup(cuadro);
        grupo->addToGroup(texto);
        posx+=dim;
    }
    return grupo;
}
