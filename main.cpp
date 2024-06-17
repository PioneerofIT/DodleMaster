#include "doodle.h"
#include <qtextcodec.h>
#include <QTextCodec>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("eucKR"));
	
	

	Doodle w;
	w.show();
	return a.exec();
}
