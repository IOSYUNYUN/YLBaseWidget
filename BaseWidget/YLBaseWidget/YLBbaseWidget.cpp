#include "YLBaseWidget.h"

YLBaseWidget::YLBaseWidget(QWidget *parent)
	: QWidget(parent)
{
	//���ڵ���ʽ
	setWindowFlags(Qt::FramelessWindowHint);
	//���ڵ�����  �ر�ʱ�ͷ��ڴ�  �����ڶ�����ջ����ʱ  ����ʱ���쳣
	setAttribute(Qt::WA_DeleteOnClose);
}

YLBaseWidget::~YLBaseWidget()
{

}
//�ػ��¼�
void YLBaseWidget::paintEvent(QPaintEvent *)
{
	//����ʵ��ÿ��Բ��������4�����ص�Բ��
	QBitmap objBitmap(this->size());
	QPainter painter(&objBitmap);
	painter.fillRect(rect(), Qt::white);
	painter.setBrush(QColor(0, 0, 0));
	painter.drawRoundedRect(this->rect(), 4, 4);
	this->setMask(objBitmap);
	//��������ʵ��qss�ļ��ļ���
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
//��갴�µ��¼�
void YLBaseWidget::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		clickedPos = event->globalPos() - pos();
		isLeftPressDown = true;
	}
	event->accept();
}
//����ƶ��¼�
void YLBaseWidget::mouseMoveEvent(QMouseEvent *event)
{
	if (isLeftPressDown && event->buttons() == Qt::LeftButton)
	{
		move(event->globalPos() - clickedPos);
	}
	event->accept();
}
//����ͷ��¼�
void YLBaseWidget::mouseReleaseEvent(QMouseEvent *event)
{
	isLeftPressDown = false;
	event->accept();
}
//���ڹر��¼�
void YLBaseWidget::closeEvent(QCloseEvent *event)
{
	//���͹رյ��ź�
	emit closeYL_Wgt();
	event->accept();
}
