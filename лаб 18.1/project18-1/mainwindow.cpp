#include <QtGui>
#include "mainwindow.h"

MainWindow::MainWindow() {
	setWindowTitle(tr("TColor 02"));
	setFixedSize(500, 300);
	
	redColor = 255;

	redLabel = new QLabel(this);
	redLabel->setGeometry(10, 10, 880, 50);
	redLabel->setFont(QFont("Courier", 20, QFont::Bold));
	redLabel->setText( "Red Color: " + QString::number(redColor) );

	startButton = new QPushButton(tr("Draw"), this);
	startButton->setGeometry(310, 55, 100, 30);
	connect(startButton, SIGNAL(clicked()), this, SLOT(startButtonClick()));
	
	redEdit = new QLineEdit(this);
	redEdit->setGeometry(100, 100, 150, 30);
	redEdit->setText(QString::number(redColor));
	
	color.setRgb(redColor, 0, 0, 255);

}

void MainWindow::startButtonClick() {
	redColor = redEdit->text().toInt();
	color.setRgb(redColor, 0, 0, 255);
	redLabel->setText( "Red Color: " + QString::number(redColor) );
	update();
}

void MainWindow::paintEvent( QPaintEvent * ) {
	QPainter p(this);
	p.setBrush(QBrush(color));
	p.drawRect(100, 150, 200, 150);
}
