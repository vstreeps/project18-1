#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

QT_BEGIN_NAMESPACE
 class QLabel;
 class QPushButton;
 class QPainter;
 class QLineEdit;
QT_END_NAMESPACE

class MainWindow :public QMainWindow
{
	Q_OBJECT
	public:
    	MainWindow();
    protected:
    	void paintEvent (QPaintEvent *event);
    private slots:
    	void startButtonClick();
    private:
    	QLabel *redLabel;
    	QPainter *p;
    	QPushButton *startButton;
		QLineEdit *redEdit;
		QColor color;
		int redColor;
};
#endif
