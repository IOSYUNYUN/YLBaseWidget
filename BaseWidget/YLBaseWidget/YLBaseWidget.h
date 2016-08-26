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
	//�ػ��¼�
	void paintEvent(QPaintEvent *);
	//���İ����¼�
	void mousePressEvent(QMouseEvent *event);
	//�����ƶ��¼�
	void mouseMoveEvent(QMouseEvent *event);
	//�����ͷ��¼�
	void mouseReleaseEvent(QMouseEvent *event);
	//�ر��¼�
	void closeEvent(QCloseEvent *event);
private:
	//�����λ��
	QPoint clickedPos;
	//����Ƿ���
	bool isLeftPressDown;
signals:
	//�ر�ʱ ���͵Ĺر��ź�
	void closeYL_Wgt();
	
};

#endif // YLBASEWIDGET_H
