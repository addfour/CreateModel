#include <QtGui/QApplication>
#include <QtCore/QTextCodec>
#include "CreatModel.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	//����Ϊ��������(���Ļ�)
	QTextCodec::setCodecForTr(QTextCodec::codecForName(QTextCodec::codecForLocale()->name()));
	QTextCodec::setCodecForLocale(QTextCodec::codecForName(QTextCodec::codecForLocale()->name()));
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName(QTextCodec::codecForLocale()->name()));
	CreatModel* creatmodel = new CreatModel;
	creatmodel->show();

	return app.exec();
}