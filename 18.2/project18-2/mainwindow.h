#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QLabel>

QT_BEGIN_NAMESPACE
class QPainter;
class QLabel;
QT_END_NAMESPACE
class MainWindow : public QMainWindow {
	Q_OBJECT
	public:
		MainWindow();
		
	protected:
		void paintEvent(QPaintEvent *event);
		void mousePressEvent(QMouseEvent *event);
		
	private:
		QPainter *myPainter;
		
		int startX;
		int startY;
		int rectWidth;
		int rectHeight;
		int N;
		int M;
		int color;

		QLabel *posLabel;
		QImage chess;
};
#endif
