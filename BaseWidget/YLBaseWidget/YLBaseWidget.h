#ifndef YLBASEWIDGET_H
#define YLBASEWIDGET_H
#include <QWidget>
#include <QBitmap>
#include <QPainter>
#include <QStyleOption>
#include <QMouseEvent>

class YLBaseWidget : public QWidget
{
	Q_OBJECT

public:
	YLBaseWidget(QWidget *parent);
	~YLBaseWidget();
protected:
	//重绘事件
	void paintEvent(QPaintEvent *);
	//鼠标的按下事件
	void mousePressEvent(QMouseEvent *event);
	//鼠标的移动事件
	void mouseMoveEvent(QMouseEvent *event);
	//鼠标的释放事件
	void mouseReleaseEvent(QMouseEvent *event);
	//关闭事件
	void closeEvent(QCloseEvent *event);
private:
	//点击的位置
	QPoint clickedPos;
	//左键是否按下
	bool isLeftPressDown;
signals:
	//关闭时 发送的关闭信号
	void closeYL_Wgt();
	
};

#endif // YLBASEWIDGET_H
