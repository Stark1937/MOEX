//
//  Created by everettjf
//  Copyright © 2017 everettjf. All rights reserved.
//
#include "blankcontentview.h"
#include <QLabel>
#include <QLayout>

BlankContentView::BlankContentView(QWidget *parent) : QWidget(parent)
{
    QLabel *text = new QLabel(this);
    text->setText(tr("Drop one file here"));
    text->setAlignment(Qt::AlignCenter);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(text);
    setLayout(layout);

}
