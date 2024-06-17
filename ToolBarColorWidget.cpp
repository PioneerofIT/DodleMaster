
#include "ToolBarColorWidget.h"
#include <QPalette>
#include "Chain_Of_Responsibility/ChangeFigureColorRequest.h"
#include <qcolordialog.h>
#include "Observer/ChangeManager.h"

ToolBarColorWidget::ToolBarColorWidget(QWidget *parent, Chain *chain)
	:QWidget(parent), Chain(chain) {

	ui.setupUi(this);

	connect(ui.redButton, &QPushButton::clicked, this, &ToolBarColorWidget::redButtonClicked);
	connect(ui.yellowButton, &QPushButton::clicked, this, &ToolBarColorWidget::yellowButtonClicked);
	connect(ui.blueButton, &QPushButton::clicked, this, &ToolBarColorWidget::blueButtonClicked);
	connect(ui.dialogButton, &QPushButton::clicked, this, &ToolBarColorWidget::dialogButtonClicked);

	ChangeManager::getInstance()->registerObserve(this);
}

void ToolBarColorWidget::redButtonClicked() {

	ChangeFigureColorRequest request(QColor(255, 0, 0));

	this->request(&request);

}

void ToolBarColorWidget::yellowButtonClicked() {

	ChangeFigureColorRequest request(QColor(255, 255, 0));

	this->request(&request);

}

void ToolBarColorWidget::blueButtonClicked() {

	ChangeFigureColorRequest request(QColor(0, 0, 255));

	this->request(&request);

}

void ToolBarColorWidget::dialogButtonClicked() {


	QColorDialog dialog;

	if (dialog.exec() != QDialog::Accepted)
		return;
	else {
		ChangeFigureColorRequest request(dialog.currentColor());

		this->request(&request);
	}

}




ToolBarColorWidget::~ToolBarColorWidget() {

}



#include "Observer/CurrentColorChangedEvent.h"

void ToolBarColorWidget::update(NotifyEvent *notifyEvent) {


	if (dynamic_cast<CurrentColorChangedEvent*>(notifyEvent)) {
	
		QPalette p = ui.dialogButton->palette();
		p.setColor(QPalette::Button, dynamic_cast<CurrentColorChangedEvent*>(notifyEvent)->getColor());

		ui.dialogButton->setAutoFillBackground(true);
		ui.dialogButton->setFlat(true);
		ui.dialogButton->setPalette(p);
		ui.dialogButton->update();

	}
}