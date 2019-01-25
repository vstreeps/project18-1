#include <QtGui>
#include <QTimer>
#include "mainwindow.h"

int chessStartX = 910;
int chessStartY = 10;
int chessW = 100;
int chessH = 100;
int chessCount = 6;
const QString imagesFolder = "G:\\prog\\cpp\\lab18\\project18-2\\images\\";
QString chessName = "empty";
QString chessArray[8][8];

MainWindow::MainWindow() {
	setWindowTitle(tr("Chess board"));
	resize(1200, 950);
	
	rectWidth = 100;
	rectHeight = 100;
	startX = 40;
	startY = 40;
	N = 8;
	M = 8;
	color = 0;

	posLabel = new QLabel(this);
	posLabel->setGeometry(10, 920, 880, 25);
	posLabel->setFont(QFont("Courier", 24, QFont::Normal));
	posLabel->setText("Position: ");
	
	for(int i = 0; i < M; i++)
		for(int j = 0; j < N; j++)
			chessArray[i][j] = "empty";
}

void MainWindow::paintEvent(QPaintEvent *) {
	QPainter myPainter(this);
	
	for( int i = 0; i < M; i++ ) {
		int y = startY + i * rectHeight;
		for( int j = 0; j < N; j++ ) {
			int x = startX + j * rectWidth;
			
			if(color == 0) {
				myPainter.setPen( QPen(Qt::white, 0, Qt::SolidLine) );
				myPainter.setBrush( QBrush(Qt::white) );
			}
			else {
				myPainter.setPen( QPen(Qt::black, 0, Qt::SolidLine) );
				myPainter.setBrush( QBrush(Qt::black) );
			}
			
			// Rectangle
			
			myPainter.drawRect(x, y, rectWidth, rectHeight);
			color = (color == 0) ? 1 : 0;
			
			if( chessArray[j][i] != "empty" ) {
				chess.load(imagesFolder + chessArray[j][i]);
				myPainter.drawImage(x, y, chess.scaled(chessW, chessH), 0, 0, chessW, chessH);
			}
				
		}
		color = (color == 0) ? 1 : 0;
	}
	
	myPainter.setPen( QPen(Qt::black, 0, Qt::SolidLine) );
	myPainter.setFont(QFont("Comic Sans MS", 20, QFont::Bold));
	
	for( int i = 0; i < M; i++ ) {
		int y = startY + i * rectHeight;
		QString num;
		num.setNum(i + 1);
		myPainter.drawText(startX - 30, y + rectHeight / 2, num);
		myPainter.drawText(startX + rectWidth * N + 30, y + rectHeight / 2, num);
	}
	
	QString chars[8] = {"A", "B", "C", "D", "E", "F", "G", "H" };
	
	for( int i = 0; i < N; i++ ) {
		int x = startX + i * rectWidth;
		myPainter.drawText(x + rectWidth / 2, startY - 15, chars[i]);
		myPainter.drawText(x + rectWidth / 2, startY  + rectHeight * M + 30, chars[i]);
	}
	
	for(int i = 0; i < chessCount; i++) {
		int y = chessStartY + i * chessH;
		chess.load(imagesFolder + "b" + QString::number(i) + ".png");
		myPainter.drawImage(chessStartX, y, chess, 0, 0, chessW, chessH);
		
		chess.load(imagesFolder + "w" + QString::number(i) + ".png");
		myPainter.drawImage(chessStartX + chessW, y, chess, 0, 0, chessW, chessH);
	}
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
	int x = event->x();
	int y = event->y();
	QString chars[8] = {"A", "B", "C", "D", "E", "F", "G", "H" };

	for( int i = 0; i < M; i++ ) {
		int y2 = startY + i * rectHeight;
		for( int j = 0; j < N; j++ ) {
			int x2 = startX + j * rectWidth;
			if( x > x2 && x < x2 + rectWidth && y > y2 && y < y2 + rectHeight ) {
				posLabel->setText("Start");
				posLabel->setText("Chess: " + chessArray[j][i]);
				if(chessName != "empty" && chessArray[j][i] == "empty") {
					chessArray[j][i] = chessName;
					update();
					chessName = "empty";
					posLabel->setText("Chess: " + chessArray[j][i]);
				}
				else {
					posLabel->setText("Chess no");
				}
			}
		}
	}
	
	for( int i = 0; i < chessCount; i++ ) {
		int y2 = chessStartY + i * chessH;
		for( int j = 0; j < 2; j++ ) {
			int x2 = chessStartX + chessW * j;
			
			if( x > x2 && x < x2 + chessW && y > y2 && y < y2 + chessH ) {
				(j == 0) ? chessName = "b" + QString::number(i) + ".png" : chessName = "w" + QString::number(i) + ".png";
			}
			
		}
	}
}
