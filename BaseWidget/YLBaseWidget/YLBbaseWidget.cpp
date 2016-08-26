#include "YLBaseWidget.h"

YLBaseWidget::YLBaseWidget(QWidget *parent)
	: QWidget(parent)
{
	//窗口的样式
	setWindowFlags(Qt::FramelessWindowHint);
	//窗口的属性  关闭时释放内存  当窗口定义在栈里面时  销毁时会异常
	setAttribute(Qt::WA_DeleteOnClose);
}

YLBaseWidget::~YLBaseWidget()
{

}
//重绘事件
void YLBaseWidget::paintEvent(QPaintEvent *)
{
	//用来实现每个圆角上面有4个像素的圆角
	QBitmap objBitmap(this->size());
	QPainter painter(&objBitmap);
	painter.fillRect(rect(), Qt::white);
	painter.setBrush(QColor(0, 0, 0));
	painter.drawRoundedRect(this->rect(), 4, 4);
	this->setMask(objBitmap);
	//这里用来实现qss文件的加载
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
//鼠标按下的事件
void YLBaseWidget::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		clickedPos = event->globalPos() - pos();
		isLeftPressDown = true;
	}
	event->accept();
}
//鼠标移动事件
void YLBaseWidget::mouseMoveEvent(QMouseEvent *event)
{
	if (isLeftPressDown && event->buttons() == Qt::LeftButton)
	{
		move(event->globalPos() - clickedPos);
	}
	event->accept();
}
//鼠标释放事件
void YLBaseWidget::mouseReleaseEvent(QMouseEvent *event)
{
	isLeftPressDown = false;
	event->accept();
}
//窗口关闭事件
void YLBaseWidget::closeEvent(QCloseEvent *event)
{
	//发送关闭的信号
	emit closeYL_Wgt();
	event->accept();
}
